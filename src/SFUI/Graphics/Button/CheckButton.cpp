//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  CheckBtn::CheckButton(const Vector2f& size, const Object& builder, int radius,
                        const Vector2f& buildPosition, const Vector2b& buildAddSize)
    : AbsBtn(this), TexDiv(size, builder, radius, buildPosition, buildAddSize), Touchable(this) {}
  CheckBtn::CheckButton(const Frame& frame, int radius)
    : AbsBtn(this), TexDiv(frame, radius), Touchable(this) {}
  
  inline func CheckBtn::draw(RenderTarget& target, const RenderStates& states) const -> void { this->__rendererCheck();
    if(this->mov.getAuto()) this->mov.next();
    if(this->requestUpdate()) this->update();
    if(this->__ATTRIBUTE__.__VISIBLE__ && (this->inView()
                                       || !(__PREDEF_ENABLE_FASTDRAW_SOV__
                                       && !this->__ATTRIBUTE__.__IGNORE_FASTDRAW_SOV__))) {
      if(this->__ATTRIBUTE__.__VISIBLE_BASE__)
        target.draw(this->__Base, states);
      if(this->__ATTRIBUTE__.__VISIBLE_TEX__ && this->isTexVisible())
        target.draw(this->__Tex_spr, states);
      if(this->__ATTRIBUTE__.__VISIBLE_TEXT__ && !this->__Text.getString().isEmpty())
        target.draw(this->__Text, states);
    }
  }
  
  inline func CheckBtn::update(void) const -> void { this->TexDiv::update();
    if(this->getChecked())
         this->Obj::setFillColor(this->__StateColor.__Checked);
    else this->Obj::setFillColor(this->__StateColor.__None);
  }

  inline func CheckBtn::pollEvent(const Event& event) -> bool {
    if(this->__isPressed && event.type == Event::TouchEnded) {
      if(!this->__cancelable && this->getChecked()) {
        this->__reclick = true; return true;
      } this->__reclick = false; this->setChecked(!this->getChecked()); return true;
    } else if(!this->isTouchDown()) {
      this->__isPressed = false;
    } else if(this->__isPressed) {
    } else if(event.type == Event::TouchBegan) {
      this->__isPressed = true;
    } return false;
  }
  
  inline func CheckBtn::setFillColor(const Color& value) const -> void {
    this->setStateColor(value, std::nullopt);
  }
  
  inline func CheckBtn::setChecked(bool value) -> void {
    this->__State = (value ? BtnState::Checked : BtnState::None);
    this->needUpdate();
  }
  inline func CheckBtn::getChecked(void) const -> bool {
    return (this->__State == BtnState::Checked);
  }
  
  inline func CheckBtn::setCancelable(bool value) -> void {
    this->__cancelable = value;
  }
  inline func CheckBtn::getCancelable(void) const -> bool {
    return this->__cancelable;
  }
  
  inline func CheckBtn::clrReclick(void) -> void {
    this->__reclick = false;
  }
  inline func CheckBtn::getReclick(void) const -> bool {
    return this->__reclick;
  }
  
  inline func CheckBtnFat::build(CheckBtn* _ori, std::initializer_list<CheckBtn*>&& _tar,
      Vector2f distance, Vector2b direct) -> void {
    for(auto i = _tar.begin(); i != _tar.end(); ++i) {
      (*i)->getText().setOutlineThickness(_ori->getText(false).getOutlineThickness());
      (*i)->getText().setCharacterSize   (_ori->getText(false).getCharacterSize());
      (*i)->getText().setLetterSpacing   (_ori->getText(false).getLetterSpacing());
      (*i)->getText().setOutlineColor    (_ori->getText(false).getOutlineColor());
      (*i)->getText().setLineSpacing     (_ori->getText(false).getLineSpacing());
      (*i)->getText().setRotation        (_ori->getText(false).getRotation());
      (*i)->getText().setOrigin          (_ori->getText(false).getOrigin());
      (*i)->getText().setScale           (_ori->getText(false).getScale());
      (*i)->getText().setStyle           (_ori->getText(false).getStyle());
      
      (*i)->setTextString(_ori->getTextString());
      (*i)->setTextDeviat(_ori->getTextDeviat());
      (*i)->setTextColor (_ori->getTextColor());
      (*i)->setTextAdapt (_ori->getTextAdapt());
      (*i)->setTextAlign (_ori->getTextAlign());
      (*i)->setFont     (*_ori->getFont());
      
      (*i)->getBase().setOutlineThickness(_ori->getBase(false).getOutlineThickness());
      (*i)->getBase().setOutlineColor    (_ori->getBase(false).getOutlineColor());
      (*i)->getBase().setTextureRect     (_ori->getBase(false).getTextureRect());
      (*i)->getBase().setFillColor       (_ori->getBase(false).getFillColor());
      (*i)->getBase().setRotation        (_ori->getBase(false).getRotation());
      (*i)->getBase().setTexture         (_ori->getBase(false).getTexture());
      (*i)->getBase().setScale           (_ori->getBase(false).getScale());
      
      (*i)->setRounded_List(_ori->getRounded_List());
      (*i)->__ATTRIBUTE__ = _ori->__ATTRIBUTE__;
      (*i)->setAlignLock(_ori->getAlignLock());
      (*i)->setRadius   (_ori->getRadius());
      (*i)->setFrame    (_ori->getFrame());
      
      (*i)->setStateColor(_ori->getStateColor(BtnState::Checked), BtnState::Checked);
      (*i)->setStateColor(_ori->getStateColor(BtnState::Pressed), BtnState::Pressed);
      (*i)->setStateColor(_ori->getStateColor(BtnState::None),    BtnState::None);
      
      (*i)->setBuilder((i == _tar.begin()) ? *_ori : **(i - 1), distance, direct);
    }
  }
}
