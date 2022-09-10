//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

namespace sf::ui {
  template<typename Type>
  func range(                   Type& value, Type min, Type max, const std::vector<Type>& special = {}) -> Type&;
  
  template<typename Type>
  func range(Type& changeValue, Type  value, Type min, Type max, const std::vector<Type>& special = {}) -> Type&;
};

#include "../../src/System/Range.cpp"

