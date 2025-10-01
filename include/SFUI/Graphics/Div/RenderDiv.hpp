//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

#include "Div.hpp"

namespace sf::ui {
  typedef class RenderDiv : public Div {
  public:    RenderDiv(const Vector2f& size, const Object& builder, int radius = 0,
                       const Vector2f& buildPosition = {},
                       const Vector2b& buildAddSize  = {});
             RenderDiv(const Frame& = {}, int radius = 0);
    virtual ~RenderDiv(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
    virtual func draw_RTx(RenderTarget& target, const RenderStates& states) const -> void;
    virtual func update(void) const -> void;
    
    mutable Sprite __RTs{};
    mutable std::unique_ptr<RenderTexture> __pRTx{nullptr};
    std::vector<Drawable*> __Targets{};
    
  _data_public:
    
    
  _func_public:
    func operator +=(Div&) -> void;
    
  } RenderDiv;
}

#include "../../../../src/SFUI/Graphics/Div/RenderDiv.cpp"
