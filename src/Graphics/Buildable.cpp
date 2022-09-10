//>>> 2021~2022 Gamexyrs© & SFML®

namespace sf::ui {
  inline func Buildable::followerNeedUpdate(void) const -> void {
    for(auto& i : this->Follower) i->needUpdate(true);
  }
  
  inline func Buildable::setBuilder(Object& builder, const Vector2f& deviat, bool cW, bool cH) -> void {
    if(this->Builder != &builder) (this->Builder = &builder)->Follower.emplace_back(this->Self);
    this->setBuilder(deviat, cW, cH);
  }
  inline func Buildable::setBuilder(const Vector2f& deviat, bool cW, bool cH) -> void {
   this->BuildDeviat = deviat; this->BuildWidth = cW; this->BuildHeight = cH;
  }
  inline func Buildable::getBuilder(void) const -> Object& {
    return *this->Builder;
  }
  inline func Buildable::delBuilder(void) -> void {
    for(std::deque<Object*>::iterator it = this->Builder->Follower.begin(); it != this->Builder->Follower.end(); it++) {
      if((*it) == this->Self) { this->Builder->Follower.erase(it); break; }
    } this->Builder = nullptr;
  }
};
