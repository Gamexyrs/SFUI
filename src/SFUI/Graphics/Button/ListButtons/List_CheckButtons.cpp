//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  CheckBtns::List_CheckButtons(const std::initializer_list<CheckButton*>& m) : AbsBtns(m) {}
  
  inline func CheckBtns::draw(RenderTarget& target, const RenderStates& states) const -> void {
    for(auto i : *this)
      target.draw(*i, states);
  }
  
  inline func CheckBtns::pollEvent(const Event& event) -> bool {
    for(auto& i : *this) {
      if(i->pollEvent(event))
        return true;
    }   return false;
  }
  
  inline func CheckBtns::hasResult(void) -> bool {
    return !this->getResult().empty();
  }
  inline func CheckBtns::setResult(const std::vector<size_t>& _at) -> void {
    for(auto& i : *this) i->setChecked(false);
    for(const auto& i : _at)
      this->at(i)->setChecked(true);
  }
  inline func CheckBtns::getResult(void) const -> std::vector<size_t> {
    static std::vector<size_t> r{}; r.clear();
    for(size_t t{0}; t < this->size(); ++t)
      if(this->at(t)->getChecked()) r.emplace_back(t);
    return r;
  }
}
