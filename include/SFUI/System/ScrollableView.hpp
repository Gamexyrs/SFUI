//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#ifdef __PREDEF_ENABLE_TOUCHDATA__
#if    __PREDEF_ENABLE_TOUCHDATA__

#include "Messagable.hpp"
#include "Inputable.hpp"

namespace sf::ui {
  typedef class ScrollableView {
  protected: ScrollableView(void) = delete;
    virtual ~ScrollableView(void) = delete;
  
    static inline struct CopyableData {
      float __MoveFactor{0.8},
            __SlideAttenuate{1.2}; // in a tick
      
      Time __ReactTime{milliseconds(30)};
      
      Vector2f __Move{}, __MinMove{4, 4},
               __VerticalMax{},
               __HorizontalMax{};
                            
      bool __Enable_Smooth        {true},
           __Enable_MutexMove     {true},
           __Enable_VerticalMove  {false},
           __Enable_HorizontalMove{false};
           
    } v{0.8, 1.2, milliseconds(30), {}, {4, 4}, {}, {}, 1, 1, 0, 0};
    
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
    
    static func setCopyableData(const CopyableData&) -> void;
    static func getCopyableData(void) -> CopyableData;
    
    static func getAutoSliding(void) -> bool;
    
  _func_public:
    static func resetHorizontalView(void) -> void;
    static func resetVerticalView  (void) -> void;
    
    static func pollEvent(void) -> void;
      
  }ScrollableView;
}

#include "../../../src/SFUI/System/ScrollableView.cpp"

#else
  #warning "cannot use 'class ScrollableView' with __PREDEF_ENABLE_TOUCHDATA__ is false"

#endif

#else
  #warning "cannot use 'class ScrollableView' with __PREDEF_ENABLE_TOUCHDATA__ is undefined"

#endif
