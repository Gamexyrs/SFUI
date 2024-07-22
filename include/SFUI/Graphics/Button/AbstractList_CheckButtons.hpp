//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "CheckButton.hpp"

namespace sf::ui {
  typedef interface class AbstractList_CheckButtons : public RenderUnity {
  protected: AbstractList_CheckButtons(const std::initializer_list<CheckButton*>& = {});
    virtual ~AbstractList_CheckButtons(void) = default;
    
    std::vector<CheckButton*> __List{};
  
  _data_public:
    func insert(CheckButton*, const std::optional<size_t>& = std::nullopt) -> size_t;
    func del   (CheckButton*) -> bool;
    func del   (size_t)       -> bool;
    
    func getList(void) const -> std::vector<CheckButton*>;
    
  }AbsCheckBtns;
}

#include "../../../../src/SFUI/Graphics/Button/AbstractList_CheckButtons.cpp"
