//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  Obj::Object(const Vector2f& size, const Object& builder, const Vector2f& buildPosition, const Vector2b& buildAddSize)
    : Buildable(this) {
    this->setBuilder(const_cast<Object&>(builder), buildPosition, buildAddSize); this->setSize(size);
  }
  Obj::Object(const Frame& frame)
    : Buildable(this) {
    this->setPosition(frame.pos); this->setSize(frame.size);
  }
  
  inline func Obj::getBase(bool update) const -> ConvexShape& {
    if(update) this->needUpdate();
    return this->__Base;
  }

  inline func Obj::setPosition(const Vector2f& value) const -> void {
    this->__Base.setPosition(value);
    this->needUpdate();
  }
  inline func Obj::getPosition(void) const _____ -> const Vector2f& {
    return this->__Base.getPosition();
  }

  inline func Obj::setSize(const Vector2f& value) const -> void {
    this->__Size = value;
    this->needUpdate();
  }
  inline func Obj::getSize(void) const _____ -> const Vector2f& {
    return this->__Size;
  }

  inline func Obj::setAlignLock(const std::optional<Align>& value) -> void {
    this->__AlignLock = value;
    this->needUpdate();
  }
  inline func Obj::getAlignLock(void) const -> const std::optional<Align>& {
    return this->__AlignLock;
  }

  template<typename type>
  inline func Obj::setTag(const type& value) -> void {
    this->__Tag = std::make_any<type>(value);
  }
  template<typename type>
  inline func Obj::getTag(void) const -> type {
    return this->hasTag() ? std::any_cast<type>(this->__Tag) : type{};
  }
  inline func Obj::hasTag(void) const -> bool {
    return this->__Tag.has_value();
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

  inline func Obj::getRect(void) const -> FloatRect {
    return{this->getPosition(), this->getSize()};
  }
  inline func Obj::getRoot(void) const -> Vector2f {
    return this->getPosition() + this->getSize();
  }
  
  inline func Obj::setFrame(const Frame& value) -> void {
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
    return((SlidableView::getAutoSliding() && this->inView())
         || this->build() != this->getPosition()
         || this->__NeedUpdate);
  }
  
  inline func Obj::inView(void) const -> bool {
    return (this->getRect() + FloatRect({}, {1, 1})).intersects(this->getViewRect());
  }
}
