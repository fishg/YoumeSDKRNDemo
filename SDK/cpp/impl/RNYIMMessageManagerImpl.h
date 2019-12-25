#pragma once

#include "ReactBridge.hpp"
#include "RNYIMMessageManager.hpp"

class RNYIMMessageManagerImpl : public RNYIMMessageManager
{
public:
  RNYIMMessageManagerImpl(const std::shared_ptr<::ReactBridge>& bridge){};
  ~RNYIMMessageManagerImpl() {}

  virtual void SendTextMessage(const std::string & receiverID, int32_t chatType, const std::string & text, const std::string & extra,const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void SendAudioMessage(const std::string & receiverID, int32_t chatType, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void SendOnlyAudioMessage(const std::string & receiverID, int32_t chatType, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void StopAudioMessage(const std::string & extraParam, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void CancelAudioMessage(const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void SendFile(const std::string & receiverID, int32_t chatType, const std::string & filePath, int32_t fileType, const std::string & extraParam, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void DownloadFile(const std::string & messageID, const std::string & savePath, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void DownloadFileByUrl(const std::string & url, const std::string & savePath, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void SetMessageRead(const std::string & messageID, bool isRead, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void SetAllMessageRead(const std::string & userID, bool isRead, const std::shared_ptr<::JavascriptCallback> & callback) override;
};
