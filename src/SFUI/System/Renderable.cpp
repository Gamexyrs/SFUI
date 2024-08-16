//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func Renderable::__rendererCheck(void) -> bool {
    if(Renderable::Renderer == nullptr) {
      err() << "Undefined to renderer [= nullptr]" << std::endl;
      return false;
    } return true;
  }
  
  inline func Renderable::setRenderer(const RenderWindow& value) -> void {
    Renderable::Renderer = const_cast<RenderWindow*>(&value);
  }
  inline func Renderable::getRenderer(void) -> RenderWindow* {
    return Renderable::Renderer;
  }
  
  inline func Renderable::setDefaultFont(const Font& value) -> void {
    Renderable::__DefaultFont = const_cast<Font*>(&value);
  }
  inline func Renderable::getDefaultFont(void) -> Font& {
    static Font __tmp_f{};
    if(Renderable::__DefaultFont == nullptr) {
      err() << "Undefined to defaultFont [= nullptr]\n\n";
             __tmp_f.loadFromFile("/system/fonts/NotoSansCJK-Regular.ttc");
      return __tmp_f;
    } return *Renderable::__DefaultFont;
  }
  
  inline func Renderable::loopBegin(const Color& clear) -> bool {
    if(Renderable::Renderer->isOpen()) {
       Renderable::__fps_clock.restart();
       Renderable::Renderer->clear(clear);
      return true;
    } return false;
  }
  inline func Renderable::getFPS_loopEnd(void) -> String {
    return String(std::to_wstring((static_cast<unsigned>(std::ceil(Renderable::getFPS_loopEndf())))));
  }
  inline func Renderable::getFPS_loopEndf(void) -> float {
    return 1.0f / Renderable::__fps_clock.getElapsedTime().asSeconds();
  }
  
  inline func Renderable::getViewPosition(void) -> Vector2f {
    return(Renderable::Renderer->getView().getCenter()
         - Renderable::Renderer->getView().getSize() / 2.0f);
  }
  inline func Renderable::getViewRect(void) -> FloatRect {
    return FloatRect{
      {Renderable::getViewPosition().x,
       Renderable::getViewPosition().y},
      {Renderable::Renderer->getView().getSize().x,
       Renderable::Renderer->getView().getSize().y}};
  }
  
  inline func Renderable::draw(const std::initializer_list<Drawable*>& value) -> void {
    for(auto& i : value) {
      if(i != nullptr) Renderable::Renderer->draw(*i);
    }
  }
  inline func Renderable::draw_fast(const std::initializer_list<Drawable*>& value) -> void {
    for(auto& i : value) {
      Renderable::Renderer->draw(*i);
    }
  }
}
