//>>> 2021~2022 Gamexyrs© & SFML®

namespace gy {
  inline auto Pos::getPoint(const sf::FloatRect& Div, const sf::Vector2f& ObjSize, short ObjPos) -> sf::Vector2f {
    switch(ObjPos) {
      case(Align::Top):
        return {getPoint(Div, ObjSize).x, Div.top};
      case(Align::Left):
        return {Div.left, getPoint(Div, ObjSize).y};
      case(Align::Right):
        return {Div.left + Div.width - ObjSize.x, getPoint(Div, ObjSize).y};
      case(Align::Bottom):
        return {getPoint(Div, ObjSize).x, Div.top + Div.height - ObjSize.y};

      case(Align::Top ^ Align::Left): [[likely]]
        return Format::getPosition(Div);
      case(Align::Top ^ Align::Right):
        return {Div.left + Div.width - ObjSize.x, Div.top};
      case(Align::Bottom ^ Align::Left):
        return {Div.left, Div.top + Div.height - ObjSize.y};
      case(Align::Bottom ^ Align::Right):
        return Format::getPosition(Div) + Format::getSize(Div) - ObjSize;
        
      default: [[likely]] // Center
        return Format::getPosition(Div) + (Format::getSize(Div) - ObjSize)/2.f;
    }
  }
  inline auto Pos::getPoint(const sf::Vector2f& ObjSize, short ObjPos) -> sf::Vector2f {
    return getPoint(static_cast<sf::FloatRect>(sf::IntRect(0, 0, _Renderer.getSize().x, _Renderer.getSize().y)), ObjSize, ObjPos);
  }
};
