//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  InputDiv::InputDiv(const Vector2f& size, const Object& builder, int radius,
                     const Vector2f& buildPosition, const Vector2b& buildAddSize)
    : CheckBtn(size, builder, radius, buildPosition, buildAddSize) {
    this->__Enable_AutoLineBreak = true;
    this->__StateColor.__Checked = Color::White;
    this->__Flasher.setOutlineThickness(0);
    this->__Flasher.setFillColor(Color::Black);
  }
  InputDiv::InputDiv(const Frame& frame, int radius)
    : CheckBtn(frame, radius) {
    this->__Enable_AutoLineBreak = true;
    this->__StateColor.__Checked = Color::White;
    this->__Flasher.setOutlineThickness(0);
    this->__Flasher.setFillColor(Color::Black);
  }
  
  inline func InputDiv::draw(RenderTarget& target, const RenderStates& states) const -> void { this->__rendererCheck();
    if(this->mov.getAuto()) this->mov.next();
    if(this->requestUpdate() || this->getChecked()) this->update();
    if(this->__ATTRIBUTE__.__VISIBLE__ && (this->inView()
                                       || !(__PREDEF_ENABLE_FASTDRAW_SOV__
                                       && !this->__ATTRIBUTE__.__IGNORE_FASTDRAW_SOV__))) {
      if(this->__ATTRIBUTE__.__VISIBLE_BASE__)
        target.draw(this->__Base, states);
      if(this->__ATTRIBUTE__.__VISIBLE_TEXT__ && !this->__Text.getString().isEmpty())
        target.draw(this->__Text, states);
      if(this->__ATTRIBUTE__.__VISIBLE_INER__ &&  this->getChecked())
        target.draw(this->__Flasher, states);
    }
  }
  
  inline func InputDiv::update(void) const -> void {
    bool __had_update{false};
    
    if(this->getChecked()) {
      if(this->getTextString() != KbEvent::getBufString(false) || this->__NeedUpdate) {
         this->setTextString(     KbEvent::getBufString(false));
         this->CheckBtn::update(); __had_update = true;
         
         this->__Flasher.setSize({1, static_cast<float>(this->__Text.getCharacterSize())});
         if(this->getTextString().isEmpty())
              this->__Flasher.setPosition(::sf::ui::align(this->__Flasher.getSize(), this->getRect(), this->getTextAlign()));
         else this->__Flasher.setPosition(this->getNextPosition());
      }
      
      if(this->__FlashClock.getElapsedTime().asSeconds()
                       >= this->__FlashItval.asSeconds()) {
           this->__Flasher.__ATTRIBUTE__.__VISIBLE_BASE__
        = !this->__Flasher.__ATTRIBUTE__.__VISIBLE_BASE__;
           this->__FlashClock.restart();
      }
    }
    if(!__had_update) this->CheckBtn::update();
  }
  
  inline func InputDiv::getFlasher(bool update) const -> Div& {
    if(update) this->needUpdate();
    return this->__Flasher;
  }
  
  inline func InputDiv::setFlashInterval(const Time& value) -> void {
    this->__FlashItval = value;
  }
  inline func InputDiv::getFlashInterval(void) const -> const Time& {
    return this->__FlashItval;
  }

  inline func InputDiv::pollEvent(const Event& event) -> bool {
    bool __tmp_cek = this->getChecked();
    if(this->CheckBtn::pollEvent(event)) {
       this->setChecked(true);
      if(!__tmp_cek) {
        KbEvent::setBufString(this->getTextString());
        this->__Flasher.align(this->getTextAlign());
        this->__Flasher.__ATTRIBUTE__.__VISIBLE_BASE__ = true;
        this->__FlashClock.restart();
      } return true;
    } else if(((__tmp_cek && Touch::isDown(0) && !this->isTouchDown()) && !Msgable::getLocked())
      || KbEvent::isDown(event, 10)) {
      this->setChecked(false); KbEvent::setBufString();
    } return false;
  }
  
  inline func InputDiv::setKeyboardMethod(std::pair<std::function<void(void)>, std::function<void(void)>> __f_calls) -> void {
    this->__KeyboardCallMethod = __f_calls.first;
    this->__KeyboardCallbackMethod = __f_calls.second;
  }
  
  inline func InputDiv::setChecked(bool value) -> void {
    if(value) this->__KeyboardCallMethod();
         else this->__KeyboardCallbackMethod();
    this->CheckBtn::setChecked(value);
  }
  inline func InputDiv::getChecked(void) const -> bool {
    return this->CheckBtn::getChecked();
  }
}
