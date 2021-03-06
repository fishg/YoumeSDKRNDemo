// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from main.djinni

#pragma once

#include "JavascriptCallback.hpp"
#include "ReactBridge.hpp"
#include <cstdint>
#include <memory>
#include <string>

/**----------------------------IM管理类---------------------------- */
class RNYIMManager {
public:
    virtual ~RNYIMManager() {}

    static std::shared_ptr<RNYIMManager> create(const std::shared_ptr<::ReactBridge> & bridge);

    /** 初始化 */
    virtual void Init(const std::string & appkey, const std::string & secret, const std::string & packageName, int32_t model, const std::shared_ptr<::JavascriptCallback> & callback) = 0;

    /**
     * 登录
     *Login(userID:string, password:string, promise:JavascriptPromise);	      				
     */
    virtual void Login(const std::string & userID, const std::string & password,const std::string & token, const std::shared_ptr<::JavascriptCallback> & callback) = 0;

    /** 登出 */
    virtual void Logout(const std::shared_ptr<::JavascriptCallback> & callback) = 0;

    /** 播放语音 */
    virtual void StartPlayAudio(const std::string & path, const std::shared_ptr<::JavascriptCallback> & callback) = 0;

    /** 停止播放 */
    virtual void StopPlayAudio(const std::shared_ptr<::JavascriptCallback> & callback) = 0;

    /** 获取最近联系人(最大100条) */
    virtual void GetRecentContacts(const std::shared_ptr<::JavascriptCallback> & callback) = 0;

    /** 程序切到后台运行 */
    virtual void OnPause() = 0;

    /** 程序切到前台运行 */
    virtual void OnResume() = 0;

    /** 设置录音缓存目录 */
    virtual void SetAudioRecordCacheDir(const std::string & path) = 0;

    /** 获取语音缓存目录(返回值 path:string) */
    virtual void GetAudioCachePath(const std::shared_ptr<::JavascriptCallback> & callback) = 0;

    /** 清理语音缓存目录(返回值 result:bool) */
    virtual void ClearAudioCachePath() = 0;

    /** 关键词过滤（返回值 text:string 过滤后文本, level:int 关键字等级） */
    virtual void FilterKeyword(const std::string & text, const std::shared_ptr<::JavascriptCallback> & callback) = 0;

};
