//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

namespace gy {
  typedef class Color final {
  protected: Color(void) = default;
    virtual ~Color(void) = default;
  
  _data_public:
    static const sf::Color Grey;
    static const sf::Color Pink;
    static const sf::Color LightPink;
  
  }Color;
};

#include "../src/Color.cpp"
