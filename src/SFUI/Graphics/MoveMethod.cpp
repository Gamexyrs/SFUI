//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
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
