//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "__Config.hpp"
#if __has_include(<optional>)
#include <optional>
#elif __has_include(<experimental/optional>)
#include <experimental/optional>
#else
#error "Unsupport cpp version"
#endif
#include <utility>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>

#define _RendererRect (::sf::FloatRect(::sf::Vector2f(::sf::ui::Renderable::getRenderer()->getPosition().x, \
                                                      ::sf::ui::Renderable::getRenderer()->getPosition().y), \
                                       ::sf::Vector2f(::sf::ui::Renderable::getRenderer()->getView().getSize().x,\
                                                      ::sf::ui::Renderable::getRenderer()->getView().getSize().y)))
#define _RendererSize (static_cast<::sf::Vector2f>(::sf::ui::Renderable::getRenderer()->getView().getSize()))
#define _Renderer (*::sf::ui::Renderable::getRenderer())

namespace sf::ui {
  typedef interface class Renderable {
  private:
    static inline RenderWindow* Renderer{nullptr};
    static inline Clock __fps_clock{};
  
  protected: Renderable(void) = default;
    virtual ~Renderable(void) = default;

    static inline Font* __DefaultFont{nullptr};
    
    static func __rendererCheck(void) -> bool;
    
  _data_public:
    static func setRenderer(const RenderWindow&) -> void;
    static func getRenderer(void) -> _____ RenderWindow*;

    static func setDefaultFont(const Font&) -> void;
    static func getDefaultFont(void) -> _____ Font&;
    
    static func loopBegin(const Color& clear = Color::White) -> bool;
    static func getFPS_loopEnd (void) -> String;
    static func getFPS_loopEndf(void) -> float;
    
    static func getViewPosition(void) -> Vector2f;
    static func getViewRect    (void) -> FloatRect;
    
    static func draw     (const std::initializer_list<Drawable*>&) -> void;
    static func draw_fast(const std::initializer_list<Drawable*>&) -> void;
    
  }Renderable;
}

#include "../../../src/SFUI/System/Renderable.cpp"
