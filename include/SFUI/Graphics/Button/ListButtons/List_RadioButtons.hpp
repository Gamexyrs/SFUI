//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

#include "AbstractList_Buttons.hpp"

namespace sf::ui {
  typedef class List_RadioButtons : public AbsBtns {
  public:    List_RadioButtons(const std::initializer_list<CheckButton*>& = {});
    virtual ~List_RadioButtons(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
    
    bool __cancelable{true}; // 已被选择的按钮被重复点击时，可否被取消
    
  _func_public:
    virtual func pollEvent(const Event&) -> bool;
    
    func getCancelable(void) const -> bool;
    func setCancelable(bool) -> void;

    func hasResult(void) -> bool;
    func setResult(const std::optional<size_t>&) -> void;
    func getResult(void) const -> std::optional<size_t>;
    
    func clrReclick(void) -> void;
    func getReclick(void) const -> std::optional<size_t>;
    
  }RadioBtns;
}

#include "../../../../../src/SFUI/Graphics/Button/ListButtons/List_RadioButtons.cpp"
