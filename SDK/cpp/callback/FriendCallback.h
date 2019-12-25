#pragma once

#include "YIM.h"


class FriendCallback : public IYIMFriendCallback
{
public:
  FriendCallback();
  ~FriendCallback();
  void Init();
  
private:
  //virtual void OnFindUser(YIMErrorcode errorcode, std::list<std::shared_ptr<IYIMUserBriefInfo> >& users) override;
  virtual void OnRequestAddFriend(YIMErrorcode errorcode, const XString& userID) override;
  virtual void OnBeRequestAddFriendNotify(const XString& userID, const XString& comments) override;
  virtual void OnBeAddFriendNotify(const XString& userID, const XString& comments) override;
  virtual void OnDealBeRequestAddFriend(YIMErrorcode errorcode, const XString& userID, const XString& comments, int dealResult) override;
  virtual void OnRequestAddFriendResultNotify(const XString& userID, const XString& comments, int dealResult) override;
  virtual void OnDeleteFriend(YIMErrorcode errorcode, const XString& userID) override;
  virtual void OnBeDeleteFriendNotify(const XString& userID) override;
  virtual void OnBlackFriend(YIMErrorcode errorcode, int type, const XString& userID) override;
  virtual void OnQueryFriends(YIMErrorcode errorcode, int type, int startIndex, std::list<std::shared_ptr<IYIMUserBriefInfo> >& friends) override;
  virtual void OnQueryFriendRequestList(YIMErrorcode errorcode, int startIndex, std::list<std::shared_ptr<IYIMFriendRequestInfo> >& requestList) override;
};
