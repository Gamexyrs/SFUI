//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  Obj::Object(const Vector2f& size, const Object& builder, const Vector2f& buildPosition, const Vector2b& buildAddSize)
    : Buildable(this) {
    this->setBuilder(builder, buildPosition, buildAddSize); this->setSize(size);
  }
  Obj::Object(const Frame& frame) : Buildable(this) {
    this->setPosition(frame.x); this->setSize(frame.y);
  }
  
  inline func Obj::getBase(void) const -> ConvexShape& {
    this->needUpdate(true);
    return this->__Base;
  }

  inline func Obj::setPosition(const Vector2f& value) const -> void {
    this->__Base.setPosition(value);
    this->needUpdate(true);
  }
  inline func Obj::getPosition(void) const _____ -> const Vector2f& {
    return this->__Base.getPosition();
  }

  inline func Obj::setSize(const Vector2f& value) const -> void {
    this->__Size = value;
    this->needUpdate(true);
  }
  inline func Obj::getSize(void) const _____ -> const Vector2f& {
    return this->__Size;
  }

  inline func Obj::setVisible(bool value) -> void {
    this->__Visible = value;
  }
  inline func Obj::getVisible(void) const -> bool {
    return this->__Visible;
  }
  
  inline func Obj::setBaseVisible(bool value) -> void {
    this->__BaseVisible = value;
  }
  inline func Obj::getBaseVisible(void) const -> bool {
    return this->__BaseVisible;
  }
  
  inline func Obj::setTag(const String& value) -> void {
    this->__Tag = value;
  }
  inline func Obj::getTag(void) const -> const String& {
    return this->__Tag;
  }
  
  inline func Obj::align(const Vector2f size, const FloatRect& rect, short align) -> const Vector2f {
    switch(align) {
      case(Align::T):
        return {Obj::align(size, rect, Align::Center).x,
                            Format::getPosition(rect).y};

      case(Align::L):
        return {            Format::getPosition(rect).x,
                Obj::align(size, rect, Align::Center).y};

      case(Align::R):
        return {       Format::getRoot(rect).x - size.x,
                Obj::align(size, rect, Align::Center).y};

      case(Align::B):
        return {Obj::align(size, rect, Align::Center).x,
                       Format::getRoot(rect).y - size.y};

      case(Align::TL):
        return Format::getPosition(rect);
        
      case(Align::TR):
        return {Format::getRoot(rect).x - size.x,
                     Format::getPosition(rect).y};

      case(Align::BL):
        return {     Format::getPosition(rect).x,
                Format::getRoot(rect).y - size.y};

      case(Align::BR):
        return (Format::getRoot(rect) - size);
        
      default: // Center
        return (Format::getPosition(rect) + (Format::getSize(rect) - size) / 2.f);
    }
  }
  inline func Obj::align(const std::optional<FloatRect>& optRect, short align) -> const Vector2f& {
    this->setPosition(this->align(this->getSize(), optRect.value_or((this->__Builder != nullptr)
      ? this->__Builder->getRect() : _RendererRect), align));
    if(this->__Builder != nullptr) {
      this->__BuildPosition = this->getPosition() - this->__Builder->getPosition();
      this->__BuildAddSize  = {};
    } this->needUpdate(true);
    return this->getPosition();
  }

  inline func Obj::move(const Vector2f& value) const -> void {
    if(this->__Builder == nullptr) {
      this->__Base.move(value);
    } else {
      this->__BuildPosition += value;
    } this->needUpdate(true);
  }

  inline func Obj::getRect(void) const -> FloatRect {
    return{this->getPosition().x, this->getPosition().y, this->getSize().x, this->getSize().y};
  }
  inline func Obj::getRoot(void) const -> Vector2f {
    return this->getPosition() + this->getSize();
  }
}
