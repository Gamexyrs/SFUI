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

  inline func Div::draw(RenderTarget& target, const RenderStates& states) const -> void { this->__rendererCheck();
    if(this->requestUpdate()) this->update();
    if(this->mov.getAuto()) this->mov.next();
    if(this->__ATTRIBUTE__.__VISIBLE__ && (this->inView()
                                       || !(__PREDEF_ENABLE_FASTDRAW_SOV__
                                       && !this->__ATTRIBUTE__.__IGNORE_FASTDRAW_SOV__))) {
      if(this->__ATTRIBUTE__.__VISIBLE_BASE__)
        target.draw(this->__Base, states);
    }
  }
  
  inline func Div::update(void) const -> void {
    if(this->__ATTRIBUTE__.__IGNORE_ROTATEAGL__) {
       this->__Base.setRotation(0);
    }  this->setPosition(this->build());
    if(this->__Border.__PointCount == 4
       || (!this->inView()
       && (__PREDEF_ENABLE_FASTDRAW_SOV__
       && ! this->__ATTRIBUTE__.__IGNORE_FASTDRAW_SOV__))
       || ! this->__Border.__Radius
       || !(this->__Border.__Rounded_RT
       ||   this->__Border.__Rounded_RB
       ||   this->__Border.__Rounded_LB
       ||   this->__Border.__Rounded_LT)) {
      this->__Base.setPointCount(4);
      this->__Base.setPoint(0, {});
      this->__Base.setPoint(2, this->getSize());
      this->__Base.setPoint(1, {this->getSize().x, 0});
      this->__Base.setPoint(3, {0, this->getSize().y});
    } else if(this->getMaxRadius() != 0) {
      unsigned ori_radius{this->__Border.__Radius};
                          this->__Border.__Radius = std::fmin(this->__Border.__Radius, this->getMaxRadius());
      this->__Base.setPointCount(this->__Border.__PointCount);
      float angleprec{static_cast<float>(M_PI * 2 / this->__Border.__PointCount)};
      for(size_t i{0}; i < this->__Base.getPointCount(); ++i) {
        if(i <= this->__Base.getPointCount() * 0.25f) {
          if(!this->__Border.__Rounded_RT)
            this->__Base.setPoint(i, Vector2f{this->getRoot().x, this->getPosition().y} - this->getPosition());
          else {
            float angle{static_cast<float>(i * angleprec - M_PI/2)};
            this->__Base.setPoint(i, Vector2f{this->getSize().x - this->__Border.__Radius * 2.0f + this->__Border.__Radius * (std::cos(angle) + 1.0f),
                                              this->__Border.__Radius * (std::sin(angle) + 1.0f)});
          }
        } else if(i <= this->__Base.getPointCount()*0.50) {
          if(!this->__Border.__Rounded_RB)
            this->__Base.setPoint(i, this->getRoot() - this->getPosition());
          else {
            float angle{static_cast<float>(i * angleprec - M_PI/2)};
            this->__Base.setPoint(i, Vector2f{this->getSize().x - this->__Border.__Radius * 2 + this->__Border.__Radius * (std::cos(angle) + 1.0f),
                                              this->getSize().y - this->__Border.__Radius * 2 + this->__Border.__Radius * (std::sin(angle) + 1.0f)});
          }
        } else if(i <= this->__Base.getPointCount()*0.75) {
          if(!this->__Border.__Rounded_LB)
            this->__Base.setPoint(i, Vector2f(this->getPosition().x, this->getRoot().y) - this->getPosition());
          else {
            float angle{static_cast<float>(i * angleprec - M_PI/2)};
            this->__Base.setPoint(i,                   Vector2f{this->__Border.__Radius * (std::cos(angle) + 1.0f),
              this->getSize().y - this->__Border.__Radius * 2 + this->__Border.__Radius * (std::sin(angle) + 1.0f)});
          }
        } else if(i <= this->__Base.getPointCount()*1.00) {
          if(!this->__Border.__Rounded_LT)
            this->__Base.setPoint(i, {});
          else {
            float angle{static_cast<float>(i * angleprec - M_PI/2)};
            this->__Base.setPoint(i, Vector2f{this->__Border.__Radius * (std::cos(angle) + 1.0f),
                                              this->__Border.__Radius * (std::sin(angle) + 1.0f)});
          }
        }
      } this->__Border.__Radius = ori_radius;
    } if(this->__AlignLock.has_value()) {
         this->align(this->__AlignLock.value());
    } this->__NeedUpdate = false;
  }
  
  inline func Div::setRounded_List(const std::vector<bool>& value) const -> void {
    if(value.size() < 4) return;
    this->__Border.__Rounded_LT = value.at(0);
    this->__Border.__Rounded_RT = value.at(1);
    this->__Border.__Rounded_LB = value.at(2);
    this->__Border.__Rounded_RB = value.at(3);
  }
  inline func Div::getRounded_List(void) const -> std::vector<bool> {
    return{this->__Border.__Rounded_LT,
           this->__Border.__Rounded_RT,
           this->__Border.__Rounded_LB,
           this->__Border.__Rounded_RB};
  }
  inline func Div::setRounded(bool value, const Align& corner) const -> void {
    this->needUpdate();
    switch(corner) {
      case(Align::L):  this->__Border.__Rounded_LT = value;
                       this->__Border.__Rounded_LB = value; return;
      case(Align::R):  this->__Border.__Rounded_RT = value;
                       this->__Border.__Rounded_RB = value; return;
      case(Align::T):  this->__Border.__Rounded_LT = value;
                       this->__Border.__Rounded_RT = value; return;
      case(Align::B):  this->__Border.__Rounded_LB = value;
                       this->__Border.__Rounded_RB = value; return;
      case(Align::LT): this->__Border.__Rounded_LT = value; return;
      case(Align::LB): this->__Border.__Rounded_LB = value; return;
      case(Align::RT): this->__Border.__Rounded_RT = value; return;
      case(Align::RB): this->__Border.__Rounded_RB = value; return;
      default:
        this->__Border.__Rounded_LT = value;
        this->__Border.__Rounded_LB = value;
        this->__Border.__Rounded_RT = value;
        this->__Border.__Rounded_RB = value;
    }
  }
  inline func Div::getRounded(const Align& corner) const -> bool {
    switch(corner) {
      case(Align::C):  return this->__Border.__Rounded_LT && this->__Border.__Rounded_LB
                           && this->__Border.__Rounded_LB && this->__Border.__Rounded_RB;
      case(Align::L):  return this->__Border.__Rounded_LT && this->__Border.__Rounded_LB;
      case(Align::R):  return this->__Border.__Rounded_RT && this->__Border.__Rounded_RB;
      case(Align::T):  return this->__Border.__Rounded_LT && this->__Border.__Rounded_RT;
      case(Align::B):  return this->__Border.__Rounded_LB && this->__Border.__Rounded_RB;
      case(Align::LT): return this->__Border.__Rounded_LT;
      case(Align::LB): return this->__Border.__Rounded_LB;
      case(Align::RT): return this->__Border.__Rounded_RT;
      case(Align::RB): return this->__Border.__Rounded_RB;
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
    this->__Border.__Radius = value;
    this->needUpdate();
  }
  inline func Div::getRadius(void) const -> unsigned {
    return this->__Border.__Radius;
  }
  
  inline func Div::getRealRadius(void) const -> unsigned {
    return std::fmin(this->__Border.__Radius, this->getMaxRadius());
  }
  inline func Div::getMaxRadius(void) const -> unsigned {
    return static_cast<unsigned>(std::fmin(this->getSize().x, this->getSize().y)/2);
  }
}
