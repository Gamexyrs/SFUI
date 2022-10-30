//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "../Object.hpp"

namespace sf::ui {
  typedef enum class ButtonEvent {
    None, Move, Press, Release,
    
  }BtnEvent;

  typedef enum class ButtonState {
    None, Held, Pressed, Checked,
    
  }BtnState;

  typedef class AbstractButton {
  private:
    Object* __Self = nullptr;
  
  protected: AbstractButton(Object* self) : __Self(self) {}
    virtual ~AbstractButton(void) = default;
    
    struct {
      Color __None    = Color::White,
            __Held    = ColorEx_Grey,
            __Pressed = ColorEx_Grey,
            __Checked = ColorEx_Grey;
    }__StateColor;
    
    BtnState __State = BtnState::None;
    
  _data_public:
    func setStateColor(const Color& value, const std::optional<BtnState>& state = std::nullopt) -> void;
    func getStateColor(const BtnState& state) const -> const Color&;
    
    func setState(const BtnState& value) -> void;
    func getState(void) const -> const BtnState&;

  _func_public:
  
    
  }AbsBtn;
}

#include "../../../../src/SFUI/Graphics/Button/AbstractButton.cpp"
