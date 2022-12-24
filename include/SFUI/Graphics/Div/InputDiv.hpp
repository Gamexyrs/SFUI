//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "../Button/CheckButton.hpp"

namespace sf::ui {
  typedef class InputDiv : public TextDiv {
  public:    InputDiv(const Vector2f& size, const Object& builder, unsigned radius = 0,
                      const Vector2f& buildPosition = {},
                      const Vector2b& buildAddSize  = {});
             InputDiv(const Frame& frame = {{}, {}}, unsigned radius = 0);
    virtual ~InputDiv(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, RenderStates states) const -> void;
    virtual func update(void) const -> void;
    
    static inline InputDiv* __InputtingDiv = nullptr;
    
  _data_public:
    
  _func_public:
    virtual func pollEvent(const Event& event) -> bool;
    
  }InputDiv;
}

#include "../../../../src/SFUI/Graphics/Div/InputDiv.cpp"
