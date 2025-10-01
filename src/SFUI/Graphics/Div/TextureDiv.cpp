//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  TexDiv::TextureDiv(const Vector2f& size, const Object& builder, int radius,
                     const Vector2f& buildPosition, const Vector2b& buildAddSize)
  : TextDiv(size, builder, radius, buildPosition, buildAddSize), Texable(this) {}
  TexDiv::TextureDiv(const Frame& frame, int radius)
  : TextDiv(frame, radius), Texable(this) {}
  
  inline func TexDiv::draw(RenderTarget& target, const RenderStates& states) const -> void { this->__rendererCheck();
    if(this->mov.getAuto()) this->mov.next();
    if(this->requestUpdate()) this->update();
    if(this->__ATTRIBUTE__.__VISIBLE__ && (this->inView()
                                       || !(__PREDEF_ENABLE_FASTDRAW_SOV__
                                       && !this->__ATTRIBUTE__.__IGNORE_FASTDRAW_SOV__))) {
      if(this->__ATTRIBUTE__.__VISIBLE_BASE__)
        target.draw(this->__Base, states);
      if(this->__ATTRIBUTE__.__VISIBLE_TEX__ && this->isTexVisible())
        target.draw(this->__Tex_spr, states);
      if(this->__ATTRIBUTE__.__VISIBLE_TEXT__ && !this->__Text.getString().isEmpty())
        target.draw(this->__Text, states);
    }
  }

  inline func TexDiv::update_tex(void) const -> void {
    if(this->hasTexture()) {
      // Scale
      this->__Tex_spr.setScale({1, 1});
      if(this->__TexAutoFit) {
        const float __fit_factor{
        std::fmin(this->getSize().x / this->getTexSize().x,
                  this->getSize().y / this->getTexSize().y)};
        this->__Tex_spr.setScale({__fit_factor, __fit_factor});
      } this->__Tex_spr.scale(this->__TexScale);
      
      // Rot
      if(!this->__ATTRIBUTE__.__IGNORE_ROTATEAGL__ && !this->__Tex_spr.getRotation())
          this->__Tex_spr.setRotation(this->__Base.getRotation());
      if(this->__TexOriginC)
         this->__Tex_spr.setOrigin(this->getTexSize() / this->__TexScale / 2.0f);
      
      // Pos
      this->__Tex_spr.setPosition(::sf::ui::align(this->getTexSize(), this->getRect(), this->__TexAlign));
      if(this->__Border.__Radius) {
        switch(this->__TexAlign) {
        case(Align::TL): case(Align::BL): case(Align::L):
          this->__Tex_spr.move({static_cast<float>(      this->__Border.__Radius),  0}); break;
        case(Align::TR): case(Align::BR): case(Align::R):
          this->__Tex_spr.move({static_cast<float>(-fabs(this->__Border.__Radius)), 0}); break;
        default: break;
        }
      }
      this->__Tex_spr.move(this->__TexDeviat + this->__Tex_spr.getOrigin());
    }
  }
  
  inline func TexDiv::update(void) const -> void {
    this->TextDiv::update();
    this->update_tex();
  }
  
  inline func TexDiv::resizeByTex(void) -> void {
    this->setSize(this->getTexSize());
    this->needUpdate();
  }
  
  inline func TexDiv::inView(void) const -> bool {
    return (this->getRect()                   + FloatRect{{}, {1, 1}}).intersects(this->getViewRect())
        || (this->__Text   .getGlobalBounds() + FloatRect{{}, {1, 1}}).intersects(this->getViewRect())
        || (this->__Tex_spr.getGlobalBounds() + FloatRect{{}, {1, 1}}).intersects(this->getViewRect())
        ||  this->__ATTRIBUTE__.__IGNORE_FASTDRAW_SOV__;
  }
}
