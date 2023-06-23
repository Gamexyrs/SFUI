//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func Touchable::setTouchEnable(bool value) -> void {
    this->__TouchEnable = value;
  }
  inline func Touchable::getTouchEnable(void) const -> bool {
    return this->__TouchEnable;
  }
  
  inline func Touchable::setTouchRectScale(const Vector2f& value) -> void {
    this->__TouchRectScale = {std::fabs(value.x),
                              std::fabs(value.y)};
  }
  inline func Touchable::getTouchRectScale(void) const -> const Vector2f& {
    return this->__TouchRectScale;
  }
  
  inline func Touchable::isTouchDown(void) -> unsigned {
    unsigned tmp_r = 0;
    if(this->__TouchEnable && (!Msgable::getLocked() || this->__Self->__ATTRIBUTE__.__ALWAYS_TOUCHABLE__)) {
      Vector2f tmp_cent  =  this->__Self->getCenter(),
               tmp_size  =  this->__Self->getSize();
      this->__Self->setSize(this->__Self->getSize() * this->__TouchRectScale);
      this->__Self->setCenter(tmp_cent);
      tmp_r = TouchEvent::isDownAt((!this->__Self->getBase(false).getRotation()) ? this->__Self->getRect()
                                   : this->__Self->getBase(false).getGlobalBounds());
      this->__Self->setSize  (tmp_size);
      this->__Self->setCenter(tmp_cent);
    } return tmp_r;
  }
}
