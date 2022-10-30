//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  template<typename Type>
  inline func Fm::getPosition(const Rect<Type>& rect) -> Vector2<Type> {
    return{rect.left, rect.top};
  }
  template<typename Type>
  inline func Fm::getSize(const Rect<Type>& rect) -> Vector2<Type> {
    return{rect.width, rect.height};
  }
  template<typename Type>
  inline func Fm::getRoot(const Rect<Type>& rect) -> Vector2<Type> {
    return{rect.left + rect.width, rect.top + rect.height};
  }
  
  inline func Fm::getSize(const Sprite& target) -> Vector2f {
    return Fm::getSize(target.getGlobalBounds());
  }
  inline func Fm::getSize(const Shape& target) -> Vector2f {
    return Fm::getSize(target.getGlobalBounds());
  }
  inline func Fm::getSize(const Text& target) -> Vector2f {
    return Fm::getSize(target.getGlobalBounds());
  }
  
  inline func Fm::getFPS(const Clock& clock) -> String {
    return String(std::to_wstring((static_cast<unsigned>(std::ceil(1 / clock.getElapsedTime().asSeconds())))));
  }
  
  template<typename Type>
  inline func Fm::reverse(const Vector2<Type>& vector2) -> Vector2<Type> {
    return{vector2.y, vector2.x};
  }
  
  inline func Fm::toString(const VideoMode& videoMode) -> String {
    return String(L"[w:" + std::to_wstring(videoMode.width) + L", h:" + std::to_wstring(videoMode.height) +
      L", bpp:" + std::to_wstring(videoMode.bitsPerPixel) + L"]");
  }
  template<typename Type>
  inline func Fm::toString(const Rect<Type>& rect) -> String {
    return String(L"[x:" + std::to_wstring(rect.left) + L", y:" + std::to_wstring(rect.top)
      + L", w:" + std::to_wstring(rect.width) + L", h:" + std::to_wstring(rect.height) + L"]");
  }
  template<typename Type>
  inline func Fm::toString(const Vector2<Type>& vector2) -> String {
    return String(L"[x:" + std::to_wstring(vector2.x) + L", y:" + std::to_wstring(vector2.y) + L"]");
  }
  template<typename Type>
  inline func Fm::toString(const Vector3<Type>& vector3) -> String {
    return String(L"[x:" + std::to_wstring(vector3.x) + L", y:" + std::to_wstring(vector3.y)
      + L", z:" + std::to_wstring(vector3.z) + L"]");
  }
    
  template<typename Type>
  inline func operator* (const Vector2<Type>& left, const Vector2<Type>& right) -> Vector2<Type> {
    return{left.x * right.x, left.y * right.y};
  }
}

namespace std {
  inline func to_wstring(const string& str) -> wstring {
  	wstring_convert<codecvt_utf8<wchar_t>> converter;
  	return converter.from_bytes(str);
  }
  inline func to_string(const wstring& wstr) -> string {
  	wstring_convert<codecvt_utf8<wchar_t>> converter;
  	return converter.to_bytes(wstr);
  }
}
