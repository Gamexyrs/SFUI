//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  inline func ScrollableView::__check(void) -> void {
    if(!ScrollableView::v.__Enable_HorizontalMove
    ||      Renderable::getViewPosition().x
    + ScrollableView::v.__Move.x < ScrollableView::v.__HorizontalMax.x)
      ScrollableView::resetHorizontalView();
    else if(Fm::getRoot(Renderable::getViewRect()).x
    + ScrollableView::v.__Move.x > ScrollableView::v.__HorizontalMax.y)
      const_cast<View&>(_Renderer.getView()).move(
        {ScrollableView::v.__HorizontalMax.y - Fm::getRoot(Renderable::getViewRect()).x,
         ScrollableView::v.__Move.x = 0});
      
    if(!ScrollableView::v.__Enable_VerticalMove
    ||      Renderable::getViewPosition().y
    + ScrollableView::v.__Move.y < ScrollableView::v.__VerticalMax.x)
      ScrollableView::resetVerticalView();
    else if(Fm::getRoot(Renderable::getViewRect()).y
    + ScrollableView::v.__Move.y > ScrollableView::v.__VerticalMax.y)
      const_cast<View&>(_Renderer.getView()).move(
        {ScrollableView::v.__Move.y = 0,
         ScrollableView::v.__VerticalMax.y - Fm::getRoot(Renderable::getViewRect()).y});
  }
  
  inline func ScrollableView::setMoveFactor(float value) -> void {
    ScrollableView::v.__MoveFactor = value;
  }
  inline func ScrollableView::getMoveFactor(void) -> float {
    return ScrollableView::v.__MoveFactor;
  }
  
  inline func ScrollableView::setSlideAttenuate(float value) -> void {
    ScrollableView::v.__SlideAttenuate = value;
  }
  inline func ScrollableView::getSlideAttenuate(void) -> float {
    return ScrollableView::v.__SlideAttenuate;
  }
  
  inline func ScrollableView::setReactTime(const Time& value) -> void {
    ScrollableView::v.__ReactTime = value;
  }
  inline func ScrollableView::getReactTime(void) -> const Time& {
    return ScrollableView::v.__ReactTime;
  }
  
  inline func ScrollableView::setMinMove(const Vector2f& value) -> void {
    ScrollableView::v.__MinMove = Fm::abs(value);
  }
  inline func ScrollableView::getMinMove(void) -> const Vector2f& {
    return ScrollableView::v.__MinMove;
  }
  
  inline func ScrollableView::setHorizontalMax(const Vector2f& value) -> void {
    ScrollableView::v.__HorizontalMax = value;
  }
  inline func ScrollableView::getHorizontalMax(void) -> const Vector2f& {
    return ScrollableView::v.__HorizontalMax;
  }
  
  inline func ScrollableView::setVerticalMax(const Vector2f& value) -> void {
    ScrollableView::v.__VerticalMax = value;
  }
  inline func ScrollableView::getVerticalMax(void) -> const Vector2f& {
    return ScrollableView::v.__VerticalMax;
  }
  
  inline func ScrollableView::setSmoothEnable(bool value) -> void {
    ScrollableView::v.__Enable_Smooth = value;
  }
  inline func ScrollableView::getSmoothEnable(void) -> bool {
    return ScrollableView::v.__Enable_Smooth;
  }
  
  inline func ScrollableView::setMutexMoveEnable(bool value) -> void {
    ScrollableView::v.__Enable_MutexMove = value;
  }
  inline func ScrollableView::getMutexMoveEnable(void) -> bool {
    return ScrollableView::v.__Enable_MutexMove;
  }
  
  inline func ScrollableView::setHorizontalMoveEnable(bool value) -> void {
    ScrollableView::v.__Enable_HorizontalMove = value;
  }
  inline func ScrollableView::getHorizontalMoveEnable(void) -> bool {
    return ScrollableView::v.__Enable_HorizontalMove;
  }
  
  inline func ScrollableView::setVerticalMoveEnable(bool value) -> void {
    ScrollableView::v.__Enable_VerticalMove = value;
  }
  inline func ScrollableView::getVerticalMoveEnable(void) -> bool {
    return ScrollableView::v.__Enable_VerticalMove;
  }

  inline func ScrollableView::setCopyableData(const CopyableData& value) -> void {
    ScrollableView::v = value;
  }
  inline func ScrollableView::getCopyableData(void) -> CopyableData {
    return ScrollableView::v;
  }

  inline func ScrollableView::getAutoSliding(void) -> bool {
    return ScrollableView::v.__Move != Vector2f();
  }
  
  inline func ScrollableView::resetHorizontalView(void) -> void {
    const_cast<View&>(_Renderer.getView()).move(
      {-Renderable::getViewPosition().x, ScrollableView::v.__Move.x = 0});
  }
  inline func ScrollableView::resetVerticalView(void) -> void {
    const_cast<View&>(_Renderer.getView()).move(
      {ScrollableView::v.__Move.y = 0, -Renderable::getViewPosition().y});
  }
  
  inline func ScrollableView::pollEvent(void) -> void {
    if(Msgable::getLocked()) {
      ScrollableView::v.__Move = {}; return;
    }
    if(TouchEvent::getTouchTime(0).asMilliseconds()       >= ScrollableView::v.__ReactTime.asMilliseconds()) {
      ScrollableView::v.__Move = TouchEvent::getTouchMove() * -ScrollableView::v.__MoveFactor;
      if(ScrollableView::v.__Enable_MutexMove) {
        if(std::fabs(ScrollableView::v.__Move.y)
        >= std::fabs(ScrollableView::v.__Move.x))
           ScrollableView::v.__Move.x = 0;
        else
           ScrollableView::v.__Move.y = 0;
        if(std::fabs(ScrollableView::v.__Move.x) < ScrollableView::v.__MinMove.x)
                     ScrollableView::v.__Move.x = 0;
        if(std::fabs(ScrollableView::v.__Move.y) < ScrollableView::v.__MinMove.y)
                     ScrollableView::v.__Move.y = 0;
      }
    } else if(Touch::isDown(0) && ScrollableView::v.__Move != Vector2f{}) {
      ScrollableView::v.__Move = Vector2f{};
    } else if(ScrollableView::v.__Enable_Smooth) {
           if(ScrollableView::v.__Move.x >  5) ScrollableView::v.__Move.x -= ScrollableView::v.__SlideAttenuate;
      else if(ScrollableView::v.__Move.x < -5) ScrollableView::v.__Move.x += ScrollableView::v.__SlideAttenuate;
      else    ScrollableView::v.__Move.x = 0;
           if(ScrollableView::v.__Move.y >  5) ScrollableView::v.__Move.y -= ScrollableView::v.__SlideAttenuate;
      else if(ScrollableView::v.__Move.y < -5) ScrollableView::v.__Move.y += ScrollableView::v.__SlideAttenuate;
      else    ScrollableView::v.__Move.y = 0;
    } else {
      ScrollableView::v.__Move = {};
    } ScrollableView::__check();
    
    const_cast<View&>(_Renderer.getView()).move(ScrollableView::v.__Move);
    _Renderer.setView(_Renderer.getView());
  }
}
