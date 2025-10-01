//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

namespace sf::ui {
  typedef class ColorExtern {
  public:
    static inline const Color LightGreen{ 0, 205,  88};
    static inline const Color LightBlue{ 96, 128, 176};
    static inline const Color   SkyBlue{135, 206, 235};
    static inline const Color LightPink{255, 192, 203};
    static inline const Color LightGrey{154, 154, 154};
    static inline const Color      Rice{254, 244, 213};
    static inline const Color      Pink{255, 182, 193};
    static inline const Color      Grey{114, 114, 114};
    static inline const Color    Silver{192, 192, 192};
    static inline const Color    Orange{215,  86,   0};
    
    static func makeTrs(Color rgb, uint8_t alpha = 155) -> Color;
    
  }ColorEx;
  
  static func operator| (Color rgb, uint8_t alpha) -> Color;
}

#include "../../../src/SFUI/System/Color.cpp"
