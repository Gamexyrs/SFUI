//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "Object.hpp"

namespace sf::ui {
  typedef interface class Touchable {
  private:
    Object* __Self{nullptr};
    
  protected: Touchable(Object* self) : __Self(self) {}
    virtual ~Touchable(void) = default;
    
    bool __TouchEnable{true};
    
    Vector2f __TouchRectScale {1, 1};
    Vector2f __TouchRectDeviat{};
  
  _data_public:
    func setTouchEnable(bool) _____ -> void;
    func getTouchEnable(void) const -> bool;
    
    func setTouchRectScale(const Vector2f&) _____ -> void;
    func getTouchRectScale(void) const -> const Vector2f&;
  
    func setTouchRectDeviat(const Vector2f&) _____ -> void;
    func getTouchRectDeviat(void) const -> const Vector2f&;
  
  _func_public:
    func isTouchDown(void) -> unsigned;
  
  }Touchable;
}

#include "../../../src/SFUI/Graphics/Touchable.cpp"
