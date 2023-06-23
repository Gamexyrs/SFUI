//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "../System.hpp"
#include "Buildable.hpp"
#include <any>

namespace sf::ui {
  typedef class Object : public Renderable, public Buildable {
  protected: Object(const Vector2f& size, const Object& builder,
                    const Vector2f& buildPosition = {},
                    const Vector2b& buildAddSize  = {});
    explicit Object(const Frame& frame = {});
    virtual ~Object(void) = default;
    
    mutable ConvexShape __Base{};
    mutable Vector2f    __Size{};
    
    std::optional<Align> __AlignLock{std::nullopt};
    
    std::any __Tag{};
    
  _data_public:
    func getBase(bool update = true) const -> ConvexShape&;

    func setPosition(const Vector2f&) const -> void;
    func getPosition(void) const -> const Vector2f&;

    func setSize(const Vector2f&) const -> void;
    func getSize(void) const -> const Vector2f&;

    func setAlignLock(const std::optional<Align>&) -> void;
    func getAlignLock(void) const -> const std::optional<Align>&;
    
    template<typename type = std::string>
    func setTag(const type&) -> void;
    template<typename type = std::string>
    func getTag(void) const -> type;
    func hasTag(void) const -> bool;
    
    struct {
      bool        __PROTECTED__{false};
      bool __IGNORE_PROTECTED__{false};
      bool __IGNORE_ROTATEAGL__{false};
      bool __IGNORE_FASTDRAW_SOV__{false};
      
      bool __ALWAYS_TOUCHABLE__{false};
      
      bool __VISIBLE__     {true};
      bool __VISIBLE_BASE__{true};
      bool __VISIBLE_TEXT__{true};
      bool __VISIBLE_MASK__{true};
      bool __VISIBLE_INER__{true};
      
    }__ATTRIBUTE__;
    
  _func_public:
    func align(short align = Align::Center,
      const std::optional<FloatRect>& optRect = std::nullopt) const -> Vector2f&;

    func move(const Vector2f&) const -> void;

    func getRect(void) const -> FloatRect;
    func getRoot(void) const -> Vector2f;
    
    func setFrame(const Frame&) -> void;
    func getFrame(void) const -> const Frame;
    
    func setCenter(const Vector2f&) const -> void;
    func getCenter(void) const -> Vector2f;

    func requestUpdate(void) const -> bool;
    
    virtual func inView(void) const -> bool;

  }Obj;
}

#include "../../../src/SFUI/Graphics/Object.cpp"
#include "../../../src/SFUI/Graphics/Buildable.cpp"

#define __SFUI_OBJECT__ 
