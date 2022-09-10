//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  Obj::Object(const BuildFrame& frame) : Buildable(this) {
    this->setPosition(frame.x); this->setSize(frame.y);
  }
  
  inline func Obj::move(const Vector2f& value) const -> void {
    this->setPosition(this->getPosition() + value);
  }
  
  inline func Obj::getRect(void) const -> FloatRect {
    return{this->getPosition().x, this->getPosition().y, this->getSize().x, this->getSize().y};
  }
  inline func Obj::getRoot(void) const -> Vector2f {
    return this->getPosition() + this->getSize();
  }
  
  inline func Obj::needUpdate(bool subobj) const -> void {
    this->NeedUpdate = true; if(subobj) this->followerNeedUpdate();
  }
  
  inline func Obj::isTouchDown(void) const -> unsigned {
    return((!Renderer::getEnableVirtualKeyboard() && this->Active) ? MultiTouch::isDown(this->getRect()) : false);
  }
};
