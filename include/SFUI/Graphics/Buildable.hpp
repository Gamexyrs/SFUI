//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include <deque>

namespace sf::ui {
  typedef Vector2f Vector2b;

  class Object;
  typedef interface class Buildable {
  private:
    Object* __Self = nullptr;
  
  protected: Buildable(Object* self) : __Self(self) {}
    virtual ~Buildable(void) = default;
    
    static inline std::deque<Object*> __Registered_Object__ = {};
    std::deque<Object*> __Subobject;
    
    mutable Vector2f __BuildPosition = {};
    mutable Vector2b __BuildAddSize  = {};
             Object* __Builder = nullptr;
    
    mutable bool __NeedUpdate = true;
    
  _data_public:
    func getSubobject(void) const -> const std::deque<Object*>&;
    func delSubobject(void) -> void;
    
    func setBuildPosition(const Vector2f& value) const -> void;
    func getBuildPosition(void) const _____ -> const Vector2f&;
    
    func setBuildAddSize(const Vector2b& value) const -> void;
    func getBuildAddSize(void) const _____ -> const Vector2b&;
    
    func setBuilder(const Object& value, const std::optional<Vector2f>& buildPosition = std::nullopt,
                                         const std::optional<Vector2b>& buildAddSize  = std::nullopt) -> void;
    func getBuilder(void) const noexcept(false) -> const Object&;
    func delBuilder(void) -> void;
    
  _func_public:
    func needUpdate(bool subobject_needUpdate = false) const -> void;
    
    func build(void) const -> Vector2f;
    
    static func flash(void) -> void;
    
  }Buildable;
}

#ifdef __SFUI_OBJECT__
  #include "../../../src/SFUI/Graphics/Buildable.cpp"
#endif

