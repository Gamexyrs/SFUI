//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

namespace sf::ui {
  typedef class Trigger {
  public:    Trigger(void) = default;
    virtual ~Trigger(void) = default;
    
  _data_public:
    std::wstring __data{};
  
  } Trigger;
}

#include "../../../src/SFUI/System/Trigger.cpp"
