//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func Msgable::setLocked(bool value) -> void {
    Msgable::__Locked = value;
  }
  inline func Msgable::getLocked(void) -> bool {
    return Msgable::__Locked;
  }
}