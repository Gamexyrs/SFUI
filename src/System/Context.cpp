//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  static int FpsFlashTime = 0;

  Text* Renderer::Fps = nullptr;
  //RenderWindow* Renderer::ptr = nullptr;
  bool Renderer::__Enable_VirtualKeyboard__ = false;
  
  inline func Renderer::setEnableVirtualKeyboard(bool value, bool useSystemKeyboard) -> void {
    if(useSystemKeyboard) Keyboard::setVirtualKeyboardVisible(value);
    else {
      Renderer::__Enable_VirtualKeyboard__ = value;
    }
  }
}
