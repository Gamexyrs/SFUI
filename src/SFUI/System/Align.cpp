//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func align(const Vector2f size, const FloatRect& rect, short _align) -> const Vector2f {
    if(!_align)
      return(Fm::getPosition(rect) + (Fm::getSize(rect) - size) / 2.f);
      
    Vector2f tmp_v2 = {};
           if(_align & Align::L) {
      tmp_v2.x = rect.left;
    } else if(_align & Align::R) {
      tmp_v2.x = Fm::getRoot(rect).x - size.x;
    } else {
      tmp_v2.x = align(size, rect).x;
    }
           if(_align & Align::T) {
      tmp_v2.y = rect.top;
    } else if(_align & Align::B) {
      tmp_v2.y = Fm::getRoot(rect).y - size.y;
    } else {
      tmp_v2.y = align(size, rect).y;
    } return tmp_v2;
  }
}
