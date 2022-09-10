//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "TextDiv.hpp"

namespace sf::ui {
  typedef enum class ButtonEvent {
    None, Move, Press, Release,
    
  }BtnEvent;

  typedef enum class ButtonState {
    None, Held, Pressed,
    
    LongPressed = Held,
  }BtnState;

  typedef class PushButton : public TextDiv {
  protected:
    virtual func draw(RenderTarget& target, RenderStates states) const -> void;
    virtual func update(void) const -> void;
    
    bool Enable_HeldState = false;
      
    Time  TimeToHeld = seconds(1);
    Clock Timer;
    
    BtnState _State = BtnState::None;
    
  _data_public:
    inline func setState(BtnState value) -> void __SET__(this->_State, this->needUpdate);
    inline func getState(void) const -> BtnState __GET__(this->_State);
  
    inline func setEnableHeld(bool value) -> void __SET__(this->Enable_HeldState, this->needUpdate);
    inline func getEnableHeld(void) const -> bool __GET__(this->Enable_HeldState);
  
    struct {
      Color None    = Color::Transparent,
            Held    = Color_Grey,
            Pressed = Color_Grey,
            Checked = Color_Grey;
    }StateColor;

  _func_public:
    virtual func pollEvent   (const Event& event) -> BtnEvent;
    virtual func pollEvent_if(const Event& event, BtnEvent tar = BtnEvent::Release) -> bool;
  
             PushButton(const BuildFrame& frame = {{}, {}}, unsigned radius = 0);
    virtual ~PushButton(void) = default;
    
  }PushBtn;
};

#include "../../src/Graphics/PushButton.cpp"
