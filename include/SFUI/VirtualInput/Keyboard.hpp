//>>> 2021~2024 Gamexyrs© & SFML®

#pragma once

#include "../Graphics.hpp"

namespace sf::ui {
  typedef class interface AbstractKeyboard {
  public:    AbstractKeyboard(void) = default;
    virtual ~AbstractKeyboard(void) = default;
  
  protected:
    sf::Div __base;
    std::vector<std::vector<sf::PushBtn>> __btns;
    
  _data_public:
    func getBase(void) const -> Div&;
    func getBtns(void) const -> std::vector<std::vector<sf::PushBtn>>&;
    
    func getKey(void) const -> sf::String;
    
  _func_public:
    virtual func pollEvent(const Event&) -> bool;
    
  } AbsKeyboard;
}

#include "../../../src/SFUI/VirtualInput/Joystick.cpp"
