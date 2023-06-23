#ifndef __SFUI_INCLUDE_SYSTEM__
  #if __has_include("./System/Renderable.hpp")
    #include "./System/Renderable.hpp"
  #else
    #error "No such file: SFUI/System/Renderable.hpp"
  #endif
  
  #if __has_include("./System/RenderUnity.hpp")
    #include "./System/RenderUnity.hpp"
  #else
    #error "No such file: SFUI/System/RenderUnity.hpp"
  #endif
  
  #if __has_include("./System/Format.hpp")
    #include "./System/Format.hpp"
  #else
    #error "No such file: SFUI/System/Format.hpp"
  #endif
  
  #if __has_include("./System/Align.hpp")
    #include "./System/Align.hpp"
  #else
    #error "No such file: SFUI/System/Align.hpp"
  #endif
  
  #if __has_include("./System/Color.hpp")
    #include "./System/Color.hpp"
  #else
    #error "No such file: SFUI/System/Color.hpp"
  #endif
  
  #if __has_include("./System/Inputable.hpp")
    #include "./System/Inputable.hpp"
  #else
    #error "No such file: SFUI/System/Inputable.hpp"
  #endif
  
  #if __has_include("./System/Messagable.hpp")
    #include "./System/Messagable.hpp"
  #else
    #error "No such file: SFUI/System/Messagable.hpp"
  #endif
  
  #ifdef __PREDEF_ENABLE_TOUCHDATA__
  #if    __PREDEF_ENABLE_TOUCHDATA__
    #if __has_include("./System/SlidableView.hpp")
      #include "./System/SlidableView.hpp"
    #else
      #error "No such file: SFUI/System/SlidableView.hpp"
    #endif
  #endif
  #endif
  
  #if __has_include("./System/Geometry.hpp")
    #include "./System/Geometry.hpp"
  #else
    #error "No such file: SFUI/System/Geometry.hpp"
  #endif
  
  #if __has_include("./System/Frame.hpp")
    #include "./System/Frame.hpp"
  #else
    #error "No such file: SFUI/System/Frame.hpp"
  #endif
  
  #define __SFUI_INCLUDE_SYSTEM__ 9
#endif
