//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

#include "Div.hpp"

namespace sf::ui {
  typedef class SliderDiv : public Div, public Progressable {
  public:    SliderDiv(const Vector2f& size, const Object& builder, int radius = 0,
                       const Vector2f& buildPosition = {},
                       const Vector2b& buildAddSize  = {});
             SliderDiv(const Frame& frame = {}, int radius = 0);
    virtual ~SliderDiv(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
    virtual func update(void) const -> void;
    
    bool __TouchFlowEnabled{true};
    
    mutable Div __Inside{};
    
  _data_public:
    func setTouchFlowEnabled(bool) -> void;
    func getTouchFlowEnabled(void) const -> bool;
    
    func getInside(bool update = true) const -> Div&;
    
  _func_public:
    virtual func pollEvent(const Event&) -> bool;
    
  } Slider;
}

#include "../../../../src/SFUI/Graphics/Div/SliderDiv.cpp"
