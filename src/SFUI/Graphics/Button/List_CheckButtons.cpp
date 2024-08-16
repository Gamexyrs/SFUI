//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  CheckBtns::List_CheckButtons(const std::initializer_list<CheckButton*>& m, const std::vector<size_t>& r) : AbsCheckBtns(m) {
    this->setResult(r);
  }
  
  inline func CheckBtns::pollEvent(const Event& event) -> bool {
    for(auto& i : this->__List) {
      if(i->pollEvent(event))
        return true;
    }   return false;
  }
  
  inline func CheckBtns::hasResult(void) -> bool {
    return !this->getResult().empty();
  }
  inline func CheckBtns::setResult(const std::vector<size_t>& _at) -> void {
    for(auto& i : this->__List) i->setChecked(false);
    for(const auto& i : _at)
      this->__List.at(i)->setChecked(true);
  }
  inline func CheckBtns::getResult(void) const -> std::vector<size_t> {
    static std::vector<size_t> r{}; r.clear();
    for(size_t t{0}; t < this->__List.size(); ++t)
      if(this->__List.at(t)->getChecked()) r.emplace_back(t);
    return r;
  }
}
