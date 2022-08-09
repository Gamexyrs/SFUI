//>>> 2021~2022 Gamexyrs© & SFML®

namespace gy {
  unsigned Touch::MultiFinger_Max = 5;

  inline auto Touch::isDown(const sf::FloatRect& Rect) -> unsigned {
    for(int i = 0; i < Touch::MultiFinger_Max; ++i) {
         if(!sf::Touch::isDown(i)) return false;
    else if(Rect.contains(Touch::getPosition(i))) return i+1;
    } return false;
  }
  
  inline auto Touch::getPosition(unsigned index) -> sf::Vector2f {
    return static_cast<sf::Vector2f>(sf::Touch::getPosition(index, _Renderer));
  }
};
