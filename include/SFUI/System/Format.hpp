//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "Frame.hpp"
#include <codecvt>
#include <string>

namespace sf::ui {
  typedef class Format {
  protected: Format(void) = default;
    virtual ~Format(void) = default;
    
  _func_public:
    template<typename type>
    static func getPosition(const Rect<type>&) -> Vector2<type>;
    template<typename type>
    static func getSize    (const Rect<type>&) -> Vector2<type>;
    template<typename type>
    static func getRoot    (const Rect<type>&) -> Vector2<type>;
    static func getRoot    (const Sprite&) -> Vector2f;
    template<typename type>
    static func getCenter  (const Rect<type>&) -> Vector2<type>;
    
    static func getCenter(const Sprite&) -> Vector2f;
    static func getCenter(const Shape& ) -> Vector2f;
    static func getCenter(const Text&  ) -> Vector2f;
    
    static func getSize(const Sprite&) -> Vector2f;
    static func getSize(const Shape& ) -> Vector2f;
    static func getSize(const Text&  ) -> Vector2f;
    
    template<typename type>
    static func reverse(const Vector2<type>&) -> Vector2<type>;
    template<typename type>
    static func abs    (const Vector2<type>&) -> Vector2<type>;
    
    static func toString(const Color&, bool out_a = true) -> String;
    static func toString(const Frame&) -> String;
    static func toString(const Time& ) -> String;
    template<typename type>
    static func toString(const Rect   <type>&) -> String;
    template<typename type>
    static func toString(const Vector2<type>&) -> String;
    template<typename type>
    static func toString(const Vector3<type>&) -> String;
    
  }Fm;
}

namespace std {
  func to_wstring(const  string&) -> wstring;
  func to_string (const wstring&) ->  string;
}

#include "../../../src/SFUI/System/Format.cpp"
