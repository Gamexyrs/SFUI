//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "Object.hpp"

#define __V2CJK__ {1.0f, 1.25}

namespace sf::ui {
  typedef interface class Textable {
  private:
    Object* __Self = nullptr;
  
  protected: Textable(Object* self) : __Self(self) {}
    virtual ~Textable(void) = default;
    
    mutable Text __Text;
    
    mutable bool __TextUpdate = false;
    
    Vector2f __TextDeviat = {};
    Align    __TextAlign  = Align::TL;
    Vector2f __TextAdapt  = __V2CJK__;
    
    func lineBreak(void) const -> String;
    
  _data_public:
    func setText(const String& str, const Font& font, unsigned size = 30) -> void;
    func getText(bool update = true) const -> Text&;
  
    func setTextDeviat(const Vector2f& value) -> void;
    func getTextDeviat(void) const -> const Vector2f&;

    func setTextAdapt(const Vector2f& value) -> void;
    func getTextAdapt(void) const -> const Vector2f&;

    func setTextAlign(const Align& value) -> void;
    func getTextAlign(void) const -> const Align&;
    
  _func_public:
    func setFont(const Font& font) -> void;
    func getFont(void) const ->const Font*;
    
    func setTextColor(const Color& value) -> void;
    func getTextColor(void) const -> const Color&;
    
    func setTextString(const String& value) -> void;
    func getTextString(void) const -> const String&;
    
    func getTextSize(bool adaptedSize = false) const -> Vector2f;
    
  }Textable;
}

#include "../../../src/SFUI/Graphics/Textable.cpp"
