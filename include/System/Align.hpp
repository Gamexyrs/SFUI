//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "Context.hpp"
#include "Format.hpp"

namespace sf::ui {
  typedef enum AlignPosition {
    Center = 0 << 0, C = Center,
    Top    = 1 << 0, T = Top,
    Left   = 1 << 1, L = Left,
    Right  = 1 << 2, R = Right,
    Bottom = 1 << 3, B = Bottom,
    
  }Align;

  func getPosition(const FloatRect& div,     const Vector2f& objSize = {}, short objPos = Align::Center) -> Vector2f;
  func getPosition(/* Div = _RendererRect */ const Vector2f& objSize = {}, short objPos = Align::Center) -> Vector2f;
};

#include "../../src/System/Align.cpp"
