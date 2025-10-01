//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

namespace sf::ui {
  typedef class Timer {
  public:    Timer(const Time& = Time::Zero, bool start = false);
    virtual ~Timer(void);
    
  protected:
    inline static std::vector<Timer*> Timer_Group{};
  
    Clock __Clock{};
    Time __Time{};
    struct Time_format{ size_t h{0}; size_t m{0}; size_t s{0}; };
    
    float __SpeedFactor{1.00f};
    bool __Running{false};
    
    func update(void) -> void;
    
  _data_public:
    func getTime_format(void) -> Time_format;
    func getTime(void) -> Time;
    func setTime(const Time&) -> void;
    
    func getSpeedFactor(void) -> float;
    func setSpeedFactor(float) -> void;
    
    func isRunning(void) const -> bool;
  
  _func_public:
    func toString(bool __fill = true, std::wstring __sper = L":") -> String;
    
    func reset(void) -> Time;
    func restart(void) -> Time;
    func start(void) -> Time;
    func stop(void) -> Time;
    
    static func all_reset(void) -> size_t;
    static func all_restart(void) -> size_t;
    static func all_start_if_noZero(void) -> size_t;
    static func all_start(void) -> size_t;
    static func all_stop(void) -> size_t;
    
    func operator+= (Time) -> void;
    func operator-= (Time) -> void;
  } Timer;
}

#include "../../../src/SFUI/System/Timer.cpp"
