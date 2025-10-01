//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

#include "Div.hpp"

namespace sf::ui {
  typedef class ProgressSliderDiv : public ProgressDiv {
  public:    ProgressSliderDiv(const Vector2f& size, const Object& builder, int radius = 0,
                       const Vector2f& buildPosition = {},
                       const Vector2b& buildAddSize  = {});
             ProgressSliderDiv(const Frame& frame = {}, int radius = 0);
    virtual ~ProgressSliderDiv(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
    virtual func update(void) const -> void;
    
    bool __TouchFlowEnabled{true};
    
  _data_public:
    func setTouchFlowEnabled(bool) -> void;
    func getTouchFlowEnabled(void) const -> bool;
    
  _func_public:
    virtual func pollEvent(const Event&) -> bool;
    
  } ProgressSlider;
}

#include "../../../../src/SFUI/Graphics/Div/ProgressSliderDiv.cpp"
