//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func Renderable::__rendererCheck(void) const -> void {
    if(Renderable::Renderer == nullptr)
      err() << "Undefined to renderer [= nullptr]" << std::endl;
  }
  inline func Renderable::setRenderer(const RenderWindow& value) -> void {
    Renderable::Renderer = const_cast<RenderWindow*>(&value);
  }
  inline func Renderable::getRenderer(void) _____ -> _____ RenderWindow& {
    return *Renderable::Renderer;
  }
}
