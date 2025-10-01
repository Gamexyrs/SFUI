//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

namespace sf::ui::geometry {
  using PointBuilder = Vector2f;
  typedef struct CircleBuilder {
       float _radius; // 圆的半径
    Vector2f _center; // 圆心位置
    
    bool _allow_in = true; // 允许点落在圆内
    
  }CircleBuilder;
  
  static struct parse_data_type {
      float    v_Angle{};
      Vector2f v_Position{};
      float    v_LengthToCenter_Oblique;
      Vector2f v_LengthToCenter_Coordinates;
      
  }parse_data;
  
  // Get info on the circle by a point . will update:
    // [: v_Angle
    // [: v_Position
    // [: v_LengthToCenter_Oblique
    // [: v_LengthToCenter_Coordinates
    func parse_circle_point(const CircleBuilder&, const PointBuilder&) -> parse_data_type;

}

#include "../../../src/SFUI/System/Geometry.cpp"
