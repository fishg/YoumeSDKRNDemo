#pragma once

#include "YIM.h"


class LocationCallback : public IYIMLocationCallback
{
public:
  LocationCallback();
  ~LocationCallback();
  void Init();
  
private:
  virtual void OnUpdateLocation(YIMErrorcode errorcode, std::shared_ptr<GeographyLocation> location) override;
  virtual void OnGetNearbyObjects(YIMErrorcode errorcode, std::list< std::shared_ptr<RelativeLocation> > neighbourList, unsigned int startDistance, unsigned int endDistance) override;
  virtual void OnGetDistance(YIMErrorcode errorcode, const XString& userID, unsigned int distance) override;
};
