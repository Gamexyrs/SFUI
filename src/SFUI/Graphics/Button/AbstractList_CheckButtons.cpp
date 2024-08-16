//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  AbsCheckBtns::AbstractList_CheckButtons(const std::initializer_list<CheckButton*>& m) {
    for(const auto& i : m) { this->__List.emplace_back(i); this->push_unity({i}); }
  }
  
  inline func AbsCheckBtns::insert(CheckButton* _tar, const std::optional<size_t>& _at) -> size_t {
    if(!_at.has_value()) this->__List.emplace_back(_tar);
    else {
      auto i = this->__List.begin(); for(size_t t{0}; t < _at; ++t) {
        ++i; if(i == this->__List.end()) return this->__List.size();
      } this->__List.insert(i, _tar);
    } return this->__List.size();
  }
  inline func AbsCheckBtns::del(CheckButton* _tar) -> bool {
    for(auto i = this->__List.begin(); i != this->__List.end(); ++i)
      if(*i == _tar) { this->__List.erase(i); return true; }
    return false;
  }
  inline func AbsCheckBtns::del(size_t _at) -> bool {
    auto i = this->__List.begin(); for(size_t t{0}; t < _at; ++t) {
      ++i; if(i == this->__List.end()) return false;
    } this->__List.erase(i); return true;
  }
  
  inline func AbsCheckBtns::getList(void) const -> std::vector<CheckButton*> {
    return this->__List;
  }
}
