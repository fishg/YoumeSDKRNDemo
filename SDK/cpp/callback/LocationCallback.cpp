#include "LocationCallback.h"
#include "IMManager.h"
#include "RNYIMCommon.hpp"
#include "ReactBridge.hpp"
#include "JavascriptMap.hpp"
#include "JobQueueImpl.hpp"
#include "JavascriptArray.hpp"


LocationCallback::LocationCallback()
{
  
}

LocationCallback::~LocationCallback()
{
  
}

void LocationCallback::Init()
{
  if (IMManager::Instance()->GetYouMeIMManager() != NULL)
  {
    IMManager::Instance()->GetYouMeIMManager()->SetLocationCallback(this);
  }
}

void LocationCallback::OnUpdateLocation(YIMErrorcode errorcode, std::shared_ptr<GeographyLocation> location)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_LOCATION_UPDATE);
    result->putInt("Errorcode", errorcode);
    result->putDouble("Longitude", location->GetLongitude());
    result->putDouble("Latitude", location->GetLatitude());
    result->putInt("DistrictCode", location->GetDistrictCode());
    result->putString("Country", location->GetCountry());
    result->putString("Province", location->GetProvince());
    result->putString("City", location->GetCity());
    result->putString("DistrictCounty", location->GetDistrictCounty());
    result->putString("Street", location->GetStreet());
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_LOCATION, result);
  });
}

void LocationCallback::OnGetNearbyObjects(YIMErrorcode errorcode, std::list<std::shared_ptr<RelativeLocation> > neighbourList, unsigned int startDistance, unsigned int endDistance)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_LOCATION_GET_NEARBY_OBJECT);
    result->putInt("Errorcode", errorcode);
    result->putInt("StartDistance", startDistance);
    result->putInt("EndDistance", endDistance);
    std::shared_ptr<JavascriptArray> array = IMManager::Instance()->GetBridge()->createArray();
    for (std::list<std::shared_ptr<RelativeLocation> >::const_iterator itr = neighbourList.begin(); itr != neighbourList.end(); ++itr)
    {
      RelativeLocation* ralativeLoation = itr->get();
      std::shared_ptr<JavascriptMap> item = IMManager::Instance()->GetBridge()->createMap();
      item->putString("UserID", ralativeLoation->GetUserID());
      item->putInt("Distance", ralativeLoation->GetDistance());
      item->putDouble("Longitude", ralativeLoation->GetLongitude());
      item->putDouble("Latitude", ralativeLoation->GetLatitude());
      item->putString("Country", ralativeLoation->GetCountry());
      item->putString("Province", ralativeLoation->GetProvince());
      item->putString("City", ralativeLoation->GetCity());
      item->putString("DistrictCounty", ralativeLoation->GetDistrictCounty());
      item->putString("Street", ralativeLoation->GetStreet());
      array->pushMap(item);
    }
    result->putArray("Neighbours", array);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_LOCATION, result);
  });
}

void LocationCallback::OnGetDistance(YIMErrorcode errorcode, const XString &userID, unsigned int distance)
{ 
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_LOCATION_GET_DISTANCE);
    result->putInt("Errorcode", errorcode);
    result->putInt("Distance", distance);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_LOCATION, result);
  });
}

