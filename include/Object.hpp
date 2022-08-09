//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "Position.hpp"
#include "Context.hpp"
#include "Format.hpp"
#include "Touch.hpp"
#include "Color.hpp"

namespace gy {
  typedef sf::Vector2<sf::Vector2f> BuildFrame;

  typedef class Object : public sf::Drawable {
  protected: Object(const BuildFrame& Frame = {});
    virtual ~Object(void) = default;
    
  _data_public:
    sf::Vector2f Position = {}, Size = {};
    mutable sf::ConvexShape Base;
  
  _func_public:
    auto build(const sf::Vector2f& Deviat, bool Width = false, bool Height = false) const -> sf::Vector2f;
    
    auto getBoundsSize(void) const -> sf::Vector2f;
    
    auto getRect(void) const -> sf::FloatRect;
    auto getRoot(void) const -> sf::Vector2f;
    
    auto isDown(void) const -> int;
    
  }Obj;
};

#include "../src/Object.cpp"
