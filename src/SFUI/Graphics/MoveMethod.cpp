//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  inline func MoveMethod::standard(const Vector2f& total_mov, float stepL) -> std::vector<Vector2f> {
    std::vector<Vector2f> __result{};
    for(float t{0}; t < 1.0f; t += stepL) {
             __result.emplace_back((total_mov * (std::min(t + stepL, 1.0f) - t)));
    } return __result;
  }

  // inline func MoveMethod::bezier(std::vector<Vector2f> control_points, float stepL) -> std::vector<Vector2f> {
    // int n{static_cast<int>(control_points.size() - 1)}; // 阶数
    // static auto binomial = [](int n, int k) -> int {
      // int result{1};
      // for(int i{0}; i < k; ++i) {
               // result *= static_cast<int>(static_cast<float>(n - i) / static_cast<float>(i + 1));
      // } return result;
    // };
    
    // std::vector<Vector2f> __result{};
    // for(float t{0}; t <= 1.0f; t += stepL) {
      // __result.emplace_back(Vector2f{});
      // for(int i{0}; i <= n; ++i)
             // __result.back() += control_points[i] * (binomial(n, i) * std::pow(t, i) * std::pow(1 - t, n - i));
    // } return __result;
  // }
  
  // inline func MoveMethod::hermite(const Vector2f& total_mov, float stepL) -> std::vector<Vector2f> {
    // std::vector<Vector2f> __result{{}};
    
    // for(float t{0}; t <= 1.0f; t += stepL) {
             // __result.emplace_back((-2 * t * t * t + 3 * t * t) * total_mov - __result.back());
    // } return __result;
  // }
  
  // inline func MoveMethod::spring(const Vector2f& total_mov, float stepL, float k, float m) -> std::vector<Vector2f> {
    // // TODO-> linear method.
    // return{};
  // }
  
  // inline func MoveMethod::quadratic(const Vector2f& total_mov, float stepL) -> std::vector<Vector2f> {
    // // TODO-> quadratic method.
    // return{};
  // }
  // inline func MoveMethod::quadratic_RK4(const Vector2f& total_mov, float total_time, float stepL) -> std::vector<Vector2f> {
    // // TODO-> RK4 model quadratic method.
    // return{};
  // }
  
  // OLD METHOD
  inline func MoveMethod::standard(const Vector2f& mov, size_t steps) -> std::vector<Vector2f> {
    std::vector<Vector2f> __result{steps};
    std::fill(__result.begin(), __result.end(),
                mov / static_cast<float>(steps));
    return __result;
  }
  inline func MoveMethod::standard(const Vector2f& begin, const Vector2f& end, size_t steps) -> std::vector<Vector2f> {
    return MoveMethod::standard(end - begin, steps);
  }
  
  inline func MoveMethod::linear_down(const Vector2f& mov, Vector2f maxSp, size_t steps) -> std::vector<Vector2f> {
    if(maxSp == Vector2f{} )
       maxSp = mov * 2 / static_cast<float>(steps);
       
    Vector2f __midSp{mov / static_cast<float>(steps)};
    
    if(std::fabs(maxSp.x) < std::fabs(__midSp.x)
    || std::fabs(maxSp.y) < std::fabs(__midSp.y)) {
      err() << "\nNot matched speed_max. autoAdapt.";
      maxSp = mov * 2 / static_cast<float>(steps);
    }
    
    Vector2f __fixValue{(maxSp - __midSp) / ((steps - 1) / 2.0f)};
    
    std::vector<Vector2f> __result{steps};
    
    for(auto& i : __result)
              i = (maxSp -= __fixValue);
    
    return __result;
    
  }
  inline func MoveMethod::linear_down(const Vector2f& begin, const Vector2f& end, Vector2f maxSp, size_t steps) -> std::vector<Vector2f> {
    return MoveMethod::linear_down(end - begin, maxSp, steps);
  }
  
  inline func MoveMethod::linear_up(const Vector2f& mov, Vector2f maxSp, size_t steps) -> std::vector<Vector2f> {
    if(maxSp == Vector2f{})
       maxSp = mov * 2 / static_cast<float>(steps);
       
    Vector2f __midSp{mov / static_cast<float>(steps)};
    
    if(std::fabs(maxSp.x) < std::fabs(__midSp.x)
    || std::fabs(maxSp.y) < std::fabs(__midSp.y)) {
      err() << "\nNot matched speed_max. autoAdapt.";
      maxSp = mov * 2 / static_cast<float>(steps);
    }
    
    Vector2f __fixValue{(maxSp - __midSp) / ((steps - 1) / 2.0f)};
      maxSp = {};
    
    std::vector<Vector2f> __result{steps};
    
    for(auto& i : __result)
              i = (maxSp += __fixValue);
    
    return __result;
  }
  inline func MoveMethod::linear_up(const Vector2f& begin, const Vector2f& end, Vector2f maxSp, size_t steps) -> std::vector<Vector2f> {
    return MoveMethod::linear_up(end - begin, maxSp, steps);
  }
  
  inline func MoveMethod::quadratic_down(const Vector2f& mov, Vector2f maxSp, size_t steps) -> std::vector<Vector2f> {
    std::vector<Vector2f> __result{steps};
    if(maxSp == Vector2f{})
       maxSp = mov * 2 / static_cast<float>(steps);
    Vector2f __fixValue{maxSp / (steps / 2.0f)}; maxSp = {};
    for(size_t i{0} ; i < __result.size(); ++i) {
      if(i < __result.size() / 2)
             __result.at(i) = (maxSp += __fixValue);
      else   __result.at(i) = (maxSp -= __fixValue);
    } return __result;
  }
  inline func MoveMethod::quadratic_down(const Vector2f& begin, const Vector2f& end, Vector2f maxSp, size_t steps) -> std::vector<Vector2f> {
    return MoveMethod::quadratic_down(end - begin, maxSp, steps);
  }
}

/*
// 定义RK4方法的辅助函数
void rk4(const std::function<double(double, double)>& a, double& t, double& x, double& v, double dt) {
    double k1_x, k1_v, k2_x, k2_v, k3_x, k3_v, k4_x, k4_v;
    double t1 = t + dt / 2.0;
    double t2 = t + dt / 2.0;
    double t3 = t + dt;
    
    // k1
    k1_x = dt * v;
    k1_v = dt * a(t, x);

    // k2
    double x_temp = x + k1_x / 2.0;
    double v_temp = v + k1_v / 2.0;
    k2_x = dt * v_temp;
    k2_v = dt * a(t1, x_temp);

    // k3
    x_temp = x + k2_x / 2.0;
    v_temp = v + k2_v / 2.0;
    k3_x = dt * v_temp;
    k3_v = dt * a(t1, x_temp);

    // k4
    x_temp = x + k3_x;
    v_temp = v + k3_v;
    k4_x = dt * v_temp;
    k4_v = dt * a(t3, x_temp + k3_x);

    // 更新位置和速度
    x += (k1_x + 2 * k2_x + 2 * k3_x + k4_x) / 6.0;
    v += (k1_v + 2 * k2_v + 2 * k3_v + k4_v) / 6.0;
    t += dt;
}
*/
