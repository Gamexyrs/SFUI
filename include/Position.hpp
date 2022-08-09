//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "Context.hpp"
#include "Format.hpp"

namespace gy {
  typedef enum AlignPosition {
    Center = 0 << 0, C = Center,
    Top    = 1 << 0, T = Top,
    Left   = 1 << 1, L = Left,
    Right  = 1 << 2, R = Right,
    Bottom = 1 << 3, B = Bottom,
    
  }Align;

  typedef class Position final {
  _func_public:
    static auto getPoint(const sf::FloatRect& Div, const sf::Vector2f& ObjSize = {}, short ObjPos = Align::Center) -> sf::Vector2f;
    static auto getPoint(/* Div = _RendererSize */ const sf::Vector2f& ObjSize = {}, short ObjPos = Align::Center) -> sf::Vector2f;
    
  }Pos;
};

#include "../src/Position.cpp"
