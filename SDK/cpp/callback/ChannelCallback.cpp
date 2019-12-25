#include "ChannelCallback.h"
#include "IMManager.h"
#include "RNYIMCommon.hpp"
#include "ReactBridge.hpp"
#include "JavascriptMap.hpp"
#include "JobQueueImpl.hpp"


ChannelCallback::ChannelCallback()
{
  
}

ChannelCallback::~ChannelCallback()
{
  
}

void ChannelCallback::Init()
{
  if (IMManager::Instance()->GetYouMeIMManager() != NULL)
  {
    IMManager::Instance()->GetYouMeIMManager()->SetChatRoomCallback(this);
  }
}

void ChannelCallback::OnJoinChatRoom(YIMErrorcode errorcode, const XString& chatRoomID)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_JOIN_ROOM);
    result->putInt("Errorcode", errorcode);
    result->putString("ChannelID", chatRoomID);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_CHANNEL, result);
  });
}

void ChannelCallback::OnLeaveChatRoom(YIMErrorcode errorcode, const XString& chatRoomID)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_LEAVE_ROOM);
    result->putInt("Errorcode", errorcode);
    result->putString("ChannelID", chatRoomID);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_CHANNEL, result);
  });
}
