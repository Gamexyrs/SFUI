//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  MsgDiv::MessageDiv(unsigned radius, const Vector2f& sizeFactor, const Align& align)
    : TextDiv({{}, {_RendererSize * sizeFactor}}, radius) {
    this->__Mask.getBase().setFillColor({
      ColorEx_TrsGrey.r,
      ColorEx_TrsGrey.g,
      ColorEx_TrsGrey.b,
      0,
    });
    this->__Mask.getBase().setOutlineThickness(0);
    this->__Mask.setSize(_RendererSize);
    
    this->__Info.setBuilder(*this, Vector2f(50, 110));
    this->__Info.__ATTRIBUTE__.__PROTECTED__ = true;
    
    this->setTextAlign(Align::LT);
    this->setTextDeviat({50, 20});
    this->align(align);
  }
  
  inline func MsgDiv::draw(RenderTarget& target, RenderStates states) const -> void {
    if(this->__NeedUpdate) {
      this->update();
    }
    if(this->__Visible) {
      if(this->__MaskVisible) {
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
        if(this->__BaseVisible) {
          target.draw(this->__Base, states);
        }
        if(this->__TextVisible && !this->__Text.getString().isEmpty()) {
          target.draw(this->__Info, states);
          target.draw(this->__Text, states);
        }
        for(auto& i : this->__Btn) {
          target.draw(*i);
        }
      }
    }
  }
  inline func MsgDiv::update(void) const -> void { this->TextDiv::update();
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
  
  inline func MsgDiv::setMaskColor(const Color& value) -> void {
    this->__Mask.getBase().setFillColor({
      value.r,
      value.g,
      value.b,
      this->__Mask.getBase().getFillColor().a,
    });
    this->__MaskTrs = value.a;
  }
  inline func MsgDiv::getMaskColor(void) const -> Color {
    return {
      this->__Mask.getBase().getFillColor().r,
      this->__Mask.getBase().getFillColor().g,
      this->__Mask.getBase().getFillColor().b,
      this->__MaskTrs,
    };
  }
  
  inline func MsgDiv::getQueueSize(void) const -> size_t {
    return this->__Msg.size();
  }
  
  inline func MsgDiv::pollEvent(const Event& event) -> std::optional<int> {
    if(this->__Pushing) for(auto& i : this->__Btn) {
      if(i->pollEvent_if(event)) {
        this->stopPushing(); return std::stoi(i->getTag().toAnsiString());
      }
    } return std::nullopt;
  }
  
  inline func MsgDiv::stopPushing(bool delMsg) -> void {
    if(!this->__Pushing) return;
    
    if(delMsg) this->__Msg.pop();
    this->__Pushing = false;
    this->__Locked  = false;
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
    if(!this->__Visible
     || this->__Pushing
     ||!this->getQueueSize()) return;
     
    if(this->__Msg.front().font == nullptr) {
       this->__Msg.front().font = this->__DefaultFont;
    }
    
    // Data    处理
    this->__Pushing = true;
    this->__Locked  = true;
    
    // Texts   处理
    this->       setText(this->__Msg.front().title, *this->__Msg.front().font, 70);
    this->__Info.setText(this->__Msg.front().info,  *this->__Msg.front().font, 40);
    
    // Buttons 处理
    this->__Btn.clear();
    this->__Btn.reserve(0);
    for(auto& i : this->__Msg.front().btn) {
      std::unique_ptr<PushBtn> new_btn(new PushBtn({{}, {150, 50}}, 5));
        new_btn->setText(i.first, *this->__Msg.front().font, 35);
        new_btn->setStateColor(Color::Transparent, BtnState::None);
        new_btn->setSize({new_btn->getTextSize().x + 20, new_btn->getSize().y});
        new_btn->__ATTRIBUTE__.__ALWAYS_TOUCHABLE__ = true;
        new_btn->__ATTRIBUTE__.__PROTECTED__ = true;
        new_btn->setTag(std::to_string(i.second));
        new_btn->getBase().setOutlineThickness(0);
        new_btn->setTextAlign(Align::C);
        if(!this->__Btn.size()) {
          new_btn->setBuilder(*this);
          new_btn->align(Align::RB) -= (new_btn->getTextSize() + Vector2f(-10, -10));
        } else {
          new_btn->setBuilder(*this->__Btn[this->__Btn.size() - 1],
                     Vector2f(-53 - new_btn->getTextSize().x, 0));
        }
      this->__Btn.push_back(std::move(new_btn));
    } this->needUpdate(true);
  }
}
