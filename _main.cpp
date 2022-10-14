#include <SFML/Graphics.hpp>
#include "./SFUI/include/Graphics.hpp"

int main(void) {
  sf::ContextSettings settings(0, 0, 1);
  sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "", sf::Style::Fullscreen, settings);
  window.setFramerateLimit(90);
  
  sf::Font Font;
  Font.loadFromFile("../MiSansVF.ttf");
  
  sf::Renderable::setRenderer(window);

  sf::ProgressDiv Div({{}, {1000, 20}}, 10);
  Div.setText(L"测试", Font, 20);
  Div.setTextAlign(sf::Align::C);
  Div.setProgress(-1);
  Div.align();
  
  sf::Div Sub({150, 100}, Div, 10);
  Sub.align();
  
  sf::Text Text(L"FPS: ", Font, 100);
  Text.setFillColor(sf::Color::Black);
  
  sf::Text Note(std::to_string(sizeof(0)), Font, 40);
  Note.setFillColor(sf::Color::Red);
  
  sf::Clock Clock;
  sf::Event event; unsigned tick = 0;
  while(window.isOpen() && ++tick) {
    Clock.restart();
    while(window.pollEvent(event)) {
      if(__ANDROID_ACTIVITY_CLOSED__(event)) {
        window.close();
      }
      //if(Div.pollEvent(event)) {
        //window.close();
      //}
    }
    _Renderer.clear(sf::Color::White);
    
    _Renderer.draw(Div);
    //_Renderer.draw(Sub);
    _Renderer.draw(Text);
    _Renderer.draw(Note);
    
    _Renderer.display();
    if(!(tick % 10) || (tick > 1e5 && (tick = 0))) {
      Text.setString(L"FPS: " + sf::Format::getFPS(Clock));
    } // Div.movProgress(0.2);
  } return 0;
}