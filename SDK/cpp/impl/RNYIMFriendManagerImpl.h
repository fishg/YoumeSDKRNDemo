#pragma once


#include "JavascriptCallback.hpp"
#include "RNYIMFriendManager.hpp"


class RNYIMFriendManagerImpl : public RNYIMFriendManager
{
public:
  RNYIMFriendManagerImpl(const std::shared_ptr<::ReactBridge>& bridge){}
  ~RNYIMFriendManagerImpl() {}

  virtual void RequestAddFriend(const std::string & userID, const std::string & comments, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void DealBeRequestAddFriend(const std::string & userID, int32_t dealResult, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void DeleteFriend(const std::string & userID, int32_t deleteType, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void BlackFriend(int32_t type, const std::string & userID, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void QueryFriends(int32_t type, int32_t startIndex, int32_t count, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void QueryFriendRequestList(int32_t startIndex, int32_t count, const std::shared_ptr<::JavascriptCallback> & callback) override;

};
