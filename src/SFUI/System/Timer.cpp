//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  Timer::Timer(const Time& value, bool start) : __Time(value) {
    Timer::Timer_Group.emplace_back(this);
    if(start) this->start();
  }
  
  Timer::~Timer(void) {
    for(auto i = Timer::Timer_Group.begin(); i != Timer::Timer_Group.end(); ++i) if(*i == this) { Timer::Timer_Group.erase(i); return; }
  }
  
  inline func Timer::update(void) -> void {
    this->__Time += this->__Clock.restart() * this->__SpeedFactor;
  }
  
  inline func Timer::getTime_format(void) -> Time_format {
    if(this->__Running) this->update();
    size_t __s{static_cast<size_t>(this->__Time.asSeconds())};
    size_t __h{static_cast<size_t>(__s / 3600)}; __s %= 3600;
    return Time_format{.h= __h, .m= static_cast<size_t>(__s / 60), .s= __s % 60};
  }
  inline func Timer::getTime(void) -> Time {
    if(this->__Running) this->update();
    return this->__Time;
  }
  inline func Timer::setTime(const Time& value) -> void {
    this->__Time = value;
  }
  
  inline func Timer::getSpeedFactor(void) -> float {
    return this->__SpeedFactor;
  }
  inline func Timer::setSpeedFactor(float value) -> void {
    this->__SpeedFactor = value;
  }
  
  inline func Timer::isRunning(void) const -> bool {
    return this->__Running;
  }
  
  inline func Timer::toString(bool __fill, std::wstring __sepr) -> String {
    auto __data{this->getTime_format()};
    return
      String((__fill && __data.h < 10) ? L"0" : L"") + std::to_wstring(__data.h) + __sepr
          + ((__fill && __data.m < 10) ? L"0" : L"") + std::to_wstring(__data.m) + __sepr
          + ((__fill && __data.s < 10) ? L"0" : L"") + std::to_wstring(__data.s);
  }
  
  inline func Timer::reset(void) -> Time {
    this->__Running = false;
    return this->restart();
  }
  inline func Timer::restart(void) -> Time {
    const Time& __tempTime{this->getTime()};
    this->__Time = Time::Zero;
    return __tempTime;
  }
  inline func Timer::start(void) -> Time {
    if(!this->__Running) {
        this->__Running = true;
        this->__Clock.restart();
    } return this->getTime();
  }
  inline func Timer::stop(void) -> Time {
    if(this->__Running) {
       this->__Running = false;
       this->update();
    } return this->getTime();
  }
  
  inline func Timer::all_reset(void) -> size_t {
    for(auto& i : Timer::Timer_Group) i->reset();
    return Timer::Timer_Group.size();
  }
  
  inline func Timer::all_restart(void) -> size_t {
    for(auto& i : Timer::Timer_Group) i->restart();
    return Timer::Timer_Group.size();
  }
  
  inline func Timer::all_start(void) -> size_t {
    for(auto& i : Timer::Timer_Group) i->start();
    return Timer::Timer_Group.size();
  }
  
  inline func Timer::all_start_if_noZero(void) -> size_t {
    for(auto& i : Timer::Timer_Group) if(i->getTime() != Time::Zero) i->start();
    return Timer::Timer_Group.size();
  }
  
  inline func Timer::all_stop(void) -> size_t {
    for(auto& i : Timer::Timer_Group) i->stop();
    return Timer::Timer_Group.size();
  }
  
  inline func Timer::operator+=(Time value) -> void {
    this->__Time += value;
  }
  inline func Timer::operator-=(Time value) -> void {
    if(this->__Time <= value)
       this->__Time = Time::Zero;
    else this->__Time -= value;
  }
}
