#ifndef __SFUI_INCLUDE_BUTTON__
  #if __has_include("./Button/AbstractButton.hpp")
    #include "./Button/AbstractButton.hpp"
  #endif
  
  #if __has_include("./Button/PushButton.hpp")
    #include "./Button/PushButton.hpp"
  #endif
  
  #if __has_include("./Button/CheckButton.hpp")
    #include "./Button/CheckButton.hpp"
  #endif
  
  #define __SFUI_INCLUDE_BUTTON__ 3
#endif
