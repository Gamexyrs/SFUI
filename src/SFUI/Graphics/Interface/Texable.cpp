//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  inline func Texable::isTexVisible(void) const -> bool {
    return this->hasTexture() && this->__TexVisible;
  }
  
  inline func Texable::setTexture(Texture* value) -> void {
    if(this->__Tex == value) return;
    if(value != nullptr) this->__Tex_spr.setTexture(*value);
    
    this->__Tex = value;
    this->__Self->needUpdate();
  }
  inline func Texable::hasTexture(void) const -> bool {
    return this->__Tex != nullptr;
  }
  inline func Texable::getTexture(void) const -> Texture* {
    return this->__Tex;
  }
  
  inline func Texable::setTexOriginInCenter(bool value) -> void {
    this->__TexOriginC = value;
  }
  inline func Texable::getTexOriginInCenter(void) const -> bool {
    return this->__TexOriginC;
  }
  
  inline func Texable::setTexVisible(bool value) -> void {
    this->__TexVisible = value;
  }
  inline func Texable::getTexVisible(void) const -> bool {
    return this->__TexVisible;
  }
  
  inline func Texable::setTexDeviat(const Vector2f& value) -> void {
    this->__TexDeviat = value;
    this->__Self->needUpdate();
  }
  inline func Texable::getTexDeviat(void) const -> const Vector2f& {
    return this->__TexDeviat;
  }
  
  inline func Texable::setTexScale(float value) -> void {
    this->__TexScale = {value, value};
    this->__Self->needUpdate();
  }
  inline func Texable::setTexScale(const Vector2f& value) -> void {
    this->__TexScale = value;
    this->__Self->needUpdate();
  }
  inline func Texable::getTexScale(void) const -> const Vector2f& {
    return this->__TexScale;
  }
  
  inline func Texable::setTexRotation(float value) -> void {
    this->__Tex_spr.setRotation(value);
    this->__Self->needUpdate();
  }
  inline func Texable::texRotate(float value) -> void {
    this->__Tex_spr.rotate(value);
    this->__Self->needUpdate();
  }
  inline func Texable::getTexRotation(void) const -> float {
    return this->__Tex_spr.getRotation();
  }
  
  inline func Texable::setTexAlign(const Align& value) -> Vector2f& {
    this->__TexAlign = value;
    this->__Self->needUpdate();
    return this->__TexDeviat;
  }
  inline func Texable::getTexAlign(void) const -> const Align& {
    return this->__TexAlign;
  }
  
  inline func Texable::setTexColor(const Color& value) -> void {
    this->__Tex_spr.setColor(value);
  }
  inline func Texable::getTexColor(void) const -> const Color& {
    return this->__Tex_spr.getColor();
  }
  
  inline func Texable::setTexAutoFit(bool value) -> void {
    this->__TexAutoFit = value;
    this->__Self->needUpdate();
  }
  inline func Texable::getTexAutoFit(void) const -> bool {
    return this->__TexAutoFit;
  }
  
  inline func Texable::getTexSize(void) const -> Vector2f {
    if(this->hasTexture())
         return static_cast<Vector2f>(this->__Tex->getSize()) * this->__Tex_spr.getScale();
    else return{};
  }
}
