//>>> 2021~2025 Gamexyrs© & SFML®

#include "../Object.hpp"

#pragma once

namespace sf::ui {
  typedef interface class Progressable {
  private:
    Object* __Self{nullptr};
    
  protected: Progressable(Object* self) : __Self(self) {}
    virtual ~Progressable(void) = default;
    
    mutable float __Progress{0};
  
  _data_public:
    func setProgress(float current, float total) -> void;
    func setProgress(float)   -> void;
    func setProgress(Percent) -> void;
    func movProgress(float)   -> void;
    func movProgress(Percent) -> void;
    func getProgress(void) const -> float;
#if   (__cplusplus >= 202002L)
    template<typename T = float>
#elif (__cplusplus < 202002L)
    template<typename T>
#endif
    func getProgress(Vector2<T> range) const -> T;
    func strProgress(size_t precision = 0) const -> Percent /* (String) */ ;
  
  } Progressable;
}

#include "../../../../src/SFUI/Graphics/Interface/Progressable.cpp"
