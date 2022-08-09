//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "PushButton.hpp"

namespace gy {
  typedef class CheckButton : public Button {
  protected:
    virtual auto update(void) const -> void;
    virtual auto draw(sf::RenderTarget& target, sf::RenderStates states) const -> void;
    
  _data_public:
    bool Checked = false;

  _func_public:
    auto pollEvent   (const sf::Event& Event) -> BState;
    auto pollEvent_if(const sf::Event& Event, BState Tar = BState::Released) -> bool;
  
             CheckButton(const BuildFrame& Frame = {{}, {}}, unsigned Radius = 0);
    virtual ~CheckButton(void) = default;
    
  }CButton;
};

#include "../src/CheckButton.cpp"
