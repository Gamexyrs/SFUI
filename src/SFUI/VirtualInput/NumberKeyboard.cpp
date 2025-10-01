//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  NumKeyboard::NumberKeyboard(void) {
    this->__Base.setSize({_RendererSize.x, _RendererSize.y * 0.3f});
    this->__Base.setTextString(L" SFUI Virtual Input - NumKeyboard");
    this->__Base.setCharSize(20);
    this->__Base.setTextColor(Color::White);
    this->__Base.setFillColor(ColorEx::Grey);
    this->__Base.mov.setAuto(true);
    
    for(auto& i : this->__KeyBtns)
      i.resize(3);
    
    for(size_t i = 0; i < this->__KeyBtns.size(); ++i) {
      for(size_t j = 0; j < this->__KeyBtns[i].size(); ++j) {
        if(i != 3) {
          this->__KeyBtns[i][j].setTag<int>(i * 3 + j + 1);
          this->__KeyBtns[i][j].setTextString(std::to_wstring(i * 3 + j + 1));
          this->__KeyBtns[i][j].setTextDeviat({0, -10});
          this->__KeyBtns[i][j].getText().setStyle(Text::Style::Bold | Text::Style::Italic);
        } else if(j == 1) {
          this->__KeyBtns[i][j].getText().setStyle(Text::Style::Bold | Text::Style::Italic);
        }
        
        if(!i && !j) {
          this->__KeyBtns[i][j].setSize({(this->__Base.getSize().x - 52.0f) / 3.0f,
                                         (this->__Base.getSize().y - 70.0f) / 4.0f});
          this->__KeyBtns[i][j].setBuilder(this->__Base, Vector2f{18, 28});
        } else {
          this->__KeyBtns[i][j].setSize(this->__KeyBtns.front().front().getSize());
          
          if(!j) {
            this->__KeyBtns[i][j].setBuilder(this->__KeyBtns[i - 1][j], Vector2f{0, 8}, Vector2b{false, true});
          } else {
            this->__KeyBtns[i][j].setBuilder(this->__KeyBtns[i][j - 1], Vector2f{8, 0}, Vector2b{true, false});
          }
        }
        this->__KeyBtns[i][j].__ATTRIBUTE__.__ALWAYS_TOUCHABLE__ = true;
        this->__KeyBtns[i][j].setRadius(14);
        this->__KeyBtns[i][j].setCharSize(60);
        this->__KeyBtns[i][j].setTouchRectDeviat({0, 20});
        this->__KeyBtns[i][j].setTextAlign(Align::C);
      }
    }
    this->__KeyBtns[3][0].setTag<int>(-1);
    this->__KeyBtns[3][0].setTextString(L"<");
    this->__KeyBtns[3][0].setTextDeviat({0, -18});
    this->__KeyBtns[3][1].setTag<int>(0);
    this->__KeyBtns[3][1].setTextString(L"0");
    this->__KeyBtns[3][1].setTextDeviat({0, -10});
    this->__KeyBtns[3][2].setTag<int>(-2);
    this->__KeyBtns[3][2].setTextString(L"确定");
    
    // must ensure the kb is living.
    KbEvent::__supportKeyboard.emplace_back(std::bind(&NumKeyboard::pollEvent, this, std::placeholders::_1));
  }
  
  inline func NumKeyboard::draw(RenderTarget& target, const RenderStates& states) const -> void {
    if(!this->__Displaying && !this->__Calling) return;
    
    this->update();
    
    static Vector2f __spos{};

    const View& __view{target.getView()};
    if(this->__standPos == Vector2f{})
       this->__standPos = {__view.getCenter().x - __view.getSize().x / 2.0f,
                           __view.getCenter().y + __view.getSize().y / 2.0f};
    
    if(this->__Calling) {
      if(this->__Displaying && this->__Base.mov.isEnd()) {
        this->__Base.setPosition(__standPos + Vector2f{0, -this->__Base.getSize().y});
        Msgable::setLocked(true);
      }
      if(!this->__Displaying) {
        if(__spos != __view.getCenter()) {
           __spos  = __view.getCenter();
          this->__Base.setPosition(__standPos);
        }
        this->__Base.mov.apply(MoveMethod::standard(Vector2f{0, -this->__Base.getSize().y}, static_cast<size_t>(4)), true);
        this->__Displaying = true;
      }
    } else if(this->__Displaying) {
      if(this->__Base.getPosition().y >= __standPos.y) {
        this->__Displaying = false; return;
      } this->__Base.move({0, 100});
    }
    
    target.draw(this->__Base, states);
    for(const auto& i : this->__KeyBtns)
      for(const auto& j : i)
        target.draw(j, states);
  }
  
  inline func NumKeyboard::update(void) const -> void {
    for(size_t i = 0; i < this->__KeyBtns.size(); ++i) {
      for(size_t j = 0; j < this->__KeyBtns[i].size(); ++j) {
        if(!i && !j)
          this->__KeyBtns[i][j].setSize({(this->__Base.getSize().x - 52.0f) / 3.0f,
                                         (this->__Base.getSize().y - 70.0f) / 4.0f});
        else
          this->__KeyBtns[i][j].setSize(this->__KeyBtns.front().front().getSize());
      }
    }
  }
  
  inline func NumKeyboard::setStandPos(const Vector2f& value) -> void {
    this->__standPos = value;
  }
  
  inline func NumKeyboard::getBase(void) const -> Div& {
    return const_cast<TextDiv&>(this->__Base);
  }
  inline func NumKeyboard::getKeyBtns(void) const -> std::vector<std::vector<PushBtn>>& {
    return const_cast<std::vector<std::vector<PushBtn>>&>(this->__KeyBtns);
  }
  
  inline func NumKeyboard::pollEvent(const Event& event) -> bool {
    if(!this->__Displaying && !this->__Calling) return false;
    if(Touch::isDown(0) && !TouchEvent::isDownAt(this->__Base.getRect() + FloatRect{-10, -10, 20, 20})) { this->callback(); return false; }
    
    for(auto& i : this->__KeyBtns) for(auto& j : i) if(j.pollEvent_if(event)) {
      if(j.getTag<int>() > -1) KbEvent::pushBack(std::to_wstring(j.getTag<int>()));
      else if(j.getTag<int>() == -1) KbEvent::backspace();
      else if(j.getTag<int>() == -2) this->callback();
      return true;
    }
    return false;
  }
  
  inline func NumKeyboard::call(void) -> void {
    this->__Calling = true;
    Msgable::setLocked(true);
  }
  inline func NumKeyboard::callback(void) -> void {
    this->__Calling = false;
    Msgable::setLocked(false);
  }
  inline func NumKeyboard::isCalling(void) const -> bool {
    return this->__Calling;
  }
  
  inline func NumKeyboard::bind(void) -> std::pair<std::function<void(void)>, std::function<void(void)>> {
    return{std::bind(&NumKeyboard::call, this), std::bind(&NumKeyboard::callback, this)};
  }
}
