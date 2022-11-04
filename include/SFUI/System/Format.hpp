//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include <codecvt>
#include <string>
#include <cmath>

namespace sf::ui {
  typedef class Format {
  protected: Format(void) = default;
    virtual ~Format(void) = default;
    
  _func_public:
    template<typename Type>
    static func getPosition(const Rect<Type>& rect) -> Vector2<Type>;
    template<typename Type>
    static func getSize    (const Rect<Type>& rect) -> Vector2<Type>;
    template<typename Type>
    static func getRoot    (const Rect<Type>& rect) -> Vector2<Type>;
    
    static func getSize(const Sprite& target) -> Vector2f;
    static func getSize(const Shape&  target) -> Vector2f;
    static func getSize(const Text&   target) -> Vector2f;
    
    static func getFPS(const Clock& clock) -> String;
    
    template<typename Type>
    static func reverse(const Vector2<Type>& vector2) -> Vector2<Type>;
    
    static func toString(const VideoMode&  videoMode) -> String;
    static func toString(const Time&            time) -> String;
    template<typename Type>
    static func toString(const Rect   <Type>&   rect) -> String;
    template<typename Type>
    static func toString(const Vector2<Type>& vector2) -> String;
    template<typename Type>
    static func toString(const Vector3<Type>& vector3) -> String;
    
  }Fm;
  
  template<typename Type>
  func operator* (const Vector2<Type>& left, const Vector2<Type>& right) -> Vector2<Type>;
}

namespace std {
  func to_wstring(const  string&  str) -> wstring;
  func to_string (const wstring& wstr) ->  string;
}

#include "../../../src/SFUI/System/Format.cpp"
