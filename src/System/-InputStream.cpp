//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func InputStream::set(const Num& value) -> void {
    InputStream::_Data.push(value);
  }
  inline func InputStream::get(void) -> const String& {
    String str = L"";
    for(const auto& i : InputStream::_Data) {
      str += std::to_wstring(static_cast<int>(i.front())); i.pop();
    } return str;
  }
};
