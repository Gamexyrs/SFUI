//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  RadioBtns::List_RadioButtons(const std::initializer_list<CheckButton*>& m) : AbsBtns(m) {}
  
  inline func RadioBtns::draw(RenderTarget& target, const RenderStates& states) const -> void {
    for(auto i : *this)
      target.draw(*i, states);
  }
  
  inline func RadioBtns::pollEvent(const Event& event) -> bool { size_t t{0};
    for(auto& i : *this) {
      if(i->pollEvent(event)) {
        this->setResult(i->getChecked() ? std::make_optional<size_t>(t) : std::nullopt);
        return true;
      } ++t;
    } return false;
  }
  
  inline func RadioBtns::getCancelable(void) const -> bool {
    return this->__cancelable;
  }
  inline func RadioBtns::setCancelable(bool v) -> void {
    for(auto& i : *this) i->setCancelable(v);
    this->__cancelable = v;
  }
  
  inline func RadioBtns::hasResult(void) -> bool {
    return this->getResult().has_value();
  }
  inline func RadioBtns::setResult(const std::optional<size_t>& _at) -> void {
    if(_at.has_value()) {
      for(auto& i : *this) i->setChecked(false);
                    this->at(_at.value())->setChecked(true);
    } else if(this->__cancelable) {
      for(auto& i : *this) i->setChecked(false);
    }
  }
  inline func RadioBtns::getResult(void) const -> std::optional<size_t> {
    for(size_t t{0}; t < this->size(); ++t)
      if(this->at(t)->getChecked()) return std::make_optional<size_t>(t);
    return std::nullopt;
  }
  
  inline func RadioBtns::clrReclick(void) -> void {
    for(auto& i : *this) i->clrReclick();
  }
  inline func RadioBtns::getReclick(void) const -> std::optional<size_t> {
    if(!this->__cancelable) {
      for(size_t t{0}; t < this->size(); ++t) if(this->at(t)->getReclick()) return t;
    } return std::nullopt;
  }
}
