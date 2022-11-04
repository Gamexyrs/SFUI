//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "Renderable.hpp"
#include <sstream>

namespace sf::ui {
  typedef class KeyboardEvent {
  protected: KeyboardEvent(void) = default;
    virtual ~KeyboardEvent(void) = default;
  
    static inline String __Buffer = L"";
  
  _data_public:
    static inline struct __KB_SETTINGS__ {
      bool __ALLOW_NUMBER__, // 'N' (identifiers, etc.)
           __ALLOW_LETTER__, // 'L'
           __ALLOW_SYMBOL__, // 'S'
           __ALLOW_NXLINE__, // '+'
           __ALLOW_DELETE__; // 'D'
      
    }__SETTINGS__ = {true, true, true, true, true};
    
    // if str includes corresponding identifiers means those settings turn to true
    static func setSettings(const String& str = "NLSD+") -> void;
  
  _func_public:
    static func getBufPwString(bool dLast = true,
      wchar_t dChar = L'*') -> String;
    static func getBufString  (bool reset = true) -> String;
    static func delBufString  (void) ->   void;
    
    static func getBufSize(void) -> size_t;
    
    static func backspace(void) -> void;
    static func nextLine (void) -> void;
    static func pushBack (const String& str) -> void;
    
    static func pollEvent(const Event& event,
                          bool inBuf = false) -> String;
  
  }KbEvent;

//>>>
  
  typedef class TouchEvent {
  protected: TouchEvent(void) = default;
    virtual ~TouchEvent(void) = default;

#if __PREDEF_ENABLE_TOUCHDATA__
    static inline std::vector<std::pair<Vector2f, Clock>> __TouchData
                = std::vector<std::pair<Vector2f, Clock>>(11);
    static inline Vector2f __TouchMove    = {};
#endif
    static inline unsigned __FingerMaxNum = 11;
  
  _data_public:
    static func setFingerMaxNum(unsigned value) -> void;
    static func getFingerMaxNum(void) _____ -> unsigned;

#if __PREDEF_ENABLE_TOUCHDATA__
    static func getTouchMove(void) -> Vector2f;
    
    static func resetTouchTime(std::optional<unsigned> index = std::nullopt) -> void;
    static func   getTouchTime(unsigned index = 0) -> Time;
#endif

  _func_public:
#if __PREDEF_ENABLE_TOUCHDATA__
    static func pollEvent(const Event& event) -> void;
#endif
    static func getPosition(unsigned index = 0) -> Vector2f;
    static func isDownAt(const std::optional<FloatRect>& optRect = std::nullopt) -> unsigned;
    
  }TouchEvent;
}

#include "../../../src/SFUI/System/Inputable.cpp"
