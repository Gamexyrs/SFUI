//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func ColorEx::makeTrs(Color rgb, Uint8 alpha) -> Color {
    return {
      rgb.r,
      rgb.g,
      rgb.b,
      alpha,
    };
  }
}
