//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

#include "TextureDiv.hpp"
#include "../Interface/Progressable.hpp"

namespace sf::ui {
  typedef class ProgressDiv : public TexDiv, public Progressable {
  public:    ProgressDiv(const Vector2f& size, const Object& builder, int radius = 0,
                         const Vector2f& buildPosition = {},
                         const Vector2b& buildAddSize  = {});
             ProgressDiv(const Frame& frame = {}, int radius = 0);
    virtual ~ProgressDiv(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
    virtual func update(void) const -> void;
    
    struct {
      float __RunSpeed{5.0f};
      bool  __Running {true};
    }__Busy;
    
    mutable Div __Inside{};
    
  _data_public:
    func getInside(bool update = true) const -> Div&;

    func setBusyRunning(bool) -> void;
    func getBusyRunning(void) const -> bool;
  
    func setBusyRunSpeed(float) -> void;
    func getBusyRunSpeed(void) const -> float;
  
  _func_public:
    
  } ProgressDiv;
}

#include "../../../../src/SFUI/Graphics/Div/ProgressDiv.cpp"
