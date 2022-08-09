//>>> 2021~2022 Gamexyrs© & SFML®

namespace gy {
  inline auto Button::update(void) const -> void { this->TextDiv::update();
    if(this->State == BState::Pressed)
      this->Base.setFillColor(this->Color.Pressed);
    else this->Base.setFillColor(this->Color.None);
  }
  
  inline auto Button::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void {
    this->update(); target.draw(this->Base, states);
    if((!this->Text.getString().isEmpty())) [[likely]] {
      target.draw(this->Text, states);
    }
  }
  
  auto Button::pollEvent(const sf::Event& Event) -> BState {
         if(this->State == BState::Pressed && Event.type == sf::Event::TouchEnded) this->State = BState::Released;
    else if(!this->isDown()) this->State = BState::None;
    else if(this->State == BState::Pressed || Event.type == sf::Event::TouchBegan) this->State = BState::Pressed;
    else    this->State = BState::None;
    return  this->State;
  }
  inline auto Button::pollEvent_if(const sf::Event& Event, BState Tar) -> bool {
    return(this->pollEvent(Event) == Tar);
  }
  
  Button::PushButton(const BuildFrame& Frame, unsigned Radius) : TDiv(Frame, Radius) {}
};
