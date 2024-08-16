//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  RenderUnity::RenderUnity(const std::initializer_list<Drawable*>& value) {
    this->push_unity(value);
  }
  
  inline func RenderUnity::draw(RenderTarget& target, const RenderStates& states) const -> void {
    for(auto& i : this->__Unity)
      target.draw(*i, states);
  }
  
  inline func RenderUnity::push_unity(const std::initializer_list<Drawable*>& value) -> void {
    for(auto& i : value)
      if(i != nullptr) this->__Unity.emplace_back(i);
  }
  
  inline func RenderUnity::clear(void) -> void {
    this->__Unity.clear();
  }
  
  inline func RenderUnity::size(void) const -> size_t {
    return this->__Unity.size();
  }
}
