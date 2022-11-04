//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

namespace sf::ui {
  typedef enum AlignPosition {
    Center = 0 << 0, C = Center,
    Top    = 1 << 0, T = Top,
    Left   = 1 << 1, L = Left,
    Right  = 1 << 2, R = Right,
    Bottom = 1 << 3, B = Bottom,
    
    LT = (T ^ L), TL = LT,
    LB = (T ^ R), BL = LB,
    RT = (B ^ L), TR = RT,
    RB = (B ^ R), BR = RB,
  }Align;
  
  func align(const Vector2f size, const FloatRect& rect,
         short align = Align::Center) -> const Vector2f;
}

#include "../../../src/SFUI/System/Align.cpp"
