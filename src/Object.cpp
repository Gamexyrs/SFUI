//>>> 2021~2022 Gamexyrs© & SFML®

namespace gy {
  Obj::Object(const BuildFrame& Frame) : Position(Frame.x), Size(Frame.y) {}
  
  inline auto Obj::build(const sf::Vector2f& Deviat, bool Width, bool Height) const -> sf::Vector2f {
    return this->Position + Deviat + sf::Vector2f((Width ? this->Size.x : 0), (Height ? this->Size.y : 0));
  }
  
  inline auto Obj::getBoundsSize(void) const -> sf::Vector2f {
    return Format::getSize(this->Base.getGlobalBounds());
  }
  
  inline auto Obj::getRect(void) const -> sf::FloatRect {
    return{this->Position.x, this->Position.y, this->Size.x, this->Size.y};
  }
  inline auto Obj::getRoot(void) const -> sf::Vector2f {
    return this->Position + this->Size;
  }
  
  inline auto Obj::isDown(void) const -> int {
    return Touch::isDown(this->getRect());
  }
};
