//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "../System.hpp"
#include "Buildable.hpp"

namespace sf::ui {
  typedef Vector2<Vector2f> Frame;
  
  typedef struct Attribute {
    bool        __PROTECTED__ = false;
    bool __IGNORE_PROTECTED__ = false;
    bool __ALWAYS_TOUCHABLE__ = false;
    
  }Attribute;

  typedef class Object : public Renderable, public Buildable {
  protected: Object(const Vector2f& size, const Object& builder,
                    const Vector2f& buildPosition = {},
                    const Vector2b& buildAddSize  = {});
    explicit Object(const Frame& frame = {{}, {}});
    virtual ~Object(void) = default;
    
    mutable ConvexShape __Base;
    mutable Vector2f    __Size = {};

    bool       __Visible = true;
    bool   __BaseVisible = true;
    
    String __Tag = L"";
    
  _data_public:
    func getBase(void) const -> ConvexShape&;

    func setPosition(const Vector2f& value) const -> void;
    func getPosition(void) const _____ -> const Vector2f&;

    func setSize(const Vector2f& value) const -> void;
    func getSize(void) const _____ -> const Vector2f&;

    func setVisible(bool value) -> void;
    func getVisible(void) const -> bool;

    func setBaseVisible(bool value) -> void;
    func getBaseVisible(void) const -> bool;

    func setTag(const String& value) -> void;
    func getTag(void) const -> const String&;
    
    Attribute __ATTRIBUTE__;
    
  _func_public:
    func align(short align = Align::Center,
      const std::optional<FloatRect>& optRect = std::nullopt) -> Vector2f&;

    func move(const Vector2f& value) const -> void;

    func getRect(void) const -> FloatRect;
    func getRoot(void) const -> Vector2f;
    
#if __PREDEF_ENABLE_UNITYDRAW__
    func joinUnity(void) -> void;
#endif

  }Obj;
}

#include "../../../src/SFUI/Graphics/Object.cpp"
#include "../../../src/SFUI/Graphics/Buildable.cpp"

#define __SFUI_OBJECT__ 
