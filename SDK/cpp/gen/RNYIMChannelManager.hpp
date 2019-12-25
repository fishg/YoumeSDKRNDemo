// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from main.djinni

#pragma once

#include "JavascriptCallback.hpp"
#include "ReactBridge.hpp"
#include <memory>
#include <string>

/**----------------------------频道管理---------------------------- */
class RNYIMChannelManager {
public:
    virtual ~RNYIMChannelManager() {}

    static std::shared_ptr<RNYIMChannelManager> create(const std::shared_ptr<::ReactBridge> & bridge);

    /** 进入IM频道 */
    virtual void JoinChannel(const std::string & channelID, const std::shared_ptr<::JavascriptCallback> & callback) = 0;

    /** 离开IM频道 */
    virtual void LeaveChannel(const std::string & channelID, const std::shared_ptr<::JavascriptCallback> & callback) = 0;
};
