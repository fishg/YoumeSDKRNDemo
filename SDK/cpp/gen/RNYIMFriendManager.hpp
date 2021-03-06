// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from main.djinni

#pragma once

#include "JavascriptCallback.hpp"
#include "ReactBridge.hpp"
#include <cstdint>
#include <memory>
#include <string>

/**----------------------------好友管理---------------------------- */
class RNYIMFriendManager {
public:
    virtual ~RNYIMFriendManager() {}

    static std::shared_ptr<RNYIMFriendManager> create(const std::shared_ptr<::ReactBridge> & bridge);

    /** 功能：添加好友 */
    virtual void RequestAddFriend(const std::string & userID, const std::string & comments, const std::shared_ptr<::JavascriptCallback> & callback) = 0;

    /** 处理被请求添加好友 (dealResult：处理结果	0：同意	1：拒绝) */
    virtual void DealBeRequestAddFriend(const std::string & userID, int32_t dealResult, const std::shared_ptr<::JavascriptCallback> & callback) = 0;

    /** 删除好友 deleteType：删除类型	0：双向删除	1：单向删除(删除方在被删除方好友列表依然存在) */
    virtual void DeleteFriend(const std::string & userID, int32_t deleteType, const std::shared_ptr<::JavascriptCallback> & callback) = 0;

    /** 拉黑好友 type：0：拉黑	1：解除拉黑 */
    virtual void BlackFriend(int32_t type, const std::string & userID, const std::shared_ptr<::JavascriptCallback> & callback) = 0;

    /** 查询我的好友 */
    virtual void QueryFriends(int32_t type, int32_t startIndex, int32_t count, const std::shared_ptr<::JavascriptCallback> & callback) = 0;

    /** 查询好友请求列表 */
    virtual void QueryFriendRequestList(int32_t startIndex, int32_t count, const std::shared_ptr<::JavascriptCallback> & callback) = 0;

    /** 获取推荐好友 */
    //virtual void GetRecommandUser(int32_t startIndex, int32_t count, const std::shared_ptr<::JavascriptCallback> & callback) = 0;
};
