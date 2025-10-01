//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

#include "AbstractList_Buttons.hpp"

namespace sf::ui {
  typedef class List_CheckButtons : public AbsBtns {
  public:    List_CheckButtons(const std::initializer_list<CheckButton*>& = {});
    virtual ~List_CheckButtons(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
    
  _func_public:
    virtual func pollEvent(const Event&) -> bool;
    
    func hasResult(void) -> bool;
    func setResult(const std::vector<size_t>&) -> void;
    func getResult(void) const -> std::vector<size_t>;
    func getReclick(void) const -> std::vector<size_t>;
    
  }CheckBtns;
}

#include "../../../../../src/SFUI/Graphics/Button/ListButtons/List_CheckButtons.cpp"
