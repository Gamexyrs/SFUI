//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  inline func Msgable::setLocked(bool value) -> void {
    Msgable::__Locked = value;
  }
  inline func Msgable::getLocked(void) -> bool {
    return Msgable::__Locked;
  }
}