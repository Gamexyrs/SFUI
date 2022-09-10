//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include <SFML/Graphics.hpp>

#define _RendererRect (static_cast<sf::FloatRect>(FloatRect(sf::Renderer::get().getPosition().x, \
                                                            sf::Renderer::get().getPosition().y, \
                                                            sf::Renderer::get().getSize().x,     \
                                                            sf::Renderer::get().getSize().y)))
#define _RendererSize (static_cast<sf::Vector2f>(sf::Renderer::get().getSize()))
#define _Renderer (sf::Renderer::get())

#define __SET__(var, fn) {var = value; fn();}
#define __GET__(var) {return var;}

#define __NF []()->void{}

#define _data_public public
#define _func_public public

#define func auto

namespace sf {
  inline namespace ui {
    typedef class Renderer final {
      protected: Renderer(void) = default;
        virtual ~Renderer(void) = default;
        
        static Text* Fps;
        
        static inline RenderWindow* ptr = nullptr;
        
        static bool __Enable_VirtualKeyboard__;
        
      _data_public:
        static inline func set(const RenderWindow& value) -> void {ptr = const_cast<RenderWindow*>(&value);}
        static inline func get(void) -> RenderWindow& __GET__(*ptr);
        
        static        func setEnableVirtualKeyboard(bool value, bool useSystemKeyboard = true) -> void;
        static inline func getEnableVirtualKeyboard(void) -> bool __GET__(Renderer::__Enable_VirtualKeyboard__);
        
    }Renderer;
  };
};

#include "../../src/System/Context.cpp"

