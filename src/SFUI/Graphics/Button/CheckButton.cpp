//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  CheckBtn::CheckButton(const Vector2f& size, const Object& builder, unsigned radius,
                        const Vector2f& buildPosition, const Vector2b& buildAddSize)
    : AbsBtn(this), TextDiv(size, builder, radius, buildPosition, buildAddSize), Touchable(this) {}
  CheckBtn::CheckButton(const Frame& frame, unsigned radius)
    : AbsBtn(this), TextDiv(frame, radius), Touchable(this) {}
  
  inline func CheckBtn::draw(RenderTarget& target, const RenderStates& states) const -> void { this->__rendererCheck();
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
  
  inline func CheckBtn::update(void) const -> void { this->TextDiv::update();
    if(this->getChecked())
         this->__Base.setFillColor(this->__StateColor.__Checked);
    else this->__Base.setFillColor(this->__StateColor.__None);
  }

  inline func CheckBtn::pollEvent(const Event& event) -> bool {
    if(this->__isPressed && event.type == Event::TouchEnded) {
      this->setChecked(!this->getChecked()); return true;
    } else if(!this->isTouchDown()) {
      this->__isPressed = false;
    } else if(this->__isPressed) {
    } else if(event.type == Event::TouchBegan) {
      this->__isPressed = true;
    } return false;
  }
  
  inline func CheckBtn::setChecked(bool value) -> void {
    this->__State = (value ? BtnState::Checked : BtnState::None);
    this->needUpdate();
  }
  inline func CheckBtn::getChecked(void) const -> bool {
    return (this->__State == BtnState::Checked);
  }
}
