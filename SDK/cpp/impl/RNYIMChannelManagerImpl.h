#pragma once

#include "ReactBridge.hpp"
#include "RNYIMChannelManager.hpp"


class RNYIMChannelManagerImpl : public RNYIMChannelManager{
public:
  RNYIMChannelManagerImpl(const std::shared_ptr<::ReactBridge>& bridge){};
  virtual ~RNYIMChannelManagerImpl() {}

  virtual void JoinChannel(const std::string & channelID, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void LeaveChannel(const std::string & channelID, const std::shared_ptr<::JavascriptCallback> & callback) override;
};
