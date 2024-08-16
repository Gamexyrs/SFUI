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
  
  inline func TextDiv::draw(RenderTarget& target, const RenderStates& states) const -> void { this->__rendererCheck();
    if(this->requestUpdate()) this->update();
    if(this->mov.getAuto()) this->mov.next();
    if(this->__ATTRIBUTE__.__VISIBLE__ && (this->inView()
                                       || !(__PREDEF_ENABLE_FASTDRAW_SOV__
                                       && !this->__ATTRIBUTE__.__IGNORE_FASTDRAW_SOV__))) {
      if(this->__ATTRIBUTE__.__VISIBLE_BASE__)
        target.draw(this->__Base, states);
      if(this->__ATTRIBUTE__.__VISIBLE_TEXT__ && !this->__Text.getString().isEmpty())
        target.draw(this->__Text, states);
    }
  }
  
  inline func TextDiv::update_text(void) const -> void {
    if(this->getFont() == nullptr && this->__DefaultFont != nullptr)
       this->__Text.setFont(*this->__DefaultFont);
    if(!this->__Text.getString().isEmpty()) {
      this->__Text.setRotation(this->__ATTRIBUTE__.__IGNORE_ROTATEAGL__ ? 0 : this->__Base.getRotation());
      this->__Text.setPosition(::sf::ui::align(this->getTextSize(true), this->getRect(), this->__TextAlign));
      if(this->__Border.__Radius) {
        switch(this->__TextAlign) {
        case(Align::TL): case(Align::BL): case(Align::L):
          this->__Text.move({static_cast<float>(      this->__Border.__Radius),  0}); break;
        case(Align::TR): case(Align::BR):
          this->__Text.move({static_cast<float>(-fabs(this->__Border.__Radius)), 0}); break;
        default: break;
        }
      } this->__Text.move(this->__TextDeviat);
    }
  }
  
  inline func TextDiv::update(void) const -> void {
    this->Div::update();
    this->update_text();
  }
  
  inline func TextDiv::resize(void) -> void {
    this->setSize(this->getTextSize());
    this->needUpdate();
  }
  
  inline func TextDiv::inView(void) const -> bool {
    return (this->getRect()                + FloatRect{{}, {1, 1}}).intersects(this->getViewRect())
        || (this->__Text.getGlobalBounds() + FloatRect{{}, {1, 1}}).intersects(this->getViewRect())
        ||  this->__ATTRIBUTE__.__IGNORE_FASTDRAW_SOV__;
  }
}
