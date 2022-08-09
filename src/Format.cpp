//>>> 2021~2022 Gamexyrs© & SFML®

namespace gy {
  template<typename Type>
  inline auto Format::getPosition(const sf::Rect<Type>& Rect) -> sf::Vector2<Type> {
    return{Rect.left, Rect.top};
  }
  template<typename Type>
  inline auto Format::getSize(const sf::Rect<Type>& Rect) -> sf::Vector2<Type> {
    return{Rect.width, Rect.height};
  }
  
  inline auto Format::getSize(const sf::Sprite& Target) -> sf::Vector2f {
    return Format::getSize(Target.getGlobalBounds());
  }
  inline auto Format::getSize(const sf::Shape& Target) -> sf::Vector2f {
    return Format::getSize(Target.getGlobalBounds());
  }
  inline auto Format::getSize(const sf::Text& Target) -> sf::Vector2f {
    return Format::getSize(Target.getGlobalBounds());
  }
  
  template<typename Type>
  inline auto Format::reverse(const sf::Vector2<Type>& Vector) -> sf::Vector2<Type> {
    return{Vector.y, Vector.x};
  }
  
  inline auto Format::toString(const sf::VideoMode& VideoMode) -> sf::String {
    return sf::String(L"[w:" + std::to_wstring(VideoMode.width) + L", h:" + std::to_wstring(VideoMode.height) +
      L", bpp:" + std::to_wstring(VideoMode.bitsPerPixel) + L"]");
  }
  template<typename Type>
  inline auto Format::toString(const sf::Rect<Type>& Rect) -> sf::String {
    return sf::String(L"[x:" + std::to_wstring(Rect.left) + L", y:" + std::to_wstring(Rect.top)
      + L", w:" + std::to_wstring(Rect.width) + L", h:" + std::to_wstring(Rect.height) + L"]");
  }
  template<typename Type>
  inline auto Format::toString(const sf::Vector2<Type>& Vector) -> sf::String {
    return sf::String(L"[x:" + std::to_wstring(Vector.x) + L", y:" + std::to_wstring(Vector.y) + L"]");
  }
  template<typename Type>
  inline auto Format::toString(const sf::Vector3<Type>& Vector) -> sf::String {
    return sf::String(L"[x:" + std::to_wstring(Vector.x) + L", y:" + std::to_wstring(Vector.y)
      + L", z:" + std::to_wstring(Vector.z) + L"]");
  }
    
  template<typename Type>
  inline auto operator* (const sf::Vector2<Type>& left, const sf::Vector2<Type>& right) -> sf::Vector2<Type> {
    return{left.x * right.x, left.y * right.y};
  }
};

namespace std {
  inline auto to_wstring(const string& str) -> wstring {
  	wstring_convert<codecvt_utf8<wchar_t>> converter;
  	return converter.from_bytes(str);
  }
  inline auto to_string(const wstring& wstr) -> string {
  	wstring_convert<codecvt_utf8<wchar_t>> converter;
  	return converter.to_bytes(wstr);
  }
};
