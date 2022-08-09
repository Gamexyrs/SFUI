//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "CheckButton.hpp"
#include <deque>

namespace gy {
  typedef class EditDiv : public Button {
    sf::Clock Clock;
  
  protected:
    virtual auto update(void) const -> void;
    virtual auto draw(sf::RenderTarget& target, sf::RenderStates states) const -> void;
    
  _data_public:
    unsigned TextCharMax = __UINT32_MAX__;
    deque<char> Banned = {};
    bool AcceptSymbol = true;
    bool AcceptLetter = true;
    bool AcceptNumber = true;
    
    struct {
      struct {
        sf::Color None    = sf::Color::Black;
        sf::Color Pressed = sf::Color::Blue;
        sf::Color Checked = sf::Color::Blue;
      }Color;
      sf::Time FlashTime = sf::Seconds(1);
      float Thickness = -1; // Auto
      bool Visible = true;
    }EditFlag;
    
    struct {
      struct {
        sf::Color None    = sf::Color::Black;
        sf::Color Pressed = sf::Color::Blue;
        sf::Color Checked = sf::Color::Blue;
      }Color;
      int Position = Align::B;
      float Thickness = -1; // Auto
      bool Visible = true;
    }EditLine;

  _func_public:
    auto pollEvent   (const sf::Event& Event) -> BState;
    auto pollEvent_if(const sf::Event& Event, BState Tar = BState::Released) -> bool;
  
             EditDiv(const BuildFrame& Frame = {{}, {}}, unsigned OutlineThickness = 0);
    virtual ~EditDiv(void) = default;
    
  }EDiv;
};

#include "../src/EditDiv.cpp"
