//>>> 2021~2022 Gamexyrs© & SFML®

namespace gy {
  sf::RenderWindow* Context::Window = nullptr;

  auto Context::setRenderer(sf::RenderWindow& Window) -> void {
    Context::Window = &Window;
  }
  auto Context::getRenderer(void) -> sf::RenderWindow& {
    return *Context::Window;
  }
}
