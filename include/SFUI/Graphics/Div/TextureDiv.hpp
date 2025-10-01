//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

#include "TextDiv.hpp"
#include "../Interface/Texable.hpp"

namespace sf::ui {
  typedef class TextureDiv : public TextDiv, public Texable {
  public:    TextureDiv(const Vector2f& size, const Object& builder, int radius = 0,
                        const Vector2f& buildPosition = {},
                        const Vector2b& buildAddSize  = {});
             TextureDiv(const Frame& frame = {}, int radius = 0);
    virtual ~TextureDiv(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
    virtual func update_tex(void) const -> void;
    virtual func update    (void) const -> void;
    
  _data_public:
    
  _func_public:
    virtual func inView(void) const -> bool;
      
    func resizeByTex(void) -> void;
    
  } TexDiv;
}

#include "../../../../src/SFUI/Graphics/Div/TextureDiv.cpp"
