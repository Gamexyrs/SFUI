//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "../Object.hpp"
#include <cmath>

#define __MIN_POINTCOUNT__ 16

namespace sf::ui {
  typedef class Div : public Obj, public Drawable {
  public:    Div(const Vector2f& size, const Object& builder, unsigned radius = 0,
                 const Vector2f& buildPosition = {},
                 const Vector2b& buildAddSize  = {});
             Div(const Frame& frame = {}, unsigned radius = 0);
    virtual ~Div(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
    virtual func update(void) const -> void;
    
    mutable struct {
      unsigned __PointCount{40};
      unsigned __Radius    {0};
      
      bool __Rounded_LT{true},
           __Rounded_LB{true},
           __Rounded_RT{true},
           __Rounded_RB{true};
    }__Border;
    
  _data_public:
    func setRounded_List(const std::vector<bool>&) const -> void;
    func getRounded_List(void) const -> std::vector<bool>;
    func setRounded(bool value, const Align& corner = Align::C) const -> void;
    func getRounded(const Align& corner) const -> bool;
    
    func setPointCount(unsigned) _____ -> void;
    func getPointCount(void) const -> unsigned;
    
    func setRadius(unsigned) const -> void;
    func getRadius    (void) const -> unsigned;
    
  _func_public:
    func getRealRadius(void) const -> unsigned;
    func getMaxRadius (void) const -> unsigned;
    
  }Div;
}

#include "../../../../src/SFUI/Graphics/Div/Div.cpp"
