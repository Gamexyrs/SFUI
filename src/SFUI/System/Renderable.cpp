//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  inline func __PercentToFloat(const Percent& percent) -> float {
    std::string tmp{percent.toAnsiString()};
    if(tmp.back() == '%')
       tmp.pop_back();
    try {
      return(std::stof(tmp) / 100);
    } catch(...) {
      err() << "SFUI_CATCH: Input an unresolvable percent string\n";
      return 0.0f;
    }
  }
  
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
  
  inline func Renderable::capture(void) -> Image {
    if(!Renderable::__rendererCheck()) return Image{};
    
    Texture tex{};
    tex.create(static_cast<unsigned>(_RendererSize.x),
               static_cast<unsigned>(_RendererSize.y));
    tex.update(*Renderable::Renderer);
    
    Image img{tex.copyToImage()};
          img.flipVertically();
    
    return img;
  }
  
  template<typename T, typename... Args>
  inline func Renderable::draw(T&& first, Args&&... args) -> void {
          Renderable::Renderer->draw(std::forward<Drawable>(first));
    (..., Renderable::Renderer->draw(std::forward<Drawable>(args)));
  }
  template<typename T, typename... Args>
  inline func Renderable::destroy(T&& first, Args&&... args) -> void {
          std::destroy_at(&first);
    (..., std::destroy_at(&args));
  }
}
