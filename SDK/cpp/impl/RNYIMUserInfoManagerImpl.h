#pragma once


#include "JavascriptCallback.hpp"
#include "RNYIMUserInfoManager.hpp"


class RNYIMUserInfoManagerImpl : public RNYIMUserInfoManager {
public:
  RNYIMUserInfoManagerImpl(const std::shared_ptr<::ReactBridge>& bridge){}
  ~RNYIMUserInfoManagerImpl() {}

  virtual void SetUserInfo(const std::string & nickName, int32_t sex, const std::string & personalSignature, const std::string & country, const std::string & province, const std::string & city, const std::string & extraInfo, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void SetUserHeadImage(const std::string & path, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void QueryUserInfo(const std::string & userID, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void SwitchUserStatus(const std::string & userID, int32_t status, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void SetAddPermission(bool beFound, int32_t beAddPermission, const std::shared_ptr<::JavascriptCallback> & callback) override;
  //virtual void SetUserExtendStatus(const std::string & status, const std::shared_ptr<::JavascriptCallback> & callback) override;
  //virtual void SetHeaderImageUrl(const std::string & url, const std::shared_ptr<::JavascriptCallback> & callback) override;
};
