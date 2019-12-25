#include "RNYIMLocationManagerImpl.h"
#include "IMManager.h"
#include "JavascriptObject.hpp"


std::shared_ptr<RNYIMLocationManager> RNYIMLocationManager::create(const std::shared_ptr<::ReactBridge> & bridge)
{
  return std::make_shared<RNYIMLocationManagerImpl>(bridge);
}


void RNYIMLocationManagerImpl::GetCurrentLocation(const std::shared_ptr< ::JavascriptCallback> &callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetLocationManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetLocationManager()->GetCurrentLocation();
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMLocationManagerImpl::GetNearbyObjects(int32_t count, const std::string &serverAreaID, int32_t districtLevel, bool resetStartDistance, const std::shared_ptr< ::JavascriptCallback> &callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetLocationManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetLocationManager()->GetNearbyObjects(count, serverAreaID.c_str(), (DistrictLevel)districtLevel, resetStartDistance);
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMLocationManagerImpl::GetDistance(const std::string &userID, const std::shared_ptr< ::JavascriptCallback> &callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetLocationManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetLocationManager()->GetDistance(userID.c_str());
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}
