//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

#include "../Object.hpp"

#define __V2CJK__ 1.0f, 1.25f

namespace sf::ui {
  typedef interface class Textable {
  private:
    Object* __Self{nullptr};
  
  protected: Textable(Object* self) : __Self(self) {}
    virtual ~Textable(void) = default;
    
    mutable Text  __Text{};
    mutable float __RadiusProtect{};
    mutable String __OriginString{};
    
    mutable bool __Enable_AutoLineBreak{false};
    
    Vector2f __TextDeviat{};
    Align    __TextAlign {Align::TL};
    Vector2f __TextAdapt {__V2CJK__};
    
    func __lineBreak(void) const -> String;
    
  _data_public:
    func setText(const String&, const Font&, unsigned size = 30) -> void;
    func getText(bool update = true) const -> Text&;
  
    func setTextDeviat(const Vector2f&) -> void;
    func getTextDeviat(void) const -> const Vector2f&;

    func setTextAdapt(const Vector2f&) -> void;
    func getTextAdapt(void) const -> const Vector2f&;

    func setTextAlign(const Align&) -> Vector2f&;
    func getTextAlign(void) const -> const Align&;
    
    func setAutoLineBreakEnable(bool) -> void;
    func getAutoLineBreakEnable(void) const -> bool;

  _func_public:
    func setFont(const Font&) -> void;
    func getFont(void) const -> const Font*;
    
    func setCharSize(size_t) -> void;
    func getCharSize(void) const -> size_t;

    func setTextColor(const Color&) -> void;
    func getTextColor(void) const -> const Color&;

    func setTextString(const String&) const -> void;
    func getTextString(void) const -> const String&;
    func getLineString(void) const -> const String&;
    
    func getTextSize(bool adaptedSize = false) const -> Vector2f;
    
    //-- Get/Guess the next character position
    func getNextPosition(void) const -> Vector2f;
    
  } Textable;
}

#undef __V2CJK__

#include "../../../../src/SFUI/Graphics/Interface/Textable.cpp"
