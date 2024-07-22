//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "MoveMethod.hpp"

namespace sf::ui {
  class Object;
  typedef interface class Movable {
  protected: Movable(Object* self);
    virtual ~Movable(void) = default;

  public: class MovRegister {
  private:
    Object* __Target{nullptr};
    
    mutable std::queue<Vector2f> __Path{};
    
    bool __Auto{false};
    
  _data_public:
    func setTarget(Object*) -> void;
    func getTarget(void) const -> Object*;
    
    func setPath(const std::vector<Vector2f>&) -> void;
    func getPath(void) const -> std::vector<Vector2f>;
    
    func setAuto(bool) -> void;
    func getAuto(void) const -> bool;
    
  _func_public:
    func apply(const std::vector<Vector2f>& path, bool instead = false) -> void;
    func clear(void) -> void;

    func isEnd(void) const -> bool;
    func next (size_t = 1) const -> bool;
      
  }mov; }Movable;
}

#ifdef __SFUI_OBJECT__
  #include "../../../src/SFUI/Graphics/Movable.cpp"
#endif
