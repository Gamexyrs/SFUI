//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  func TextDiv::update(void) const -> void { this->Div::update();
    if(!this->_Text.getString().isEmpty()) {
      this->_Text.setPosition(sf::getPosition(this->getRect(), this->getTextSize(true), this->TextAlign));
      if(this->Border.Radius) {
        switch(this->TextAlign) {
        case(Align::T ^ Align::L):
        case(Align::B ^ Align::L):
          this->_Text.move( this->Border.Radius, 0); break;
        case(Align::T ^ Align::R):
        case(Align::B ^ Align::R):
          this->_Text.move(-this->Border.Radius, 0); break;
        }
      } this->_Text.move(this->TextDeviat);
    }
  }
  
  inline func TextDiv::draw(RenderTarget& target, RenderStates states) const -> void {
    if(this->NeedUpdate) this->update(); target.draw(this->_Base, states);
    if((!this->_Text.getString().isEmpty())) {
      target.draw(this->_Text, states);
    }
  }
  
  inline func TextDiv::setText(const String& str, const Font& font, unsigned size) -> void {
    this->_Text.setFont(font);
    this->_Text.setString(str);
    this->_Text.setCharacterSize(size);
  }
  
  inline func TextDiv::getTextSize(bool Adapted) const -> Vector2f {
    return Format::getSize(this->_Text.getGlobalBounds()) * (Adapted ? this->TextAdapt : Vector2f(1, 1));
  }
  
  inline func TextDiv::reSize(void) -> void {
    this->setSize(this->getTextSize(true));
  }
  
  TextDiv::TextDiv(const BuildFrame& frame, unsigned radius) : Div(frame, radius) {
    this->_Text.setFillColor(InitColor.Text[DisplayMode]);
  }
};
