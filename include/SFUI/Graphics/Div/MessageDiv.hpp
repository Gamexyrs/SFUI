//>>> 2021~2022 Gamexyrs© & SFML®

#pragma once

#include "../Button.hpp"
#include <utility>

namespace sf::ui {
  typedef struct MessageData {
    String title = "";
    String info  = "";
    
    Font* font = nullptr;
    
    std::vector<std::pair<String, int>>
      btn = {{"OK", 1}};
    
  }MsgData;
  
  typedef class MessageDiv : public TextDiv, public Messagable {
  public:    MessageDiv(unsigned radius = 0,
                        const Vector2f& sizeFactor = {0.7, 0.15},
                        const Align& align = Align::C);
    virtual ~MessageDiv(void) = default;
    
  protected:
    virtual func draw(RenderTarget& target, RenderStates states) const -> void;
    virtual func update(void) const -> void;
    
    std::vector<std::unique_ptr<PushBtn>> __Btn;
    std::queue <MsgData> __Msg;
    
    TextDiv __Info;
        Div __Mask;
    
    bool __MaskVisible = true;
    bool __Pushing     = false;
    
  _data_public:
    func setTitleTextColor(const Color& value) -> void;
    func getTitleTextColor(void) const -> const Color&;
    
    func setInfoTextColor(const Color& value) -> void;
    func getInfoTextColor(void) const -> const Color&;
    
    func setMaskVisible(bool value) -> void;
    func getMaskVisible(void) const -> bool;
    
    func setMaskColor(const Color& value) -> void;
    func getMaskColor(void) const -> const Color&;
    
    func getQueueSize(void) const -> size_t;
    
  _func_public:
    virtual func pollEvent(const Event& event) -> std::optional<int>;
    
    func stopPushing(bool delMsg = true) -> void;
    
    func launchQueue(const MsgData& msg, bool push = false) -> size_t;
    func  clearQueue(void) -> void;
    virtual func pushQueue(void) -> void;
    
  }MsgDiv;
}

#include "../../../../src/SFUI/Graphics/Div/MessageDiv.cpp"
