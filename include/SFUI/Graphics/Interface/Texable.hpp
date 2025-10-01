//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

#include "../Object.hpp"

namespace sf::ui {
  typedef interface class Texable {
  private:
    Object* __Self{nullptr};
  
  protected: Texable(Object* self) : __Self(self) {}
    virtual ~Texable(void) = default;
    
    bool __TexVisible{true};
    Vector2f __TexDeviat{};
    Vector2f __TexScale{1, 1};
    Align    __TexAlign {Align::C};
    bool     __TexAutoFit{true};
    bool     __TexOriginC{false};
    
    Texture* __Tex{nullptr};
    mutable Sprite __Tex_spr{};
    
    func isTexVisible(void) const -> bool;
    
  _data_public:
    func setTexture(Texture*) -> void;
    func hasTexture(void) const -> bool;
    func getTexture(void) const -> Texture*;
  
    func setTexOriginInCenter(bool) -> void;
    func getTexOriginInCenter(void) const -> bool;
    
    func setTexVisible(bool) -> void;
    func getTexVisible(void) const -> bool;

    func setTexDeviat(const Vector2f&) -> void;
    func getTexDeviat(void) const -> const Vector2f&;

    func setTexScale(float) -> void;
    func setTexScale(const Vector2f&) -> void;
    func getTexScale(void) const -> const Vector2f&;

    func setTexRotation(float) -> void;
    func    texRotate  (float) -> void;
    func getTexRotation(void) const -> float;

    func setTexAlign(const Align&) -> Vector2f&;
    func getTexAlign(void) const -> const Align&;
    
    func setTexColor(const Color&) -> void;
    func getTexColor(void) const -> const Color&;
    
    func setTexAutoFit(bool) -> void;
    func getTexAutoFit(void) const -> bool;

  _func_public:
    func getTexSize(void) const -> Vector2f;
    
  } Texable;
}

#include "../../../../src/SFUI/Graphics/Interface/Texable.cpp"
