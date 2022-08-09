//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include <codecvt>
#include <string>

namespace gy {
  typedef class Formatter final {
  protected: Formatter(void) = default;
    virtual ~Formatter(void) = default;
    
  _func_public:
    template<typename Type>
    static auto getPosition(const sf::Rect<Type>& Rect) -> sf::Vector2<Type>;
    template<typename Type>
    static auto getSize    (const sf::Rect<Type>& Rect) -> sf::Vector2<Type>;
    
    static auto getSize(const sf::Sprite& Target) -> sf::Vector2f;
    static auto getSize(const sf::Shape&  Target) -> sf::Vector2f;
    static auto getSize(const sf::Text&   Target) -> sf::Vector2f;
    
    template<typename Type>
    static auto reverse(const sf::Vector2<Type>& Vector) -> sf::Vector2<Type>;
    
    static auto toString(const sf::VideoMode&  VideoMode) -> sf::String;
    template<typename Type>
    static auto toString(const sf::Rect   <Type>&   Rect) -> sf::String;
    template<typename Type>
    static auto toString(const sf::Vector2<Type>& Vector) -> sf::String;
    template<typename Type>
    static auto toString(const sf::Vector3<Type>& Vector) -> sf::String;
    
  }Format;
  
  template<typename Type>
  auto operator* (const sf::Vector2<Type>& left, const sf::Vector2<Type>& right) -> sf::Vector2<Type>;
};

namespace std {
  inline auto to_wstring(const  string&  str) -> wstring;
  inline auto to_string (const wstring& wstr) ->  string;
};

#include "../src/Format.cpp"
