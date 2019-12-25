#include "RNYIMHistoryMessageManagerImpl.h"
#include "IMManager.h"
#include "JavascriptObject.hpp"
#include <cstdlib>


std::shared_ptr<RNYIMHistoryMessageManager> RNYIMHistoryMessageManager::create(const std::shared_ptr<::ReactBridge> & bridge)
{
  return std::make_shared<RNYIMHistoryMessageManagerImpl>(bridge);
}


void RNYIMHistoryMessageManagerImpl::QueryHistoryMessage(const std::string &targetID, int32_t chatType, const std::string &startMessageID, int32_t count, int32_t direction, const std::shared_ptr< ::JavascriptCallback> &callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetMessageManager() != NULL)
  {
    unsigned long long msgID = atoll(startMessageID.c_str());
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetMessageManager()->QueryHistoryMessage(targetID.c_str(), (YIMChatType)chatType, msgID, count, direction);
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}


void RNYIMHistoryMessageManagerImpl::QueryRoomHistoryMessageFromServer(const std::string &roomID, int32_t count, int32_t direction, const std::shared_ptr< ::JavascriptCallback> &callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetMessageManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetMessageManager()->QueryRoomHistoryMessageFromServer(roomID.c_str(), count, direction);
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}


void RNYIMHistoryMessageManagerImpl::DeleteHistoryMessage(const std::string &targetID, int32_t chatType, const std::string &startMessageID, int32_t count, const std::shared_ptr< ::JavascriptCallback> &callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetMessageManager() != NULL)
  {
    unsigned long long startID = atoll(startMessageID.c_str());
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetMessageManager()->DeleteHistoryMessage(targetID.c_str(), (YIMChatType)chatType, startID, count);
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMHistoryMessageManagerImpl::DeleteHistoryMessageByID(const std::string &messageID, const std::shared_ptr< ::JavascriptCallback> &callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetMessageManager() != NULL)
  {
    unsigned long long msgID = atoll(messageID.c_str());
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetMessageManager()->DeleteHistoryMessageByID(msgID);
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMHistoryMessageManagerImpl::SetRoomHistoryMessageSwitch(const std::string& roomID, bool save, const std::shared_ptr< ::JavascriptCallback> &callback)
{
  int errorcode = YIMErrorcode_EngineNotInit;

  if (IMManager::Instance()->GetYouMeIMManager() != NULL
            && IMManager::Instance()->GetYouMeIMManager()->GetMessageManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetMessageManager()->SetRoomHistoryMessageSwitch(roomID.c_str(), save);
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}
