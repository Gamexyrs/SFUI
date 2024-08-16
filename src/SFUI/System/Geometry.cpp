//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui::geometry {
  inline func parse_circle_point(const CircleBuilder& cir, const PointBuilder& pt) -> parse_data_type {
    float v_atan = std::atan((cir._center.y - pt.y)
                           / (cir._center.x - pt.x));
    
    /* [: */
    parse_data.v_Angle = ((cir._center.x < pt.x) ? 0.0f : 180.0f) + v_atan * (180.0f / M_PI);
    /* [: */
    parse_data.v_Position = (cir._allow_in
           && (std::sqrt(std::pow(cir._center.x - pt.x, 2)
                       + std::pow(cir._center.y - pt.y, 2))
                               <= cir._radius)) ? pt
           : (Vector2f(std::cos(v_atan),
                       std::sin(v_atan))
             * ((cir._center.x < pt.x)
             ? cir._radius
             :-cir._radius)
             + cir._center);
    /* [: */
    parse_data.v_LengthToCenter_Oblique =
      std::sqrt(
        std::pow(parse_data.v_Position.x, 2) +
        std::pow(parse_data.v_Position.y, 2)
      );
    /* [: */
    parse_data.v_LengthToCenter_Coordinates = parse_data.v_Position - cir._center;
    
    return parse_data;
  }
}
