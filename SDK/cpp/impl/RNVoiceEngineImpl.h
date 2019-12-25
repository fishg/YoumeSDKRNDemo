#pragma once


#include "JavascriptCallback.hpp"
#include "RNVoiceEngine.hpp"
#include "YouMeConstDefine.h"
#include "IYouMeEventCallback.h"


class RNVoiceEngineImpl : public RNVoiceEngine, public IYouMeEventCallback,IYouMeMemberChangeCallback,IRestApiCallback
{
public:
  RNVoiceEngineImpl(const std::shared_ptr<::ReactBridge>& bridge){}
  ~RNVoiceEngineImpl() {}
  
  virtual void Init(const std::string & appkey, const std::string & appsecret, int32_t model, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void JoinChannelSingleMode(const std::string & userID, const std::string & channel, int32_t userRole, bool checkRoomExist, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void LeaveChannelAll(const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void SetSpeakerMute(bool on, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void SetMicrophoneMute(bool mute, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void SetOtherMicMute(const std::string & userID, bool mute, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void SetListenOtherVoice(const std::string & userID, bool on, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void SetOutputToSpeaker(bool on, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void SetAutoSendStatus(bool on, const std::shared_ptr<::JavascriptCallback> & callback) override;

  virtual void requestRestApi(const std::string & strCommand, const std::string & strQueryBody, const std::shared_ptr<::JavascriptCallback> & callback) override;
  
  virtual void onEvent(const YouMeEvent event, const YouMeErrorCode error, const char * channel, const char * param) override;
  virtual void onMemberChange( const char* channel, const char* listMemberChange , bool bUpdate ) override;
  virtual void onRequestRestAPI( int requestID, const YouMeErrorCode &iErrorCode, const char* strQuery, const char*  strResult ) override ;
};
