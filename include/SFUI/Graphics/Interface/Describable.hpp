//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

#include <any>

namespace sf::ui {
  typedef interface class Describable {
  protected:
    String __Description{};
    String __Label{};
    std::any __Tag{};
  
  _data_public:
    func setDescription(const String&) -> void;
    func getDescription(void) const -> const String&;
    
    func setLabel(const String&) -> void;
    func getLabel(void) const -> const String&;
    
    template<typename type = int>
    func setTag(const type&) -> void;
    template<typename type = int>
    func getTag(void) const -> type;
    func hasTag(void) const -> bool;
  
  } Describable;
}

#include "../../../../src/SFUI/Graphics/Interface/Describable.cpp"
