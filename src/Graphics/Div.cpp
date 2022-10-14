//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  Div::Div(const Vector2f& size, const Object& builder, unsigned radius,
           const Vector2f& buildPosition, const Vector2b& buildAddSize)
    : Obj(size, builder, buildPosition, buildAddSize) {
    this->__Base.setOutlineColor(Color::Black);
    this->__Base.setFillColor(Color::White);
    this->__Base.setOutlineThickness(1);
    this->setRadius(radius);
  }
  Div::Div(const Frame& frame, unsigned radius)
    : Obj(frame) {
    this->__Base.setOutlineColor(Color::Black);
    this->__Base.setFillColor(Color::White);
    this->__Base.setOutlineThickness(1);
    this->setRadius(radius);
  }

  inline func Div::draw(RenderTarget& target, RenderStates states) const -> void { this->__rendererCheck();
    if(this->__NeedUpdate) {
      this->update();
    }
    if(this->__Visible) {
      if(this->__BaseVisible) {
        target.draw(this->__Base, states);
      }
    }
  }
  
  inline func Div::update(void) const -> void {
    this->__Base.setPosition(this->build());
    if(this->__Border.__PointCount == 4
       || !this->__Border.__Radius
       || !(this->__Border.__Rounded_RT
       ||   this->__Border.__Rounded_RB
       ||   this->__Border.__Rounded_LB
       ||   this->__Border.__Rounded_RB)) {
      this->__Base.setPointCount(4);
      this->__Base.setPoint(0, {});
      this->__Base.setPoint(2, this->getSize());
      this->__Base.setPoint(1, {this->getSize().x, 0});
      this->__Base.setPoint(3, {0, this->getSize().y});
    } else {
      this->__Base.setPointCount(this->__Border.__PointCount);
      double angleprec = 6.283185308f / this->__Border.__PointCount;
      for(int i = 0; i < this->__Base.getPointCount(); ++i) {
        if(i <= this->__Base.getPointCount()*0.25) {
          if(!this->__Border.__Rounded_RT)
            this->__Base.setPoint(i, Vector2f(this->getRoot().x, this->getPosition().y) - this->getPosition());
          else {
            double angle = i * angleprec - 1.570796327f;
            this->__Base.setPoint(i, Vector2f(this->getSize().x - this->__Border.__Radius * 2 + this->__Border.__Radius * (std::cos(angle) + 1), this->__Border.__Radius * (std::sin(angle) + 1)));
          }
        } else if(i <= this->__Base.getPointCount()*0.50) {
          if(!this->__Border.__Rounded_RB)
            this->__Base.setPoint(i, this->getRoot() - this->getPosition());
          else {
            double angle = i * angleprec - 1.570796327f;
            this->__Base.setPoint(i, Vector2f(this->getSize().x - this->__Border.__Radius * 2 + this->__Border.__Radius * (std::cos(angle) + 1), this->getSize().y - this->__Border.__Radius * 2 + this->__Border.__Radius * (std::sin(angle) + 1)));
          }
        } else if(i <= this->__Base.getPointCount()*0.75) {
          if(!this->__Border.__Rounded_LB)
            this->__Base.setPoint(i, Vector2f(this->getPosition().x, this->getRoot().y) - this->getPosition());
          else {
            double angle = i * angleprec - 1.570796327f;
            this->__Base.setPoint(i, Vector2f(this->__Border.__Radius * (std::cos(angle) + 1), this->getSize().y - this->__Border.__Radius * 2 + this->__Border.__Radius * (std::sin(angle) + 1)));
          }
        } else if(i <= this->__Base.getPointCount()*1.00) {
          if(!this->__Border.__Rounded_LT)
            this->__Base.setPoint(i, {});
          else {
            double angle = i * angleprec - 1.570796327f;
            this->__Base.setPoint(i, Vector2f(this->__Border.__Radius * (std::cos(angle) + 1), this->__Border.__Radius * (std::sin(angle) + 1)));
          }
        }
      }
    } this->__NeedUpdate = false;
  }
  
  inline func Div::setRounded(bool value, const std::optional<Align>& corner) const -> void {
    this->needUpdate();
    if(corner.has_value()) switch(corner.value()) {
      case(Align::C):
        this->__Border.__Rounded_LT = value;
        this->__Border.__Rounded_LB = value;
        this->__Border.__Rounded_RT = value;
        this->__Border.__Rounded_RB = value;
        return;
      case(Align::L):
        this->__Border.__Rounded_LT = value;
        this->__Border.__Rounded_LB = value;
        return;
      case(Align::R):
        this->__Border.__Rounded_RT = value;
        this->__Border.__Rounded_RB = value;
        return;
      case(Align::T):
        this->__Border.__Rounded_LT = value;
        this->__Border.__Rounded_RT = value;
        return;
      case(Align::B):
        this->__Border.__Rounded_LB = value;
        this->__Border.__Rounded_RB = value;
        return;
      case(Align::LT):
        this->__Border.__Rounded_LT = value; return;
      case(Align::LB):
        this->__Border.__Rounded_LB = value; return;
      case(Align::RT):
        this->__Border.__Rounded_RT = value; return;
      case(Align::RB):
        this->__Border.__Rounded_RB = value; return;
    } else {
      this->__Border.__Rounded_LT = value;
      this->__Border.__Rounded_LB = value;
      this->__Border.__Rounded_RT = value;
      this->__Border.__Rounded_RB = value;
    }
  }
  inline func Div::getRounded(const Align& corner) const -> bool {
    switch(corner) {
      case(Align::C):
        return this->__Border.__Rounded_LT && this->__Border.__Rounded_LB
            && this->__Border.__Rounded_LB && this->__Border.__Rounded_RB;
      case(Align::L):
        return this->__Border.__Rounded_LT && this->__Border.__Rounded_LB;
      case(Align::R):
        return this->__Border.__Rounded_RT && this->__Border.__Rounded_RB;
      case(Align::T):
        return this->__Border.__Rounded_LT && this->__Border.__Rounded_RT;
      case(Align::B):
        return this->__Border.__Rounded_LB && this->__Border.__Rounded_RB;
      case(Align::LT):
        return this->__Border.__Rounded_LT;
      case(Align::LB):
        return this->__Border.__Rounded_LB;
      case(Align::RT):
        return this->__Border.__Rounded_RT;
      case(Align::RB):
        return this->__Border.__Rounded_RB;
    }
  }
  
  inline func Div::setPointCount(unsigned value) -> void {
    this->__Border.__PointCount = ((value >= __MIN_POINTCOUNT__) ? value : 4);
    this->needUpdate();
  }
  inline func Div::getPointCount(void) const -> unsigned {
    return this->__Border.__PointCount;
  }
  
  inline func Div::setRadius(unsigned value) const -> void {
    this->__Border.__Radius = ((value <= this->getMaxRadius()) ? value : this->getMaxRadius());
    this->needUpdate();
  }
  inline func Div::getRadius(void) const -> unsigned {
    return this->__Border.__Radius;
  }
  
  inline func Div::getMaxRadius(void) const -> unsigned {
    return static_cast<unsigned>(fmin(this->getSize().x, this->getSize().y)/2);
  }
}
