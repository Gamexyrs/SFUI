//>>> 2021~2022 Gamexyrs© & SFML®

// pre-def

// if false, you may cannot use unity draw in class Renderable
#ifdef    __PREDEF_ENABLE_UNITYDRAW__
  #undef  __PREDEF_ENABLE_UNITYDRAW__
  #define __PREDEF_ENABLE_UNITYDRAW__ false
#else
  #define __PREDEF_ENABLE_UNITYDRAW__ true
#endif

// if false, you may cannot use many functions in class TouchEvent
#ifdef    __PREDEF_ENABLE_TOUCHDATA__
  #undef  __PREDEF_ENABLE_TOUCHDATA__
  #define __PREDEF_ENABLE_TOUCHDATA__ false
#else
  #define __PREDEF_ENABLE_TOUCHDATA__ true
#endif

namespace sf {
  inline namespace ui {
  }
}
