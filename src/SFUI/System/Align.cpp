//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func align(const Vector2f size, const FloatRect& rect, short _align) -> Vector2f {
    if(!_align)
      return(Fm::getPosition(rect) + (Fm::getSize(rect) - size) / 2.0f);
      
    Vector2f tmp_v2{};
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
  
  inline func align_toRect(const Vector2f size, const FloatRect& rect, short _align) -> FloatRect {
    const Vector2f& __tmp{align(size, rect, _align)};
    return {__tmp.x - rect.left, __tmp.y - rect.top, size.x, size.y};
  }
  
  template<typename type>
  inline func overlay(const Rect<type>& left, const Rect<type>& right) -> bool {
    Rect<type> __inter{};
    return(left.intersects(right, __inter)
    && (__inter == left
    ||  __inter == right));
  }
}
