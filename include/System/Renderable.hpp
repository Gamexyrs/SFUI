//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "__Config.hpp"
#include <optional>

#define _RendererRect (static_cast<sf::FloatRect>(sf::IntRect(sf::Renderable::getRenderer().getPosition().x, \
                                                              sf::Renderable::getRenderer().getPosition().y, \
                                                              sf::Renderable::getRenderer().getSize().x,     \
                                                              sf::Renderable::getRenderer().getSize().y)))
#define _RendererSize (static_cast<sf::Vector2f>(sf::Renderable::getRenderer().getSize()))
#define _Renderer (sf::Renderable::getRenderer())

namespace sf::ui {
  typedef class Renderable {
    protected: Renderable(void) = default;
      virtual ~Renderable(void) = default;
      
      static inline RenderWindow* Renderer = nullptr;
      
      func __rendererCheck(void) const -> void;
      
    _data_public:
      static func setRenderer(const RenderWindow& value) -> void;
      static func getRenderer(void) _____ -> _____ RenderWindow&;
      
  }Renderable;
}

#include "../../src/System/Renderable.cpp"
