//>>> 2021~2022 Gamexyrs© & SFML®

namespace gy {
  std::queue<sf::Text> PushService::PushList[Total] = {};
  sf::Time PushService::RepeatInterval = sf::seconds(1);

  auto PushService::push(const sf::Text& Msg, Pusher _Pusher) -> unsigned {
           PushService::PushList[_Pusher].push(Msg);
    return PushService::PushList[_Pusher].size() - 1;
  }
  auto PushService::query(const sf::String& MsgStr, Pusher _Pusher) -> unsigned {
  }
  auto PushService::preve(const sf::String& MsgStr, Pusher _Pusher) -> unsigned {
  }
};
