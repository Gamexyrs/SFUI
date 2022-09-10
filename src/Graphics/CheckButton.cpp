//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func CheckBtn::update(void) const -> void { this->TextDiv::update();
    if(this->Checked) this->_Base.setFillColor(this->StateColor.Checked);
    else switch(this->_State) {
      case(BtnState::Pressed): this->_Base.setFillColor(this->StateColor.Pressed); break;
    default: this->_Base.setFillColor(this->StateColor.None);
    }
  }
  
  inline func CheckBtn::draw(RenderTarget& target, RenderStates states) const -> void {
    if(this->NeedUpdate) this->update(); target.draw(this->_Base, states);
    if((!this->_Text.getString().isEmpty())) {
      target.draw(this->_Text, states);
    }
  }
  
  func CheckBtn::pollEvent(const Event& event) -> BtnEvent {
    if(this->_State == BtnState::Pressed && event.type == Event::TouchEnded) {
      this->Checked = (!this->Checked); this->setState(BtnState::None); return BtnEvent::Release;
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
  inline func CheckBtn::pollEvent_if(const Event& event, BtnEvent tar) -> bool {
    return(this->pollEvent(event) == tar);
  }
  
  CheckBtn::CheckButton(const BuildFrame& frame, unsigned radius) : PushBtn(frame, radius) {
    this->StateColor.Pressed = Color::Transparent;
  }
};
