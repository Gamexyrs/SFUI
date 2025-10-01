//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  MsgDiv::MessageDiv(int radius, const Vector2f& sizeFactor, const Align& align)
    : TexDiv({{}, {_RendererSize * sizeFactor}}, radius) {
    this->__Mask.setFillColor(ColorEx::makeTrs(ColorEx::Grey, 0));
    this->__Mask.setOutlineThickness(0);
    
    this->__Info.setBuilder(*this, Vector2f(50, 110));
    this->__Info.__ATTRIBUTE__.__PROTECTED__ = true;
    this->__Info.setOutlineThickness(0);
    this->__Info.setSize({this->getSize().x
    - this->__Info.getBuildPosition().x * 2.0f, 0.0f});
    
    this->__Text.          setCharacterSize(70);
    this->__Info.getText().setCharacterSize(40);
    
    this->setTextAlign(Align::LT);
    this->setTextDeviat({50, 20});
    
    this->__AlignLock = align;
    this->__ATTRIBUTE__.__IGNORE_ROTATEAGL__ = true;
  }
  
  inline func MsgDiv::draw(RenderTarget& target, const RenderStates& states) const -> void { this->__rendererCheck();
    if(this->mov.getAuto()) this->mov.next();
    if(this->requestUpdate()) this->update();
    if(this->__ATTRIBUTE__.__VISIBLE__ && (this->inView()
                                       || !(__PREDEF_ENABLE_FASTDRAW_SOV__
                                       && !this->__ATTRIBUTE__.__IGNORE_FASTDRAW_SOV__))) {
      if(this->__ATTRIBUTE__.__VISIBLE_MASK__) {
        if(!this->__Pushing) {
          if(this->__Mask.getBase().getFillColor().a > 0) {
           const_cast<Color&>(this->__Mask.getBase().getFillColor()).a -= 10;
          }
        }
        else if(this->__Mask.getBase().getFillColor().a < this->__MaskTrs) {
          const_cast<Color&>(this->__Mask.getBase().getFillColor()).a += 10;
        } target.draw(this->__Mask, states);
      }
      if(this->__Pushing) {
        if(this->__ATTRIBUTE__.__VISIBLE_BASE__)
          target.draw(this->__Base, states);
        if(this->__ATTRIBUTE__.__VISIBLE_TEX__ && this->isTexVisible())
          target.draw(this->__Tex_spr, states);
        if(this->__ATTRIBUTE__.__VISIBLE_TEXT__ && !this->__Text.getString().isEmpty()) {
          target.draw(this->__Info, states);
          target.draw(this->__Text, states);
        }
        for(auto& i : this->__Btn) {
          target.draw(*i);
        }
      }
    }
  }
  inline func MsgDiv::update(void) const -> void { this->TexDiv::update();
    this->__Mask.setSize  (_RendererSize);
    this->__Mask.setCenter(_Renderer.getView().getCenter());
  }
  
  inline func MsgDiv::setTitleTextColor(const Color& value) -> void {
    this->__Text.setFillColor(value);
  }
  inline func MsgDiv::getTitleTextColor(void) const -> const Color& {
    return this->__Text.getFillColor();
  }
  
  inline func MsgDiv::setInfoTextColor(const Color& value) -> void {
    this->__Info.getText().setFillColor(value);
  }
  inline func MsgDiv::getInfoTextColor(void) const -> const Color& {
    return this->__Info.getText().getFillColor();
  }
  
  inline func MsgDiv::setSize(const Vector2f& value, bool reset_InfoDiv) -> void {
    this->TextDiv::setSize(value);
    if(reset_InfoDiv)
      this->__Info.setSize({this->getSize().x
      - this->__Info.getBuildPosition().x * 2.0f, 0.0f});
  }
  
  inline func MsgDiv::getInfo(bool update) const -> TextDiv& {
    if(update) this->needUpdate();
    return const_cast<TextDiv&>(this->__Info);
  }
  
  inline func MsgDiv::setMaskColor(const Color& value) -> void {
    this->__Mask.getBase().setFillColor(ColorEx::makeTrs(value,
    this->__Mask.getBase().getFillColor().a));
    this->__MaskTrs = value.a;
  }
  inline func MsgDiv::getMaskColor(void) const -> Color {
    return ColorEx::makeTrs(this->__Mask.getBase().getFillColor(), this->__MaskTrs);
  }
  
  inline func MsgDiv::getQueueSize(void) const -> size_t {
    return this->__Msg.size();
  }
  
  inline func MsgDiv::pollEvent(const Event& event) -> std::optional<int> {
    if(this->__Pushing) for(auto& i : this->__Btn) {
      if(i->pollEvent_if(event)) {
        this->stopPushing(); return std::stoi(i->getLabel().toAnsiString());
      }
    } return std::nullopt;
  }
  
  inline func MsgDiv::buttonIsDown(void) const -> std::optional<int> {
    if(this->__Pushing) for(auto& i : this->__Btn) {
      if(i->getState() == sf::BtnState::Pressed)
        return std::stoi(i->getLabel().toAnsiString());
    } return std::nullopt;
  }
  
  inline func MsgDiv::stopPushing(bool delMsg) -> void {
    if(!this->__Pushing) return;
    
    if(delMsg) this->__Msg.pop();
    this->__Pushing = false;
    this->__Locked  = false;
  }
  inline func MsgDiv::isPushing(void) const -> bool {
    return this->__Pushing;
  }
  
  inline func MsgDiv::launchQueue(const MsgData& msg, bool push) -> size_t {
    this->__Msg.push(msg); if(push) this->pushQueue();
    return this->getQueueSize();
  }
  inline func MsgDiv::clearQueue(void) -> void {
    std::queue<MsgData>    new_queue;
    std::swap(this->__Msg, new_queue);
  }
  inline func MsgDiv::pushQueue(void) -> void {
    if(!this->__ATTRIBUTE__.__VISIBLE__
     || this->__Pushing
     ||!this->getQueueSize()) return;
     
    if(this->__Msg.front().font == nullptr) {
      if(this->__DefaultFont == nullptr)
        err() << "Undefined to font [= nullptr] (in MessageDiv)" << std::endl;
      else this->__Msg.front().font = this->__DefaultFont;
    }
    
    // Data    处理
    this->__Pushing = true;
    this->__Locked  = true;
    
    // Texts   处理
    this->       setTextString( this->__Msg.front().title);
    this->       setFont      (*this->__Msg.front().font);
    this->__Info.setTextString( this->__Msg.front().info);
    this->__Info.setFont      (*this->__Msg.front().font);
    
    // Buttons 处理
    this->__Btn.clear();
    this->__Btn.reserve(0);
    for(auto& i : this->__Msg.front().btn) {
      std::unique_ptr<PushBtn> new_btn = std::make_unique<PushBtn>(Frame{}, 5);
      new_btn->setText(i.first, *this->__Msg.front().font,
                                 this->__Msg.front().btnTextSize);
      new_btn->setStateColor(Color::Transparent, BtnState::None);
      new_btn->setSize(new_btn->getTextSize() + Vector2f(20, 20));
      new_btn->__ATTRIBUTE__.__ALWAYS_TOUCHABLE__ = true;
      new_btn->__ATTRIBUTE__.__PROTECTED__        = true;
      new_btn->setTextColor(Color{125, 144, 169});
      new_btn->setLabel(std::to_string(i.second));
      new_btn->getBase().setOutlineThickness(0);
      new_btn->setTouchRectScale({1, 2});
      new_btn->setTextAlign(Align::C);
      if(!this->__Btn.size()) {
        new_btn->setBuilder(*this);
        new_btn->align(Align::RB) -= (new_btn->getTextSize() + Vector2f(-10, -10));
      } else {
        new_btn->setBuilder(*this->__Btn.back(), Vector2f{-20 - new_btn->getSize().x, 0});
      } this->__Btn.emplace_back(std::move(new_btn));
    }   this->needUpdate();
  }
}
