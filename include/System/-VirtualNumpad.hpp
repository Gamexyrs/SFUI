//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "PushButton.hpp"

namespace sf::ui {
  typedef class VirtualNumpad : protected Div {
  protected: VirtualNumpad(void) = default;
    virtual ~VirtualNumpad(void) = default;

    static PushBtn _Numkey[10];
    static PushBtn _Deletekey;
    static PushBtn _Enterkey;
    
    static bool isInit;
    
  _data_public:
  
  _func_public:
    static func setEnable(bool value) -> void;
    static func getEnable(void)       -> bool;

    static func pollEvent(const Event& event) -> void;
    static func display(void) -> void;
  
  }VirtualNumpad;
};

#include "../../src/System/VirtualNumpad.cpp"
