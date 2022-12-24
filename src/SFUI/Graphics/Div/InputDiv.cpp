//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  InputDiv::InputDiv(const Vector2f& size, const Object& builder, unsigned radius,
                     const Vector2f& buildPosition, const Vector2b& buildAddSize)
    : CheckBtn(size, builder, radius, buildPosition, buildAddSize) {
    this->__StateColor.__Checked = ColorEx::makeTrs(Color::Blue);
  }
  InputDiv::InputDiv(const Frame& frame, unsigned radius)
    : CheckBtn(frame, radius) {
    this->__StateColor.__Checked = ColorEx::makeTrs(Color::Blue);
  }
    
  inline func InputDiv::draw(RenderTarget& target, RenderStates states) const -> void;
  inline func InputDiv::update(void) const -> void;
    
  inline func InputDiv::pollEvent(const Event& event) -> bool {
    if(this->__isPressed && event.type == Event::TouchEnded) {
      if(!this->__getChecked()) {
        this->__InputtingDiv = this;
        this->setChecked(true);
      } return true;
    } else if(Touch::isDown()) {
      if(!this->isTouchDown()) {
        this->setChecked(false);
      } else {
        if(event.type == Event::TouchBegan) {
          this->__isPressed = true;
        }
      }
    } return false;
    /*
    if( this->CheckBtn::pollEvent(event)) {
      if(this->getChecked()) {
        if(this->__InputtingDiv != nullptr) {
           this->__InputtingDiv  = nullptr;
        }
        this->__InputtingDiv = this;
      }
    }
    */
  }
}
