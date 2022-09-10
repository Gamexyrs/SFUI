//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "Div.hpp"

namespace sf::ui {
  typedef class TextDiv : public Div {
  protected:
    virtual func draw(RenderTarget& target, RenderStates states) const -> void;
    virtual func update(void) const -> void;
    
    mutable Text _Text;
    
    Vector2f TextDeviat = {       }; // 文字偏移量
    Vector2f TextAdapt  = {1, 1.25}; // 文字大小乘数
    short TextAlign = (Align::T ^ Align::L); // 文字位置
    
  _data_public:
           func setText(const String& str, const Font& font, unsigned size = 30) -> void;
    inline func getText(void) const -> Text& {this->needUpdate(); return this->_Text;}
  
    inline func setTextString(const String& value) -> void {this->_Text.setString(value); this->needUpdate();}
    inline func getTextString(void) const -> const String& __GET__(this->_Text.getString());
  
    inline func setTextDeviat(const Vector2f& value) -> void __SET__(this->TextDeviat, this->needUpdate);
    inline func getTextDeviat(void) const -> const Vector2f& __GET__(this->TextDeviat);

    inline func setTextAdapt(const Vector2f& value) -> void __SET__(this->TextAdapt, this->needUpdate);
    inline func getTextAdapt(void) const -> const Vector2f& __GET__(this->TextAdapt);

    inline func setTextAlign(short value) -> void __SET__(this->TextAlign, this->needUpdate);
    inline func getTextAlign(void) const -> short __GET__(this->TextAlign);

  _func_public:
    func getTextSize(bool Adapted = false) const -> Vector2f;
    
    func reSize(void) -> void; // byText
  
             TextDiv(const BuildFrame& frame = {{}, {}}, unsigned radius = 0);
    virtual ~TextDiv(void) = default;
    
  }TextDiv;
};

#include "../../src/Graphics/TextDiv.cpp"
