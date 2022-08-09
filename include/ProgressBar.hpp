//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "TextDiv.hpp"

#warning "__Experimental_Module__"

namespace gy {
  typedef class ProgressBar : public TDiv {
  protected:
    virtual auto update(void) const -> void;
    virtual auto draw(sf::RenderTarget& target, sf::RenderStates states) const -> void;
    
    mutable Div Insider;
    
  _data_public:
    mutable float Progress = 0; /* % */
    struct {
      float RunSpeed = 5;
      bool isRunning = false;
      bool Enable    = false;
    }BusyMode;
  
  _func_public:
    auto setInsiderColor(const sf::Color& Color) -> void;
  
    auto getProgress(void) const -> sf::String;
    template<typename Type>
    auto setProgress(Type Now, Type Total) -> float;
    
    // BusyMode
    auto start(void) -> void;
    auto stop (void) -> void;
  
             ProgressBar(const BuildFrame& Frame = {{}, {}}, bool BusyMode = false);
    virtual ~ProgressBar(void) = default;
    
  }ProgressBar;
};

#include "../src/ProgressBar.cpp"
