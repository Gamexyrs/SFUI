//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  template<typename type>
  inline func operator+ (const Rect<type>& left, const Rect<type>& right) -> Rect<type> {
    return{{left.left   + right.left,
            left.top    + right.top},
           {left.width  + right.width,
            left.height + right.height}};
  }
  
  template<typename type ,typename type_2>
  inline func operator+ (const Vector2<type>& left, const type_2& right) -> Vector2<type> {
    return{left.x + static_cast<type>(right), left.y + static_cast<type>(right)};
  }
  template<typename type, typename type_2>
  inline func operator+ (const Vector2<type>& left, const Vector2<type_2>& right) -> Vector2<type> {
    return{left.x + static_cast<type>(right.x), left.y + static_cast<type>(right.y)};
  }
  template<typename type ,typename type_2>
  inline func operator* (const Vector2<type>& left, const type_2& right) -> Vector2<type> {
    return{left.x * static_cast<type>(right),   left.y * static_cast<type>(right)};
  }
  template<typename type, typename type_2>
  inline func operator* (const Vector2<type>& left, const Vector2<type_2>& right) -> Vector2<type> {
    return{left.x * static_cast<type>(right.x), left.y * static_cast<type>(right.y)};
  }
}
