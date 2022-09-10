//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once
#include <deque>

namespace sf::ui {
  class Object;
  
  typedef class Buildable {
    Object* Self = nullptr;
  
  protected: Buildable(Object* self) : Self(self) {}
    virtual ~Buildable(void) = default;
    
    func followerNeedUpdate(void) const -> void;
    
    Object* Builder = nullptr;
    bool BuildWidth  = false;
    bool BuildHeight = false;
    Vector2f BuildDeviat = {};
    
    std::deque<Object*> Follower;
    
  _data_public:
    
  _func_public:
    inline func getFollowerList(void) -> const std::deque<Object*>& __GET__(this->Follower);
  
    func setBuilder(  Object& builder,  const Vector2f& deviat, bool cW = false, bool cH = false) -> void;
    func setBuilder(/*without builder*/ const Vector2f& deviat, bool cW = false, bool cH = false) -> void;
    func getBuilder(void) const -> Object&;
    func delBuilder(void) -> void;
    
  }Buildable;
};
