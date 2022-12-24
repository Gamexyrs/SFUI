//>>> 2021~2022 Gamexyrs© & SFML®

// pre-def

// if false, you may cannot use unity draw in class Renderable
#ifdef    __PREDEF_ENABLE_UNITYDRAW__
  #undef  __PREDEF_ENABLE_UNITYDRAW__
  #define __PREDEF_ENABLE_UNITYDRAW__ false
#else
  #define __PREDEF_ENABLE_UNITYDRAW__ true
#endif

// if false, you may cannot use touchMove and touchTime in class TouchEvent
#ifdef    __PREDEF_ENABLE_TOUCHDATA__
  #undef  __PREDEF_ENABLE_TOUCHDATA__
  #define __PREDEF_ENABLE_TOUCHDATA__ false
#else
  #define __PREDEF_ENABLE_TOUCHDATA__ true
#endif

// if false, you may cannot use many functions about buffer in class KeyboardEvent
#ifdef    __PREDEF_ENABLE_KB_BUFFER__
  #undef  __PREDEF_ENABLE_KB_BUFFER__
  #define __PREDEF_ENABLE_KB_BUFFER__ false
#else
  #define __PREDEF_ENABLE_KB_BUFFER__ true
#endif

namespace sf {
  inline namespace ui {
  }
}
