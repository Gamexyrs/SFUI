#include <SFML/Graphics.hpp>
#include "./include/CheckButton.hpp"

int main(void) {
  sf::ContextSettings settings(0, 0, 1);
  sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "", sf::Style::Fullscreen, settings);
  window.setVerticalSyncEnabled(true);
  
  sf::Font Font;
  Font.loadFromFile("../MiSansVF.ttf");
  
  gy::Context::setRenderer(window);
  
  sf::Text Text(L"Gypro© sf::RenderWindow(aka. _Renderer) for test: " + gy::Format::toString(window.getSize()), Font);
  Text.setFillColor(sf::Color::Black);
  
  gy::CButton Div({{}, {300, 200}}, 20);
  Div.Position = gy::Pos::getPoint(Div.Size);
  Div.setText(L"文字", Font, 50);
  Div.TextAlign = gy::Align::C;
  
  sf::Event event;
  while(window.isOpen()) {
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed)
        window.close();
      else if(event.type == sf::Event::TextEntered)
        Div.Text.setString(sf::String(event.text.unicode));
      if(Div.pollEvent_if(event)) {
        if(Div.Checked)
          sf::Keyboard::setVirtualKeyboardVisible(true);
        else
          sf::Keyboard::setVirtualKeyboardVisible(false);
      }
    }
    
    _Renderer.clear(sf::Color::White);
    
    _Renderer.draw(Text);
    _Renderer.draw(Div);
    
    _Renderer.display();
    
  } return 0;
}