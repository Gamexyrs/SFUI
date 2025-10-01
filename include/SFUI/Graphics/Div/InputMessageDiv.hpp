//>>> 2021~2025 Gamexyrs© & SFML®

#pragma once

#ifdef __PREDEF_ENABLE_KB_BUFFER__
#if    __PREDEF_ENABLE_KB_BUFFER__

#include "InputDiv.hpp"
#include "MessageDiv.hpp"

namespace sf::ui {
  typedef class InputMessageDiv : public MsgDiv {
  public:    InputMessageDiv(int radius = 0,
                             const Vector2f& sizeFactor = {0.7, 0.25},
                             const Align& align = Align::C);
    virtual ~InputMessageDiv(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
    virtual func update(void) const -> void;
    
    InputDiv __Input{};
    
  _data_public:
    func getInput(bool update = true) const -> InputDiv&;
    
  _func_public:
#if   (__cplusplus >= 202002L)
    [[nodiscard("Must use such 'auto r = <name>.pollEvent(*)' to get the result code")]]
#elif (__cplusplus == 201703L)
    [[nodiscard]]
#endif
    // it won't be closed when clicked the button, to check the input is correct.
    virtual func pollEvent(const Event& event) -> std::optional<int>;
    
    func getInputString(void) -> const String&;
    
    virtual func pushQueue(void) -> void;
    
  }InputMsgDiv;
}

#include "../../../../src/SFUI/Graphics/Div/InputMessageDiv.cpp"

#endif
#endif
