//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  template<typename T>
  func RenderVector<T>::draw(RenderTarget& target, const RenderStates& states) const -> void {
    for(auto i : *this)
      target.draw(i, states);
  }
}
