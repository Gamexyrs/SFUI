//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func align(const Vector2f size, const FloatRect& rect, short _align) -> const Vector2f {
    switch(_align) {
      case(Align::T):
        return {align(size, rect).x,
            Fm::getPosition(rect).y};

      case(Align::L):
        return {Fm::getPosition(rect).x,
                    align(size, rect).y};

      case(Align::R):
        return {Fm::getRoot(rect).x - size.x,
                         align(size, rect).y};

      case(Align::B):
        return {align(size, rect).x,
       Fm::getRoot(rect).y - size.y};

      case(Align::TL):
        return Fm::getPosition(rect);
        
      case(Align::TR):
        return {Fm::getRoot(rect).x - size.x,
                     Fm::getPosition(rect).y};

      case(Align::BL):
        return {Fm::getPosition(rect).x,
           Fm::getRoot(rect).y - size.y};

      case(Align::BR):
        return (Fm::getRoot(rect) - size);
        
      default: // Center
        return (Fm::getPosition(rect) + (Fm::getSize(rect) - size) / 2.f);
    }
  }
}
