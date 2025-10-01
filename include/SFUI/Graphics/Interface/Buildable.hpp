//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

namespace sf::ui {
  class Object;
  typedef interface class Buildable {
  private:
    Object* __Self{nullptr};
  
  protected: Buildable(Object* self);
    virtual ~Buildable(void);
    
    static inline std::deque<Object*> __RegisteredObject{};
    
    mutable Vector2f __BuildPosition{};
    mutable Vector2b __BuildAddSize {};
    
 // std::vector<Object*> __Subobject{};
                Object*  __Builder{nullptr};
    
    mutable bool __NeedUpdate{true};
    
  _data_public:
    func setBuildPosition_Global(const Vector2f&) const -> void;
    func setBuildPosition(const Vector2f&) const -> void;
    func getBuildPosition(void) const -> const Vector2f&;
    
    func setBuildAddSize(const Vector2b&) const -> void;
    func getBuildAddSize(void) const -> const Vector2b&;
    
    func setBuilder(Object& value, const std::optional<Vector2f>& buildPosition = std::nullopt,
                                   const std::optional<Vector2b>& buildAddSize  = std::nullopt) -> void;
    func getBuilder(void) const -> Object*;
    func delBuilder(void) -> void;
    
  _func_public:
    func setPerSize  (const Percent& = "100%") -> void;
    func setPerWidth (const Percent& = "100%") -> void;
    func setPerHeight(const Percent& = "100%") -> void;
    
    func needUpdate(void) const -> void;
    
    func build(void) const -> Vector2f;
    
    static func flash(void) -> void;
    
  }Buildable;
}

#ifdef __SFUI_OBJECT__
  #include "../../../../src/SFUI/Graphics/Interface/Buildable.cpp"
#endif

