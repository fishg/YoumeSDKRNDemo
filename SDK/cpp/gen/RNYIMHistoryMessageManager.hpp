// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from main.djinni

#pragma once

#include "JavascriptCallback.hpp"
#include "ReactBridge.hpp"
#include <cstdint>
#include <memory>
#include <string>

/**----------------------------历史消息管理---------------------------- */
class RNYIMHistoryMessageManager {
public:
    virtual ~RNYIMHistoryMessageManager() {}

    static std::shared_ptr<RNYIMHistoryMessageManager> create(const std::shared_ptr<::ReactBridge> & bridge);

    /** 查询本地历史消息 */
    virtual void QueryHistoryMessage(const std::string & targetID, int32_t chatType, const std::string & startMessageID, int32_t count, int32_t direction, const std::shared_ptr<::JavascriptCallback> & callback) = 0;

    /** 查询服务端房间最近历史消息 */
    virtual void QueryRoomHistoryMessageFromServer(const std::string & roomID, int32_t count, int32_t direction, const std::shared_ptr<::JavascriptCallback> & callback) = 0;

    /** 删除本地历史消息 */
    virtual void DeleteHistoryMessage(const std::string & targetID, int32_t chatType, const std::string & startMessageID, int32_t count, const std::shared_ptr<::JavascriptCallback> & callback) = 0;

    /** 删除本地历史消息 */
    virtual void DeleteHistoryMessageByID(const std::string & messageID, const std::shared_ptr<::JavascriptCallback> & callback) = 0;

    virtual void SetRoomHistoryMessageSwitch(const std::string & roomID, bool save, const std::shared_ptr<::JavascriptCallback> & callback) = 0;
};