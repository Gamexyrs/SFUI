//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#ifdef __PREDEF_ENABLE_TOUCHDATA__
#if    __PREDEF_ENABLE_TOUCHDATA__

#include "Messagable.hpp"
#include "Inputable.hpp"

namespace sf::ui {
  typedef class SlidableView {
    protected:  SlidableView(void) = delete;
      virtual  ~SlidableView(void) = delete;
      
      static inline float __MoveFactor{0.8},
                      __SlideAttenuate{0.5}; // in a tick
      
      static inline Time  __ReactTime{milliseconds(38)};
      
      static inline Vector2f __Move{}, __MinMove{2, 2},
                             __VerticalMax{},
                             __HorizontalMax{};
                            
      static inline bool __Enable_Smooth        {true},
                         __Enable_MutexMove     {true},
                         __Enable_VerticalMove  {false},
                         __Enable_HorizontalMove{false};
      
      static func __check(void) -> void;
      
    _data_public:
      static func setMoveFactor(float) -> void;
      static func getMoveFactor(void) -> float;
      
      static func setSlideAttenuate(float) -> void;
      static func getSlideAttenuate(void) -> float;
      
      static func setReactTime(const Time&) -> void;
      static func getReactTime(void) -> const Time&;
      
      static func setMinMove(const Vector2f&) -> void;
      static func getMinMove(void) -> const Vector2f&;
      
      static func setHorizontalMax(const Vector2f&) -> void;
      static func getHorizontalMax(void) -> const Vector2f&;
      
      static func setVerticalMax(const Vector2f&) -> void;
      static func getVerticalMax(void) -> const Vector2f&;
      
      static func setSmoothEnable(bool) -> void;
      static func getSmoothEnable(void) -> bool;
      
      static func setMutexMoveEnable(bool) -> void;
      static func getMutexMoveEnable(void) -> bool;
      
      static func setHorizontalMoveEnable(bool) -> void;
      static func getHorizontalMoveEnable(void) -> bool;
      
      static func setVerticalMoveEnable(bool) -> void;
      static func getVerticalMoveEnable(void) -> bool;
      
      static func getAutoSliding(void) -> bool;
      
    _func_public:
      static func resetHorizontalView(void) -> void;
      static func resetVerticalView  (void) -> void;
      
      static func pollEvent(void) -> void;
      
  }SlidableView;
}

#include "../../../src/SFUI/System/SlidableView.cpp"

#else
  #warning "cannot use 'class SlidableView' with __PREDEF_ENABLE_TOUCHDATA__ is false"

#endif

#else
  #warning "cannot use 'class SlidableView' with __PREDEF_ENABLE_TOUCHDATA__ is undefined"

#endif
