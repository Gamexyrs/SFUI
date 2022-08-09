//>>> 2021~2022 Gamexyrs© & SFML®

namespace gy {
  inline auto ProgressBar::update(void) const -> void { this->TDiv::update();
    this->Base.setScale(1, 1); this->Base.setRotation(0);
    this->Insider.Border.Radius = this->Border.Radius;
  
    if(this->BusyMode.Enable) {
      const sf::Vector2f Full_Size = {static_cast<float>(this->Size.x * 0.2), this->Size.y};
      this->Insider.Size.y = Full_Size.y;
      
      if(this->Progress != 0) {
        this->Insider.Size.x = 0;
        this->Progress = 0;
      }
      if(this->Insider.Position.y != this->Position.y) {
        this->Insider.Position = this->Position;
      }
      if(this->BusyMode.isRunning) {
        if(this->Insider.Position == this->Position) {
          if(this->Insider.Size.x >= Full_Size.x) {
            this->Insider.Position.x += this->BusyMode.RunSpeed;
          } else this->Insider.Size.x += this->BusyMode.RunSpeed;
        }
        else if(this->Insider.getRoot().x >= this->getRoot().x) {
          if(this->Insider.Position.x >= this->getRoot().x) {
            this->Insider.Position = this->Position;
            this->Insider.Size = {};
          } else {
            this->Insider.Position.x += this->BusyMode.RunSpeed;
            this->Insider.Size.x     -= this->BusyMode.RunSpeed;
          }
        } else this->Insider.Position.x += this->BusyMode.RunSpeed;
      }
    }
    else {
      if(this->Progress > 100) this->Progress = 100;
      this->Insider.Size = {this->Size.x * (this->Progress / 100), this->Size.y};
      this->Insider.Position = this->Position;
    }
  }
  
  inline auto ProgressBar::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void {
    this->update(); target.draw(this->Base,    states);
                    target.draw(this->Insider, states);
    if((!this->Text.getString().isEmpty())) [[likely]] {
      target.draw(this->Text, states);
    }
  }
  
  inline auto ProgressBar::setInsiderColor(const sf::Color& Color) -> void {
    this->Insider.Base.setFillColor(Color);
  }
  
  inline auto ProgressBar::getProgress(void) const -> sf::String {
    if(this->Progress > 100) this->Progress = 100;
    return sf::String(std::to_wstring(static_cast<int>(this->Progress)) + L"%");
  }
  
  template<typename Type>
  inline auto ProgressBar::setProgress(Type Now, Type Total) -> float {
    if(Now >= Total) this->Progress = 100;
    else this->Progress = Now / Total * 100;
    return this->Progress;
  }
  
  inline auto ProgressBar::start(void) -> void {
    this->BusyMode.isRunning = true;
  }
  inline auto ProgressBar::stop(void) -> void {
    this->BusyMode.isRunning = false;
  }
  
  ProgressBar::ProgressBar(const BuildFrame& Frame, bool BusyMode) : TDiv(Frame, 0) {
    this->Insider.Base.setFillColor(Color::Grey);
    this->Insider.Base.setOutlineThickness(0);
    this->BusyMode.Enable = BusyMode;
    this->TextAlign = Align::C;
  }
};
