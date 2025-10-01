//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  Slider::SliderDiv(const Vector2f& size, const Object& builder, int radius,
                    const Vector2f& buildPosition, const Vector2b& buildAddSize)
    : Div(size, builder, radius, buildPosition, buildAddSize), Progressable(this) {
    this->__Inside.setBuilder(*this, Vector2f{-size.y * 1.1f, -size.y * 1.1f + size.y / 2.0f});
    this->__Inside.setFillColor(ColorEx::LightBlue);
    this->__Inside.setOutlineThickness(0);
    this->__Inside.setSize({size.y * 2.2f, size.y * 2.2f});
    this->__Inside.setRadius(-1);
    
    this->__Inside.__ATTRIBUTE__.__PROTECTED__        = true;
    this->__Inside.__ATTRIBUTE__.__IGNORE_ROTATEAGL__ = true;
    this->         __ATTRIBUTE__.__IGNORE_ROTATEAGL__ = true;
  }
  Slider::SliderDiv(const Frame& frame, int radius)
    : Div(frame, radius), Progressable(this) {
    this->__Inside.setBuilder(*this, Vector2f{-frame.size.y * 1.1f, -frame.size.y * 1.1f + frame.size.y / 2.0f});
    this->__Inside.setFillColor(ColorEx::LightBlue);
    this->__Inside.setOutlineThickness(0);
    this->__Inside.setSize({frame.size.y * 2.2f, frame.size.y * 2.2f});
    this->__Inside.setRadius(-1);
    
    this->__Inside.__ATTRIBUTE__.__PROTECTED__        = true;
    this->__Inside.__ATTRIBUTE__.__IGNORE_ROTATEAGL__ = true;
    this->         __ATTRIBUTE__.__IGNORE_ROTATEAGL__ = true;
  }
  
  inline func Slider::draw(RenderTarget& target, const RenderStates& states) const -> void { this->__rendererCheck();
    if(this->mov.getAuto()) this->mov.next();
    if(this->requestUpdate()) this->update();
    if(this->__ATTRIBUTE__.__VISIBLE__ && (this->inView()
                                       || !(__PREDEF_ENABLE_FASTDRAW_SOV__
                                       && !this->__ATTRIBUTE__.__IGNORE_FASTDRAW_SOV__))) {
      if(this->__ATTRIBUTE__.__VISIBLE_BASE__)
        target.draw(this->__Base, states);
      if(this->__ATTRIBUTE__.__VISIBLE_INER__)
        target.draw(this->__Inside, states);
    }
  }
  
  inline func Slider::update(void) const -> void {
    this->__Inside.setBuildPosition({this->getSize().x * this->getProgress() - this->__Inside.getSize().x / 2.0f, this->__Inside.getBuildPosition().y});
    this->Div::update();
  }
  
  inline func Slider::setTouchFlowEnabled(bool value) -> void {
    this->__TouchFlowEnabled = value;
  }
  inline func Slider::getTouchFlowEnabled(void) const -> bool {
    return this->__TouchFlowEnabled;
  }

  inline func Slider::getInside(bool update) const -> Div& {
    if(update) this->needUpdate();
    return const_cast<Div&>(this->__Inside);
  }
  
  inline func Slider::pollEvent(const Event& event) -> bool {
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
