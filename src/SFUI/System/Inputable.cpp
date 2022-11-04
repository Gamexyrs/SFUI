//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func KbEvent::setSettings(const String& str) -> void {
    KbEvent::__SETTINGS__.__ALLOW_NUMBER__
      = (str.find("N") != String::InvalidPos);
    KbEvent::__SETTINGS__.__ALLOW_LETTER__
      = (str.find("L") != String::InvalidPos);
    KbEvent::__SETTINGS__.__ALLOW_SYMBOL__
      = (str.find("S") != String::InvalidPos);
    KbEvent::__SETTINGS__.__ALLOW_NXLINE__
      = (str.find("+") != String::InvalidPos);
    KbEvent::__SETTINGS__.__ALLOW_DELETE__
      = (str.find("D") != String::InvalidPos);
  }
  
  inline func KbEvent::getBufPwString(bool dLast, wchar_t dChar) -> String {
    if(!KbEvent::__Buffer.isEmpty()) {
      String tmp_str = L"";
      for(const auto& i  :  KbEvent::__Buffer) {
        if(dLast && (&i == &KbEvent::__Buffer[KbEvent::__Buffer.getSize() - 1])) {
               tmp_str +=   KbEvent::__Buffer[KbEvent::__Buffer.getSize() - 1];
        } else tmp_str += ((i == '\n') ? '\n' : dChar);
      } return tmp_str;
    }   return L"";
  }
  inline func KbEvent::getBufString(bool reset) -> String {
    if(!KbEvent::__Buffer.isEmpty()) {
      String tmp_buf = KbEvent::__Buffer;
      if(reset) {
        KbEvent::delBufString();
      } return tmp_buf;
    }   return L"";
  }
  inline func KbEvent::delBufString(void) -> void {
    KbEvent::__Buffer = L"";
  }
  
  inline func KbEvent::getBufSize(void) -> size_t {
    return KbEvent::__Buffer.getSize();
  }
  
  inline func KbEvent::backspace(void) -> void {
    if(!KbEvent::__Buffer.isEmpty()) {
      KbEvent::__Buffer.erase(KbEvent::__Buffer.getSize() - 1);
    }
  }
  inline func KbEvent::nextLine(void) -> void {
    KbEvent::__Buffer += "\n";
  }
  inline func KbEvent::pushBack(const String& str) -> void {
    KbEvent::__Buffer += str;
  }
  
  inline func KbEvent::pollEvent(const Event& event, bool inBuf) -> String {
    if(event.type == Event::TextEntered) {
      if(event.text.unicode > 31
      && event.text.unicode < 126) {
        // Check Settings
        char tmp_input = static_cast<char>(event.text.unicode);
        if(!(KbEvent::__SETTINGS__.__ALLOW_NUMBER__ || !std::isdigit(tmp_input))
        || !(KbEvent::__SETTINGS__.__ALLOW_LETTER__ || !std::isalpha(tmp_input))
        || !(KbEvent::__SETTINGS__.__ALLOW_SYMBOL__ ||  std::isdigit(tmp_input)
                                                    ||  std::isalpha(tmp_input)))
        return L"";
        // Codecvt
        std::string str; std::stringstream strsr;
        strsr << tmp_input; strsr >> str;
        if(inBuf) {
          KbEvent::__Buffer += std::to_wstring(str);
        }               return std::to_wstring(str);
      } else if(event.text.unicode == 10
        && KbEvent::__SETTINGS__.__ALLOW_NXLINE__) {
           KbEvent::nextLine();
      }
    } else if(event.type == Event::KeyPressed) {
      if(event.text.unicode == 59
      && KbEvent::__SETTINGS__.__ALLOW_DELETE__) {
         KbEvent::backspace();
      }
    } return "";
  }

// ▲ class KeyboardEvent
//>>>
// ▼ class TouchEvent

  inline func TouchEvent::setFingerMaxNum(unsigned value) -> void {
#if __PREDEF_ENABLE_TOUCHDATA__
    TouchEvent::__TouchData.resize(value);
#endif
    TouchEvent::__FingerMaxNum = value;
  }
  inline func TouchEvent::getFingerMaxNum(void) _____ -> unsigned {
    return TouchEvent::__FingerMaxNum;
  }
#if __PREDEF_ENABLE_TOUCHDATA__
  inline func TouchEvent::getTouchMove(void) -> Vector2f {
    return (TouchEvent::__TouchData.at(0).first == Vector2f())
      ? Vector2f() : TouchEvent::__TouchMove;
  }
  
  inline func TouchEvent::resetTouchTime(std::optional<unsigned> index) -> void {
    if(index.has_value()) {
      TouchEvent::__TouchData.at(index.value()).second.restart();
    } else for(auto& i : TouchEvent::__TouchData) {
      i.second.restart();
    }
  }
  inline func TouchEvent::getTouchTime(unsigned index) -> Time {
    if(Touch::isDown(index)) {
      return TouchEvent::__TouchData.at(index).second.getElapsedTime();
    } else return Time::Zero;
  }

  inline func TouchEvent::pollEvent(const Event& event) -> void {
    for(unsigned i = 0; i < TouchEvent::__FingerMaxNum; ++i) {
      if(!Touch::isDown(i)) {
        if(event.type == Event::TouchBegan) {
          TouchEvent::__TouchData.at(i - 1).second.restart();
        } for(; i < TouchEvent::__FingerMaxNum; ++i) {
          TouchEvent::__TouchData.at(i).first = {};
        } return;
      } else if(!i && TouchEvent::__TouchData.at(0).first != Vector2f()) {
           TouchEvent::__TouchMove
        = (TouchEvent::getPosition(0) - TouchEvent::__TouchData.at(0).first);
      } TouchEvent::__TouchData.at(i).first = TouchEvent::getPosition(i);
    }
  }
#endif 
  inline func TouchEvent::getPosition(unsigned index) -> Vector2f {
    if(Touch::isDown(index)) {
      return static_cast<Vector2f>(Touch::getPosition(index, _Renderer));
    } else return Vector2f();
  }

  inline func TouchEvent::isDownAt(const std::optional<FloatRect>& optRect) -> unsigned {
    FloatRect rect = optRect.value_or(_RendererRect);
    for(unsigned i = 0; i < TouchEvent::__FingerMaxNum; ++i) {
           if(!Touch::isDown(i))                         return false;
      else if(rect.contains(TouchEvent::getPosition(i))) return (i + 1);
    } return false;
  }
}
