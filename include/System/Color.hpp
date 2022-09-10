//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "Context.hpp"
#include <vector>

// Mode - 0
#define _BRIGHT_MODE_ 0
// Mode - 1
#define _DARK_MODE_   1

namespace sf::ui {
  const Color Color_LightPink = {255, 192, 203};
  const Color Color_Pink      = {255, 182, 193};
  const Color Color_Grey      = {114, 114, 114};
  
  const Color Color_Black     = {  0,   0,   0};
  const Color Color_White     = {255, 255, 255};
  
  struct {
    std::vector<Color> Background = {Color_White, Color_Black};
    std::vector<Color> Outline    = {Color_Black, Color_White};
    std::vector<Color> Text       = {Color_Black, Color_White};
    
  }InitColor;
  
  int DisplayMode = _BRIGHT_MODE_;
};

#include "../../src/System/Color.cpp"
