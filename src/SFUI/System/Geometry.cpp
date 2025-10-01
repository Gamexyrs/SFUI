//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui::geometry {
  inline func parse_circle_point(const CircleBuilder& cir, const PointBuilder& pt) -> parse_data_type {
    // 使用 atan2 避免除零并自动处理所有象限
    float v_atan{std::atan2(cir._center.y - pt.y,
                            cir._center.x - pt.x)};

    /* [: */
    // 直接由 atan2 得到的弧度转为角度
    parse_data.v_Angle = v_atan * (180.0f / M_PI);

    /* [: */
    // 判断点是否在圆内
    const bool inside{cir._allow_in
      && (std::sqrt(std::pow(cir._center.x - pt.x, 2)
                  + std::pow(cir._center.y - pt.y, 2))
                          <= cir._radius)};

    // 若在内则返回原坐标，否则投影到圆周
    parse_data.v_Position = inside ? pt
      : Vector2f{std::cos(v_atan), std::sin(v_atan)} * cir._radius + cir._center;

    /* [: */
    // 计算结果点到圆心的距离
    parse_data.v_LengthToCenter_Oblique =
      std::sqrt(
        std::pow(parse_data.v_Position.x - cir._center.x, 2) +
        std::pow(parse_data.v_Position.y - cir._center.y, 2)
      );

    /* [: */
    // 结果点相对圆心的向量
    parse_data.v_LengthToCenter_Coordinates = parse_data.v_Position - cir._center;

    return parse_data;
  }
}
