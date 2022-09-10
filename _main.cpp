#include <SFML/Graphics.hpp>
#include "./include/System.hpp"
#include "./include/Graphics.hpp"

int main(void) {
  sf::ContextSettings settings(0, 0, 1);
  sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "", sf::Style::Fullscreen, settings);
  window.setVerticalSyncEnabled(true);
  
  sf::Font Font;
  Font.loadFromFile("../MiSansVF.ttf");
  
  sf::Renderer::set(window);
  
  sf::PushButton Btn({{}, {300, 200}}, 20);
  Btn.setPosition(sf::getPosition(Btn.getSize()) + sf::Vector2f(0, 300));
  Btn.setText(L"按钮", Font, 50);
  Btn.setTextAlign(sf::Align::C);
  
  sf::ProgressBar Div({{}, {1000, 20}}, 20, true);
  Div.setPosition(sf::getPosition(Div.getSize()));
  Div.setText(L"测试", Font, 15);
  
  sf::Text Text(L"FPS: UNDEFINED", Font, 100);
  Text.setFillColor(sf::Color_Black);
  
  sf::Clock Clock;
  sf::Event event; unsigned tick = 0;
  while(window.isOpen() && ++tick) {
    Clock.restart();
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed)
        window.close();
      Btn.pollEvent_if(event);
    }
    _Renderer.clear(sf::InitColor.Background[sf::DisplayMode]);
    
    _Renderer.draw(Btn);
    _Renderer.draw(Div);
    _Renderer.draw(Text);
    
    _Renderer.display();
    if(!(tick % 10) || (tick > 1e5 && (tick = 0))) Text.setString(L"FPS: " + sf::Format::getFPS(Clock));
  } return 0;
}