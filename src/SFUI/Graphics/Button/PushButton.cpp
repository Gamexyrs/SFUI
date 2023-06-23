//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  PushBtn::PushButton(const Vector2f& size, const Object& builder, unsigned radius,
                      const Vector2f& buildPosition, const Vector2b& buildAddSize)
    : AbsBtn(this), TextDiv(size, builder, radius, buildPosition, buildAddSize), Touchable(this) {}
  PushBtn::PushButton(const Frame& frame, unsigned radius)
    : AbsBtn(this), TextDiv(frame, radius), Touchable(this) {}
  
  inline func PushBtn::draw(RenderTarget& target, const RenderStates& states) const -> void { this->__rendererCheck();
    if(this->requestUpdate()) this->update();
    if(this->__ATTRIBUTE__.__VISIBLE__ && (this->inView()
                                       || !(__PREDEF_ENABLE_FASTDRAW_SOV__
                                       && !this->__ATTRIBUTE__.__IGNORE_FASTDRAW_SOV__))) {
      if(this->__ATTRIBUTE__.__VISIBLE_BASE__)
        target.draw(this->__Base, states);
      if(this->__ATTRIBUTE__.__VISIBLE_TEXT__ && !this->__Text.getString().isEmpty())
        target.draw(this->__Text, states);
    }
  }
  
  inline func PushBtn::update(void) const -> void { this->TextDiv::update();
    switch(this->__State) {
      case(BtnState::Pressed):
        this->__Base.setFillColor(this->__StateColor.__Pressed); break;
      default:
        this->__Base.setFillColor(this->__StateColor.__None);
    }
  }

  inline func PushBtn::pollEvent_if(const Event& event, const BtnEvent& target) -> bool {
    return(this->pollEvent(event) == target);
  }
  inline func PushBtn::pollEvent(const Event& event) -> BtnEvent {
    if(this->__State == BtnState::Pressed && event.type == Event::TouchEnded) {
      this->setState(BtnState::None); return BtnEvent::Release;
    } else if(!this->isTouchDown()) {
      if(this->__State != BtnState::None) {
        this->setState(BtnState::None);
      }
    } else if(this->__State == BtnState::Pressed) {
      this->__State = BtnState::Pressed; return BtnEvent::Press;
    } else if(event.type == Event::TouchBegan) {
      this->setState(BtnState::Pressed); return BtnEvent::Press;
    } return BtnEvent::None;
  }
}
