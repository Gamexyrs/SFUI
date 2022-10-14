//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "../System.hpp"
#include "Buildable.hpp"

namespace sf::ui {
  typedef Vector2<Vector2f> Frame;

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
    
  _func_public:
    static func align(const Vector2f size,             const FloatRect& rect, short align = Align::Center) -> const Vector2f;
           func align(const std::optional<FloatRect>& optRect = std::nullopt, short align = Align::Center) -> const Vector2f&;

    func move(const Vector2f& value) const -> void;

    func getRect(void) const -> FloatRect;
    func getRoot(void) const -> Vector2f;

  }Obj;
}

#include "../../src/Graphics/Object.cpp"
#include "../../src/Graphics/Buildable.cpp"

#define __SFUI_OBJECT__ 
