//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  Obj::Object(const Vector2f& size, const Object& builder, const Vector2f& buildPosition, const Vector2b& buildAddSize)
    : Buildable(this), Movable(this) {
    this->setBuilder(const_cast<Object&>(builder), buildPosition, buildAddSize); this->setSize(size);
  }
  Obj::Object(const Frame& frame)
    : Buildable(this), Movable(this) {
    this->setPosition(frame.pos); this->setSize(frame.size);
  }
  
  inline func Obj::getBase(bool update) const -> ConvexShape& {
    if(update) this->needUpdate();
    return this->__Base;
  }

  inline func Obj::setOutlineThickness(float value) const -> void {
    this->__Base.setOutlineThickness(value);
    this->needUpdate();
  }
  inline func Obj::getOutlineThickness(void) const -> float {
    return this->__Base.getOutlineThickness();
  }
    
  inline func Obj::setOutlineColor(const Color& value) const -> void {
    this->__Base.setOutlineColor(value);
    this->needUpdate();
  }
  inline func Obj::getOutlineColor(void) const -> const Color& {
    return this->__Base.getOutlineColor();
  }
    
  inline func Obj::setFillColor(const Color& value) const -> void {
    this->__Base.setFillColor(value);
    this->needUpdate();
  }
  inline func Obj::getFillColor(void) const -> const Color& {
    return this->__Base.getFillColor();
  }

  inline func Obj::setPosition(const Vector2f& value) const -> void {
    this->__Base.setPosition(value);
    this->needUpdate();
  }
  inline func Obj::getPosition(void) const -> const Vector2f& {
    return this->__Base.getPosition();
  }

  inline func Obj::setSize(const Vector2f& value) const -> void {
    this->__Size = value;
    this->needUpdate();
  }
  inline func Obj::getSize(void) const -> const Vector2f& {
    return this->__Size;
  }

  inline func Obj::setAlignLock(const std::optional<Align>& value) -> void {
    this->__AlignLock = value;
    this->needUpdate();
  }
  inline func Obj::getAlignLock(void) const -> const std::optional<Align>& {
    return this->__AlignLock;
  }

  inline func Obj::align(short align, const std::optional<FloatRect>& optRect) const -> Vector2f& {
    this->setPosition(::sf::ui::align(this->getSize(), optRect.value_or((this->__Builder != nullptr)
      ? this->__Builder->getRect() : this->getViewRect()), align)); this->needUpdate();
    if(this->__Builder != nullptr) {
      this->__BuildPosition = this->getPosition() - this->__Builder->getPosition();
      this->__BuildAddSize  = {};
      return const_cast<Vector2f&>(this->getBuildPosition());
    } else return const_cast<Vector2f&>(this->getPosition());
  }

  inline func Obj::move(const Vector2f& value) const -> void {
    if(this->__Builder != nullptr) {
       this->__BuildPosition += value;
    }  this->__Base.move(value);
    this->needUpdate();
  }
  inline func Obj::zoom(const Vector2f& value) const -> void {
    const Vector2f& __ct_pos{this->getCenter()};
    this->setSize(value); this->setCenter(__ct_pos);
  }

  inline func Obj::setRect(const FloatRect& value) const -> void {
    this->setFrame({{value.left, value.top}, {value.width, value.height}});
  }
  inline func Obj::getRect(void) const -> FloatRect {
    return{this->getPosition(), this->getSize()};
  }
  
  inline func Obj::setRoot(const Vector2f& value) const -> void {
    this->setPosition(value - this->getSize());
  }
  inline func Obj::getRoot(void) const -> Vector2f {
    return this->getPosition() + this->getSize();
  }
  
  inline func Obj::setFrame(const Frame& value) const -> void {
    this->setPosition(value.pos);
    this->setSize    (value.size);
  }
  inline func Obj::getFrame(void) const -> const Frame {
    return{this->getPosition(), this->getSize()};
  }
  
  inline func Obj::setCenter(const Vector2f& value) const -> void {
    this->setPosition(value - this->getSize() / 2.0f);
  }
  inline func Obj::getCenter(void) const -> Vector2f {
    return this->getPosition() + this->getSize() / 2.0f;
  }
  
  inline func Obj::requestUpdate(void) const -> bool {
    return((ScrollableView::getAutoSliding() && this->inView())
         || this->build() != this->getPosition()
         || this->__NeedUpdate);
  }
  
  inline func Obj::inView(void) const -> bool {
    return (this->getRect() + FloatRect{{}, {1, 1}}).intersects(this->getViewRect());
  }
  
}
