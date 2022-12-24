//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

namespace sf::ui {
  typedef class ColorExtern {
  public:
    static inline const Color LightPink = {255, 192, 203};
    static inline const Color      Pink = {255, 182, 193};
    static inline const Color      Grey = {114, 114, 114};
    
    static func makeTrs(Color rgb, Uint8 alpha = 155) -> Color;
    
  }ColorEx;
}

#include "../../../src/SFUI/System/Color.cpp"
