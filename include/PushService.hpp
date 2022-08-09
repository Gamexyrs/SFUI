//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include <queue>
#include "Pusher.hpp"

namespace gy {
  typedef enum PushMethod {
    Bubble = 0,
    
    _Total_,
  }Pusher;

  typedef class PushService {
    friend PSV_Bubble;
  
  protected: PushService(void) = default;
    virtual ~PushService(void) = default;
    
    static std::queue<sf::Text> PushList[_Total_];
    
  _data_public:
    static sf::Time RepeatInterval; /* = 1s */

  _func_public:
    static auto push (const sf::Text&   Msg,    Pusher _Pusher) -> unsigned;
    static auto query(const sf::String& MsgStr, Pusher _Pusher) -> unsigned;
    static auto preve(const sf::String& MsgStr, Pusher _Pusher) -> unsigned;
    
  }PushService;
};

#include "../src/PushService.cpp"
