#include "MessageCallback.h"
#include "IMManager.h"
#include "RNYIMCommon.hpp"
#include "ReactBridge.hpp"
#include "JobQueueImpl.hpp"
#include "JavascriptMap.hpp"
#include "JavascriptArray.hpp"


MessageCallback::MessageCallback()
{
  
}

MessageCallback::~MessageCallback()
{
  
}

void MessageCallback::Init()
{
  if (IMManager::Instance()->GetYouMeIMManager() != NULL)
  {
    IMManager::Instance()->GetYouMeIMManager()->SetMessageCallback(this);
    IMManager::Instance()->GetYouMeIMManager()->SetDownloadCallback(this);
  }
}

void MessageCallback::OnSendMessageStatus(XUINT64 requestID, YIMErrorcode errorcode, unsigned int sendTime, bool isForbidRoom, int reasonType, XUINT64 forbidEndTime)
{
    IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
      char szRequestID[32] = {0};
      snprintf(szRequestID, sizeof(szRequestID), "%llu", requestID);
      char szForbidEndTime[32] = {0};
      snprintf(szForbidEndTime, sizeof(szForbidEndTime), "%llu", forbidEndTime);
      std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
      result->putInt("Command", RNYIMCommon::CMD_SEND_MESSAGE_STATUS);
      result->putInt("Errorcode", errorcode);
      result->putString("RequestID", szRequestID);
      result->putInt("SendTime", sendTime);
      result->putBoolean("IsForbidRoom", isForbidRoom);
      result->putInt("ReasonType", reasonType);
      result->putString("ForbidEndTime", szForbidEndTime);
      IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_MESSAGE, result);
    });
}

void MessageCallback::OnStartSendAudioMessage(XUINT64 requestID, YIMErrorcode errorcode, const XString& text, const XString& audioPath, unsigned int audioTime)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    char szRequestID[32] = {0};
    snprintf(szRequestID, sizeof(szRequestID), "%llu", requestID);
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_STOP_AUDIO_MESSAGE);
    result->putInt("Errorcode", errorcode);
    result->putString("RequestID", szRequestID);
    result->putString("Text", text);
    result->putString("AudioPath", audioPath);
    result->putInt("AudioTime", audioTime);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_MESSAGE, result);
  });
}

void MessageCallback::OnSendAudioMessageStatus(XUINT64 requestID, YIMErrorcode errorcode, const XString& text, const XString& audioPath, unsigned int audioTime, unsigned int sendTime,bool isForbidRoom,  int reasonType, XUINT64 forbidEndTime)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    char szRequestID[32] = {0};
    snprintf(szRequestID, sizeof(szRequestID), "%llu", requestID);
    char szForbidEndTime[32] = {0};
    snprintf(szForbidEndTime, sizeof(szForbidEndTime), "%llu", forbidEndTime);
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_SEND_AUDIO_MESSAGE_STATUS);
    result->putInt("Errorcode", errorcode);
    result->putString("RequestID", szRequestID);
    result->putString("Text", text);
    result->putString("AudioPath", audioPath);
    result->putInt("AudioTime", audioTime);
    result->putInt("SendTime", sendTime);
    result->putBoolean("IsForbidRoom", isForbidRoom);
    result->putInt("ReasonType", reasonType);
    result->putString("ForbidEndTime", szForbidEndTime);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_MESSAGE, result);
  });
}

void MessageCallback::OnRecvMessage( std::shared_ptr<IYIMMessage> message)
{
    IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
        char szMessageID[32] = {0};
        snprintf(szMessageID, sizeof(szMessageID), "%llu", message->GetMessageID());
        IYIMMessageBodyBase* msgBody = message->GetMessageBody();
        std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
        result->putInt("Command", RNYIMCommon::CMD_RECV_MAEESAG_NOTIFY);
        result->putString("MessageID", szMessageID);
        result->putInt("MessageType", msgBody->GetMessageType());
        result->putInt("ChatType", message->GetChatType());
        result->putString("SenderID", message->GetSenderID());
        result->putInt("SendTime", message->GetCreateTime());
        result->putString("RecverID", message->GetReceiveID());
        result->putInt("IsRead", message->IsRead());
        switch (msgBody->GetMessageType())
        {
            case MessageBodyType_TXT:
            {
                IYIMMessageBodyText* textMessage = (IYIMMessageBodyText*)msgBody;
                result->putString("Content", textMessage->GetMessageContent());
                result->putString("ExtraParam", textMessage->GetAttachParam());
            }
                break;
            case MessageBodyType_Voice:
            {
                IYIMMessageBodyAudio* voiceMessage = (IYIMMessageBodyAudio*) msgBody;
                result->putString("Content", voiceMessage->GetText());
                result->putInt("AudioTime", voiceMessage->GetAudioTime());
                result->putInt("FileSize", voiceMessage->GetFileSize());
                result->putString("ExtraParam", voiceMessage->GetExtraParam());
            }
                break;
            case MessageBodyType_File:
            {
              IYIMMessageBodyFile* fileMessage = (IYIMMessageBodyFile*) msgBody;
              result->putInt("FileSize", fileMessage->GetFileSize());
              result->putString("FileName", fileMessage->GetFileName());
              result->putInt("FileType", fileMessage->GetFileType());
              result->putString("FileExtension", fileMessage->GetFileExtension());
              result->putString("ExtraParam", fileMessage->GetExtraParam());
            }
              break;
            default:
                return;
        }
        IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_MESSAGE, result);
    });
}

void MessageCallback::OnTranslateTextComplete(YIMErrorcode errorcode, unsigned int requestID, const XString& text, LanguageCode srcLangCode, LanguageCode destLangCode)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_TEXT_TANSLATE);
    result->putInt("Errorcode", errorcode);
    result->putInt("RequestID", requestID);
    result->putString("Text", text);
    result->putInt("SrcLanguage", srcLangCode);
    result->putInt("DestLanguage", destLangCode);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_MESSAGE, result);
  });
}

void MessageCallback::OnRecordVolumeChange(float volume)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_RECORD_VOLUME_CHANGE);
    result->putDouble("Volume", volume);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_MESSAGE, result);
  });
}


void MessageCallback::OnQueryHistoryMessage(YIMErrorcode errorcode, const XString& targetID, int remain, std::list<std::shared_ptr<IYIMMessage> > messageList)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_QUERY_LOCAL_HISTORY_MSG);
    result->putInt("Errorcode", errorcode);
    result->putString("TargetID", targetID);
    result->putInt("Remain", remain);
    std::shared_ptr<JavascriptArray> array = IMManager::Instance()->GetBridge()->createArray();
    for (std::list<std::shared_ptr<IYIMMessage> >::const_iterator itr = messageList.begin(); itr != messageList.end(); ++itr)
    {
      std::shared_ptr<JavascriptMap> msgItem = IMManager::Instance()->GetBridge()->createMap();
      char szID[32] = {0};
      char szMessageID[32] = {0};
      snprintf(szID, sizeof(szID), "%llu", itr->get()->GetID());
      snprintf(szMessageID, sizeof(szMessageID), "%llu", itr->get()->GetMessageID());
      IYIMMessageBodyBase* msgBody = itr->get()->GetMessageBody();
      msgItem->putString("ID", szID);
      msgItem->putString("MessageID", szMessageID);
      msgItem->putInt("MessageType", msgBody->GetMessageType());
      msgItem->putString("SenderID", itr->get()->GetSenderID());
      msgItem->putInt("SendTime", itr->get()->GetCreateTime());
      msgItem->putInt("ChatType", itr->get()->GetChatType());
      msgItem->putInt("IsRead", itr->get()->IsRead());
      //__android_log_print(ANDROID_LOG_DEBUG,"GetMessageType","GetMessageType: %d",msgBody->GetMessageType());
      switch (msgBody->GetMessageType())
      {
        case MessageBodyType_TXT:
        {
          IYIMMessageBodyText* textMessage = (IYIMMessageBodyText*)msgBody;
          msgItem->putString("Content", textMessage->GetMessageContent());
          msgItem->putString("ExtraParam", textMessage->GetAttachParam());
        }
          break;
        case MessageBodyType_Voice:
        {
          IYIMMessageBodyAudio* voiceMessage = (IYIMMessageBodyAudio*) msgBody;
          msgItem->putString("Content", voiceMessage->GetText());
          msgItem->putInt("AudioTime", voiceMessage->GetAudioTime());
          msgItem->putInt("FileSize", voiceMessage->GetFileSize());
          msgItem->putString("ExtraParam", voiceMessage->GetExtraParam());
          msgItem->putString("LocalPath", voiceMessage->GetLocalPath());
        }
          break;
        case MessageBodyType_File:
        {
          IYIMMessageBodyFile* fileMessage = (IYIMMessageBodyFile*) msgBody;
          msgItem->putInt("MessageType",MessageBodyType_File); //统一处理为messageTypeFile
          msgItem->putInt("FileSize", fileMessage->GetFileSize());
          msgItem->putString("FileName", fileMessage->GetFileName());
          msgItem->putInt("FileType", fileMessage->GetFileType());
          msgItem->putString("FileExtension", fileMessage->GetFileExtension());
          msgItem->putString("ExtraParam", fileMessage->GetExtraParam());
          msgItem->putString("LocalPath", fileMessage->GetLocalPath());
        }
          break;
        default:
          continue;
      }
      array->pushMap(msgItem);
    }
    result->putArray("Messages", array);
    
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_HISTORYMESSAGE, result);
  });
}

void MessageCallback::OnQueryRoomHistoryMessageFromServer(YIMErrorcode errorcode, const XString& roomID, int remain, std::list<std::shared_ptr<IYIMMessage> >& tempList)
{
  std::list<std::shared_ptr<IYIMMessage> > messageList (tempList);
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_QUERY_ROOM_HISTORY_MSG_SERVER);
    result->putInt("Errorcode", errorcode);
    result->putString("TargetID", roomID);
    result->putInt("Remain", remain);
    std::shared_ptr<JavascriptArray> array = IMManager::Instance()->GetBridge()->createArray();
    for (std::list<std::shared_ptr<IYIMMessage> >::const_iterator itr = messageList.begin(); itr != messageList.end(); ++itr)
    {
      std::shared_ptr<JavascriptMap> msgItem = IMManager::Instance()->GetBridge()->createMap();
      char szMessageID[32] = {0};
      snprintf(szMessageID, sizeof(szMessageID), "%llu", itr->get()->GetMessageID());
      IYIMMessageBodyBase* msgBody = itr->get()->GetMessageBody();
      msgItem->putString("MessageID", szMessageID);
      msgItem->putInt("MessageType", msgBody->GetMessageType());
      msgItem->putString("SenderID", itr->get()->GetSenderID());
      msgItem->putInt("SendTime", itr->get()->GetCreateTime());
      msgItem->putInt("IsRead", itr->get()->IsRead());
      msgItem->putInt("ChatType", itr->get()->GetChatType());
      msgItem->putString("RecverID", itr->get()->GetReceiveID());
      switch (msgBody->GetMessageType())
      {
        case MessageBodyType_TXT:
        {
          IYIMMessageBodyText* textMessage = (IYIMMessageBodyText*)msgBody;
          msgItem->putString("Content", textMessage->GetMessageContent());
          msgItem->putString("ExtraParam", textMessage->GetAttachParam());
        }
          break;
        case MessageBodyType_Voice:
        {
          IYIMMessageBodyAudio* voiceMessage = (IYIMMessageBodyAudio*) msgBody;
          msgItem->putString("Content", voiceMessage->GetText());
          msgItem->putInt("AudioTime", voiceMessage->GetAudioTime());
          msgItem->putInt("FileSize", voiceMessage->GetFileSize());
          msgItem->putString("ExtraParam", voiceMessage->GetExtraParam());
        }
          break;
        case MessageBodyType_Image:
        case MessageBodyType_Video:
        case MessageBodyType_File:
        {
          IYIMMessageBodyFile* fileMessage = (IYIMMessageBodyFile*) msgBody;
          msgItem->putInt("FileSize", fileMessage->GetFileSize());
          msgItem->putString("FileName", fileMessage->GetFileName());
          msgItem->putInt("FileType", fileMessage->GetFileType());
          msgItem->putString("FileExtension", fileMessage->GetFileExtension());
          msgItem->putString("ExtraParam", fileMessage->GetExtraParam());

        }
          break;
        default:
          continue;
      }
      
      array->pushMap(msgItem);
    }
    result->putArray("Messages", array);
    
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_HISTORYMESSAGE_SERVER, result);
  });
}


void MessageCallback::OnDownload(YIMErrorcode errorcode, std::shared_ptr<IYIMMessage> message, const XString& savePath)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    char szMessageID[32] = {0};
    snprintf(szMessageID, sizeof(szMessageID), "%llu", message->GetMessageID());
    IYIMMessageBodyBase* msgBody = message->GetMessageBody();
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_DOWNLOAD_FILE);
    result->putInt("Errorcode", errorcode);
    result->putString("SavePath", savePath);
    if (message != NULL)
    {
      result->putString("MessageID", szMessageID);
      result->putInt("MessageType", msgBody->GetMessageType());
      result->putInt("ChatType", message->GetChatType());
      result->putString("SenderID", message->GetSenderID());
      result->putInt("SendTime", message->GetCreateTime());
      switch (msgBody->GetMessageType())
      {
        case MessageBodyType_Voice:
        {
          IYIMMessageBodyAudio* voiceMessage = (IYIMMessageBodyAudio*) msgBody;
          result->putString("Content", voiceMessage->GetText());
          result->putString("LocalPath", voiceMessage->GetLocalPath());
          result->putInt("AudioTime", voiceMessage->GetAudioTime());
          result->putInt("FileSize", voiceMessage->GetFileSize());
          result->putString("ExtraParam", voiceMessage->GetExtraParam());
        }
          break;
        case MessageBodyType_File:
        {
          IYIMMessageBodyFile* fileMessage = (IYIMMessageBodyFile*) msgBody;
          result->putInt("FileSize", fileMessage->GetFileSize());
          result->putString("FileName", fileMessage->GetFileName());
          result->putInt("FileType", fileMessage->GetFileType());
          result->putString("FileExtension", fileMessage->GetFileExtension());
          result->putString("ExtraParam", fileMessage->GetExtraParam());
          result->putString("LocalPath", fileMessage->GetLocalPath());
        }
          break;
        default:
          return;
      }
    }
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_MESSAGE, result);
  });
}

void MessageCallback::OnDownloadByUrl(YIMErrorcode errorcode, const XString& strFromUrl, const XString& savePath)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_DOWNLOAD_FILEY_BY_URL);
    result->putInt("Errorcode", errorcode);
    result->putString("Url", strFromUrl);
    result->putString("SavePath", savePath);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_MESSAGE, result);
  });
}
