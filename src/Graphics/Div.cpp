//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  func Div::update(void) const -> void {
    if(this->Builder != nullptr) this->_Base.setPosition(
      this->Builder->getPosition() + this->BuildDeviat + Vector2f(this->BuildWidth  ? this->Builder->getSize().x : 0.f,
                                                                  this->BuildHeight ? this->Builder->getSize().y : 0.f));
    if(!this->Border.Radius
       || !(this->Border.R_RT
       ||   this->Border.R_RB
       ||   this->Border.R_LB
       ||   this->Border.R_LT)
       || this->Border.PointCount == 4) {
      this->_Base.setPointCount(4);
      this->_Base.setPoint(0, {});
      this->_Base.setPoint(2, this->getSize());
      this->_Base.setPoint(1, {this->getSize().x, 0});
      this->_Base.setPoint(3, {0, this->getSize().y});
    } else [[likely]] {
      this->setBorderPointCount(this->Border.PointCount);
      this->_Base.setPointCount(this->Border.PointCount);
      double angleprec = 6.283185308f / this->Border.PointCount;
      for(int i = 0; i < this->_Base.getPointCount(); ++i) {
        if(i <= this->_Base.getPointCount()*0.25) {
          if(!this->Border.R_RT)
            this->_Base.setPoint(i, Vector2f(this->getRoot().x, this->getPosition().y) - this->getPosition());
          else {
            double angle = i * angleprec - 1.570796327f;
            this->_Base.setPoint(i, Vector2f(this->getSize().x - this->Border.Radius * 2 + this->Border.Radius * (std::cos(angle) + 1), this->Border.Radius * (std::sin(angle) + 1)));
          }
        } else if(i <= this->_Base.getPointCount()*0.50) {
          if(!this->Border.R_RB)
            this->_Base.setPoint(i, this->getRoot() - this->getPosition());
          else {
            double angle = i * angleprec - 1.570796327f;
            this->_Base.setPoint(i, Vector2f(this->getSize().x - this->Border.Radius * 2 + this->Border.Radius * (std::cos(angle) + 1), this->getSize().y - this->Border.Radius * 2 + this->Border.Radius * (std::sin(angle) + 1)));
          }
        } else if(i <= this->_Base.getPointCount()*0.75) {
          if(!this->Border.R_LB)
            this->_Base.setPoint(i, Vector2f(this->getPosition().x, this->getRoot().y) - this->getPosition());
          else {
            double angle = i * angleprec - 1.570796327f;
            this->_Base.setPoint(i, Vector2f(this->Border.Radius * (std::cos(angle) + 1), this->getSize().y - this->Border.Radius * 2 + this->Border.Radius * (std::sin(angle) + 1)));
          }
        } else if(i <= this->_Base.getPointCount()*1.00) {
          if(!this->Border.R_LT)
            this->_Base.setPoint(i, {});
          else {
            double angle = i * angleprec - 1.570796327f;
            this->_Base.setPoint(i, Vector2f(this->Border.Radius * (std::cos(angle) + 1), this->Border.Radius * (std::sin(angle) + 1)));
          }
        }
      }
    } this->NeedUpdate = false;
  }
  
  inline func Div::draw(RenderTarget& target, RenderStates states) const -> void {
    if(this->NeedUpdate) this->update(); target.draw(this->_Base, states);
  }
  
  inline func Div::getMaxRadius(void) const -> unsigned {
    return static_cast<unsigned>(fmin(this->getSize().x, this->getSize().y)/2);
  }
  
  inline func Div::operator[] (const String& name) -> bool& {
    this->needUpdate();
         if(name == "Radius_LT") return this->Border.R_LT;
    else if(name == "Radius_LB") return this->Border.R_LB;
    else if(name == "Radius_RT") return this->Border.R_RT;
    else if(name == "Radius_RB") return this->Border.R_RB;
    else return this->Border.R_LT;
  }
  
  Div::Div(const BuildFrame& frame, unsigned radius) : Obj(frame) {
    this->_Base.setOutlineColor(InitColor.Outline[DisplayMode]);
    this->_Base.setFillColor(Color::Transparent);
    this->_Base.setOutlineThickness(1);
    this->setBorderRadius(radius);
  }
};
