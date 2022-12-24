//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func Buildable::__PercentToFloat(const std::string& percent) -> float {
    std::string tmp_str = percent;
    if(tmp_str.back() == '%') {
       tmp_str.pop_back();
    }
    try {
      return(std::stof(tmp_str) / 100);
    } catch( std::invalid_argument) {
      return 0.0f;
    }
  }
  
  inline func Buildable::getSubobject(void) const -> const std::deque<Object*>& {
    this->needUpdate(true);
    return this->__Subobject;
  }
  inline func Buildable::delSubobject(void) -> void {
    this->needUpdate(true);
    for(const auto& i : this->__Subobject) {
      if(i != nullptr &&   (!i->__ATTRIBUTE__.__PROTECTED__
        || this->__Self->__ATTRIBUTE__.__IGNORE_PROTECTED__)) {
        i->delBuilder();
      }
    }
  }
  
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
      this->delBuilder();
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
    if(this->__Builder == nullptr) return;
    for(std::deque<Object*>::iterator it = this->__Builder->__Subobject.begin(); it != this->__Builder->__Subobject.end(); ++it) {
      if(*it == this->__Self) {
        this->__Builder->__Subobject.erase(it); break;
      }
    } this->__Builder = nullptr;
    this->needUpdate(true);
  }
  
  inline func Buildable::setPerSize  (const std::string& percent /* 0~100% */) -> void {
    this->__Self->setSize(((this->__Builder == nullptr)
    ? _RendererSize : this->__Builder->getSize())
    * this->__PercentToFloat(percent));
  }
  inline func Buildable::setPerWidth (const std::string& percent /* 0~100% */) -> void {
    this->__Self->setSize({((this->__Builder == nullptr)
    ? _RendererSize.x : this->__Builder->getSize().x)
    * this->__PercentToFloat(percent), this->__Self->getSize().y});
  }
  inline func Buildable::setPerHeight(const std::string& percent /* 0~100% */) -> void {
    this->__Self->setSize({this->__Self->getSize().x, ((this->__Builder == nullptr)
    ? _RendererSize.y : this->__Builder->getSize().y)
    * this->__PercentToFloat(percent)});
  }
  
  inline func Buildable::needUpdate(bool subobject_needUpdate) const -> void {
    this->__NeedUpdate = true;
    if(subobject_needUpdate) {
      for(const auto& i : this->__Subobject) {
        if(i != nullptr) i->needUpdate(true);
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
  
  inline func Buildable::flash(void) -> void {
    for(auto& i : Obj::__Registered_Object__) {
      if(i != nullptr) i->needUpdate();
    }
  }
}
