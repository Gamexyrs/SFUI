//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

namespace sf::ui {
  typedef enum Align {
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
}

#include "../../src/System/Align.cpp"
