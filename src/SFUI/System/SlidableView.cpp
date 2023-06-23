//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func SlidableView::__check(void) -> void {
    if(!SlidableView::__Enable_HorizontalMove
    ||               Renderable::getViewPosition().x
    + SlidableView::__Move.x < SlidableView::__HorizontalMax.x)
      SlidableView::resetHorizontalView();
    else if(Fm::getRoot(Renderable::getViewRect()).x
    + SlidableView::__Move.x > SlidableView::__HorizontalMax.y)
      const_cast<View&>(_Renderer.getView()).move(
        {SlidableView::__HorizontalMax.y - Fm::getRoot(Renderable::getViewRect()).x,
         SlidableView::__Move.x = 0});
      
    if(!SlidableView::__Enable_VerticalMove
    ||               Renderable::getViewPosition().y
    + SlidableView::__Move.y < SlidableView::__VerticalMax.x)
      SlidableView::resetVerticalView();
    else if(Fm::getRoot(Renderable::getViewRect()).y
    + SlidableView::__Move.y > SlidableView::__VerticalMax.y)
      const_cast<View&>(_Renderer.getView()).move(
        {SlidableView::__Move.y = 0,
         SlidableView::__VerticalMax.y - Fm::getRoot(Renderable::getViewRect()).y});
  }
  
  inline func SlidableView::setMoveFactor(float value) -> void {
    SlidableView::__MoveFactor = value;
  }
  inline func SlidableView::getMoveFactor(void) -> float {
    return SlidableView::__MoveFactor;
  }
  
  inline func SlidableView::setSlideAttenuate(float value) -> void {
    SlidableView::__SlideAttenuate = value;
  }
  inline func SlidableView::getSlideAttenuate(void) -> float {
    return SlidableView::__SlideAttenuate;
  }
  
  inline func SlidableView::setReactTime(const Time& value) -> void {
    SlidableView::__ReactTime = value;
  }
  inline func SlidableView::getReactTime(void) -> const Time& {
    return SlidableView::__ReactTime;
  }
  
  inline func SlidableView::setMinMove(const Vector2f& value) -> void {
    SlidableView::__MinMove = Fm::abs(value);
  }
  inline func SlidableView::getMinMove(void) -> const Vector2f& {
    return SlidableView::__MinMove;
  }
  
  inline func SlidableView::setHorizontalMax(const Vector2f& value) -> void {
    SlidableView::__HorizontalMax = value;
  }
  inline func SlidableView::getHorizontalMax(void) -> const Vector2f& {
    return SlidableView::__HorizontalMax;
  }
  
  inline func SlidableView::setVerticalMax(const Vector2f& value) -> void {
    SlidableView::__VerticalMax = value;
  }
  inline func SlidableView::getVerticalMax(void) -> const Vector2f& {
    return SlidableView::__VerticalMax;
  }
  
  inline func SlidableView::setSmoothEnable(bool value) -> void {
    SlidableView::__Enable_Smooth = value;
  }
  inline func SlidableView::getSmoothEnable(void) -> bool {
    return SlidableView::__Enable_Smooth;
  }
  
  inline func SlidableView::setMutexMoveEnable(bool value) -> void {
    SlidableView::__Enable_MutexMove = value;
  }
  inline func SlidableView::getMutexMoveEnable(void) -> bool {
    return SlidableView::__Enable_MutexMove;
  }
  
  inline func SlidableView::setHorizontalMoveEnable(bool value) -> void {
    SlidableView::__Enable_HorizontalMove = value;
  }
  inline func SlidableView::getHorizontalMoveEnable(void) -> bool {
    return SlidableView::__Enable_HorizontalMove;
  }
  
  inline func SlidableView::setVerticalMoveEnable(bool value) -> void {
    SlidableView::__Enable_VerticalMove = value;
  }
  inline func SlidableView::getVerticalMoveEnable(void) -> bool {
    return SlidableView::__Enable_VerticalMove;
  }

  inline func SlidableView::getAutoSliding(void) -> bool {
    return SlidableView::__Move != Vector2f();
  }
  
  inline func SlidableView::resetHorizontalView(void) -> void {
    const_cast<View&>(_Renderer.getView()).move(
      {-Renderable::getViewPosition().x, SlidableView::__Move.x = 0});
  }
  inline func SlidableView::resetVerticalView(void) -> void {
    const_cast<View&>(_Renderer.getView()).move(
      {SlidableView::__Move.y = 0, -Renderable::getViewPosition().y});
  }
  
  inline func SlidableView::pollEvent(void) -> void {
    if(Msgable::getLocked()) {
      SlidableView::__Move = {}; return;
    }
    if(TouchEvent::getTouchTime(0).asMilliseconds()     >= SlidableView::__ReactTime.asMilliseconds()) {
      SlidableView::__Move = TouchEvent::getTouchMove() * -SlidableView::__MoveFactor;
      if(SlidableView::__Enable_MutexMove) {
        if(std::fabs(SlidableView::__Move.y)
        >= std::fabs(SlidableView::__Move.x))
           SlidableView::__Move.x = 0;
        else
           SlidableView::__Move.y = 0;
        if(std::fabs(SlidableView::__Move.x) < SlidableView::__MinMove.x)
                     SlidableView::__Move.x = 0;
        if(std::fabs(SlidableView::__Move.y) < SlidableView::__MinMove.y)
                     SlidableView::__Move.y = 0;
      }
    } else if(Touch::isDown(0) && SlidableView::__Move != Vector2f()) {
      SlidableView::__Move = Vector2f();
    } else if(SlidableView::__Enable_Smooth) {
           if(SlidableView::__Move.x >  5) SlidableView::__Move.x -= SlidableView::__SlideAttenuate;
      else if(SlidableView::__Move.x < -5) SlidableView::__Move.x += SlidableView::__SlideAttenuate;
      else    SlidableView::__Move.x = 0;
           if(SlidableView::__Move.y >  5) SlidableView::__Move.y -= SlidableView::__SlideAttenuate;
      else if(SlidableView::__Move.y < -5) SlidableView::__Move.y += SlidableView::__SlideAttenuate;
      else    SlidableView::__Move.y = 0;
    } else {
      SlidableView::__Move = {};
    } SlidableView::__check();
    
    const_cast<View&>(_Renderer.getView()).move(SlidableView::__Move);
    _Renderer.setView(_Renderer.getView());
  }
}
