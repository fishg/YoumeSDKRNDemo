#include "FriendCallback.h"
#include "IMManager.h"
#include "RNYIMCommon.hpp"
#include "ReactBridge.hpp"
#include "JavascriptMap.hpp"
#include "JobQueueImpl.hpp"
#include "JavascriptArray.hpp"


FriendCallback::FriendCallback()
{
  
}

FriendCallback::~FriendCallback()
{
  
}

void FriendCallback::Init()
{
  if (IMManager::Instance()->GetYouMeIMManager() != NULL)
  {
    IMManager::Instance()->GetYouMeIMManager()->SetFriendCallback(this);
  }
}


void FriendCallback::OnRequestAddFriend(YIMErrorcode errorcode, const XString &userID)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_REQUEST_ADD_FRIEND);
    result->putInt("Errorcode", errorcode);
    result->putString("UserID", userID);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_FRIEND, result);
  });
}

void FriendCallback::OnBeRequestAddFriendNotify(const XString &userID, const XString &comments)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_BE_REQUEST_ADD_FRIEND);
    result->putString("UserID", userID);
    result->putString("Comments", comments);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_FRIEND, result);
  });
}

void FriendCallback::OnBeAddFriendNotify(const XString &userID, const XString &comments)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_BE_ADD_FRIEND);
    result->putString("UserID", userID);
    result->putString("Comments", comments);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_FRIEND, result);
  });
}

void FriendCallback::OnDealBeRequestAddFriend(YIMErrorcode errorcode, const XString &userID, const XString &comments, int dealResult)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_DEAL_BE_REQUEST_ADD_FRIEND);
    result->putInt("Errorcode", errorcode);
    result->putString("UserID", userID);
    result->putString("Comments", comments);
    result->putInt("DealResult", dealResult);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_FRIEND, result);
  });
}

void FriendCallback::OnRequestAddFriendResultNotify(const XString &userID, const XString &comments, int dealResult)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_REQUEST_ADD_FRIEND_RESULT_NOTIFY);
    result->putString("UserID", userID);
    result->putString("Comments", comments);
    result->putInt("DealResult", dealResult);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_FRIEND, result);
  });
}

void FriendCallback::OnDeleteFriend(YIMErrorcode errorcode, const XString &userID)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_DELETE_FRIEND);
    result->putInt("Errorcode", errorcode);
    result->putString("UserID", userID);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_FRIEND, result);
  });
}

void FriendCallback::OnBeDeleteFriendNotify(const XString &userID)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_BE_DELETE_FRIEND_NOTIFY);
    result->putString("UserID", userID);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_FRIEND, result);
  });
}

void FriendCallback::OnBlackFriend(YIMErrorcode errorcode, int type, const XString &userID)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_BE_DELETE_FRIEND_NOTIFY);
    result->putInt("Errorcode", errorcode);
    result->putInt("Type", type);
    result->putString("UserID", userID);
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_FRIEND, result);
  });
}

void FriendCallback::OnQueryFriends(YIMErrorcode errorcode, int type, int startIndex, std::list<std::shared_ptr<IYIMUserBriefInfo> > &friends)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_QUERY_FRIENDS);
    result->putInt("Errorcode", errorcode);
    result->putInt("Type", type);
    result->putInt("StartIndex", startIndex);
    std::shared_ptr<JavascriptArray> array = IMManager::Instance()->GetBridge()->createArray();
    for (std::list<std::shared_ptr<IYIMUserBriefInfo> >::const_iterator itr = friends.begin(); itr != friends.end(); ++itr)
    {
      IYIMUserBriefInfo* friendInfo = itr->get();
      std::shared_ptr<JavascriptMap> item = IMManager::Instance()->GetBridge()->createMap();
      item->putString("UserID", friendInfo->GetUserID());
      item->putString("Nickname", friendInfo->GetNickname());
      item->putInt("Status", friendInfo->GetUserStatus());
      array->pushMap(item);
    }
    result->putArray("Friends", array);
    
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_FRIEND, result);
  });
}

void FriendCallback::OnQueryFriendRequestList(YIMErrorcode errorcode, int startIndex, std::list<std::shared_ptr<IYIMFriendRequestInfo> > &requestList)
{
  IMManager::Instance()->GetCallbackQueue()->enqueue([=]() {
    std::shared_ptr<JavascriptMap> result = IMManager::Instance()->GetBridge()->createMap();
    result->putInt("Command", RNYIMCommon::CMD_QUERY_FRIEND_REQUEST_LIST);
    result->putInt("Errorcode", errorcode);
    result->putInt("StartIndex", startIndex);
    std::shared_ptr<JavascriptArray> array = IMManager::Instance()->GetBridge()->createArray();
    for (std::list<std::shared_ptr<IYIMFriendRequestInfo> >::const_iterator itr = requestList.begin(); itr != requestList.end(); ++itr)
    {
      IYIMFriendRequestInfo* info = itr->get();
      std::shared_ptr<JavascriptMap> item = IMManager::Instance()->GetBridge()->createMap();
      item->putString("AskerID", info->GetAskerID());
      item->putString("AskerNick", info->GetAskerNickname());
      item->putString("AskerID", info->GetInviteeID());
      item->putString("AskerNick", info->GetInviteeNickname());
      item->putString("ValidateInfo", info->GetValidateInfo());
      item->putInt("Status", info->GetStatus());
      item->putInt("CreateTime", info->GetCreateTime());
      array->pushMap(item);
    }
    result->putArray("Friends", array);
    
    IMManager::Instance()->GetBridge()->emitEventWithMap(RNYIMCommon::EVENT_FRIEND, result);
  });
}

