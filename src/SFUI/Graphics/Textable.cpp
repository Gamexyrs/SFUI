//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func Textable::lineBreak(void) const -> String {
    if(!this->__Text.getString().isEmpty()) {
      String ori_str = this->__Text.getString();
      String tmp_str = this->__Text.getString();
      for(size_t i = 0; i < tmp_str.getSize(); ++i) {
        if(this->__Text.getFont()->getGlyph(this->__Text.getString()[i],
                                            this->__Text.getCharacterSize(),
        /*                               */ this->__Text.getStyle() & Text::Bold,
                                            this->__Text.getOutlineThickness())
        .advance + this->__Text.findCharacterPos(i).x - this->__Text.getPosition().x
        >= this->__Self->getSize().x) {
           tmp_str.insert(i, L"\n"); this->__Text.setString(tmp_str);
        }
      } this->__Text.setString(ori_str); return tmp_str;
    }                                    return L"";
  }
  
  
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

  inline func Textable::setTextAlign(const Align& value) -> void {
    this->__TextAlign = value;
    this->__Self->needUpdate();
  }
  inline func Textable::getTextAlign(void) const -> const Align& {
    return this->__TextAlign;
  }
  
  inline func Textable::setFont(const Font& font) -> void {
    this->__Text.setFont(font);
    this->__Self->needUpdate();
  }
  inline func Textable::getFont(void) const ->const Font* {
    return this->__Text.getFont();
  }
  
  inline func Textable::setTextColor(const Color& value) -> void {
    this->__Text.setFillColor(value);
    this->__Self->needUpdate();
  }
  inline func Textable::getTextColor(void) const -> const Color& {
    return this->__Text.getFillColor();
  }
  
  inline func Textable::setTextString(const String& value) -> void {
    this->__Text.setString(value);
    this->__Self->needUpdate();
  }
  inline func Textable::getTextString(void) const -> const String& {
    return this->__Text.getString();
  }
    
  inline func Textable::getTextSize(bool adaptedSize) const -> Vector2f {
    return Fm::getSize(this->__Text.getGlobalBounds()) * (adaptedSize ? this->__TextAdapt : Vector2f(1, 1));
  }
}
