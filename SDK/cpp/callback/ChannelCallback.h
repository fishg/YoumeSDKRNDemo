#pragma once

#include "YIM.h"


class ChannelCallback : public IYIMChatRoomCallback
{
public:
  ChannelCallback();
  ~ChannelCallback();
  void Init();
  
private:
  virtual void OnJoinChatRoom(YIMErrorcode errorcode, const XString& chatRoomID) override;
  virtual void OnLeaveChatRoom(YIMErrorcode errorcode, const XString& chatRoomID) override;
};
