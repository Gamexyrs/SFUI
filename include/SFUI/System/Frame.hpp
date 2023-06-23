//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include <optional>

namespace sf::ui {
  typedef class Frame {
  public:
    template<typename type = float>
    constexpr Frame(const Vector2<type>& pos = {}, const Vector2<type>& size = {})
        :  pos(static_cast<Vector2f>(pos)),
          size(static_cast<Vector2f>(size)) {}
          
    template<typename type = float>
    constexpr Frame(const Rect<type>& rect)
        :  pos({static_cast<float>(rect.left),
                static_cast<float>(rect.top)}),
          size({static_cast<float>(rect.width),
                static_cast<float>(rect.height)}) {}
  
  _data_public:
    Vector2f pos{}, size{};
  
  }Frame;
  
  template<typename type, typename type_2>
  func operator+ (const Rect<type>&, const Rect<type_2>&) -> Rect<type>;
  
  template<typename type, typename type_2>
  func operator+ (const Vector2<type>&, const         type_2 &) -> Vector2<type>;
  template<typename type, typename type_2>
  func operator+ (const Vector2<type>&, const Vector2<type_2>&) -> Vector2<type>;
  template<typename type, typename type_2>
  func operator* (const Vector2<type>&, const         type_2 &) -> Vector2<type>;
  template<typename type, typename type_2>
  func operator* (const Vector2<type>&, const Vector2<type_2>&) -> Vector2<type>;
}

#include "../../../src/SFUI/System/Frame.cpp"
