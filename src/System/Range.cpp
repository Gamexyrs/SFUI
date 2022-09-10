//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  template<typename Type>
  inline func range(Type& value, Type min, Type max, const std::vector<Type>& special) -> Type& {
    if(!special.empty()) {
      for(auto& i : special) if(i == value) return value;
    } return(value = ((value < min) ? min : ((value > max) ? max : value)));
  }
  
  template<typename Type>
  inline func range(Type& changeValue, Type value, Type min, Type max, const std::vector<Type>& special) -> Type& {
    return(changeValue = range(value, min, max, special));
  }
};
