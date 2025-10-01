//>>> 2021~2025 Gamexyrs© & SFML®

namespace sf::ui {
  inline func Describable::setDescription(const String& value) -> void {
    this->__Description = value;
  }
  inline func Describable::getDescription(void) const -> const String& {
    return this->__Description;
  }

  inline func Describable::setLabel(const String& value) -> void {
    this->__Label = value;
  }
  inline func Describable::getLabel(void) const -> const String& {
    return this->__Label;
  }

  template<typename type>
  inline func Describable::setTag(const type& value) -> void {
    this->__Tag = std::make_any<type>(value);
  }
  template<typename type>
  inline func Describable::getTag(void) const -> type {
    return this->hasTag() ? std::any_cast<type>(this->__Tag) : type{};
  }
  inline func Describable::hasTag(void) const -> bool {
    return this->__Tag.has_value();
  }
}
