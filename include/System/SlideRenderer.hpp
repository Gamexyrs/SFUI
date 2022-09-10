//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "Context.hpp"
#include <optional>

namespace sf::ui {
  typedef class SlideRenderer {
  protected: SlideRenderer(void) = default;
    virtual ~SlideRenderer(void) = default;
    
    static Vector2<Vector2<std::optional<float>>> MaxPosition; /* = {{0, std::nullopt}, {0, std::nullopt}} */
    
    static bool EnableSmooth; /* = true */
    
    static bool Active; /* = false */
    
    static Vector2 TouchPosition;
    
    static View _View;
  
  _data_public:
    static inline func setMaxPosition_X(Vector2<std::optional<float>> value) -> void __SET__(SlideRenderer::MaxPosition.x, __NF);
    static inline func getMaxPosition_X(void) -> Vector2<std::optional<float>>       __GET__(SlideRenderer::MaxPosition.x);
  
    static inline func setMaxPosition_Y(Vector2<std::optional<float>> value) -> void __SET__(SlideRenderer::MaxPosition.y, __NF);
    static inline func getMaxPosition_Y(void) -> Vector2<std::optional<float>>       __GET__(SlideRenderer::MaxPosition.y);
  
    static inline func setEnableSmooth(bool value) -> void __SET__(SlideRenderer::EnableSmooth, __NF);
    static inline func getEnableSmooth(void) -> bool       __GET__(SlideRenderer::EnableSmooth);
  
    static inline func setActive(bool value) -> void __SET__(SlideRenderer::Active, __NF);
    static inline func getActive(void) -> bool       __GET__(SlideRenderer::Active);
  
  _func_public:
    
  }SlideRenderer;
};

#include "../../src/System/SlideRenderer.cpp"

//>>>

namespace gy {
  typedef class [[deprecated]] SlidableActivity : virtual protected Context {
  protected:
    static sf::Vector2f TouchBegan, TouchCurr, MoveAll, MoveCurr;
  
             SlidableActivity(void) = default;
    virtual ~SlidableActivity(void) = default;
  
  public:
    stline avoidOverTop(sf::View& View) -> void;
    
    stline pollEvent(sf::Event Event)   -> void;
    
    stline slide_smooth(sf::View& View) -> void;
    stline slide(sf::View& View)        -> void;
    stline reset(sf::View& View)        -> void;
  }SlidableActivity;
  
  typedef SlidableActivity Slider;
  
  sf::Vector2f SlidableActivity::TouchBegan = {};
  sf::Vector2f SlidableActivity::TouchCurr  = {};
  sf::Vector2f SlidableActivity::MoveAll    = {};
  sf::Vector2f SlidableActivity::MoveCurr   = {};
  
  //>>>
  
  atline SlidableActivity::pollEvent(sf::Event Event) -> void {
         if(Event.type == sf::Event::TouchBegan) {
      TouchBegan = (sf::Vector2f)sf::Touch::getPosition(0, *Window);
    }
    else if(Event.type == sf::Event::TouchMoved) {
      TouchCurr  = (sf::Vector2f)sf::Touch::getPosition(0, *Window);
    }
    else if(Event.type == sf::Event::TouchEnded) {
      TouchBegan = {}; TouchCurr = {}; 
    }
  }
  atline SlidableActivity::avoidOverTop(sf::View& View) -> void {
    if(MoveAll.y < 0) {
      View = Window->getDefaultView();
      MoveCurr.y = 0; MoveAll.y = 0;
    }
  }
  atline SlidableActivity::slide_smooth(sf::View& View) -> void {
         if(MoveCurr.x >  5) MoveCurr.x -= 0.5;
    else if(MoveCurr.x < -5) MoveCurr.x += 0.5;
    else MoveCurr.x = 0;
         if(MoveCurr.y >  5) MoveCurr.y -= 0.5;
    else if(MoveCurr.y < -5) MoveCurr.y += 0.5;
    else MoveCurr.y = 0;
    if(TouchBegan.y && TouchCurr.y) {
      MoveCurr.y = TouchBegan.y - TouchCurr.y;
      TouchBegan = TouchCurr;
    }
    if(MoveAll.y > 0 || MoveCurr.y > 0) {
      View.move(0.f, MoveCurr.y);
      MoveAll.y += MoveCurr.y;
    } Window->setView(View);
  }
  atline SlidableActivity::slide(sf::View& View) -> void {
    if(TouchBegan.y && TouchCurr.y) {
      MoveCurr.y = TouchBegan.y - TouchCurr.y;
      TouchBegan = TouchCurr;
    }
    if(MoveAll.y > 0 || MoveCurr.y > 0) {
      View.move(0.f, MoveCurr.y);
      MoveAll.y += MoveCurr.y;
    } Window->setView(View);
    MoveCurr.y = 0;
  }
  atline SlidableActivity::reset(sf::View& View) -> void {
    View = Window->getDefaultView();
    MoveCurr.y = 0; MoveAll.y = 0;
  }
};

