#include "UserInfoCallback.h"
#include "IMManager.h"
#include "RNYIMCommon.hpp"
#include "ReactBridge.hpp"
#include "JavascriptMap.hpp"
#include "JobQueueImpl.hpp"
#include "JavascriptArray.hpp"


UserInfoCallback::UserInfoCallback()
{
  
}

UserInfoCallback::~UserInfoCallback()
{
  
}

void UserInfoCallback::Init()
{
  if (IMManager::Instance()->GetYouMeIMManager() != NULL)
  {
    IMManager::Instance()->GetYouMeIMManager()->SetUserProfileCallback(this);
  }
}

void UserInfoCallback::OnQueryUserInfo(YIMErrorcode errorcode, const IMUserProfileInfo &userInfo)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_QUERY_USER_INFO);
    result->putInt("Errorcode", errorcode);
    result->putString("UserID", userInfo.userID);
    result->putString("HeadImage", userInfo.photoURL);
    result->putString("Nickname", userInfo.settingInfo.nickName);
    result->putInt("Sex", userInfo.settingInfo.sex);
    result->putString("Signature", userInfo.settingInfo.personalSignature);
    result->putString("Country", userInfo.settingInfo.country);
    result->putString("Province", userInfo.settingInfo.province);
    result->putString("City", userInfo.settingInfo.city);
    result->putString("ExtraInfo", userInfo.settingInfo.extraInfo);
    result->putInt("Status", userInfo.onlineState);
    result->putInt("BeAddPermission", userInfo.beAddPermission);
    result->putInt("FoundPermission", userInfo.foundPermission);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_USERINFO, result);
  });
}

void UserInfoCallback::OnSetUserInfo(YIMErrorcode errorcode)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_SET_USER_INFO);
    result->putInt("Errorcode", errorcode);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_USERINFO, result);
  });
}

void UserInfoCallback::OnSwitchUserOnlineState(YIMErrorcode errorcode)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_SWITCH_USER_STATUS);
    result->putInt("Errorcode", errorcode);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_USERINFO, result);
  });
}

void UserInfoCallback::OnSetPhotoUrl(YIMErrorcode errorcode, const XString &photoUrl)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_SET_HEAD_IMAGE);
    result->putInt("Errorcode", errorcode);
    result->putString("HeadImageUrl", photoUrl);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_USERINFO, result);
  });
}

void UserInfoCallback::OnUserInfoChangeNotify(const XString &userID)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_UNSER_INFO_CHANGE_NOTIFY);
    result->putString("UserID", userID);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_USERINFO, result);
  });
}
