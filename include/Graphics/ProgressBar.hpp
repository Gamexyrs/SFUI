//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "TextDiv.hpp"

namespace sf::ui {
  typedef class ProgressBar : public TextDiv {
  protected:
    virtual func draw(RenderTarget& target, RenderStates states) const -> void;
    virtual func update(void) const -> void;
    
    mutable float Progress = 0; /* % */
    
    struct {
      float RunSpeed = 5.f;
      bool Running = true;
    }BusyMode;
    
    mutable Div _Insider;
    
  _data_public:
    inline func getInsider(void) -> Div& {this->needUpdate(); return this->_Insider;}
  
    template<typename Type>
           func setProgress(Type Now, Type Total) -> void;
    inline func setProgress(float value) -> void __SET__(this->Progress, this->needUpdate);
    inline func movProgress(float value) -> void {this->setProgress(this->getProgress() + value); this->needUpdate();}
    inline func getProgress(void) const -> float __GET__((this->Progress > 100) ? 100 : this->Progress);
           func getProgress_String(void) const -> String;
    
    inline func setBusyModeRunning(bool value) -> void __SET__(this->BusyMode.Running, this->needUpdate);
    inline func getBusyModeRunning(void) const -> bool __GET__(this->BusyMode.Running);
  
    inline func setBusyModeRunSpeed(float value) -> void __SET__(this->BusyMode.RunSpeed, this->needUpdate);
    inline func getBusyModeRunSpeed(void) const -> float __GET__(this->BusyMode.RunSpeed);
  
  _func_public:
             ProgressBar(const BuildFrame& frame = {{}, {}}, float radius = 0, bool enableBusyMode = false);
    virtual ~ProgressBar(void) = default;
    
  }ProgressBar;
};

#include "../../src/Graphics/ProgressBar.cpp"
