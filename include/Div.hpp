//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include <cmath>
#include "Object.hpp"

namespace gy {
  typedef class Div : public Obj {
  protected:
    virtual auto update(void) const -> void;
    virtual auto draw(sf::RenderTarget& target, sf::RenderStates states) const -> void;
    
  _data_public:
    struct {
              unsigned PointCount = 80;
      mutable unsigned Radius     = 0;
    }Border;
  
  _func_public:
             Div(const BuildFrame& Frame = {{}, {}}, unsigned Radius = 0);
    virtual ~Div(void) = default;
    
  }Div;
};

#include "../src/Div.cpp"
