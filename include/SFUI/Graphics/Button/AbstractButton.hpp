//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

#include "../Object.hpp"
#include "../Interface/Touchable.hpp"

namespace sf::ui {
  typedef enum class ButtonEvent {
    None, Press, Release,
    
  }BtnEvent;

  typedef enum class ButtonState {
    None, Pressed, Checked,
    
  }BtnState;

  typedef interface class AbstractButton {
  private:
    Object* __Self{nullptr};
  
  protected: AbstractButton(Object* self) : __Self(self) {}
    virtual ~AbstractButton(void) = default;
    
    mutable struct {
      Color __None   {Color::White},
            __Pulled {ColorEx::Grey},
            __Pressed{ColorEx::Grey},
            __Checked{ColorEx::Grey};
    }__StateColor;
    
    BtnState __State{BtnState::None};
    
  _data_public:
    func setStateColor(const Color&, const std::optional<BtnState>& = std::nullopt) const -> void;
    func getStateColor(const BtnState&) const -> const Color&;
    
    func setState(const BtnState&) -> void;
    func getState(void) const -> const BtnState&;

  _func_public:
    
  }AbsBtn;
}

#include "../../../../src/SFUI/Graphics/Button/AbstractButton.cpp"
