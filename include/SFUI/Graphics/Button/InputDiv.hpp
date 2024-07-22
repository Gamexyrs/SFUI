//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#ifdef __PREDEF_ENABLE_KB_BUFFER__
#if    __PREDEF_ENABLE_KB_BUFFER__

#include "CheckButton.hpp"

namespace sf::ui {
  typedef class InputDiv : public CheckBtn {
  public:    InputDiv(const Vector2f& size, const Object& builder, unsigned radius = 0,
                      const Vector2f& buildPosition = {},
                      const Vector2b& buildAddSize  = {});
             InputDiv(const Frame& frame = {}, unsigned radius = 0);
    virtual ~InputDiv(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
    virtual func update(void) const -> void;
    
    mutable Div   __Flasher{};
    mutable Clock __FlashClock{};
             Time __FlashItval{milliseconds(600)};
    
  _data_public:
    func getFlasher(bool update = true) const -> Div&;
    
    func setFlashInterval(const Time&) _____ -> void;
    func getFlashInterval(void) const -> const Time&;
    
  _func_public:
    virtual func pollEvent(const Event&) -> bool;
    
    virtual func setChecked(bool) _____ -> void;
    virtual func getChecked(void) const -> bool;
    
  }InputDiv;
}

#include "../../../../src/SFUI/Graphics/Button/InputDiv.cpp"

#endif
#endif
