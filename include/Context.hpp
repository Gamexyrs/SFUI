//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include <SFML/Graphics.hpp>

#define _Renderer gy::Context::getRenderer()

#define _data_public public
#define _func_public public

namespace sf { inline namespace ui {
  typedef class Context {
  protected: Context(void) = default;
    virtual ~Context(void) = default;
    
    static sf::RenderWindow* Window;
    
  _func_public:
    static auto setRenderer(sf::RenderWindow& Window) -> void;
    static auto getRenderer(void) -> sf::RenderWindow&;
    
  }Context;
};

#include "../src/Context.cpp"
