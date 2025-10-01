//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

#ifdef __PREDEF_ENABLE_KB_BUFFER__
#if    __PREDEF_ENABLE_KB_BUFFER__

#include "../Button/CheckButton.hpp"

namespace sf::ui {
  typedef class InputDiv : public CheckBtn {
  public:    InputDiv(const Vector2f& size, const Object& builder, int radius = 0,
                      const Vector2f& buildPosition = {},
                      const Vector2b& buildAddSize  = {});
             InputDiv(const Frame& frame = {}, int radius = 0);
    virtual ~InputDiv(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
    virtual func update(void) const -> void;
    
    mutable Div   __Flasher{};
    mutable Clock __FlashClock{};
             Time __FlashItval{milliseconds(600)};
    
    std::function<void(void)> __KeyboardCallMethod{ [](void) -> void {::sf::Keyboard::setVirtualKeyboardVisible(true);} };
    std::function<void(void)> __KeyboardCallbackMethod{ [](void) -> void {::sf::Keyboard::setVirtualKeyboardVisible(false);} };
    
  _data_public:
    func getFlasher(bool update = true) const -> Div&;
    
    func setFlashInterval(const Time&) -> void;
    func getFlashInterval(void) const -> const Time&;
    
  _func_public:
    virtual func pollEvent(const Event&) -> bool;
    
    func setKeyboardMethod(std::pair<std::function<void(void)>, std::function<void(void)>> __f_calls) -> void;
    
    virtual func setChecked(bool) -> void;
    virtual func getChecked(void) const -> bool;
    
  } InputDiv;
}

#include "../../../../src/SFUI/Graphics/Div/InputDiv.cpp"

#endif
#endif
