//>>> 2021~2022 Gamexyrs© & SFML®

namespace gy {
  inline auto CButton::update(void) const -> void { this->TextDiv::update();
    if(this->State == BState::Pressed)
      this->Base.setFillColor(this->Color.Pressed);
    else if(this->Checked)
      this->Base.setFillColor(this->Color.Checked);
    else this->Base.setFillColor(this->Color.None);
  }
  
  inline auto CButton::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void {
    this->update(); target.draw(this->Base, states);
    if((!this->Text.getString().isEmpty())) [[likely]] {
      target.draw(this->Text, states);
    }
  }
  
  auto CButton::pollEvent(const sf::Event& Event) -> BState {
    this->State = this->Button::pollEvent(Event);
    if(this->State == BState::Released)
      this->Checked = (!this->Checked);
    return this->State;
  }
  inline auto CButton::pollEvent_if(const sf::Event& Event, BState Tar) -> bool {
    return(this->pollEvent(Event) == Tar);
  }
  
  CButton::CheckButton(const BuildFrame& Frame, unsigned Radius) : Button(Frame, Radius) {}
};
