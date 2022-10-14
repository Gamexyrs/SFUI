//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "PushButton.hpp"

namespace sf::ui {
  typedef class CheckButton : public AbsBtn, public TextDiv, public Touchable {
  public:    CheckButton(const Vector2f& size, const Object& builder, unsigned radius = 0,
                         const Vector2f& buildPosition = {},
                         const Vector2b& buildAddSize  = {});
             CheckButton(const Frame& frame = {{}, {}}, unsigned radius = 0);
    virtual ~CheckButton(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, RenderStates states) const -> void;
    virtual func update(void) const -> void;
    
    bool __isPressed = false;
    
  _data_public:
  
  
  _func_public:
    virtual func pollEvent(const Event& event) -> bool;
    
    func setChecked(bool value) -> void;
    func getChecked(void) const -> bool;

  }CheckBtn;
}

#include "../../../src/Graphics/Button/CheckButton.cpp"
