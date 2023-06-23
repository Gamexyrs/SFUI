//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "TextDiv.hpp"
#include <iomanip>

namespace sf::ui {
  typedef class ProgressDiv : public TextDiv {
  public:    ProgressDiv(const Vector2f& size, const Object& builder, unsigned radius = 0,
                         const Vector2f& buildPosition = {},
                         const Vector2b& buildAddSize  = {});
             ProgressDiv(const Frame& frame = {}, unsigned radius = 0);
    virtual ~ProgressDiv(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
    virtual func update(void) const -> void;
    
    mutable float __Progress{0};
    
    struct {
      float __RunSpeed{5.0f};
      bool  __Running {true};
    }__Busy;
    
    mutable Div __Inside{};
    
  _data_public:
    func getInside(bool update = true) const -> Div&;
  
    func setProgress(float current, float total) -> void;
    func setProgress(float)   -> void;
    func setProgress(Percent) -> void;
    func getProgress(void) const -> float;
    
    func setBusyRunning(bool) -> void;
    func getBusyRunning(void) const -> bool;
  
    func setBusyRunSpeed(float) -> void;
    func getBusyRunSpeed(void) const -> float;
  
  _func_public:
    func movProgress(float)   -> void;
    func movProgress(Percent) -> void;
    func strProgress(size_t precision = 0) const -> String;
    
  }ProgressDiv;
}

#include "../../../../src/SFUI/Graphics/Div/ProgressDiv.cpp"
