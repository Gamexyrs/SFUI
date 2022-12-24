//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "Renderable.hpp"

namespace sf::ui {
  typedef class Percent {
  protected: Percent(void) = default;
    virtual ~Percent(void) = default;
    
    float __Value = 0.0f;
      
  }Pct;
  
  func operator""pct(const char* value) -> Pct;
}

#include "../../../src/SFUI/System/Percent.cpp"