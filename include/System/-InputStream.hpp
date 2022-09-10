//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include <queue>

namespace sf::ui {
  typedef enum Number {
    _0 = 0,
    _1 = 1,
    _2 = 2,
    _3 = 3,
    _4 = 4,
    _5 = 5,
    _6 = 6,
    _7 = 7,
    _8 = 8,
    _9 = 9,
  }Num;

  typedef class InputStream final {
  protected: InputStream(void) = default;
    virtual ~InputStream(void) = default;
  
    static std::queue<Num> _Data; /* [_0, _9] */
  
  _data_public:
    static func set(const Num& value) -> void;
    static func get(void) -> const String&;
  
  }InputStream;
};

#include "../../src/System/InputStream.cpp"
