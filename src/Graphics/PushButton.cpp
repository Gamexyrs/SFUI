//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func PushBtn::update(void) const -> void { this->TextDiv::update();
    switch(this->_State) {
      case(BtnState::Held   ): this->_Base.setFillColor(this->StateColor.Held   ); break;
      case(BtnState::Pressed): this->_Base.setFillColor(this->StateColor.Pressed); break;
    default: this->_Base.setFillColor(this->StateColor.None);
    }
  }
  
  inline func PushBtn::draw(RenderTarget& target, RenderStates states) const -> void {
    if(this->NeedUpdate) this->update(); target.draw(this->_Base, states);
    if((!this->_Text.getString().isEmpty())) {
      target.draw(this->_Text, states);
    }
  }
  
  func PushBtn::pollEvent(const Event& event) -> BtnEvent {
    if(this->_State == BtnState::Pressed && event.type == Event::TouchEnded) {
      this->setState(BtnState::None); return BtnEvent::Release;
    } else if(!this->isTouchDown()) {
      if(this->_State != BtnState::None) {
        this->setState(BtnState::None); return BtnEvent::None;
      }
    } else if(this->_State == BtnState::Pressed) {
      this->_State = BtnState::Pressed;  return BtnEvent::Press;
    } else if(event.type == Event::TouchBegan) {
      this->setState(BtnState::Pressed); return BtnEvent::Press;
    } return BtnEvent::None;
  }
  inline func PushBtn::pollEvent_if(const Event& event, BtnEvent tar) -> bool {
    return(this->pollEvent(event) == tar);
  }
  
  PushBtn::PushButton(const BuildFrame& frame, unsigned radius) : TextDiv(frame, radius) {}
};
