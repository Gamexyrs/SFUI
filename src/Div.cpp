//>>> 2021~2022 Gamexyrs© & SFML®

namespace gy {
  auto Div::update(void) const -> void {
    this->Base.setPosition(this->Position);
    if(!this->Border.Radius) [[unlikely]] {
      this->Base.setPointCount(4);
      this->Base.setPoint(0, {});
      this->Base.setPoint(2, this->Size);
      this->Base.setPoint(1, {this->Size.x, 0});
      this->Base.setPoint(3, {0, this->Size.y});
    } else {
      this->Base.setPointCount((this->Border.PointCount < 4) ? 80 : this->Border.PointCount);
      if(this->Border.Radius > this->Size.y/2.f) this->Border.Radius = this->Size.y/2;
      if(this->Border.Radius > this->Size.x/2.f) this->Border.Radius = this->Size.x/2;
      for(int i = 0; i < this->Base.getPointCount(); ++i) {
        double angle = i * 6.283185308f / this->Base.getPointCount() - 1.570796327f;
        this->Base.setPoint(i,      sf::Vector2f(((i < this->Base.getPointCount()*0.50) ?
          (this->Size.x - this->Border.Radius*2) : 0) + (this->Border.Radius * (std::cos(angle) + 1)),
          ((i > this->Base.getPointCount()*0.25 && i < this->Base.getPointCount()*0.75) ?
          (this->Size.y - this->Border.Radius*2) : 0) + (this->Border.Radius * (std::sin(angle) + 1))));
      }
    }
  }
  
  inline auto Div::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void {
    this->update(); target.draw(this->Base, states);
  }
  
  Div::Div(const BuildFrame& Frame, unsigned Radius) : Obj(Frame) {
    this->Base.setFillColor(sf::Color::Transparent);
    this->Base.setOutlineColor(sf::Color::Black);
    this->Base.setOutlineThickness(1);
    this->Border.Radius = Radius;
  }
};
