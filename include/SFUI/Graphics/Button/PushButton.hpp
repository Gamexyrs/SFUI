//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "../Div/TextDiv.hpp"
#include "AbstractButton.hpp"

namespace sf::ui {
  typedef class PushButton : public AbsBtn, public TextDiv, public Touchable {
  public:    PushButton(const Vector2f& size, const Object& builder, unsigned radius = 0,
                        const Vector2f& buildPosition = {},
                        const Vector2b& buildAddSize  = {});
             PushButton(const Frame& frame = {}, unsigned radius = 0);
    virtual ~PushButton(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
    virtual func update(void) const -> void;
    
  _data_public:

  _func_public:
    virtual func pollEvent_if(const Event& event, const BtnEvent& target = BtnEvent::Release) -> bool;
    virtual func pollEvent   (const Event&) -> BtnEvent;
    
  }PushBtn;
}

#include "../../../../src/SFUI/Graphics/Button/PushButton.cpp"
