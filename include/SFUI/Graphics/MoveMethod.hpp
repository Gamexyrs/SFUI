//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

namespace sf::ui {
  typedef class MoveMethod {
  protected: MoveMethod(void) = delete;
    virtual ~MoveMethod(void) = delete;
    
  public:
    static func standard(const Vector2f& mov,                        size_t steps) -> std::vector<Vector2f>;
    static func standard(const Vector2f& begin, const Vector2f& end, size_t steps) -> std::vector<Vector2f>;
    
    static func linear_down(const Vector2f& mov,                        Vector2f maxSp, size_t steps) -> std::vector<Vector2f>;
    static func linear_down(const Vector2f& begin, const Vector2f& end, Vector2f maxSp, size_t steps) -> std::vector<Vector2f>;
    static func linear_up  (const Vector2f& mov,                        Vector2f maxSp, size_t steps) -> std::vector<Vector2f>;
    static func linear_up  (const Vector2f& begin, const Vector2f& end, Vector2f maxSp, size_t steps) -> std::vector<Vector2f>;
    
    static func quadratic_down(const Vector2f& mov,                        Vector2f maxSp, size_t steps) -> std::vector<Vector2f>;
    static func quadratic_down(const Vector2f& begin, const Vector2f& end, Vector2f maxSp, size_t steps) -> std::vector<Vector2f>;
 // static func quadratic_up  (const Vector2f& mov,                        Vector2f maxSp, size_t steps) -> std::vector<Vector2f>;
 // static func quadratic_up  (const Vector2f& begin, const Vector2f& end, Vector2f maxSp, size_t steps) -> std::vector<Vector2f>;

  }MoveMethod;
}

#include "../../../src/SFUI/Graphics/MoveMethod.cpp"
