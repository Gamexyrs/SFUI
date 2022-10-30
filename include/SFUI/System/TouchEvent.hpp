//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "Renderable.hpp"

namespace sf::ui {
  typedef class TouchEvent {
  protected: TouchEvent(void) = default;
    virtual ~TouchEvent(void) = default;
  
    static inline unsigned __FingerMaxNum = 5;
  
  _data_public:
    static func setFingerMaxNum(unsigned value) -> void;
    static func getFingerMaxNum(void) _____ -> unsigned;
  
  _func_public:
    static func getPosition(unsigned index = 0) -> Vector2f;
  
    static func isTouchAt(const std::optional<FloatRect>& optRect = std::nullopt) -> unsigned;
  
  }TouchEvent;
}

#include "../../../src/SFUI/System/TouchEvent.cpp"
