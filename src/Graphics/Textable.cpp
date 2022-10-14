//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func Textable::setText(const String& str, const Font& font, unsigned size) -> void {
    this->setFont(font);
    this->setTextString(str);
    this->__Text.setCharacterSize(size);
    this->__Self->needUpdate();
  }
  inline func Textable::getText(void) const -> Text& {
    this->__Self->needUpdate();
    return this->__Text;
  }
  
  inline func Textable::setTextDeviat(const Vector2f& value) -> void {
    this->__TextDeviat = value;
    this->__Self->needUpdate();
  }
  inline func Textable::getTextDeviat(void) const -> const Vector2f& {
    return this->__TextDeviat;
  }

  inline func Textable::setTextAdapt(const Vector2f& value) -> void {
    this->__TextAdapt = value;
    this->__Self->needUpdate();
  }
  inline func Textable::getTextAdapt(void) const -> const Vector2f& {
    return this->__TextAdapt;
  }

  inline func Textable::setTextAlign(short value) -> void {
    this->__TextAlign = value;
    this->__Self->needUpdate();
  }
  inline func Textable::getTextAlign(void) const -> short {
    return this->__TextAlign;
  }
  
  inline func Textable::setTextVisible(bool value) -> void {
    this->__TextVisible = value;
  }
  inline func Textable::getTextVisible(void) const -> bool {
    return this->__TextVisible;
  }
  
  inline func Textable::setFont(const Font& font) -> void {
    this->__Text.setFont(font);
    this->__Self->needUpdate();
  }
  inline func Textable::getFont(void) const ->const Font* {
    return this->__Text.getFont();
  }
  
  inline func Textable::setTextString(const String& value) -> void {
    this->__Text.setString(value);
    this->__Self->needUpdate();
  }
  inline func Textable::getTextString(void) const -> const String& {
    return this->__Text.getString();
  }
    
  inline func Textable::getTextSize(bool adaptedSize) const -> Vector2f {
    return Format::getSize(this->__Text.getGlobalBounds()) * (adaptedSize ? this->__TextAdapt : Vector2f(1, 1));
  }
}
