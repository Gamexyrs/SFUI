//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

#include "../Graphics.hpp"

namespace sf::ui {
  typedef class interface NumberKeyboard : public Drawable {
  public:    NumberKeyboard(void);
    virtual ~NumberKeyboard(void) = default;
  
  protected:
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
    virtual func update(void) const -> void;
    
    mutable Vector2f __standPos{};
    
    bool __Calling{false};
    mutable bool __Displaying{false};
    
    mutable TextDiv __Base;
    std::vector<std::vector<PushBtn>> __KeyBtns{4}; /* y4 x3 */
    
  _data_public:
    func setStandPos(const Vector2f& = {}) -> void;
    
    func getBase(void) const -> Div&;
    func getKeyBtns(void) const -> std::vector<std::vector<PushBtn>>&;
    
  _func_public:
    virtual func pollEvent(const Event&) -> bool;
    
    func call(void) -> void;
    func callback(void) -> void;
    func isCalling(void) const -> bool;
    
    func bind(void) -> std::pair<std::function<void(void)>, std::function<void(void)>>;
    
  } NumKeyboard;
}

#include "../../../src/SFUI/VirtualInput/NumberKeyboard.cpp"
