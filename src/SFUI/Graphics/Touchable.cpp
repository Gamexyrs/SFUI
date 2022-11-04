//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func Touchable::setEnable(bool value) -> void {
    Touchable::__Enable = value;
  }
  inline func Touchable::getEnable(void) _____ -> bool {
    return Touchable::__Enable;
  }
  
  inline func Touchable::isTouchDown(void) -> unsigned {
    if(!Messagable::getLocked() ||  this->__Self->__ATTRIBUTE__.__ALWAYS_TOUCHABLE__)
       return TouchEvent::isDownAt(this->__Self->getRect());
    else return 0;
  }
}
