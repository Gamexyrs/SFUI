//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include <SFML/Graphics.hpp>

#define __SFUI_VERSION_MAJOR__ 0
#define __SFUI_VERSION_MINOR__ 4
#define __SFUI_VERSION_PATCH__ 1
#define __SFUI_VERSION__ "0.4.1"
#define __SFUI_DEV__ true

#define __ACTIV_EXIT__(event)     \
  ((event.type     == sf::Event::KeyPressed \
 && event.key.code == sf::Keyboard::Escape) \
 || event.type     == sf::Event::LostFocus  \
 || event.type     == sf::Event::Closed)

#define __ACTIV_KEYCHECK__(event)           \
   (event.type     == sf::Event::KeyPressed \
 || event.type     == sf::Event::TextEntered)
 
#define _data_public public
#define _func_public public

#define interface  

#define func auto

#define _____


#include "../../../src/SFUI/System/__Config.cpp"
