//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "TextDiv.hpp"

namespace gy {
  typedef enum class ButtonState {
    None, Pressed, Released,
  }BState;

  typedef class PushButton : public TDiv {
  protected:
    virtual auto update(void) const -> void;
    virtual auto draw(sf::RenderTarget& target, sf::RenderStates states) const -> void;
    
  _data_public:
    BState State = BState::None;
    struct {
      sf::Color None    = sf::Color::White,
                Pressed = gy::Color::Grey,
                Checked = gy::Color::Grey;
    }Color;

  _func_public:
    auto pollEvent   (const sf::Event& Event) -> BState;
    auto pollEvent_if(const sf::Event& Event, BState Tar = BState::Released) -> bool;
  
             PushButton(const BuildFrame& Frame = {{}, {}}, unsigned Radius = 0);
    virtual ~PushButton(void) = default;
    
  }Button;
};

#include "../src/PushButton.cpp"
