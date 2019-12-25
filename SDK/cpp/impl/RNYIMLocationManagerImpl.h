#pragma once

#include "JavascriptCallback.hpp"
#include "RNYIMLocationManager.hpp"


class RNYIMLocationManagerImpl : public RNYIMLocationManager{
public:
  RNYIMLocationManagerImpl(const std::shared_ptr<::ReactBridge>& bridge){}
  ~RNYIMLocationManagerImpl() {}
  
  virtual void GetCurrentLocation(const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void GetNearbyObjects(int32_t count, const std::string & serverAreaID, int32_t districtLevel, bool resetStartDistance, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void GetDistance(const std::string & userID, const std::shared_ptr<::JavascriptCallback> & callback) override;
};
