//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "Renderable.hpp"

namespace sf::ui {
  typedef class RenderUnity : Drawable {
  public:    RenderUnity(const std::initializer_list<Drawable*>&);
    virtual ~RenderUnity(void) = default;
    
  protected:
    std::vector<Drawable*> __Unity{};
      
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
  
  _func_public:
    func push_back(const std::initializer_list<Drawable*>&) -> void;
    
    func clear(void) -> void;
    
    func size(void) const -> size_t;

  }RenderUnity;
}

#include "../../../src/SFUI/System/RenderUnity.cpp"
