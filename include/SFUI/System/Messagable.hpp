//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "Renderable.hpp"

namespace sf::ui {
  typedef interface class Messagable {
  protected: Messagable(void) = default;
    virtual ~Messagable(void) = default;
    
    static inline bool __Locked = false;
    
  _data_public:
    static func setLocked(bool value) -> void;
    static func getLocked(void) _____ -> bool;
    
    virtual func pushQueue(void) -> void = 0;
      
  }Messagable;
}

#include "../../../src/SFUI/System/Messagable.cpp"