//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "TextDiv.hpp"

namespace sf::ui {
  typedef class ProgressDiv : public TextDiv {
  public:    ProgressDiv(const Vector2f& size, const Object& builder, unsigned radius = 0,
                         const Vector2f& buildPosition = {},
                         const Vector2b& buildAddSize  = {});
             ProgressDiv(const Frame& frame = {{}, {}}, unsigned radius = 0);
    virtual ~ProgressDiv(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, RenderStates states) const -> void;
    virtual func update(void) const -> void;
    
    mutable float __Progress = 0; /* % */
    
    struct {
      float __RunSpeed = 5.0f;
      bool  __Running  = true;
    }__Busy;
    
    mutable Div __Inside;
    
  _data_public:
    func getInside(void) const -> Div&;
  
    func setProgress(float current, float total) -> void;
    func setProgress(float value) -> void;
    func getProgress(void) const -> float;
    
    func setBusyRunning(bool value) -> void;
    func getBusyRunning(void) const -> bool;
  
    func setBusyRunSpeed(float value) -> void;
    func getBusyRunSpeed(void) const -> float;
  
  _func_public:
    func movProgress(float value) -> void;
    func strProgress(void) const -> String;
    
  }ProgressDiv;
}

#include "../../../../src/SFUI/Graphics/Div/ProgressDiv.cpp"
