//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  Buildable::Buildable(Object* self) : __Self(self) {
    this->__RegisteredObject.emplace_back(self);
  }
  Buildable::~Buildable(void) {
    this->delBuilder();
  }
  
  inline func Buildable::__PercentToFloat(const Percent& percent) -> float {
    std::string tmp = percent.toAnsiString();
    if(tmp.back() == '%')
       tmp.pop_back();
    try {
      return(std::stof(tmp) / 100);
    } catch(...) {
      err() << "SFUI_CATCH: Input a unresolvable percent string\n";
      return 0.0f;
    }
  }
  
  inline func Buildable::setBuildPosition_Global(const Vector2f& value) const -> void {
    this->__BuildPosition = value - this->__Builder->getPosition();
    this->needUpdate();
  }
  inline func Buildable::setBuildPosition(const Vector2f& value) const -> void {
    this->__BuildPosition = value;
    this->needUpdate();
  }
  inline func Buildable::getBuildPosition(void) const _____ -> const Vector2f& {
    return this->__BuildPosition;
  }
  
  inline func Buildable::setBuildAddSize(const Vector2b& value) const -> void {
    this->__BuildAddSize = value;
    this->needUpdate();
  }
  inline func Buildable::getBuildAddSize(void) const _____ -> const Vector2b& {
    return this->__BuildAddSize;
  }
  
  inline func Buildable::setBuilder(Object& value, const std::optional<Vector2f>& buildPosition, const std::optional<Vector2b>& buildAddSize) -> void {
    if(&value != this->__Self) {
      this->delBuilder();
      this->__Builder = &value;
    }
    this->__BuildPosition = buildPosition.value_or(this->__BuildPosition);
    this->__BuildAddSize  = buildAddSize .value_or(this->__BuildAddSize);
    this->__Self->setPosition(this->build());
    this->needUpdate();
  }
  inline func Buildable::getBuilder(void) const -> Object* {
    this->needUpdate(); return this->__Builder;
  }
  inline func Buildable::delBuilder(void) -> void {
    if(this->__Builder == nullptr) return;
    this->__Builder = nullptr;
    this->needUpdate();
  }
  
  inline func Buildable::setPerSize  (const Percent& percent) -> void {
    this->__Self->setSize(((this->__Builder == nullptr)
    ? _RendererSize : this->__Builder->getSize())
    * this->__PercentToFloat(percent));
  }
  inline func Buildable::setPerWidth (const Percent& percent) -> void {
    this->__Self->setSize({((this->__Builder == nullptr)
    ? _RendererSize.x : this->__Builder->getSize().x)
    * this->__PercentToFloat(percent), this->__Self->getSize().y});
  }
  inline func Buildable::setPerHeight(const Percent& percent) -> void {
    this->__Self->setSize({this->__Self->getSize().x, ((this->__Builder == nullptr)
    ? _RendererSize.y : this->__Builder->getSize().y)
    * this->__PercentToFloat(percent)});
  }
  
  inline func Buildable::needUpdate(void) const -> void {
    this->__NeedUpdate = true;
  }
  
  inline func Buildable::build(void) const -> Vector2f {
    if(this->__Builder != nullptr) {
      return(this->__Builder->getPosition() + this->__BuildPosition
      + Vector2f(this->__BuildAddSize.x ? this->__Builder->getSize().x : 0.f,
                 this->__BuildAddSize.y ? this->__Builder->getSize().y : 0.f));
    } else return this->__Self->getPosition();
  }
  
  inline func Buildable::flash(void) -> void {
    if(!Buildable::__RegisteredObject.empty()) {
      for(const auto& i : Buildable::__RegisteredObject) {
                   if(i != nullptr)
                      i->needUpdate();
      }
    }
  }
}
