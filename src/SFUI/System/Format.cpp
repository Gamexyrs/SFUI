//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  template<typename type>
  inline func Fm::getPosition(const Rect<type>& rect) -> Vector2<type> {
    return{rect.left, rect.top};
  }
  template<typename type>
  inline func Fm::getSize(const Rect<type>& rect) -> Vector2<type> {
    return{rect.width, rect.height};
  }
  template<typename type>
  inline func Fm::getRoot(const Rect<type>& rect) -> Vector2<type> {
    return{rect.left + rect.width, rect.top + rect.height};
  }
  template<typename type>
  inline func Fm::getCenter(const Rect<type>& rect) -> Vector2<type> {
    return{rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f};
  }
  
  inline func Fm::getCenter(const Sprite& target) -> Vector2f {
    return Fm::getCenter(target.getGlobalBounds());
  }
  inline func Fm::getCenter(const Shape& target) -> Vector2f {
    return Fm::getCenter(target.getGlobalBounds());
  }
  inline func Fm::getCenter(const Text& target) -> Vector2f {
    return Fm::getCenter(target.getGlobalBounds());
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
  
  template<typename type>
  inline func Fm::reverse(const Vector2<type>& vector2) -> Vector2<type> {
    return{vector2.y, vector2.x};
  }
  template<typename type>
  inline func Fm::abs(const Vector2<type>& vector2) -> Vector2<type> {
    return{static_cast<type>(std::fabs(vector2.y)),
           static_cast<type>(std::fabs(vector2.x))};
  }
  
  inline func Fm::toString(const Color& color, bool out_a) -> String {
    return String(L"[r:" + std::to_wstring(color.r) + L", g:" + std::to_wstring(color.g)
      + L", b:" + std::to_wstring(color.b) + (out_a ? (L", a:" + std::to_wstring(color.a)) : L"") + L"]");
  }
  inline func Fm::toString(const Frame& frame) -> String {
    return String(L"[x:" + std::to_wstring(frame.pos.x) + L", y:" + std::to_wstring(frame.pos.y)
      + L", w:" + std::to_wstring(frame.size.x) + L", h:" + std::to_wstring(frame.size.y) + L"]");
  }
  inline func Fm::toString(const Time& time) -> String {
    return String(L"[s:" + std::to_wstring(static_cast<unsigned>(time.asSeconds())) +
      L", ms:" + std::to_wstring(time.asMilliseconds() % 1000) +
      L", us:" + std::to_wstring(time.asMicroseconds() % 1000) + L"]");
  }
  template<typename type>
  inline func Fm::toString(const Rect<type>& rect) -> String {
    return String(L"[x:" + std::to_wstring(rect.left) + L", y:" + std::to_wstring(rect.top)
      + L", w:" + std::to_wstring(rect.width) + L", h:" + std::to_wstring(rect.height) + L"]");
  }
  template<typename type>
  inline func Fm::toString(const Vector2<type>& vector2) -> String {
    return String(L"[x:" + std::to_wstring(vector2.x) + L", y:" + std::to_wstring(vector2.y) + L"]");
  }
  template<typename type>
  inline func Fm::toString(const Vector3<type>& vector3) -> String {
    return String(L"[x:" + std::to_wstring(vector3.x) + L", y:" + std::to_wstring(vector3.y)
      + L", z:" + std::to_wstring(vector3.z) + L"]");
  }
}

namespace std {
  inline func to_wstring(const string& str) -> wstring try {
  	wstring_convert<codecvt_utf8<wchar_t>> converter;
  	return converter.from_bytes(str);
  } catch(...) { return L""; }
  
  inline func to_string(const wstring& wstr) -> string try {
  	wstring_convert<codecvt_utf8<wchar_t>> converter;
  	return converter.to_bytes(wstr);
  } catch(...) { return ""; }
}
