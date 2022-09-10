//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline auto ProgressBar::update(void) const -> void {
    this->_Insider.setBorderRadius(this->Border.Radius);
    
    // 繁忙
    if(this->Progress < 0) {
      // 错位纠正
      if(this->_Insider.getPosition().y != this->getPosition().y) {
        this->_Insider.setPosition(this->getPosition());
      }
      // 运行
      if(this->BusyMode.Running) {
        // 出现
        if(this->_Insider.getPosition() == this->getPosition()) {
          if(this->_Insider.getSize().x >= this->getSize().x * 0.2) {
            this->_Insider.move({this->BusyMode.RunSpeed, 0});
          } else {
            this->_Insider["Radius_LT"] = true;
            this->_Insider["Radius_LB"] = true;
            this->_Insider.setSize({this->_Insider.getSize().x + this->BusyMode.RunSpeed, this->getSize().y});
          }
        }
        // 消失
        else if(this->_Insider.getRoot().x >= this->getRoot().x) {
          // 重启
          if(this->_Insider.getPosition().x >= (this->getRoot().x - this->Border.Radius)) {
            this->_Insider["Radius_RT"] = false;
            this->_Insider["Radius_RB"] = false;
            this->_Insider.setPosition(this->getPosition());
            this->_Insider.setSize({});
          } else {
            this->_Insider["Radius_RT"] = true;
            this->_Insider["Radius_RB"] = true;
            this->_Insider.move({this->BusyMode.RunSpeed, 0});
            this->_Insider.setSize({this->_Insider.getSize().x - this->BusyMode.RunSpeed, this->getSize().y});
          }
        } else {
          this->_Insider["Radius_LT"] = false;
          this->_Insider["Radius_LB"] = false;
          this->_Insider["Radius_RT"] = false;
          this->_Insider["Radius_RB"] = false;
          this->_Insider.move({this->BusyMode.RunSpeed, 0});
        }
      }
    }
    // 进度条
    else {
      this->_Insider.setSize({this->getSize().x * (this->Progress / 100), this->getSize().y});
      this->_Insider.setPosition(this->getPosition());
      
      if(this->_Insider.getSize().x > this->Border.Radius && this->_Insider.getSize().x < this->getSize().x - this->Border.Radius) {
        this->_Insider["Radius_RT"] = false;
        this->_Insider["Radius_RB"] = false;
      } else {
        this->_Insider["Radius_RT"] = true;
        this->_Insider["Radius_RB"] = true;
      }
    } this->TextDiv::update();
  }
  
  inline func ProgressBar::draw(RenderTarget& target, RenderStates states) const -> void {
    if(this->NeedUpdate || (this->Progress < 0 && this->BusyMode.Running)) this->update();
    target.draw(this->_Base,    states);
    target.draw(this->_Insider, states);
    if((!this->_Text.getString().isEmpty())) {
      target.draw(this->_Text, states);
    }
  }
  
  template<typename Type>
  inline func ProgressBar::setProgress(Type Now, Type Total) -> void {
    if(Now >= Total) this->Progress = 100;
    else this->Progress = (Now / Total * 100);
  }
  inline func ProgressBar::getProgress_String(void) const -> String {
    if(this->Progress > 100) this->Progress = 100;
    return String(std::to_wstring(static_cast<int>(this->Progress)) + L"%");
  }
  
  ProgressBar::ProgressBar(const BuildFrame& frame, float radius, bool enableBusyMode) : TextDiv(frame, radius) {
    this->_Insider.getBase().setFillColor(Color_Grey);
    this->_Insider.getBase().setOutlineThickness(0);
    this->Progress = (enableBusyMode ? -1 : 0);
    this->TextAlign = Align::C;
  }
};
