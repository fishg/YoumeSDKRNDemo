#pragma once

#include "YIM.h"


class AudioPlayCallback : public IYIMAudioPlayCallback
{
public:
  AudioPlayCallback();
  ~AudioPlayCallback();
  void Init();
  
private:
  virtual void OnPlayCompletion(YIMErrorcode errorcode, const XString& path) override;
  virtual void OnGetMicrophoneStatus(AudioDeviceStatus status) override;
};
