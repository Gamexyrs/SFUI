//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  bool VirtualNumpad::Enable = false;
  
  func VirtualNumpad::update(void) const -> void {
    VirtualNumpad::NeedUpdate = false;
  }
  inline func VirtualNumpad::draw(RenderTarget& target, RenderStates states) const -> void {
    if(this->NeedUpdate) this->update();
    target.draw(VirtualNumpad::_Base, states);
    target.draw(VirtualNumpad::_Text, states);
  }
  
  inline func VirtualNumpad::pollEvent(void) -> void {
    if(VirtualNumpad::Enable) {
      VirtualNumpad::NeedUpdate = true;
    }
  }
  inline func VirtualNumpad::display(void) -> void {
    if(VirtualNumpad::Enable) {
      _Renderer.draw(VirtualNumpad);
    }
  }
  inline func VirtualNumpad::init(void) -> void {
    if(VirtualNumpad::_State == KbState::NeedInit) {
      VirtualNumpad::setSize({_RendererSize.x, _RendererSize.y / 3});
      for(auto& i : VirtualNumpad::_Numkey) {
        i.setSize(VitualNumpad::getSize() / 4);
        i.setBorderRadius(20);
      }
    }
  }
};
