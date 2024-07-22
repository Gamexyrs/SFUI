//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "Div.hpp"
#include "../Textable.hpp"

namespace sf::ui {
  typedef class TextDiv : public Div, public Textable {
  public:    TextDiv(const Vector2f& size, const Object& builder, unsigned radius = 0,
                     const Vector2f& buildPosition = {},
                     const Vector2b& buildAddSize  = {});
             TextDiv(const Frame& frame = {}, unsigned radius = 0);
    virtual ~TextDiv(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
    virtual func update_text(void) const -> void;
    virtual func update     (void) const -> void;
    
  _data_public:
    virtual func inView(void) const -> bool;
    
  _func_public:
    func resize(void) -> void;
    
  }TextDiv;
}

#include "../../../../src/SFUI/Graphics/Div/TextDiv.cpp"
