//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "__Config.hpp"
#include <optional>
#include <utility>
#include <vector>
#include <deque>
#include <queue>

#define _RendererRect (static_cast<sf::FloatRect>(sf::IntRect(sf::Renderable::getRenderer().getPosition().x, \
                                                              sf::Renderable::getRenderer().getPosition().y, \
                                                              sf::Renderable::getRenderer().getSize().x,     \
                                                              sf::Renderable::getRenderer().getSize().y)))
#define _RendererSize (static_cast<sf::Vector2f>(sf::Renderable::getRenderer().getSize()))
#define _Renderer (sf::Renderable::getRenderer())

namespace sf::ui {
  typedef interface class Renderable {
    protected: Renderable(void) = default;
      virtual ~Renderable(void) = default;

#if __PREDEF_ENABLE_UNITYDRAW__
      static inline std::queue<Drawable*> __Unity;
#endif
      
      static inline RenderWindow* Renderer = nullptr;
      static inline Font*    __DefaultFont = nullptr;
      
      static func __rendererCheck(void) -> bool;
      
    _data_public:
      static func setRenderer(const RenderWindow& value) -> void;
      static func getRenderer(void) _____ -> _____ RenderWindow&;

      static func setDefaultFont(const Font& value) -> void;
      static func getDefaultFont(void) _____ -> _____ Font&;
      
      static func draw(std::initializer_list<Drawable*> value) -> void;

#if __PREDEF_ENABLE_UNITYDRAW__
      static func unityAdd(std::initializer_list<Drawable*> value) -> void;
      static func unityDraw(void) -> void;
#endif

  }Renderable;
}

#include "../../../src/SFUI/System/Renderable.cpp"
