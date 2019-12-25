#pragma once

#include "YIM.h"


class UserInfoCallback : public IYIMUserProfileCallback
{
public:
  UserInfoCallback();
  ~UserInfoCallback();
  void Init();
  
private:
  virtual void OnQueryUserInfo(YIMErrorcode errorcode, const IMUserProfileInfo &userInfo) override;
  virtual void OnSetUserInfo(YIMErrorcode errorcode) override;
  virtual void OnSwitchUserOnlineState(YIMErrorcode errorcode) override;
  virtual void OnSetPhotoUrl(YIMErrorcode errorcode, const XString &photoUrl) override;
  virtual void OnUserInfoChangeNotify(const XString& userID) override;
};
