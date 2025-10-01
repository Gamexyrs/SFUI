//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

#include "Div.hpp"
#include "../Interface/Textable.hpp"

namespace sf::ui {
  typedef class TextDiv : public Div, public Textable {
  public:    TextDiv(const Vector2f& size, const Object& builder, int radius = 0,
                     const Vector2f& buildPosition = {},
                     const Vector2b& buildAddSize  = {});
             TextDiv(const Frame& frame = {}, int radius = 0);
    virtual ~TextDiv(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
    virtual func update_text(void) const -> void;
    virtual func update     (void) const -> void;
    
  _data_public:
    
  _func_public:
    virtual func inView(void) const -> bool;
    
    func resizeByText(void) -> void;
    
  }TextDiv;
}

#include "../../../../src/SFUI/Graphics/Div/TextDiv.cpp"
