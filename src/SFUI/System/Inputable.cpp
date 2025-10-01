//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  inline func KbEvent::setSettings(const String& keystr) -> void {
    KbEvent::__SETTINGS__.__ALLOW_NUMBER__
      = (keystr.find("N") != String::InvalidPos);
      
    KbEvent::__SETTINGS__.__ALLOW_LETTER__
      = (keystr.find("L") != String::InvalidPos);
    KbEvent::__SETTINGS__.__ONLY_UPPER__
      = (keystr.find("A") != String::InvalidPos);
    KbEvent::__SETTINGS__.__ONLY_LOWER__
      = (keystr.find("a") != String::InvalidPos);
      
    KbEvent::__SETTINGS__.__ALLOW_SYMBOL__
      = (keystr.find("S") != String::InvalidPos);
    KbEvent::__SETTINGS__.__ALLOW_FLOAT__
      = (keystr.find(".") != String::InvalidPos);
      
    KbEvent::__SETTINGS__.__ALLOW_NXLINE__
      = (keystr.find("+") != String::InvalidPos);
    KbEvent::__SETTINGS__.__ALLOW_DELETE__
      = (keystr.find("-") != String::InvalidPos);
  }
#if __PREDEF_ENABLE_KB_BUFFER__
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
        KbEvent::setBufString();
      } return String(tmp_buf);
    }   return L"";
  }
  
  inline func KbEvent::setBufString(const String& value) -> void {
    KbEvent::__Buffer = value;
  }
  
  inline func KbEvent::getBufSize(void) -> size_t {
    return KbEvent::__Buffer.getSize();
  }
  
  inline func KbEvent::backspace(void) -> void {
    if(!KbEvent::__Buffer.isEmpty()) {
        KbEvent::__Buffer.erase(
        KbEvent::__Buffer.getSize() - 1);
    }
  }
  inline func KbEvent::nextLine(void) -> void {
    KbEvent::__Buffer += "\n";
  }
  inline func KbEvent::pushBack(const String& str) -> void {
    KbEvent::__Buffer += str;
  }
#endif
  inline func KbEvent::isDown(const Event& event, uint32_t key) -> bool {
    return(event.type == Event::TextEntered && event.text.unicode == key);
  }

  inline func KbEvent::pollEvent(const Event& event, bool inBuf) -> String {
    if(event.type == Event::TextEntered) {
      if(event.text.unicode > 31
      && event.text.unicode < 126) {
        // Check Settings
        char __tmp_input = static_cast<char>(event.text.unicode);
        if(__tmp_input == 46 && (KbEvent::__SETTINGS__.__ALLOW_SYMBOL__
                             ||  KbEvent::__SETTINGS__.__ALLOW_FLOAT__)) {
          #if __PREDEF_ENABLE_KB_BUFFER__
          if(KbEvent::__SETTINGS__.__ALLOW_FLOAT__
          && KbEvent::__Buffer.find(".") == String::InvalidPos) {
             KbEvent::__Buffer += std::to_wstring(".");
          #endif
             return L".";
          #if __PREDEF_ENABLE_KB_BUFFER__
          }
          #endif
        }
        if(!(KbEvent::__SETTINGS__.__ALLOW_NUMBER__ || !std::isdigit(__tmp_input))
        || !(KbEvent::__SETTINGS__.__ALLOW_LETTER__ || !std::isalpha(__tmp_input))
        || !(KbEvent::__SETTINGS__.__ALLOW_SYMBOL__ ||  std::isdigit(__tmp_input)
                                                    ||  std::isalpha(__tmp_input)))
        return L"";
        // Codecvt
        std::string str; std::stringstream strsr;
        strsr << __tmp_input; strsr >> str;
        if(std::isalpha(__tmp_input)) {
          if(KbEvent::__SETTINGS__.__ONLY_UPPER__
          && KbEvent::__SETTINGS__.__ONLY_LOWER__) return "";
          else if(KbEvent::__SETTINGS__.__ONLY_UPPER__)
            std::transform(str.begin(), str.end(), str.begin(), ::toupper);
          else if(KbEvent::__SETTINGS__.__ONLY_LOWER__)
            std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        }
        if(inBuf) {
          #if __PREDEF_ENABLE_KB_BUFFER__
          KbEvent::__Buffer += std::to_wstring(str);
          #endif
        }               return std::to_wstring(str);
      } else if(event.text.unicode == 10) {
        if(KbEvent::__SETTINGS__.__ALLOW_NXLINE__) {
          #if __PREDEF_ENABLE_KB_BUFFER__
          if(inBuf) KbEvent::nextLine();
          #endif
        } else sf::Keyboard::setVirtualKeyboardVisible(false);
        return L"\n";
      }
    } else if(event.type == Event::KeyPressed) {
      if(event.text.unicode == 59
      && KbEvent::__SETTINGS__.__ALLOW_DELETE__) {
        #if __PREDEF_ENABLE_KB_BUFFER__
        if(inBuf) KbEvent::backspace();
        #endif
        return "\b";
      }
    }
    
    for(const auto& i : KbEvent::__supportKeyboard) i(event);
    
    return "";
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
  inline func TouchEvent::getFingerMaxNum(void) -> unsigned {
    return TouchEvent::__FingerMaxNum;
  }
  
  inline func TouchEvent::setTouchPosDeviat(const Vector2f& value) -> void {
    TouchEvent::__TouchPosDeviat = value;
  }
  inline func TouchEvent::getTouchPosDeviat(void) -> const Vector2f& {
    return TouchEvent::__TouchPosDeviat;
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
    } return Time::Zero;
  }

  inline func TouchEvent::pollEvent(const Event& event) -> void {
    for(unsigned i = 0; i < TouchEvent::__FingerMaxNum; ++i) {
      if(!Touch::isDown(i)) {
        if(event.type == Event::TouchBegan) {
          TouchEvent::__TouchData.at(i).second.restart();
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
  inline func TouchEvent::getPosition(unsigned index, bool global) -> Vector2f {
    if(Touch::isDown(index)) {
      return (static_cast<Vector2f>(Touch::getPosition(index, _Renderer))
        + (global ? (Renderable::getViewPosition()) : Vector2f{}))
        + TouchEvent::__TouchPosDeviat;
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
