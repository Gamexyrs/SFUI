//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func getPosition(const FloatRect& div, const Vector2f& objSize, short objPos) -> Vector2f {
    switch(objPos) {
      case(Align::Top):
        return {getPosition(div, objSize).x, div.top};
      case(Align::Left):
        return {div.left, getPosition(div, objSize).y};
      case(Align::Right):
        return {div.left + div.width - objSize.x, getPosition(div, objSize).y};
      case(Align::Bottom):
        return {getPosition(div, objSize).x, div.top + div.height - objSize.y};

      case(Align::Top ^ Align::Left):
        return Format::getPosition(div);
      case(Align::Top ^ Align::Right):
        return {div.left + div.width - objSize.x, div.top};
      case(Align::Bottom ^ Align::Left):
        return {div.left, div.top + div.height - objSize.y};
      case(Align::Bottom ^ Align::Right):
        return Format::getPosition(div) + Format::getSize(div) - objSize;
        
      default: // Center
        return Format::getPosition(div) + (Format::getSize(div) - objSize)/2.f;
    }
  }
  inline func getPosition(const Vector2f& objSize, short objPos) -> Vector2f {
    return getPosition(_RendererRect, objSize, objPos);
  }
};
