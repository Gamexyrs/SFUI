//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "AbstractList_CheckButtons.hpp"

namespace sf::ui {
  typedef class List_RadioButtons : public AbsCheckBtns {
  protected:
    bool __cancelable{true}; // 已被选择的按钮被重复点击时，可否被取消

  public:    List_RadioButtons(const std::initializer_list<CheckButton*>& = {},
                               const std::optional<size_t>& r = std::nullopt);
    virtual ~List_RadioButtons(void) = default;
    
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

#include "../../../../src/SFUI/Graphics/Button/List_RadioButtons.cpp"
