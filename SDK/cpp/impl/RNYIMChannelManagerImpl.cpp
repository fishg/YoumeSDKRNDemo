#include "RNYIMChannelManagerImpl.h"
#include "IMManager.h"
#include "JavascriptObject.hpp"


std::shared_ptr<RNYIMChannelManager> RNYIMChannelManager::create(const std::shared_ptr<::ReactBridge> & bridge)
{
  return std::make_shared<RNYIMChannelManagerImpl>(bridge);
}


void RNYIMChannelManagerImpl::JoinChannel(const std::string & channelID, const std::shared_ptr<::JavascriptCallback> & callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetChatRoomManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetChatRoomManager()->JoinChatRoom(channelID.c_str());
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMChannelManagerImpl::LeaveChannel(const std::string & channelID, const std::shared_ptr<::JavascriptCallback> & callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetChatRoomManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetChatRoomManager()->LeaveChatRoom(channelID.c_str());
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}
