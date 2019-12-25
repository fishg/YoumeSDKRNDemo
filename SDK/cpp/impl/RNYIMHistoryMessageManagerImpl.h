#pragma once

#include "JavascriptCallback.hpp"
#include "ReactBridge.hpp"
#include "RNYIMHistoryMessageManager.hpp"


class RNYIMHistoryMessageManagerImpl : public RNYIMHistoryMessageManager {
public:
  RNYIMHistoryMessageManagerImpl(const std::shared_ptr<::ReactBridge>& bridge){};
  RNYIMHistoryMessageManagerImpl() {}

  virtual void QueryHistoryMessage(const std::string & targetID, int32_t chatType, const std::string & startMessageID, int32_t count, int32_t direction, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void QueryRoomHistoryMessageFromServer(const std::string & roomID, int32_t count, int32_t direction, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void DeleteHistoryMessage(const std::string & targetID, int32_t chatType, const std::string & startMessageID, int32_t count, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void DeleteHistoryMessageByID(const std::string & messageID, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void SetRoomHistoryMessageSwitch(const std::string& roomID, bool save, const std::shared_ptr< ::JavascriptCallback> &callback) override ;
};
