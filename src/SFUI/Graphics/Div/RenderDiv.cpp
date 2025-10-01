//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  RenderDiv::RenderDiv(const Vector2f& size, const Object& builder, int radius,
                       const Vector2f& buildPosition, const Vector2b& buildAddSize)
    : Div(size, builder, radius, buildPosition, buildAddSize) {
    this->__pRTx = std::make_unique<RenderTexture>();
    this->__pRTx->create(static_cast<unsigned>(size.x), static_cast<unsigned>(size.y),
      (this->getRenderer() == nullptr) ? ContextSettings{} : this->getRenderer()->getSettings());
    this->__pRTx->setSmooth(true);
  }
  RenderDiv::RenderDiv(const Frame& frame, int radius)
    : Div(frame, radius) {
    this->__pRTx->create(static_cast<unsigned>(frame.size.x), static_cast<unsigned>(frame.size.y),
      (this->getRenderer() == nullptr) ? ContextSettings{} : this->getRenderer()->getSettings());
    this->__pRTx->setSmooth(true);
  }
  
  inline func RenderDiv::draw(RenderTarget& target, const RenderStates& states) const -> void { this->__rendererCheck();
    if(this->mov.getAuto()) this->mov.next();
    if(this->requestUpdate()) this->update();
    if(this->__ATTRIBUTE__.__VISIBLE__ && (this->inView()
                                       || !(__PREDEF_ENABLE_FASTDRAW_SOV__
                                       && !this->__ATTRIBUTE__.__IGNORE_FASTDRAW_SOV__))) {
      if(this->__ATTRIBUTE__.__VISIBLE_BASE__)
        target.draw(this->__Base, states);
      
      this->draw_RTx(target, states);
    }
  }
  
  inline func RenderDiv::draw_RTx(RenderTarget& target, const RenderStates& states) const -> void {
    this->__pRTx->clear(Color::Transparent);
    for(const auto& i : this->__Targets)
       if(i != nullptr) this->__pRTx->draw(*i);
    this->__pRTx->display();
    
    this->__RTs.setTexture(this->__pRTx->getTexture());
    this->__RTs.setPosition(this->getPosition());
    
    target.draw(this->__RTs, states);
  }
  
  inline func RenderDiv::update(void) const -> void {
    this->Div::update();
    
    if(this->__pRTx->getSize() != static_cast<Vector2u>(this->getSize())) {
       this->__pRTx.reset();
       this->__pRTx = std::make_unique<RenderTexture>();
       this->__pRTx->create(static_cast<unsigned>(this->getSize().x), static_cast<unsigned>(this->getSize().y),
         (this->getRenderer() == nullptr) ? ContextSettings{} : this->getRenderer()->getSettings());
       this->__pRTx->setSmooth(true);
    }
  }
  
  inline func RenderDiv::operator +=(Div& __tar) -> void {
    this->__Targets.emplace_back(&__tar);
  }
}
