//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  template<typename type>
  inline func operator+ (Rect<type> left, Rect<type> right) -> Rect<type> {
    return{{left.left   + right.left,
            left.top    + right.top},
           {left.width  + right.width,
            left.height + right.height}};
  }
  
  template<typename type ,typename type_2>
  inline func operator+ (Vector2<type> left, type_2 right) -> Vector2<type> {
    return{left.x + static_cast<type>(right), left.y + static_cast<type>(right)};
  }
  template<typename type, typename type_2>
  inline func operator+ (Vector2<type> left, Vector2<type_2> right) -> Vector2<type> {
    return{left.x + static_cast<type>(right.x), left.y + static_cast<type>(right.y)};
  }
  template<typename type ,typename type_2>
  inline func operator- (Vector2<type> left, type_2 right) -> Vector2<type> {
    return{left.x - static_cast<type>(right), left.y - static_cast<type>(right)};
  }
  template<typename type, typename type_2>
  inline func operator- (Vector2<type> left, Vector2<type_2> right) -> Vector2<type> {
    return{left.x - static_cast<type>(right.x), left.y - static_cast<type>(right.y)};
  }
  template<typename type ,typename type_2>
  inline func operator* (Vector2<type> left, type_2 right) -> Vector2<type> {
    return{left.x * static_cast<type>(right),   left.y * static_cast<type>(right)};
  }
  template<typename type, typename type_2>
  inline func operator* (Vector2<type> left, Vector2<type_2> right) -> Vector2<type> {
    return{left.x * static_cast<type>(right.x), left.y * static_cast<type>(right.y)};
  }
  template<typename type ,typename type_2>
  inline func operator/ (Vector2<type> left, type_2 right) -> Vector2<type> {
    return{left.x / static_cast<type>(right),   left.y / static_cast<type>(right)};
  }
  template<typename type, typename type_2>
  inline func operator/ (Vector2<type> left, Vector2<type_2> right) -> Vector2<type> {
    return{left.x / static_cast<type>(right.x), left.y / static_cast<type>(right.y)};
  }
}
