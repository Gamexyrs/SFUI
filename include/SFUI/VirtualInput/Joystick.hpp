//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "../Graphics.hpp"

namespace sf::ui {
  typedef class Joystick : public Drawable {
  public:    Joystick(const Vector2f& ct_pos = {},
                      float edge_radius = 0.0f,
                      float edge_outline= 0.0f,
                      float iner_radius = 0.0f);
    virtual ~Joystick(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
    virtual func update(void) const -> void;
    
    geometry::parse_data_type __Data{};
    
    Div __Edge{},
        __Iner{};
    
  _data_public:
    func getEdge(void) const -> Div&;
    func getIner(void) const -> Div&;
    
    func setCenter(const Vector2f&) -> void;
    func getCenter(void) const -> Vector2f;
    
    func setEdgeRadius(float) -> void;
    func getEdgeRadius(void) const -> float;
    
    func setInerRadius(float) -> void;
    func getInerRadius(void) const -> float;
    
  _func_public:
    virtual func pollEvent(const Event&) -> bool;
    
    func getData(void) const -> geometry::parse_data_type;
    
  }Joystick;
}

#include "../../../src/SFUI/VirtualInput/Joystick.cpp"
