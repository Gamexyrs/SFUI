//>>> 2021~2022 Gamexyrs© & SFML®

// pre-def

// if false, your application's FPS may be low or float with each class Object
#ifdef        __PREDEF_ENABLE_FASTDRAW__
    #if      !__PREDEF_ENABLE_FASTDRAW__
      #define __PREDEF_ENABLE_FASTDRAW_SOV__ false
    #endif
#endif

#ifndef   __PREDEF_ENABLE_FASTDRAW_SOV__
  #define __PREDEF_ENABLE_FASTDRAW_SOV__ true
#endif

// if false, you may cannot use unity draw in class Renderable
/* [[unused]] */
#ifndef   __PREDEF_ENABLE_UNITYDRAW__
  #define __PREDEF_ENABLE_UNITYDRAW__ false
#endif

// if false, you may cannot use touchMove and touchTime in class TouchEvent
#ifndef   __PREDEF_ENABLE_TOUCHDATA__
  #define __PREDEF_ENABLE_TOUCHDATA__ true
#endif

// if false, you may cannot use many functions about buffer about class KeyboardEvent such as InputDiv
#ifndef   __PREDEF_ENABLE_KB_BUFFER__
  #define __PREDEF_ENABLE_KB_BUFFER__ true
#endif

// if false, you need to use sf::ui::<sfui_type>:: instead of sf::<sfui_type> [ sfui_type | class ]
#ifndef   __PREDEF_INLINE_NAMESPACE__
  #define __PREDEF_INLINE_NAMESPACE__ true
#endif

namespace sf {
#if __PREDEF_INLINE_NAMESPACE__
  inline
#endif
  namespace ui {
    const std::vector<const unsigned> SFUIVersion{
      __SFUI_VERSION_MAJOR__,
      __SFUI_VERSION_MINOR__,
      __SFUI_VERSION_PATCH__,
    };
    
    namespace geometry {
    
    } // internal
  }
}
