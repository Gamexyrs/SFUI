//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "Div.hpp"

namespace gy {
  typedef class TextDiv : public Div {
  protected:
    virtual auto update(void) const -> void;
    virtual auto draw(sf::RenderTarget& target, sf::RenderStates states) const -> void;
    
  _data_public:
    mutable sf::Text Text;
    // [[deprecated("\'undeveloped\'")]]
    //  bool AutoInsertLineFeed = false; // 自动换行
    sf::Vector2f TextDeviat = {       }; // 文字偏移量值
    sf::Vector2f TextAdapt  = {1, 1.25}; // 文字边框乘数
    short TextAlign = (Align::T ^ Align::L); // 文字位置

  _func_public:
    auto setText(const sf::String& Str, const sf::Font& Font, unsigned Size = 30, bool ResizeDiv = false) -> void;
    auto getTextSize(bool Adapted = false) const -> sf::Vector2f;
  
             TextDiv(const BuildFrame& Frame = {{}, {}}, unsigned Radius = 0);
    virtual ~TextDiv(void) = default;
    
  }TDiv;
};

#include "../src/TextDiv.cpp"
