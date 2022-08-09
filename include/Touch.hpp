//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

namespace gy {
  typedef class Touch final {
  protected: Touch(void) = default;
    virtual ~Touch(void) = default;
  
  _data_public:
    static unsigned MultiFinger_Max; /* = 5 */
  
  _func_public:
    // Multi-Finger Detection
    static auto isDown(const sf::FloatRect& Rect) -> unsigned;
    
    static auto getPosition(unsigned index = 0) -> sf::Vector2f;
    
  }Touch;
};

#include "../src/Touch.cpp"
