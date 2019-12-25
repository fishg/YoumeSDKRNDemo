#include "RNYIMMessageManagerImpl.h"
#include "IMManager.h"
#include "JavascriptObject.hpp"
#include <cstdlib>


std::shared_ptr<RNYIMMessageManager> RNYIMMessageManager::create(const std::shared_ptr<::ReactBridge> & bridge)
{
  return std::make_shared<RNYIMMessageManagerImpl>(bridge);
}


void RNYIMMessageManagerImpl::SendTextMessage(const std::string & receiverID, int32_t chatType, const std::string & text,const std::string & extra, const std::shared_ptr<::JavascriptCallback> & callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  std::string strRequestID;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetMessageManager() != NULL)
  {
    XUINT64 requestID = 0;
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetMessageManager()->SendTextMessage(receiverID.c_str(), (YIMChatType)chatType, text.c_str(), extra.c_str(), &requestID);
    if (YIMErrorcode_Success == errorcode)
    {
      char szRequestID[32] = {0};
      snprintf(szRequestID, sizeof(szRequestID), "%llu", requestID);
      strRequestID = std::string(szRequestID);
    }
  }
  callback->invoke(std::vector<std::shared_ptr<JavascriptObject>>{
    JavascriptObject::fromInt(errorcode),
    JavascriptObject::fromString(strRequestID)});
}

void RNYIMMessageManagerImpl::SendAudioMessage(const std::string & receiverID, int32_t chatType, const std::shared_ptr<::JavascriptCallback> & callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  std::string strRequestID;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetMessageManager() != NULL)
  {
    XUINT64 requestID = 0;
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetMessageManager()->SendAudioMessage(receiverID.c_str(), (YIMChatType)chatType, &requestID);
    if (YIMErrorcode_Success == errorcode)
    {
      char szRequestID[32] = {0};
      snprintf(szRequestID, sizeof(szRequestID), "%llu", requestID);
      strRequestID = std::string(szRequestID);
    }
  }
  callback->invoke(std::vector<std::shared_ptr<JavascriptObject>>{
    JavascriptObject::fromInt(errorcode),
    JavascriptObject::fromString(strRequestID)});
}

void RNYIMMessageManagerImpl::SendOnlyAudioMessage(const std::string & receiverID, int32_t chatType, const std::shared_ptr<::JavascriptCallback> & callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  std::string strRequestID;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetMessageManager() != NULL)
  {
    XUINT64 requestID = 0;
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetMessageManager()->SendOnlyAudioMessage(receiverID.c_str(), (YIMChatType)chatType, &requestID);
    if (YIMErrorcode_Success == errorcode)
    {
      char szRequestID[32] = {0};
      snprintf(szRequestID, sizeof(szRequestID), "%llu", requestID);
      strRequestID = std::string(szRequestID);
    }
  }
  callback->invoke(std::vector<std::shared_ptr<JavascriptObject>>{
    JavascriptObject::fromInt(errorcode),
    JavascriptObject::fromString(strRequestID)});
}

void RNYIMMessageManagerImpl::StopAudioMessage(const std::string & extraParam, const std::shared_ptr<::JavascriptCallback> & callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetMessageManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetMessageManager()->StopAudioMessage(extraParam.c_str());
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMMessageManagerImpl::CancelAudioMessage(const std::shared_ptr<::JavascriptCallback> & callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetMessageManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetMessageManager()->CancleAudioMessage();
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMMessageManagerImpl::SendFile(const std::string & receiverID, int32_t chatType, const std::string & filePath, int32_t fileType, const std::string & extraParam, const std::shared_ptr<::JavascriptCallback> & callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  std::string strRequestID;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetMessageManager() != NULL)
  {
    XUINT64 requestID = 0;
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetMessageManager()->SendFile(receiverID.c_str(), (YIMChatType)chatType, filePath.c_str(), &requestID, extraParam.c_str(), (YIMFileType)fileType);
    if (YIMErrorcode_Success == errorcode)
    {
      char szRequestID[32] = {0};
      snprintf(szRequestID, sizeof(szRequestID), "%llu", requestID);
      strRequestID = std::string(szRequestID);
    }
  }
  callback->invoke(std::vector<std::shared_ptr<JavascriptObject>>{
    JavascriptObject::fromInt(errorcode),
    JavascriptObject::fromString(strRequestID)});
}

void RNYIMMessageManagerImpl::DownloadFile(const std::string & messageID, const std::string & savePath, const std::shared_ptr<::JavascriptCallback> & callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetMessageManager() != NULL)
  {
    unsigned long long msgID = atoll(messageID.c_str());
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetMessageManager()->DownloadFile(msgID, savePath.c_str());
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMMessageManagerImpl::DownloadFileByUrl(const std::string & url, const std::string & savePath, const std::shared_ptr<::JavascriptCallback> & callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetMessageManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetMessageManager()->DownloadFile(url.c_str(), savePath.c_str());
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMMessageManagerImpl::SetMessageRead(const std::string & messageID, bool isRead, const std::shared_ptr<::JavascriptCallback> & callback)
{
    YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
    if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetMessageManager() != NULL)
    {
    unsigned long long msgID = atoll(messageID.c_str());
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetMessageManager()->SetMessageRead(msgID, isRead);
    }
    callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}
void RNYIMMessageManagerImpl::SetAllMessageRead(const std::string & userID, bool isRead, const std::shared_ptr<::JavascriptCallback> & callback)
{
    YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
    if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetMessageManager() != NULL)
    {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetMessageManager()->SetAllMessageRead(userID.c_str(), isRead);
    }
    callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}