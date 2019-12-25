#include "AudioPlayCallback.h"
#include "IMManager.h"
#include "RNYIMCommon.hpp"
#include "ReactBridge.hpp"
#include "JavascriptMap.hpp"
#include "JobQueueImpl.hpp"


AudioPlayCallback::AudioPlayCallback()
{
  
}

AudioPlayCallback::~AudioPlayCallback()
{
  
}

void AudioPlayCallback::Init()
{
  if (IMManager::Instance()->GetYouMeIMManager() != NULL)
  {
    IMManager::Instance()->GetYouMeIMManager()->SetAudioPlayCallback(this);
  }
}

void AudioPlayCallback::OnPlayCompletion(YIMErrorcode errorcode, const XString& path)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_PLAY_COMPLETE_NOTIFY);
    result->putInt("Errorcode", errorcode);
    result->putString("Path", path);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_PLAY, result);
  });
}

void AudioPlayCallback::OnGetMicrophoneStatus(AudioDeviceStatus status)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_GET_MICROPHONE_STATUS);
    result->putInt("AudioDeviceStatus", status);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_PLAY, result);
  });
}
