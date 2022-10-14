//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "Object.hpp"

#define __ADAPT_V2_CHINESE__ {1.0f, 1.25}

namespace sf::ui {
  typedef class Textable {
  private:
    Object* __Self = nullptr;
  
  protected: Textable(Object* self) : __Self(self) {}
    virtual ~Textable(void) = default;
    
    mutable Text __Text;
    
    Vector2f __TextDeviat = {};
    short    __TextAlign  = Align::TL;
    Vector2f __TextAdapt  = __ADAPT_V2_CHINESE__;
    
    bool __TextVisible = true;
    
  _data_public:
    func setText(const String& str, const Font& font, unsigned size = 30) -> void;
    func getText(void) const -> Text&;
  
    func setTextDeviat(const Vector2f& value) -> void;
    func getTextDeviat(void) const -> const Vector2f&;

    func setTextAdapt(const Vector2f& value) -> void;
    func getTextAdapt(void) const -> const Vector2f&;

    func setTextAlign(short value) -> void;
    func getTextAlign(void) const -> short;
    
    func setTextVisible(bool value) -> void;
    func getTextVisible(void) const -> bool;
    
  _func_public:
    func setFont(const Font& font) -> void;
    func getFont(void) const ->const Font*;
  
    func setTextString(const String& value) -> void;
    func getTextString(void) const -> const String&;
    
    func getTextSize(bool adaptedSize = false) const -> Vector2f;
    
  }Textable;
}

#include "../../src/Graphics/Textable.cpp"
