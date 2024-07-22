//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  Joystick::Joystick(const Vector2f& ct_pos, float edge_radius, float edge_outline, float iner_radius) {
    this->__Edge.setSize({edge_radius * 2.08f + 1, edge_radius * 2.0f + 1});
    this->__Iner.setSize({iner_radius * 2.08f + 1, iner_radius * 2.0f + 1});
    
    this->__Edge.setCenter(ct_pos); this->__Edge.setRadius(-1);
    this->__Iner.setCenter(ct_pos); this->__Iner.setRadius(-1);
    
    this->__Edge.setOutlineColor(ColorEx::makeTrs(sf::ColorEx::Grey, 80));
    this->__Edge.setFillColor(Color::Transparent);
    this->__Edge.setOutlineThickness(edge_outline);
    this->__Edge.getBase().setPointCount(50);
    
    this->__Iner.setFillColor(this->__Edge.getOutlineColor());
    this->__Iner.setOutlineThickness(0);
    this->__Iner.getBase().setPointCount(50);
  }
  
  inline func Joystick::draw(RenderTarget& target, const RenderStates& states) const -> void { this->update();
    target.draw(this->__Edge, states);
    target.draw(this->__Iner, states);
  }
  inline func Joystick::update(void) const -> void {
    this->__Iner.setCenter(this->__Edge.getCenter());
    this->__Iner.move(this->__Data.v_LengthToCenter_Coordinates);
  }

  inline func Joystick::getEdge(void) const -> Div& {
    return const_cast<Div&>(this->__Edge);
  }
  inline func Joystick::getIner(void) const -> Div& {
    return const_cast<Div&>(this->__Iner);
  }
  
  inline func Joystick::setCenter(const Vector2f& value) -> void {
    this->__Edge.setCenter(value);
    this->__Iner.setCenter(value);
  }
  inline func Joystick::getCenter(void) const -> Vector2f {
    return this->__Edge.getCenter();
  }
  
  inline func Joystick::setEdgeRadius(float r) -> void {
    this->__Edge.zoom({r * 2.08f, r * 2.0f});
  }
  inline func Joystick::getEdgeRadius(void) const -> float {
    return this->__Edge.getSize().y / 2.0f;
  }
  
  inline func Joystick::setInerRadius(float r) -> void {
    this->__Iner.zoom({r * 2.08f, r * 2.0f});
  }
  inline func Joystick::getInerRadius(void) const -> float {
    return this->__Iner.getSize().y / 2.0f;
  }
  
  inline func Joystick::pollEvent(const Event& event) -> bool {
    static short tmp_i{}, npolled{-1};
    
    if(event.type == Event::TouchBegan && npolled == -1
    && (tmp_i = TouchEvent::isDownAt(this->__Edge.getRect()))) npolled = tmp_i - 1;
    
    if((npolled > -1) && Touch::isDown(npolled) && !Msgable::getLocked()) {
      this->__Data = geometry::parse_circle_point({
          ._radius = this->getEdgeRadius() + this->__Edge.getOutlineThickness(),
          ._center = this->getCenter()}, TouchEvent::getPosition(npolled)); return true;
    } else {
      this->__Iner.setCenter(this->__Edge.getCenter());
      this->__Data = {}; npolled = -1;
    } return false;
  }

  inline func Joystick::getData(void) const -> geometry::parse_data_type {
    return this->__Data;
  }
}
