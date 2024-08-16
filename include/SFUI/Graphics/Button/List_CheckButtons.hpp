//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "AbstractList_CheckButtons.hpp"

namespace sf::ui {
  typedef class List_CheckButtons : public AbsCheckBtns {
  public:    List_CheckButtons(const std::initializer_list<CheckButton*>& = {},
                               const std::vector<size_t>& r = {});
    virtual ~List_CheckButtons(void) = default;
    
  _func_public:
    virtual func pollEvent(const Event&) -> bool;
    
    func hasResult(void) -> bool;
    func setResult(const std::vector<size_t>&) -> void;
    func getResult(void) const -> std::vector<size_t>;
    func getReclick(void) const -> std::vector<size_t>;
    
  }CheckBtns;
}

#include "../../../../src/SFUI/Graphics/Button/List_CheckButtons.cpp"
