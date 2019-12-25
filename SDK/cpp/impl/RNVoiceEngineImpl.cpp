#include "RNVoiceEngineImpl.h"
#include "IYouMeVoiceEngine.h"
#include "IMManager.h"
#include "RNYIMCommon.hpp"
#include "ReactBridge.hpp"
#include "JavascriptMap.hpp"
#include "JobQueueImpl.hpp"
#include "JavascriptObject.hpp"


//extern void youme_setServerMode(int serverMode);

std::shared_ptr<RNVoiceEngine> RNVoiceEngine::create(const std::shared_ptr<::ReactBridge> & bridge)
{
  return std::make_shared<RNVoiceEngineImpl>(bridge);
}


void RNVoiceEngineImpl::Init(const std::string &appkey, const std::string &appsecret, int32_t model, const std::shared_ptr<::JavascriptCallback> & callback)
{
  if (model == RNYIMCommon::MODEL_TEST)
  {
    //youme_setServerMode((int)SERVER_MODE_TEST);
  }
  
  YouMeErrorCode errorcode = YOUME_ERROR_NOT_INIT;
  if (IYouMeVoiceEngine::getInstance())
  {
    errorcode = IYouMeVoiceEngine::getInstance()->init(this, appkey.c_str(), appsecret.c_str(), RTC_CN_SERVER, "cn");
    if(errorcode == YOUME_SUCCESS)
    {
      IYouMeVoiceEngine::getInstance()->setMemberChangeCallback(this);
      IYouMeVoiceEngine::getInstance()->setRestApiCallback(this);
    }
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNVoiceEngineImpl::JoinChannelSingleMode(const std::string &userID, const std::string &channel, int32_t userRole, bool checkRoomExist, const std::shared_ptr<::JavascriptCallback> & callback)
{
  YouMeErrorCode errorcode = YOUME_ERROR_NOT_INIT;
  if (IYouMeVoiceEngine::getInstance())
  {
    errorcode = IYouMeVoiceEngine::getInstance()->joinChannelSingleMode(userID.c_str(), channel.c_str(), YouMeUserRole(userRole));
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNVoiceEngineImpl::requestRestApi(const std::string & strCommand, const std::string & strQueryBody, const std::shared_ptr<::JavascriptCallback> & callback)
{
  YouMeErrorCode errorcode = YOUME_ERROR_NOT_INIT;
  if (IYouMeVoiceEngine::getInstance())
  {
    int requestID = 0;
    errorcode = IYouMeVoiceEngine::getInstance()->requestRestApi(strCommand.c_str(),strQueryBody.c_str(),&requestID);
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNVoiceEngineImpl::LeaveChannelAll(const std::shared_ptr<::JavascriptCallback> & callback)
{
  YouMeErrorCode errorcode = YOUME_ERROR_NOT_INIT;
  if (IYouMeVoiceEngine::getInstance())
  {
    IYouMeVoiceEngine::getInstance()->leaveChannelAll();
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNVoiceEngineImpl::SetSpeakerMute(bool on, const std::shared_ptr<::JavascriptCallback> & callback)
{
  YouMeErrorCode errorcode = YOUME_ERROR_NOT_INIT;
  if (IYouMeVoiceEngine::getInstance())
  {
    IYouMeVoiceEngine::getInstance()->setSpeakerMute(on);
    errorcode = YOUME_SUCCESS;
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNVoiceEngineImpl::SetOutputToSpeaker(bool on, const std::shared_ptr<::JavascriptCallback> & callback)
{
    YouMeErrorCode errorcode = YOUME_ERROR_NOT_INIT;
    if (IYouMeVoiceEngine::getInstance())
    {
        IYouMeVoiceEngine::getInstance()->setOutputToSpeaker(on);
        errorcode = YOUME_SUCCESS;
    }
    callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNVoiceEngineImpl::SetAutoSendStatus(bool on, const std::shared_ptr<::JavascriptCallback> & callback)
{
    YouMeErrorCode errorcode = YOUME_ERROR_NOT_INIT;
    if (IYouMeVoiceEngine::getInstance())
    {
        IYouMeVoiceEngine::getInstance()->setAutoSendStatus(on);
        errorcode = YOUME_SUCCESS;
    }
    callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNVoiceEngineImpl::SetMicrophoneMute(bool mute, const std::shared_ptr<::JavascriptCallback> & callback)
{
  YouMeErrorCode errorcode = YOUME_ERROR_NOT_INIT;
  if (IYouMeVoiceEngine::getInstance())
  {
    IYouMeVoiceEngine::getInstance()->setMicrophoneMute(mute);
    errorcode = YOUME_SUCCESS;
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNVoiceEngineImpl::SetOtherMicMute(const std::string &userID, bool mute, const std::shared_ptr<::JavascriptCallback> & callback)
{
  YouMeErrorCode errorcode = YOUME_ERROR_NOT_INIT;
  if (IYouMeVoiceEngine::getInstance())
  {
    errorcode = IYouMeVoiceEngine::getInstance()->setOtherMicMute(userID.c_str(), mute);
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNVoiceEngineImpl::SetListenOtherVoice(const std::string &userID, bool on, const std::shared_ptr<::JavascriptCallback> & callback)
{
  YouMeErrorCode errorcode = YOUME_ERROR_NOT_INIT;
  if (IYouMeVoiceEngine::getInstance())
  {
    errorcode = IYouMeVoiceEngine::getInstance()->setListenOtherVoice(userID.c_str(), on);
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNVoiceEngineImpl::onEvent(const YouMeEvent event, const YouMeErrorCode error, const char *c_channel, const char *c_param)
{
  std::string channel;
  std::string param;
  if(c_channel != NULL){
    channel = std::string(c_channel);
  }
  if(c_param != NULL){
    param = std::string(c_param);
  }
  switch (event)
  {
    case YOUME_EVENT_INIT_OK:
    case YOUME_EVENT_INIT_FAILED:
    {
      IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
        std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
        result->putInt("Command", RNYIMCommon::CMD_INIT);
        result->putInt("Errorcode", error);
        IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
      });
    }
      break;
    case YOUME_EVENT_JOIN_OK:
    case YOUME_EVENT_JOIN_FAILED:
    {
      IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
        IYouMeVoiceEngine::getInstance()->setVadCallbackEnabled(true);
        IYouMeVoiceEngine::getInstance()->setMicLevelCallback(30);
        std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
        result->putInt("Command", RNYIMCommon::CMD_JOIN_CHANNEL);
        result->putInt("Errorcode", error);
        result->putString("Channel", channel);
        result->putString("UserID", param);
        IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
        if(error == YOUME_SUCCESS){
          IYouMeVoiceEngine::getInstance()->getChannelUserList(channel.c_str(),100,true);
        }
      });
    }
      break;
    case YOUME_EVENT_LEAVED_ALL:
    {
      IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
        std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
        result->putInt("Command", RNYIMCommon::CMD_LEAVE_ALL_CHANNEL);
        result->putInt("Errorcode", error);
        result->putString("Channel", channel);
        IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
      });
    }
      break;
    case YOUME_EVENT_LOCAL_MIC_ON:        // 自己的麦克风打开
    {
      IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
        std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
        result->putInt("Command", RNYIMCommon::CMD_SELF_MICROPHONE_CHANGE);
        result->putInt("Errorcode", error);
        result->putInt("Status", 1);
        result->putString("UserID", param);
        IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
      });
    }
      break;
    case YOUME_EVENT_LOCAL_MIC_OFF:       // 自己的麦克风关闭
    {
      IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
        std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
        result->putInt("Command", RNYIMCommon::CMD_SELF_MICROPHONE_CHANGE);
        result->putInt("Errorcode", error);
        result->putInt("Status", 0);
        result->putString("UserID", param);
        IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
      });
    }
      break;
    case YOUME_EVENT_LOCAL_SPEAKER_ON:     // 自己的扬声器打开
    {
      IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
        std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
        result->putInt("Command", RNYIMCommon::CMD_SELF_SPEAKER_CHANGE);
        result->putInt("Errorcode", error);
        result->putInt("Status", 1);
        IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
      });
    }
      break;
    case YOUME_EVENT_LOCAL_SPEAKER_OFF:   // 自己的扬声器关闭
    {
      IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
        std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
        result->putInt("Command", RNYIMCommon::CMD_SELF_SPEAKER_CHANGE);
        result->putInt("Errorcode", error);
        result->putInt("Status", 0);
        IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
      });
    }
      break;
    case YOUME_EVENT_OTHERS_MIC_ON:       // 其他用户麦克风打开
    {
      IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
        std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
        result->putInt("Command", RNYIMCommon::CMD_OTHER_MICROPHONE_CHANGE);
        result->putString("UserID", param);
        result->putInt("Status", 1);
        IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
      });
    }
      break;
    case YOUME_EVENT_OTHERS_MIC_OFF:      // 其他用户麦克风关闭
    {
      IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
        std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
        result->putInt("Command", RNYIMCommon::CMD_OTHER_MICROPHONE_CHANGE);
        result->putString("UserID", param);
        result->putInt("Status", 0);
        IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
      });
    }
      break;
    case YOUME_EVENT_OTHERS_SPEAKER_ON:   // 其他用户扬声器打开
    {
      IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
        std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
        result->putInt("Command", RNYIMCommon::CMD_OTHER_SPEAKER_CHANGE);
        result->putString("UserID", param);
        result->putInt("Status", 1);
        IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
      });
    }
      break;
    case YOUME_EVENT_OTHERS_SPEAKER_OFF:  // 其他用户扬声器关闭
    {
      IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
        std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
        result->putInt("Command", RNYIMCommon::CMD_OTHER_SPEAKER_CHANGE);
        result->putString("UserID", param);
        result->putInt("Status", 0);
        IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
      });
    }
      break;
    case YOUME_EVENT_OTHERS_VOICE_ON:     // 其他用户进入讲话状态
    {
      IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
        std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
        result->putInt("Command", RNYIMCommon::CMD_OTHER_SPEECH_CHANGE);
        result->putString("UserID", param);
        result->putInt("Status", 1);
        IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
      });
    }
      break;
    case YOUME_EVENT_OTHERS_VOICE_OFF:    // 其他用户进入静默状态
    {
      IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
        std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
        result->putInt("Command", RNYIMCommon::CMD_OTHER_SPEECH_CHANGE);
        result->putString("UserID", param);
        result->putInt("Status", 0);
        IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
      });
    }
      break;
    case YOUME_EVENT_MIC_CTR_ON:          // 麦克风被其他用户打开
    {
      IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
        std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
        result->putInt("Command", RNYIMCommon::CMD_MICROPHONE_BE_CHANGE);
        result->putString("UserID", param);
        result->putInt("Status", 1);
        IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
      });
    }
      break;
    case YOUME_EVENT_MIC_CTR_OFF:         // 麦克风被其他用户关闭
    {
      IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
        std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
        result->putInt("Command", RNYIMCommon::CMD_MICROPHONE_BE_CHANGE);
        result->putString("UserID", param);
        result->putInt("Status", 0);
        IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
      });
    }
      break;
    case YOUME_EVENT_SPEAKER_CTR_ON:      // 扬声器被其他用户打开
    {
      IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
        std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
        result->putInt("Command", RNYIMCommon::CMD_SPEAKER_BE_CHANGE);
        result->putString("UserID", param);
        result->putInt("Status", 1);
        IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
      });
    }
      break;
    case YOUME_EVENT_SPEAKER_CTR_OFF:     // 扬声器被其他用户关闭
    {
      IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
        std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
        result->putInt("Command", RNYIMCommon::CMD_SPEAKER_BE_CHANGE);
        result->putString("UserID", param);
        result->putInt("Status", 0);
        IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
      });
    }
      break;
    case YOUME_EVENT_MY_MIC_LEVEL:
    {
        IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
            std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
            result->putInt("Command", RNYIMCommon::CMD_MY_MIC_LEVEL);
            result->putInt("level", error);
            IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
        });
    }
        break;
    default:
      break;
  }
}

void RNVoiceEngineImpl::onMemberChange( const char* c_channel, const char* c_listMemberChange , bool bUpdate )
{
  std::string channel(c_channel);
  std::string listMemberChange(c_listMemberChange);
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
      std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
      result->putInt("Command", RNYIMCommon::CMD_CHANNEL_MEMBER_CHANGE_NOTIFY);
      result->putInt("Errorcode", 0);
      result->putString("Channel", channel);
      result->putString("MemberList", listMemberChange);
      result->putBoolean("isUpdate", bUpdate);
      IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
  });
}

void RNVoiceEngineImpl::onRequestRestAPI( int requestID, const YouMeErrorCode &iErrorCode, const char* strQuery, const char*  strResult )
{
    std::string query (strQuery);
    std::string resultStr (strResult);
    int code = iErrorCode;
    IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
        std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
        result->putInt("Command", RNYIMCommon::CMD_REST_API);
        result->putInt("Errorcode", code);
        result->putString("Query", query);
        result->putString("Result", resultStr);
        IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_VOICE, result);
    });
}
