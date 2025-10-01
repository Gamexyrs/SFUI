//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  ProgressSlider::ProgressSliderDiv(const Vector2f& size, const Object& builder, int radius,
                    const Vector2f& buildPosition, const Vector2b& buildAddSize)
    : ProgressDiv(size, builder, radius, buildPosition, buildAddSize) {
    this->__Inside.setFillColor(ColorEx::LightBlue);
  }
  ProgressSlider::ProgressSliderDiv(const Frame& frame, int radius)
    : ProgressDiv(frame, radius) {
    this->__Inside.setFillColor(ColorEx::LightBlue);
  }
  
  inline func ProgressSlider::draw(RenderTarget& target, const RenderStates& states) const -> void { this->__rendererCheck();
    if(this->mov.getAuto()) this->mov.next();
    if(this->requestUpdate() || (this->__Progress < 0 && this->__Busy.__Running)) this->update();
    if(this->__ATTRIBUTE__.__VISIBLE__ && (this->inView()
                                       || !(__PREDEF_ENABLE_FASTDRAW_SOV__
                                       && !this->__ATTRIBUTE__.__IGNORE_FASTDRAW_SOV__))) {
      if(this->__ATTRIBUTE__.__VISIBLE_BASE__)
        target.draw(this->__Base, states);
      if(this->__ATTRIBUTE__.__VISIBLE_INER__ && this->__Progress)
        target.draw(this->__Inside, states);
      if(this->__ATTRIBUTE__.__VISIBLE_TEX__ && this->isTexVisible())
        target.draw(this->__Tex_spr, states);
      if(this->__ATTRIBUTE__.__VISIBLE_TEXT__ && !this->__Text.getString().isEmpty())
        target.draw(this->__Text, states);
    }
  }
  
  inline func ProgressSlider::update(void) const -> void {
    this->ProgressDiv::update();
  }
  
  inline func ProgressSlider::setTouchFlowEnabled(bool value) -> void {
    this->__TouchFlowEnabled = value;
  }
  inline func ProgressSlider::getTouchFlowEnabled(void) const -> bool {
    return this->__TouchFlowEnabled;
  }

  inline func ProgressSlider::pollEvent(const Event& event) -> bool {
    static short tmp_i{}, npolled{-1};
    
    if(event.type == Event::TouchBegan && npolled == -1
    && (tmp_i = TouchEvent::isDownAt(this->getRect()))) npolled = tmp_i - 1;
    
    if((npolled > -1) && Touch::isDown(npolled)
    && (this->__TouchFlowEnabled || TouchEvent::isDownAt(this->getRect()))
    && (!Msgable::getLocked() || this->__ATTRIBUTE__.__ALWAYS_TOUCHABLE__)) {
      this->setProgress(std::fmax(std::fmin(TouchEvent::getPosition(npolled).x - this->getPosition().x, this->getSize().x), 0.0f) / this->getSize().x);
      return true;
    } else {
      npolled = -1;
      return false;
    }
  }
}
