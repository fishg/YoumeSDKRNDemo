#include "RNYIMFriendManagerImpl.h"
#include "IMManager.h"
#include "JavascriptObject.hpp"


std::shared_ptr<RNYIMFriendManager> RNYIMFriendManager::create(const std::shared_ptr<::ReactBridge> & bridge)
{
  return std::make_shared<RNYIMFriendManagerImpl>(bridge);
}


void RNYIMFriendManagerImpl::RequestAddFriend(const std::string &userID, const std::string &comments, const std::shared_ptr< ::JavascriptCallback> &callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetFriendManager() != NULL)
  {
    std::vector<XString> users;
    users.push_back(userID);
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetFriendManager()->RequestAddFriend(users, comments.c_str());
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMFriendManagerImpl::DealBeRequestAddFriend(const std::string &userID, int32_t dealResult, const std::shared_ptr< ::JavascriptCallback> &callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetFriendManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetFriendManager()->DealBeRequestAddFriend(userID.c_str(), dealResult);
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMFriendManagerImpl::DeleteFriend(const std::string &userID, int32_t deleteType, const std::shared_ptr< ::JavascriptCallback> &callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetFriendManager() != NULL)
  {
    std::vector<XString> users;
    users.push_back(userID);
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetFriendManager()->DeleteFriend(users);
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMFriendManagerImpl::BlackFriend(int32_t type, const std::string &userID, const std::shared_ptr< ::JavascriptCallback> &callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetFriendManager() != NULL)
  {
    std::vector<XString> users;
    users.push_back(userID);
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetFriendManager()->BlackFriend(type, users);
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMFriendManagerImpl::QueryFriends(int32_t type, int32_t startIndex, int32_t count, const std::shared_ptr< ::JavascriptCallback> &callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetFriendManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetFriendManager()->QueryFriends(type, startIndex, count);
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMFriendManagerImpl::QueryFriendRequestList(int32_t startIndex, int32_t count, const std::shared_ptr< ::JavascriptCallback> &callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL
      && IMManager::Instance()->GetYouMeIMManager()->GetFriendManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetFriendManager()->QueryFriendRequestList();
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}
