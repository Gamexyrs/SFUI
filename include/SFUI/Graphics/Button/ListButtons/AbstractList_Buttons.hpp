//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

#include "../CheckButton.hpp"

namespace sf::ui {
  typedef interface class AbstractList_Buttons : public std::vector<CheckButton*>, public Drawable {
  protected: AbstractList_Buttons(const std::initializer_list<CheckButton*>& = {});
    virtual ~AbstractList_Buttons(void) = default;
    
  _data_public:
    func insert(CheckButton*, const std::optional<size_t>& = std::nullopt) -> size_t;
    func del   (CheckButton*) -> bool;
    func del   (size_t)       -> bool;
    
  } AbsBtns;
}

#include "../../../../../src/SFUI/Graphics/Button/ListButtons/AbstractList_Buttons.cpp"
