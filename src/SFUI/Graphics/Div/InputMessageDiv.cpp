//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  InputMsgDiv::InputMessageDiv(unsigned radius, const Vector2f& sizeFactor, const Align& align)
    : MsgDiv(radius, sizeFactor, align) {
    this->__Input.setBuilder(*this);
    this->__Input.setPerHeight("40%");
    this->__Input.setPerWidth ("90%");
    this->__Input.align();
    this->__Input.__ATTRIBUTE__.__PROTECTED__        = true;
    this->__Input.__ATTRIBUTE__.__ALWAYS_TOUCHABLE__ = true;
  }
  
  inline func InputMsgDiv::draw(RenderTarget& target, const RenderStates& states) const -> void { this->__rendererCheck();
    if(this->requestUpdate()) this->update();
    if(this->mov.getAuto()) this->mov.next();
    if(this->__ATTRIBUTE__.__VISIBLE__ && (this->inView()
                                       || !(__PREDEF_ENABLE_FASTDRAW_SOV__
                                       && !this->__ATTRIBUTE__.__IGNORE_FASTDRAW_SOV__))) {
      if(this->__ATTRIBUTE__.__VISIBLE_MASK__) {
        if(!this->__Pushing) {
          if(this->__Mask.getBase().getFillColor().a > 0) {
           const_cast<Color&>(this->__Mask.getBase().getFillColor()).a -= 10;
          }
        }
        else if(this->__Mask.getBase().getFillColor().a < this->__MaskTrs) {
          const_cast<Color&>(this->__Mask.getBase().getFillColor()).a += 10;
        } target.draw(this->__Mask, states);
      }
      if(this->__Pushing) {
        if(this->__ATTRIBUTE__.__VISIBLE_BASE__)
          target.draw(this->__Base, states);
        if(this->__ATTRIBUTE__.__VISIBLE_TEXT__ && !this->__Text.getString().isEmpty()) {
          target.draw(this->__Info, states);
          target.draw(this->__Text, states);
        }
        if(this->__ATTRIBUTE__.__VISIBLE_INER__)
          target.draw(this->__Input, states);
        for(auto& i : this->__Btn) {
          target.draw(*i);
        }
      }
    }
  }
  inline func InputMsgDiv::update(void) const -> void { this->MsgDiv::update();
  }
  
  inline func InputMsgDiv::getInput(bool update) const -> InputDiv& {
    if(update) this->needUpdate();
    return const_cast<InputDiv&>(this->__Input);
  }
  
  inline func InputMsgDiv::pollEvent(const Event& event) -> std::optional<int> {
    if(this->__Pushing) {
      this->__Input.pollEvent(event);
      for(auto& i : this->__Btn) {
        if(i->pollEvent_if(event))
          return std::stoi(i->getTag());
      }
    }     return std::nullopt;
  }

  inline func InputMsgDiv::getInputString(void) -> const String& {
    return this->__Input.getTextString();
  }
  
  inline func InputMsgDiv::pushQueue(void) -> void {
    this->__Input.setTextString("");
    this->MsgDiv::pushQueue();
  }
  
}
