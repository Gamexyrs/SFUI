//>>> 2021~2022 Gamexyrs© & SFML®

namespace gy {
  auto TDiv::update(void) const -> void { this->Div::update();
    if(!this->Text.getString().isEmpty()) {
      this->Text.setRotation(this->Base.getRotation());
      this->Text.setScale(this->Base.getScale());
      /*
      //setLineFeed
      if(this->AutoInsertLineFeed) {
        sf::String str = this->Text.getString();
        for(std::size_t i = 0; i < this->Text.getString().getSize(); ++i) {
          if(this->Text.findCharacterPos(i).x > this->Size.x) {
            if(!i) break; else { str.insert(i - 1, "\n"); ++i; }
          }
        } this->Text.setString(str);
      }
      */
      // setPosition
      this->Text.setPosition(Pos::getPoint(this->getRect(), this->getTextSize(true), this->TextAlign));
      /**/ if(this->TextAlign == (Align::T ^ Align::L)
      || this->TextAlign == (Align::B ^ Align::L)) [[likely]]
        this->Text.move( this->Border.Radius, 0);
      else if(this->TextAlign == (Align::T ^ Align::R)
      || this->TextAlign == (Align::B ^ Align::R)) [[unlikely]]
        this->Text.move(-this->Border.Radius, 0);
      this->Text.move(this->TextDeviat);
    }
  }
  
  inline auto TDiv::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void {
    this->update(); target.draw(this->Base, states);
    if((!this->Text.getString().isEmpty())) [[likely]] {
      target.draw(this->Text, states);
    }
  }
  
  inline auto TDiv::setText(const sf::String& Str, const sf::Font& Font, unsigned Size, bool ResizeDiv) -> void {
    this->Text.setFont(Font);
    this->Text.setString(Str);
    this->Text.setCharacterSize(Size);
    if(ResizeDiv) [[unlikely]] this->Size = this->getTextSize(true);
  }
  inline auto TDiv::getTextSize(bool Adapted) const -> sf::Vector2f {
    return Format::getSize(this->Text.getGlobalBounds()) * (Adapted ? this->TextAdapt : sf::Vector2f(1, 1));
  }
  
  TDiv::TextDiv(const BuildFrame& Frame, unsigned Radius) : Div(Frame, Radius) {
    this->Text.setFillColor(sf::Color::Black);
  }
};
