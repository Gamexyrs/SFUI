#ifndef __SFUI_INCLUDE_GRAPHICS__
  #if __has_include("./Graphics/Object.hpp")
    #include "./Graphics/Object.hpp"
  #endif
  
  #if __has_include("./Graphics/Buildable.hpp")
    #include "./Graphics/Buildable.hpp"
  #endif
  
  #if __has_include("./Graphics/Textable.hpp")
    #include "./Graphics/Textable.hpp"
  #endif
  
  #if __has_include("./Graphics/Touchable.hpp")
    #include "./Graphics/Touchable.hpp"
  #endif
  
  #if __has_include("./Graphics/Divs.hpp")
    #include "./Graphics/Divs.hpp"
  #endif
 
  #if __has_include("./Graphics/Buttons.hpp")
    #include "./Graphics/Buttons.hpp"
  #endif
 
  #define __SFUI_INCLUDE_GRAPHICS__ 6
#endif
