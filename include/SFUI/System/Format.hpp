//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

#include "Frame.hpp"
#include <iomanip>
#include <codecvt>
#include <sstream>
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
    static func make_pair(const Vector2<type>&) -> std::pair<type, type>;
    template<typename type>
    static func reverse(const Vector2<type>&) -> Vector2<type>;
    template<typename type>
    static func length(const Vector2<type>&) -> float;
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
    static func toString(float, size_t precision = 2) -> String;
    
    static func imageCopyToHorizontal(Image) -> Image;
    static func imageCopyToVertical  (Image) -> Image;
    
  }Fm;
  
  func operator- (const String&) -> std::wstring;
  func operator--(const String&) -> std::string;
}

namespace std {
  func to_wstring(const  string&) -> wstring;
  func to_string (const wstring&) ->  string;
}

#include "../../../src/SFUI/System/Format.cpp"
