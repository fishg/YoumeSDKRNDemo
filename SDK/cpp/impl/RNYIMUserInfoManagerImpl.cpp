#include "RNYIMUserInfoManagerImpl.h"
#include "IMManager.h"
#include "JavascriptObject.hpp"


std::shared_ptr<RNYIMUserInfoManager> RNYIMUserInfoManager::create(const std::shared_ptr<::ReactBridge> & bridge)
{
  return std::make_shared<RNYIMUserInfoManagerImpl>(bridge);
}


void RNYIMUserInfoManagerImpl::SetUserInfo(const std::string &nickName, int32_t sex, const std::string &personalSignature, const std::string &country, const std::string &province, const std::string &city, const std::string &extraInfo, const std::shared_ptr< ::JavascriptCallback> &callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetUserProfileManager() != NULL)
  {
    IMUserSettingInfo info;
    info.nickName = nickName;
    info.sex = (IMUserSex)sex;
    info.personalSignature = personalSignature;
    info.country = country;
    info.province = province;
    info.city = city;
    info.extraInfo = extraInfo;
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetUserProfileManager()->SetUserProfileInfo(info);
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMUserInfoManagerImpl::SetUserHeadImage(const std::string &path, const std::shared_ptr< ::JavascriptCallback> &callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetUserProfileManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetUserProfileManager()->SetUserProfilePhoto(path.c_str());
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMUserInfoManagerImpl::QueryUserInfo(const std::string &userID, const std::shared_ptr< ::JavascriptCallback> &callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetUserProfileManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetUserProfileManager()->GetUserProfileInfo(userID.c_str());
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMUserInfoManagerImpl::SwitchUserStatus(const std::string &userID, int32_t status, const std::shared_ptr< ::JavascriptCallback> &callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetUserProfileManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetUserProfileManager()->SwitchUserStatus(userID.c_str(), (YIMUserStatus)status);
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMUserInfoManagerImpl::SetAddPermission(bool beFound, int32_t beAddPermission, const std::shared_ptr< ::JavascriptCallback> &callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetUserProfileManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetUserProfileManager()->SetAddPermission(beFound, (IMUserBeAddPermission) beAddPermission);
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}
