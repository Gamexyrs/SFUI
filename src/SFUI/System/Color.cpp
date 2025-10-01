//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  inline func ColorEx::makeTrs(Color rgb, uint8_t alpha) -> Color {
    return {
      rgb.r,
      rgb.g,
      rgb.b,
      alpha,
    };
  }
  
  inline func operator| (Color rgb, uint8_t alpha) -> Color {
    return ColorEx::makeTrs(rgb, alpha);
  }
}
