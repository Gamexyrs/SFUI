//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func Buildable::setBuildPosition(const Vector2f& value) const -> void {
    this->__BuildPosition = value;
    this->needUpdate(true);
  }
  inline func Buildable::getBuildPosition(void) const _____ -> const Vector2f& {
    return this->__BuildPosition;
  }
  
  inline func Buildable::setBuildAddSize(const Vector2b& value) const -> void {
    this->__BuildAddSize = value;
    this->needUpdate(true);
  }
  inline func Buildable::getBuildAddSize(void) const _____ -> const Vector2b& {
    return this->__BuildAddSize;
  }
  
  inline func Buildable::setBuilder(const Object& value, const std::optional<Vector2f>& buildPosition, const std::optional<Vector2b>& buildAddSize) -> void {
    if(&value != this->__Self && &value != this->__Builder) {
      this->__Builder = const_cast<Object*>(&value);
      for(const auto& i : this->__Builder->__Subobject) {
        if(i == this->__Self) return;
      } this->__Builder->__Subobject.emplace_back(this->__Self);
    }
    this->__BuildPosition = buildPosition.value_or(this->__BuildPosition);
    this->__BuildAddSize  = buildAddSize .value_or(this->__BuildAddSize);
    this->needUpdate(true);
  }
  inline func Buildable::getBuilder(void) const -> const Object& {
    if(this->__Builder == nullptr) throw nullptr;
    this->needUpdate(true); return *(this->__Builder);
  }
  inline func Buildable::delBuilder(void) -> void {
    for(std::deque<Object*>::iterator it = this->__Builder->__Subobject.begin(); it != this->__Builder->__Subobject.end(); ++it) {
      if(*it == this->__Self) {
        this->__Builder->__Subobject.erase(it); break;
      }
    } this->__Builder = nullptr;
    this->needUpdate(true);
  }
  
  inline func Buildable::needUpdate(bool subobject_needUpdate) const -> void {
    this->__NeedUpdate = true;
    if(subobject_needUpdate) {
      for(const auto& i : this->__Subobject) {
        i->needUpdate(true);
      }
    }
  }
  
  inline func Buildable::build(void) const -> Vector2f {
    if(this->__Builder != nullptr) {
      return (this->__Builder->getPosition() + this->__BuildPosition
      + Vector2f(this->__BuildAddSize.x ? this->__Builder->getSize().x : 0.f,
                 this->__BuildAddSize.y ? this->__Builder->getSize().y : 0.f));
    } else return this->__Self->getPosition();
  }
}
