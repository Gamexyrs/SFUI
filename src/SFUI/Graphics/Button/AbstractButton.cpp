//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  inline func AbsBtn::setStateColor(const Color& value, const std::optional<BtnState>& state) const -> void {
    this->__Self->needUpdate();
    if(state.has_value()) switch(state.value()) {
      case(BtnState::None):    this->__StateColor.__None    = value; return;
      case(BtnState::Pressed): this->__StateColor.__Pressed = value; return;
      case(BtnState::Checked): this->__StateColor.__Checked = value; return;
    } else {
      this->__StateColor.__None    = value;
      this->__StateColor.__Pressed = value;
      this->__StateColor.__Checked = value;
    }
  }
  inline func AbsBtn::getStateColor(const BtnState& state) const -> const Color& {
    switch(state) {
      case(BtnState::Pressed):       return this->__StateColor.__Pressed;
      case(BtnState::Checked):       return this->__StateColor.__Checked;
      case(BtnState::None): default: return this->__StateColor.__None;
    }
  }
  
  inline func AbsBtn::setState(const BtnState& value) -> void {
    this->__State = value;
    this->__Self->needUpdate();
  }
  inline func AbsBtn::getState(void) const -> const BtnState& {
    return this->__State;
  }
}
