//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "../Button/PushButton.hpp"

namespace sf::ui {
  typedef struct MessageData {
    String title{""};
    String info {""};
    
    Font* font{nullptr};
    
    std::vector<std::pair<String, int>>
      btn{{L"确定", 1}};
      
    size_t btnTextSize{35};
    
  }MsgData;
  
  typedef class MessageDiv : public TextDiv, public Msgable {
  public:    MessageDiv(unsigned radius = 0,
                        const Vector2f& sizeFactor = {0.7, 0.15},
                        const Align& align = Align::C);
    virtual ~MessageDiv(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, const RenderStates& states) const -> void;
    virtual func update(void) const -> void;
    
    std::vector<std::unique_ptr<PushBtn>> __Btn{};
    std::queue <MsgData> __Msg{};
    
    TextDiv __Info{};
        Div __Mask{};
    
    uint8_t __MaskTrs{155};
    
    bool __Pushing{false};
    
  _data_public:
    func setTitleTextColor(const Color&) _____ -> void;
    func getTitleTextColor(void) const -> const Color&;
    
    func setInfoTextColor(const Color&) _____ -> void;
    func getInfoTextColor(void) const -> const Color&;
    
    func getInfo(bool update = true) const -> TextDiv&;
    
    func setMaskColor(const Color&) _____ -> void;
    func getMaskColor(void) const -> Color;
    
    func getQueueSize(void) const -> size_t;
    
  _func_public:
#if   (__cplusplus >= 202002L)
    [[nodiscard("Must use such 'auto r = <name>.pollEvent(*)' to get the result code")]]
#elif (__cplusplus >= 201703L)
    [[nodiscard]]
#endif
    virtual func pollEvent(const Event& event) -> std::optional<int>;
    
    func buttonIsDown(void) const -> std::optional<int>;
    
    func stopPushing(bool delMsg = true) -> void;
    func isPushing  (void) const -> bool;
    
    func launchQueue(const MsgData& msg, bool push = false) -> size_t;
    func  clearQueue(void) -> void;
    
    virtual func pushQueue(void) -> void;
    
  }MsgDiv;
}

#include "../../../../src/SFUI/Graphics/Div/MessageDiv.cpp"
