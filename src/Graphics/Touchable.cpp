//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func TouchEvent::setFingerMaxNum(unsigned value) -> void {
    TouchEvent::__FingerMaxNum = value;
  }
  inline func TouchEvent::getFingerMaxNum(void) _____ -> unsigned {
    return TouchEvent::__FingerMaxNum;
  }

  inline func TouchEvent::getPosition(unsigned index) -> Vector2f {
    return static_cast<Vector2f>(Touch::getPosition(index, _Renderer));
  }

  inline func TouchEvent::isTouchAt(const std::optional<FloatRect>& optRect) -> unsigned {
    FloatRect rect = optRect.value_or(_RendererRect);
    for(int i = 0; i < TouchEvent::__FingerMaxNum; ++i) {
         if(!Touch::isDown(i)) return false;
    else if(rect.contains(TouchEvent::getPosition(i))) return (i + 1);
    } return false;
  }
  
  inline func Touchable::isTouchDown(void) -> unsigned {
    return TouchEvent::isTouchAt(this->__Self->getRect());
  }
}
