//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  Obj::Object(const Vector2f& size, const Object& builder, const Vector2f& buildPosition, const Vector2b& buildAddSize)
    : Buildable(this) {
    this->setBuilder(builder, buildPosition, buildAddSize); this->setSize(size);
    this->__Registered_Object__.emplace_back(this);
  }
  Obj::Object(const Frame& frame)
    : Buildable(this) {
    this->setPosition(frame.x); this->setSize(frame.y);
    this->__Registered_Object__.emplace_back(this);
  }
  
  inline func Obj::getBase(bool update) const -> ConvexShape& {
    if(update) this->needUpdate(true);
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
  
  inline func Obj::align(short align, const std::optional<FloatRect>& optRect) -> Vector2f& {
    this->setPosition(sf::align(this->getSize(), optRect.value_or((this->__Builder != nullptr)
      ? this->__Builder->getRect() : _RendererRect), align)); this->needUpdate(true);
    if(this->__Builder != nullptr) {
      this->__BuildPosition = this->getPosition() - this->__Builder->getPosition();
      this->__BuildAddSize  = {};
      return const_cast<Vector2f&>(this->getBuildPosition());
    } else return const_cast<Vector2f&>(this->getPosition());
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
  
#if __PREDEF_ENABLE_UNITYDRAW__
  inline func Obj::joinUnity(void) -> void {
    this->unityAdd({dynamic_cast<Drawable*>(this)});
  }
#endif
}
