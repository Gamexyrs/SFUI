//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  unsigned MultiTouch::MaxFingerNum = 5;
  
  inline func MultiTouch::getPosition(unsigned index) -> sf::Vector2f {
    return static_cast<Vector2f>(Touch::getPosition(index, _Renderer));
  }

  inline func MultiTouch::isDown(const FloatRect& rect) -> unsigned {
    for(int i = 0; i < MultiTouch::MaxFingerNum; ++i) {
         if(!Touch::isDown(i)) return false;
    else if(rect.contains(MultiTouch::getPosition(i))) return i+1;
    } return false;
  }
};
