//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  TextDiv::TextDiv(const Vector2f& size, const Object& builder, unsigned radius,
                   const Vector2f& buildPosition, const Vector2b& buildAddSize)
    : Div(size, builder, radius, buildPosition, buildAddSize), Textable(this) {
    this->__Text.setFillColor(Color::Black);
  }
  TextDiv::TextDiv(const Frame& frame, unsigned radius)
    : Div(frame, radius), Textable(this) {
    this->__Text.setFillColor(Color::Black);
  }
  
  inline func TextDiv::draw(RenderTarget& target, RenderStates states) const -> void { this->__rendererCheck();
    String tmp_originStr = this->__Text.getString(); 
    if(this->__NeedUpdate) {
      this->update();
    }
    if(this->__Visible) {
      if(this->__BaseVisible) {
        target.draw(this->__Base, states);
      }
      if(this->__TextVisible && !this->__Text.getString().isEmpty()) {
        target.draw(this->__Text, states);
        if(this->__Enable_AutoLineBreak) {
          this->__Text.setString(tmp_originStr); // 保护原文本字符串
        }
      }
    }
  }
  
  inline func TextDiv::update(void) const -> void { this->Div::update();
    if(!this->__Text.getString().isEmpty()) {
      this->__Text.setPosition(ui::align(this->getTextSize(true), this->getRect(), this->__TextAlign));
      if(this->__Border.__Radius) {
        switch(this->__TextAlign) {
        case(Align::TL): case(Align::BL):
          this->__Text.move(      this->__Border.__Radius,  0); break;
        case(Align::TR): case(Align::BR):
          this->__Text.move(-fabs(this->__Border.__Radius), 0); break;
        default: break;
        }
      } this->__Text.move(this->__TextDeviat);
      if(this->__Enable_AutoLineBreak) {
        this->__Text.setString(this->lineBreak());
      }
    }
  }
  
  inline func TextDiv::setTextVisible(bool value) -> void {
    this->__TextVisible = value;
  }
  inline func TextDiv::getTextVisible(void) const -> bool {
    return this->__TextVisible;
  }
  
  inline func TextDiv::setAutoLineBreakEnable(bool value) -> void {
    this->__Enable_AutoLineBreak = value;
    this->needUpdate();
  }
  inline func TextDiv::getAutoLineBreakEnable(void) const -> bool {
    return this->__Enable_AutoLineBreak;
  }
  
  inline func TextDiv::resize(void) -> void {
    this->setSize(this->getTextSize(true));
    this->needUpdate(true);
  }
}
