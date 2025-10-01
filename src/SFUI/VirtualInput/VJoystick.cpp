//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  VJoystick::VJoystick(const Vector2f& ct_pos, float edge_radius, float edge_outline, float iner_radius) {
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
  
  inline func VJoystick::draw(RenderTarget& target, const RenderStates& states) const -> void { this->update();
    target.draw(this->__Edge, states);
    target.draw(this->__Iner, states);
  }
  inline func VJoystick::update(void) const -> void {
    this->__Iner.setCenter(this->__Edge.getCenter());
    this->__Iner.move(this->__Data.v_LengthToCenter_Coordinates);
  }

  inline func VJoystick::getEdge(void) const -> Div& {
    return const_cast<Div&>(this->__Edge);
  }
  inline func VJoystick::getIner(void) const -> Div& {
    return const_cast<Div&>(this->__Iner);
  }
  
  inline func VJoystick::setCenter(const Vector2f& value) -> void {
    this->__Edge.setCenter(value);
    this->__Iner.setCenter(value);
  }
  inline func VJoystick::getCenter(void) const -> Vector2f {
    return this->__Edge.getCenter();
  }
  
  inline func VJoystick::setEdgeRadius(float r) -> void {
    this->__Edge.zoom({r * 2.08f, r * 2.0f});
  }
  inline func VJoystick::getEdgeRadius(void) const -> float {
    return this->__Edge.getSize().y / 2.0f;
  }
  
  inline func VJoystick::setInerRadius(float r) -> void {
    this->__Iner.zoom({r * 2.08f, r * 2.0f});
  }
  inline func VJoystick::getInerRadius(void) const -> float {
    return this->__Iner.getSize().y / 2.0f;
  }
  
  inline func VJoystick::pollEvent(const Event& event) -> bool {
    if(event.type == Event::TouchBegan && this->npolled == -1
    && (this->tmp_i = TouchEvent::isDownAt(this->__Edge.getRect()))) this->npolled = this->tmp_i - 1;
    
    if((this->npolled > -1) && Touch::isDown(this->npolled) && (!Msgable::getLocked() || this->__ATTRIBUTE__.__ALWAYS_TOUCHABLE__)) {
      this->__Data = geometry::parse_circle_point({
          ._radius = this->getEdgeRadius() + this->__Edge.getOutlineThickness() / 2.0f,
          ._center = this->getCenter()}, TouchEvent::getPosition(this->npolled)); return true;
    } else {
      this->__Iner.setCenter(this->__Edge.getCenter());
      this->npolled = -1;
      this->__Data = {};
    } return false;
  }

  inline func VJoystick::getData(void) const -> geometry::parse_data_type {
    return this->__Data;
  }
  
  inline func VJoystick::setMove(const Vector2f& __move) -> void {
    this->__Data = geometry::parse_circle_point({
        ._radius = this->getEdgeRadius() + this->__Edge.getOutlineThickness() / 2.0f,
        ._center = this->getCenter()}, this->getCenter() + __move);
  }
  inline func VJoystick::reset(void) -> void {
    this->npolled = -1;
    this->__Data = {};
  }
}
