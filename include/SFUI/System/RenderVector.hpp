//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

#include "Renderable.hpp"

namespace sf::ui {
  template<typename T /* cannot to be a ptr */>
  class RenderVector : public std::vector<T>, public Drawable {
  protected:
    func draw(RenderTarget& target, const RenderStates& states) const -> void;
  };
}

#include "../../../src/SFUI/System/RenderVector.cpp"
