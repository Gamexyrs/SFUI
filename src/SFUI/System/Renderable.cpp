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
  inline func Renderable::getRenderer(void) _____ -> _____ RenderWindow& {
    if(!Renderable::__rendererCheck()) throw nullptr;
    return *Renderable::Renderer;
  }
  
  inline func Renderable::setDefaultFont(const Font& value) -> void {
    Renderable::__DefaultFont = const_cast<Font*>(&value);
  }
  inline func Renderable::getDefaultFont(void) _____ -> _____ Font& {
    if(Renderable::__DefaultFont == nullptr) {
      err() << "Undefined to defaultFont [= nullptr]" << std::endl;
      throw nullptr;
    } return *Renderable::__DefaultFont;
  }
  
  inline func Renderable::draw(std::initializer_list<Drawable*> value) -> void {
    for(auto& i : value) {
      if(i != nullptr) Renderable::Renderer->draw(*i);
    }
  }
  
#if __PREDEF_ENABLE_UNITYDRAW__
  inline func Renderable::unityAdd(std::initializer_list<Drawable*> value) -> void {
    for(auto& i : value) {
      if(i != nullptr) Renderable::__Unity.push(i);
    }
  }
  inline func Renderable::unityDraw(void) -> void {
    std::queue<Drawable*> new_unity;
    while(!Renderable::__Unity.empty()) {
      if(Renderable::__Unity.front() != nullptr) {
        Renderable::Renderer->draw(*Renderable::__Unity.front());
        new_unity.push(Renderable::__Unity.front());
        Renderable::__Unity.pop();
      }
    } Renderable::__Unity = new_unity;
  }
#endif
}
