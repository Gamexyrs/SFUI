//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "Context.hpp"

namespace sf::ui {
  typedef class MultiTouch : protected Touch {
  protected: MultiTouch(void) = default;
    virtual ~MultiTouch(void) = default;
  
    static unsigned MaxFingerNum; /* = 5 */
  
  _data_public:
    static inline func setMaxFingerNum(unsigned value) -> void __SET__(MaxFingerNum, __NF);
    static inline func getMaxFingerNum(void)       -> unsigned __GET__(MaxFingerNum);
  
  _func_public:
    static func getPosition(unsigned index = 0) -> Vector2f;
  
    static func isDown(const FloatRect& rect) -> unsigned;
    
  }MultiTouch;
};

#include "../../src/System/Touch.cpp"
