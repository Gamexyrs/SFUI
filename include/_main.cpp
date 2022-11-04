// #define __PREDEF_ENABLE_UNITYDRAW__
// #define __PREDEF_ENABLE_TOUCHDATA__

#include <SFML/Graphics.hpp>
#include "SFUI/Graphics.hpp"

int main(void) {
  sf::ContextSettings settings(0, 0, 1);
  sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "", sf::Style::Fullscreen, settings);
  window.setFramerateLimit(60);
  
  sf::Font Font;
  Font.loadFromFile("../../MiSansVF.ttf");
  
  sf::Renderable::setRenderer(window);
  sf::Renderable::setDefaultFont(Font);

  sf::PushBtn Div({{}, {300, 200}}, 10);
  Div.setText(L"退出", Font, 100);
  Div.setTextAlign(sf::Align::LT);
  Div.setTextDeviat({-10, -5});
  Div.align(sf::Align::C) -= {0, 400};
  Div.setAutoLineBreakEnable(true);
  
  sf::MsgDiv Msg(20);
  Msg.setTitleTextColor(sf::Color::Red);
  Msg.setRounded(false, sf::Align::RB);
  
  sf::Div Sub({150, 100}, Div, 10);
  Sub.align();
  
  sf::Text Text(L"FPS: ", Font, 100);
  Text.setFillColor(sf::Color::Black);
  Text.setPosition({0, 100});
  
  sf::Text Note("", Font, 40);
  Note.setFillColor(sf::Color::Red);
  
  sf::Renderable::unityAdd({&Note, &Text});
  Div.joinUnity();
  Msg.joinUnity();
  sf::Object::flash();
  
  sf::KbEvent::setSettings(L"NLSD+");
  sf::Clock Clock; sf::String MsgReturn;
  sf::Event event; unsigned tick = 0;
  while(window.isOpen() && ++tick) {
    Clock.restart();
    while(window.pollEvent(event)) {
      sf::   KbEvent::pollEvent(event, true);
      sf::TouchEvent::pollEvent(event);
      if(__ACTIV_EXIT__(event)) {
        window.close();
      }
      if(__ACTIV_KEYCHECK__(event)) {
        Div.setTextString(sf::KbEvent::getBufString(false));
      }
      if(auto r = Msg.pollEvent(event)) {
        if(r > 0) {
          window.close();
        } else sf::Keyboard::setVirtualKeyboardVisible(true);
      }
      if(Div.pollEvent_if(event)) {
        Msg.launchQueue({
         .title = L"警告",
         .info  = L"是否退出？",
         .btn   = {
                    {L"取消", -1},
                    {L"确定",  1},
                  },
        }, true);
      }
    }
    _Renderer.clear(sf::Color::White);
    
    sf::Renderable::unityDraw();
    //sf::Renderable::draw({&Note, &Text, &Div, &Msg});
    
    _Renderer.display();
    if(!(tick % 10) || (tick > 1e5 && (tick = 0))) {
      Text.setString(L"FPS: " + sf::Format::getFPS(Clock));
    } //Note.setString(sf::Fm::toString(sf::TouchEvent::getTouchMove()));
    // Div.movProgress(0.2);
  } return 0;
}