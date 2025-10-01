//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  AbsBtns::AbstractList_Buttons(const std::initializer_list<CheckButton*>& m) {
    for(const auto& i : m) { this->emplace_back(i); }
  }
  
  inline func AbsBtns::insert(CheckButton* _tar, const std::optional<size_t>& _at) -> size_t {
    if(!_at.has_value()) this->emplace_back(_tar);
    else this->insert(_tar, _at);
    
    return this->size();
  }
  inline func AbsBtns::del(CheckButton* _tar) -> bool {
    for(auto i = this->begin(); i != this->end(); ++i)
      if(*i == _tar) { this->erase(i); return true; }
    return false;
  }
  inline func AbsBtns::del(size_t _at) -> bool {
    auto i = this->begin(); for(size_t t{0}; t < _at; ++t) {
      ++i; if(i == this->end()) return false;
    } this->erase(i); return true;
  }
}
