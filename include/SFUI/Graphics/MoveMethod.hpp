//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

/*
✔1. 二次方程（Quadratic Equation）: 使用二次方程来定义速度随时间变化的函数。例如，如果速度 v(t) 与时间 t 的关系可以表示为 v(t) = a(t - t_0)^2 + v_0，其中 a 是一个常数，t_0 是速度达到最大值的时间点，v_0 是初始速度。
  2. 正弦函数（Sine Function）: 使用正弦函数来模拟速度的变化。例如，v(t) = A \sin(\omega t + \phi) + v_0，其中 A 是振幅，\omega 是角频率，\phi 是相位，v_0 是初始速度。
✔3. 三次贝塞尔曲线（Cubic Bezier Curve）: 使用三次贝塞尔曲线来定义速度随时间的变化，这在动画和游戏开发中非常常见。贝塞尔曲线可以提供平滑的加速和减速效果。
  4. 物理模拟（Physics Simulation）: 使用物理引擎来模拟物体的运动，例如使用弹簧-质量系统（spring-mass system），其中物体的加速度与速度成反比，模拟阻尼运动。
✔5. 插值方法（Interpolation Methods）: 使用插值方法，如线性插值、二次插值或三次插值，来计算物体在不同时间点的速度。
  6. 自定义函数: 根据具体需求，自定义一个函数来描述速度随时间的变化，确保在开始和结束时速度为零，中间达到最大值。
*/

namespace sf::ui {
  typedef class MoveMethod {
  protected: MoveMethod(void) = delete;
    virtual ~MoveMethod(void) = delete;
    
  public:
    static func standard(const Vector2f& total_mov, float stepL) -> std::vector<Vector2f>;
    
    /* [ BezierCurve: Smooth ] */
    static func bezier(std::vector<Vector2f> control_points, float stepL = 0.02f) -> std::vector<Vector2f>;
    /* [ HermiteInterpolation: Smooth ] */
    static func hermite(const Vector2f& total_mov, float stepL = 0.02f) -> std::vector<Vector2f>;
    
    /* [ Spring-massSystem: Smooth ] */
    static func spring(const Vector2f& total_mov, float stepL = 0.02f, float k = 100.0f, float m = 1.0f) -> std::vector<Vector2f>;
    
    /* [ StandardQuadratic: Accurate ] */
    static func quadratic(const Vector2f& total_mov, float stepL = 0.02f) -> std::vector<Vector2f>;
    /* [ StandardQuadratic_RungeKutta4: VeryAccurate ] */
    static func quadratic_RK4(const Vector2f& total_mov, float stepL = 0.02f) -> std::vector<Vector2f>;
    
    
    // OLD METHOD
    static func standard(const Vector2f& mov,                        size_t steps = 50) -> std::vector<Vector2f>;
    static func standard(const Vector2f& begin, const Vector2f& end, size_t steps = 50) -> std::vector<Vector2f>;
    
    static func linear_down(const Vector2f& mov,                        Vector2f maxSp, size_t steps = 50) -> std::vector<Vector2f>;
    static func linear_down(const Vector2f& begin, const Vector2f& end, Vector2f maxSp, size_t steps = 50) -> std::vector<Vector2f>;
    static func linear_up  (const Vector2f& mov,                        Vector2f maxSp, size_t steps = 50) -> std::vector<Vector2f>;
    static func linear_up  (const Vector2f& begin, const Vector2f& end, Vector2f maxSp, size_t steps = 50) -> std::vector<Vector2f>;
    
    static func quadratic_down(const Vector2f& mov,                        Vector2f maxSp, size_t steps = 50) -> std::vector<Vector2f>;
    static func quadratic_down(const Vector2f& begin, const Vector2f& end, Vector2f maxSp, size_t steps = 50) -> std::vector<Vector2f>;
 // static func quadratic_up  (const Vector2f& mov,                        Vector2f maxSp, size_t steps = 50) -> std::vector<Vector2f>;
 // static func quadratic_up  (const Vector2f& begin, const Vector2f& end, Vector2f maxSp, size_t steps = 50) -> std::vector<Vector2f>;
    
  } MoveMethod;
}

#include "../../../src/SFUI/Graphics/MoveMethod.cpp"
