#include <SFML/Graphics.hpp>
#include "SFUI/Graphics.hpp"

int main(void) {
  sf::ContextSettings settings(0, 0, 1);
  sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "", sf::Style::Fullscreen, settings);
  window.setFramerateLimit(60);
  
  sf::Font Font;
  Font.loadFromFile("../../MiSansVF.ttf");
  
  sf::Renderable::setRenderer(window);
  sf::Renderable::setFont(Font);

  sf::PushBtn Div({{}, {300, 200}}, 10);
  Div.setText(L"退出", Font, 100);
  Div.setTextAlign(sf::Align::C);
  Div.align(sf::Align::T) += {0, 400};
  
  sf::MsgDiv Msg(20);
  Msg.setTitleTextColor(sf::Color::Red);
  Msg.setRounded(false, sf::Align::RB);
  
  sf::Div Sub({150, 100}, Div, 10);
  Sub.align();
  
  sf::Text Text(L"FPS: ", Font, 100);
  Text.setFillColor(sf::Color::Black);
  
  sf::Text Note(sf::Fm::toString(_RendererRect), Font, 40);
  Note.setFillColor(sf::Color::Red);
  
  sf::Renderable::unityAdd({&Note, &Text});
  Div.joinUnity();
  Msg.joinUnity();
  sf::Object::flash();
  
  sf::Clock Clock; sf::String MsgReturn;
  sf::Event event; unsigned tick = 0;
  while(window.isOpen() && ++tick) {
    Clock.restart();
    while(window.pollEvent(event)) {
      if(__ACTIV_EXIT__(event)) {
        window.close();
      }
      if(auto r = Msg.pollEvent(event)) {
        if(r > 0) {
          Note.setString("Yes");
          window.close();
        } else Note.setString("No");
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
    
    _Renderer.display();
    if(!(tick % 10) || (tick > 1e5 && (tick = 0))) {
      Text.setString(L"FPS: " + sf::Format::getFPS(Clock));
    } // Div.movProgress(0.2);
  } return 0;
}