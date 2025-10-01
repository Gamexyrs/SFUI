//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

#include "../Div/TextureDiv.hpp"
#include "AbstractButton.hpp"

namespace sf::ui {
  typedef class CheckButton : public AbsBtn, public TexDiv, public Touchable {
  public:    CheckButton(const Vector2f& size, const Object& builder, int radius = 0,
                         const Vector2f& buildPosition = {},
                         const Vector2b& buildAddSize  = {});
             CheckButton(const Frame& frame = {}, int radius = 0);
    virtual ~CheckButton(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
    virtual func update(void) const -> void;
    
    bool __isPressed{false};
    bool __cancelable{true}, // 已被选择的按钮被重复点击时，可否被取消
         __reclick{false};   // 不可取消时，同一按钮被重复点击

  _data_public:
  
  _func_public:
    virtual func pollEvent(const Event&) -> bool;
    
    virtual func setFillColor(const Color&) const -> void override;
        
    virtual func setChecked(bool) -> void;
    virtual func getChecked(void) const -> bool;

    virtual func setCancelable(bool) -> void;
    virtual func getCancelable(void) const -> bool;
    
    virtual func clrReclick(void) -> void;
    virtual func getReclick(void) const -> bool;

  }CheckBtn;
  
  typedef class CheckButtonFactory {
  protected: CheckButtonFactory(void) = delete;
    virtual ~CheckButtonFactory(void) = delete;
    
  _func_public:
    static func build(CheckBtn* _ori, std::initializer_list<CheckBtn*>&& _tar,
      Vector2f distance = {0, 5}, Vector2b direct = {false, true}) -> void;
    
  }CheckBtnFat;
}

#include "../../../../src/SFUI/Graphics/Button/CheckButton.cpp"
