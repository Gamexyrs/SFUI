//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#ifndef GGEL_PUSHER_BUBBLE
  #define GGEL_PUSHER_BUBBLE true
#endif
#if (GGEL_PUSHER_BUBBLE == true)
  #include "./Pusher/Bubble.hpp"
#endif

namespace gy {
  typedef enum PushMethod {
    Bubble = 0,
    
    _Total_,
  }Pusher;
};
