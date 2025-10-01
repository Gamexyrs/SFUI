//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  Movable::Movable(Object* self) {
    mov.setTarget(self);
  }

  inline func Movable::MovRegister::setTarget(Object* value) -> void {
    this->__Target = value;
  }
  inline func Movable::MovRegister::getTarget(void) const -> Object* {
    return this->__Target;
  }

  inline func Movable::MovRegister::setPath(const std::vector<Vector2f>& value) -> void {
    std::queue<Vector2f> __empty_queue{};
    std::swap(__empty_queue,   this->__Path);
    for(const auto& i : value) this->__Path.push(i);
  }
  inline func Movable::MovRegister::getPath(void) const -> std::vector<Vector2f> {
    std::queue <Vector2f> copy{this->__Path};
    std::vector<Vector2f> r{};
    while(!copy.empty()) {
      r.emplace_back(copy.front());
                     copy.pop();
    } return r;
  }

  inline func Movable::MovRegister::setAuto(bool value) -> void {
    this->__Auto = value;
  }
  inline func Movable::MovRegister::getAuto(void) const -> bool {
    return this->__Auto;
  }
  
  inline func Movable::MovRegister::apply(const std::vector<Vector2f>& path, bool instead) -> void {
    if(instead) this->setPath(path);
    else for(const auto& i :  path)
      this->__Path.push(i);
  }
  
  inline func Movable::MovRegister::clear(void) -> void {
    this->setPath(std::vector<Vector2f>{});
  }
  
  inline func Movable::MovRegister::isEnd(void) const -> bool {
    return this->__Path.empty();
  }
  inline func Movable::MovRegister::next(size_t _for) const -> bool {
    if(this->isEnd() || this->__Target == nullptr) return false;
    else for(size_t i{0}; i < _for; ++i) {
      if(this->__Target->getBuilder() == nullptr)
         this->__Target->getBase(false).move(
         this->__Path.front());
      else this->__Target->setBuildPosition(
           this->__Target->getBuildPosition()
         + this->__Path.front());
      this->__Path.pop();
      
      if(this->isEnd()) break;
    } return true;
  }
}
