//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "Object.hpp"

namespace sf::ui {
  typedef interface class Touchable {
  private:
    Object* __Self = nullptr;
    
  protected: Touchable(Object* self) : __Self(self) {}
    virtual ~Touchable(void) = default;
    
    static inline bool __Enable = true;
  
  _data_public:
    static func setEnable(bool value) -> void;
    static func getEnable(void) _____ -> bool;
  
  _func_public:
    func isTouchDown(void) -> unsigned;
  
  }Touchable;
}

#include "../../../src/SFUI/Graphics/Touchable.cpp"
