#pragma once

#include "YIM.h"


class MessageCallback : public IYIMMessageCallback, public IYIMDownloadCallback
{
public:
  MessageCallback();
  ~MessageCallback();
  void Init();
  
private:
  virtual void OnSendMessageStatus(XUINT64 requestID, YIMErrorcode errorcode, unsigned int sendTime, bool isForbidRoom, int reasonType, XUINT64 forbidEndTime) override;
  virtual void OnStartSendAudioMessage(XUINT64 requestID, YIMErrorcode errorcode, const XString& text, const XString& audioPath, unsigned int audioTime) override;
  virtual void OnSendAudioMessageStatus(XUINT64 requestID, YIMErrorcode errorcode, const XString& text, const XString& audioPath, unsigned int audioTime, unsigned int sendTime,bool isForbidRoom,  int reasonType, XUINT64 forbidEndTime) override;
  virtual void OnRecvMessage( std::shared_ptr<IYIMMessage> message) override;
  virtual void OnTranslateTextComplete(YIMErrorcode errorcode, unsigned int requestID, const XString& text, LanguageCode srcLangCode, LanguageCode destLangCode) override;
  virtual void OnRecordVolumeChange(float volume) override;
  
  virtual void OnQueryHistoryMessage(YIMErrorcode errorcode, const XString& targetID, int remain, std::list<std::shared_ptr<IYIMMessage> > messageList) override;
  virtual void OnQueryRoomHistoryMessageFromServer(YIMErrorcode errorcode, const XString& roomID, int remain, std::list<std::shared_ptr<IYIMMessage> >& messageList) override;
  
  
  virtual void OnDownload(YIMErrorcode errorcode, std::shared_ptr<IYIMMessage> message, const XString& savePath) override;
  virtual void OnDownloadByUrl(YIMErrorcode errorcode, const XString& strFromUrl, const XString& savePath) override;
};
