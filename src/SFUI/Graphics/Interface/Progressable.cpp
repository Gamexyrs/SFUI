//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  inline func Progressable::setProgress(float current, float total) -> void {
    this->__Progress = ((current >= total) ? 1.0f : (current / total));
    this->__Self->needUpdate();
  }
  inline func Progressable::setProgress(float value) -> void {
    this->__Progress = ((value >= 1) ? 1.0f : value);
    this->__Self->needUpdate();
  }
  inline func Progressable::setProgress(Percent value) -> void {
    this->setProgress(__PercentToFloat(value));
  }
  inline func Progressable::movProgress(float value) -> void {
    this->setProgress(this->__Progress + value);
  }
  inline func Progressable::movProgress(Percent value) -> void {
    this->movProgress(__PercentToFloat(value));
  }
  inline func Progressable::getProgress(void) const -> float {
    return this->__Progress;
  }
#if   (__cplusplus >= 202002L)
    template<typename T = float>
#elif (__cplusplus < 202002L)
    template<typename T>
#endif
  inline func Progressable::getProgress(Vector2<T> range) const -> T {
    return static_cast<T>(this->__Progress * (range.y - range.x) + range.x);
  }
  inline func Progressable::strProgress(size_t precision) const -> Percent {
    if(!this->__Progress)      return L"0%";
    if( this->__Progress == 1) return L"100%";
    if(!precision) return String{
      std::to_wstring(static_cast<int>(this->__Progress * 100)) + L"%"};
    else return Fm::toString(this->__Progress * 100) + L"%";
  }
}
