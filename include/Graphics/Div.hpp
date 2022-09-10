//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include <cmath>
#include "Object.hpp"
#include "Buildable.hpp"

namespace sf::ui {
  typedef class Div : public Obj {
  protected:
    virtual func draw(RenderTarget& target, RenderStates states) const -> void;
    virtual func update(void) const -> void;
    
    mutable struct {
      mutable unsigned PointCount = 40;
      mutable unsigned Radius     = 0;
      
      mutable bool R_LT = true,
                   R_LB = true,
                   R_RT = true,
                   R_RB = true;
    }Border;
    
  _data_public:
    inline func setBorderPointCount(unsigned value) const -> void {range(this->Border.PointCount, value, 20U, UINT_MAX, {4U}); this->needUpdate();}
    inline func getBorderPointCount(void) const -> unsigned __GET__(this->Border.PointCount);
    
    inline func setBorderRadius(unsigned value) const -> void {range(this->Border.Radius, value, 0U, this->getMaxRadius()); this->needUpdate();}
    inline func getBorderRadius(void) const -> unsigned __GET__(this->Border.Radius);
    
  _func_public:
    func getMaxRadius(void) const -> unsigned;
  
    // Radius_LT / Radius_LB / Radius_RT / Radius_RB
    func operator[] (const String& name) -> bool&;
  
             Div(const BuildFrame& frame = {{}, {}}, unsigned radius = 0);
    virtual ~Div(void) = default;
    
  }Div;
};

#include "../../src/Graphics/Div.cpp"
