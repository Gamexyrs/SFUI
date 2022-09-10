//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "PushButton.hpp"

namespace sf::ui {
  typedef class [[deprecated("ReactSlowly[RS] (We'll improve this object sometime)")]]
    CheckButton : public PushBtn {
  protected:
    virtual func draw(RenderTarget& target, RenderStates states) const -> void;
    virtual func update(void) const -> void;
    
    bool Checked = false;
    
  _data_public:
    inline func isChecked(void) const -> bool __GET__(this->Checked);
  
  _func_public:
    virtual func pollEvent   (const Event& event) -> BtnEvent;
    virtual func pollEvent_if(const Event& event, BtnEvent tar = BtnEvent::Release) -> bool;
    
             CheckButton(const BuildFrame& frame = {{}, {}}, unsigned radius = 0);
    virtual ~CheckButton(void) = default;
    
  }CheckBtn;
};

#include "../../src/Graphics/CheckButton.cpp"
