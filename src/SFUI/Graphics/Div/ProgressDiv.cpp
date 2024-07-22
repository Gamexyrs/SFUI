//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  ProgressDiv::ProgressDiv(const Vector2f& size, const Object& builder, unsigned radius,
                           const Vector2f& buildPosition, const Vector2b& buildAddSize)
    : TextDiv(size, builder, radius, buildPosition, buildAddSize) {
    this->__Inside.getBase().setFillColor(ColorEx::Grey);
    this->__Inside.getBase().setOutlineThickness(0);
    this->__Inside.setBuilder(*this);
    this->__TextAlign = Align::C;
    
    this->__Inside.__ATTRIBUTE__.__PROTECTED__        = true;
    this->__Inside.__ATTRIBUTE__.__IGNORE_ROTATEAGL__ = true;
    this->         __ATTRIBUTE__.__IGNORE_ROTATEAGL__ = true;
  }
  ProgressDiv::ProgressDiv(const Frame& frame, unsigned radius)
    : TextDiv(frame, radius) {
    this->__Inside.getBase().setFillColor(ColorEx::Grey);
    this->__Inside.getBase().setOutlineThickness(0);
    this->__Inside.setBuilder(*this);
    this->__TextAlign = Align::C;
    
    this->__Inside.__ATTRIBUTE__.__PROTECTED__        = true;
    this->__Inside.__ATTRIBUTE__.__IGNORE_ROTATEAGL__ = true;
    this->         __ATTRIBUTE__.__IGNORE_ROTATEAGL__ = true;
  }
  
  inline func ProgressDiv::draw(RenderTarget& target, const RenderStates& states) const -> void { this->__rendererCheck();
    if(this->requestUpdate() || (this->__Progress < 0 && this->__Busy.__Running)) this->update();
    if(this->mov.getAuto()) this->mov.next();
    if(this->__ATTRIBUTE__.__VISIBLE__ && (this->inView()
                                       || !(__PREDEF_ENABLE_FASTDRAW_SOV__
                                       && !this->__ATTRIBUTE__.__IGNORE_FASTDRAW_SOV__))) {
      if(this->__ATTRIBUTE__.__VISIBLE_BASE__)
        target.draw(this->__Base, states);
      if(this->__ATTRIBUTE__.__VISIBLE_INER__)
        target.draw(this->__Inside, states);
      if(this->__ATTRIBUTE__.__VISIBLE_TEXT__ && !this->__Text.getString().isEmpty())
        target.draw(this->__Text, states);
    }
  }
  
  inline func ProgressDiv::update(void) const -> void {
    this->__Inside.setRadius(this->__Border.__Radius);
    
    // 繁忙
    if(this->__Progress < 0 && this->__Busy.__Running) {
      // 出现
      if(this->__Inside.getBuildPosition() == Vector2f()) {
        if(this->__Inside.getSize().x >= this->getSize().x * 0.2) {
          this->__Inside.move({this->__Busy.__RunSpeed, 0});
        } else {
          this->__Inside.setSize({this->__Inside.getSize().x + this->__Busy.__RunSpeed, this->getSize().y});
          this->__Inside.setRounded(true, Align::L);
        }
      }
      // 消失
      else if(this->__Inside.getRoot().x >= this->getRoot().x) {
        // 重启
        if(this->__Inside.getPosition().x >= (this->getRoot().x - this->__Border.__Radius)) {
          this->__Inside.setRounded(false, Align::R);
          this->__Inside.setBuildPosition({});
          this->__Inside.setSize({});
        } else {
          this->__Inside.setRounded(true, Align::R);
          this->__Inside.move({this->__Busy.__RunSpeed, 0});
          this->__Inside.setSize({this->__Inside.getSize().x - this->__Busy.__RunSpeed, this->getSize().y});
        }
      } else {
        this->__Inside.setRounded(false);
        this->__Inside.move({this->__Busy.__RunSpeed, 0});
      }
    }
    else {
      this->__Inside.setBuildPosition({});
      this->__Inside.setSize({this->getSize().x * (this->__Progress), this->getSize().y});
      this->__Inside.setRounded(!(this->__Inside.getSize().x > this->__Border.__Radius
                               && this->__Inside.getSize().x < this->getSize().x - this->__Border.__Radius), Align::R);
    } this->TextDiv::update();
  }
  
  inline func ProgressDiv::getInside(bool update) const -> Div& {
    if(update) this->needUpdate();
    return this->__Inside;
  }

  inline func ProgressDiv::setProgress(float current, float total) -> void {
    this->__Progress = ((current >= total) ? 1 : (current / total));
    this->needUpdate();
  }
  inline func ProgressDiv::setProgress(float value) -> void {
    this->__Progress = ((value >= 1) ? 1 : value);
    this->needUpdate();
  }
  inline func ProgressDiv::setProgress(Percent value) -> void {
    this->setProgress(this->__PercentToFloat(value));
  }
  inline func ProgressDiv::getProgress(void) const -> float {
    return this->__Progress;
  }
  
  inline func ProgressDiv::setBusyRunning(bool value) -> void {
    this->__Busy.__Running = value;
    this->needUpdate();
  }
  inline func ProgressDiv::getBusyRunning(void) const -> bool {
    return this->__Busy.__Running;
  }

  inline func ProgressDiv::setBusyRunSpeed(float value) -> void {
    this->__Busy.__RunSpeed = value;
    this->needUpdate();
  }
  inline func ProgressDiv::getBusyRunSpeed(void) const -> float {
    return this->__Busy.__RunSpeed;
  }

  inline func ProgressDiv::movProgress(float value) -> void {
    this->setProgress(this->__Progress + value);
  }
  inline func ProgressDiv::movProgress(Percent value) -> void {
    this->movProgress(this->__PercentToFloat(value));
  }
  inline func ProgressDiv::strProgress(size_t precision) const -> String {
    if(!this->__Progress)      return L"0%";
    if( this->__Progress == 1) return L"100%";
    if(!precision) return String{
      std::to_wstring(static_cast<int>(this->__Progress)) + L"%"};
    else {    std::wstringstream sstr;
      sstr << std::setiosflags(std::ios::fixed)
           << std::setprecision(precision) 
           << (this->__Progress * 100);
      return String{sstr.str() + L"%"};
    }
  }
}