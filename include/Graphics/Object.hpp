//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "../System.hpp"
#include "Buildable.hpp"

namespace sf::ui {
  typedef Vector2<Vector2f> BuildFrame;

  typedef class Object : public Drawable, public Buildable {
  protected: Object(const BuildFrame& frame = {});
    virtual ~Object(void) = default;
    
    mutable ConvexShape _Base;
    
    mutable Vector2f Size = {};
    
    mutable bool NeedUpdate = true;
            bool Active = true;
            
    String Tag = L"";
    
  _data_public:
    inline func getBase(void) const -> ConvexShape& {this->needUpdate(true); return this->_Base;}
  
    inline func setPosition(const Vector2f& value) const -> void {this->_Base.setPosition(value); this->needUpdate(true);}
    inline func getPosition(void) const -> const Vector2f& __GET__(this->_Base.getPosition());
  
    inline func setSize(const Vector2f& value) const -> void {this->Size = value; this->needUpdate(true);}
    inline func getSize(void) const -> const Vector2f& __GET__(this->Size);
  
    inline func setActive(bool value) -> void __SET__(this->Active, __NF);
    inline func getActive(void) const -> bool __GET__(this->Active);
    
  _func_public:
    func move(const Vector2f& value) const -> void;
    
    func getRect(void) const -> FloatRect;
    func getRoot(void) const -> Vector2f;
    
    func needUpdate(bool subobj = false) const -> void;
    
    func isTouchDown(void) const -> unsigned;
    
  }Obj;
};

#include "../../src/Graphics/Object.cpp"
#include "../../src/Graphics/Buildable.cpp"
