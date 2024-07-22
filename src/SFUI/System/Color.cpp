//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func ColorEx::makeTrs(Color rgb, uint8_t alpha) -> Color {
    return {
      rgb.r,
      rgb.g,
      rgb.b,
      alpha,
    };
  }
}
