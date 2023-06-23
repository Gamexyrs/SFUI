//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "../Object.hpp"
#include "../Touchable.hpp"

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
    
    struct {
      Color __None   {Color::White},
            __Pulled {ColorEx::Grey},
            __Pressed{ColorEx::Grey},
            __Checked{ColorEx::Grey};
    }__StateColor;
    
    BtnState __State{BtnState::None};
    
  _data_public:
    func setStateColor(const Color& value, const std::optional<BtnState>& state = std::nullopt) -> void;
    func getStateColor(const BtnState& state) const -> const Color&;
    
    func setState(const BtnState&) _____ -> void;
    func getState(void) const -> const BtnState&;

  _func_public:
  
    
  }AbsBtn;
}

#include "../../../../src/SFUI/Graphics/Button/AbstractButton.cpp"
