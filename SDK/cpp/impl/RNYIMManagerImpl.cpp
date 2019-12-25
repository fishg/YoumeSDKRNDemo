#include "RNYIMManagerImpl.h"
#include "IMManager.h"

#include "JavascriptType.hpp"
#include "JavascriptObject.hpp"
#include "JobDispatcher.hpp"
#include "JavascriptMap.hpp"
#include "ReactBridge.hpp"
#include "JobQueueImpl.hpp"

#include <thread>
#include <chrono>


std::shared_ptr<RNYIMManager> RNYIMManager::create(const std::shared_ptr<::ReactBridge> &bridge)
{
    return std::make_shared<RNYIMManagerImpl>(bridge);
}

RNYIMManagerImpl::RNYIMManagerImpl(const std::shared_ptr<::ReactBridge> &bridge)
{
  IMManager::Instance()->SetBridge(bridge);
}

RNYIMManagerImpl::~RNYIMManagerImpl()
{
  
}

void RNYIMManagerImpl::Init(const std::string & appkey, const std::string & secret, const std::string & packageName, int32_t model, const std::shared_ptr<::JavascriptCallback> & callback)
{
  YIMErrorcode errorcode = IMManager::Instance()->Init(appkey, secret, packageName, model);
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMManagerImpl::Login(const std::string & userID, const std::string & password,const std::string & token, const std::shared_ptr<::JavascriptCallback> & callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->Login(userID.c_str(), password.c_str(), token.c_str());
  }
  //promise->resolveInt(errorcode);
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMManagerImpl::Logout(const std::shared_ptr<::JavascriptCallback> & callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->Logout();
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMManagerImpl::StartPlayAudio(const std::string & path, const std::shared_ptr<::JavascriptCallback> & callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->StartPlayAudio(path.c_str());
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMManagerImpl::StopPlayAudio(const std::shared_ptr<::JavascriptCallback> & callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->StopPlayAudio();
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMManagerImpl::GetRecentContacts(const std::shared_ptr< ::JavascriptCallback> &callback)
{
  YIMErrorcode errorcode = YIMErrorcode_EngineNotInit;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL)
  {
    errorcode = IMManager::Instance()->GetYouMeIMManager()->GetRecentContacts();
  }
  callback->invokeSingleArg(JavascriptObject::fromInt(errorcode));
}

void RNYIMManagerImpl::OnPause()
{
  if (IMManager::Instance()->GetYouMeIMManager() != NULL)
  {
     IMManager::Instance()->GetYouMeIMManager()->OnPause(false);
  }
}

void RNYIMManagerImpl::OnResume()
{
  if (IMManager::Instance()->GetYouMeIMManager() != NULL)
  {
    IMManager::Instance()->GetYouMeIMManager()->OnResume();
  }
}

void RNYIMManagerImpl::SetAudioRecordCacheDir(const std::string & path)
{
  if (IMManager::Instance()->GetYouMeIMManager() != NULL)
  {
    IMManager::Instance()->GetYouMeIMManager()->SetAudioCacheDir(path.c_str());
  }
}

void RNYIMManagerImpl::GetAudioCachePath(const std::shared_ptr< ::JavascriptCallback> &callback)
{
  std::string path;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL)
  {
    path = IMManager::Instance()->GetYouMeIMManager()->GetAudioCachePath();
  }
  callback->invokeSingleArg(JavascriptObject::fromString(path));
}

void RNYIMManagerImpl::ClearAudioCachePath()
{
  if (IMManager::Instance()->GetYouMeIMManager() != NULL)
  {
    IMManager::Instance()->GetYouMeIMManager()->ClearAudioCachePath();
  }
}

void RNYIMManagerImpl::FilterKeyword(const std::string &text, const std::shared_ptr< ::JavascriptCallback> &callback)
{
  int level = 0;
  std::string result;
  if (IMManager::Instance()->GetYouMeIMManager() != NULL)
  {
    result = IMManager::Instance()->GetYouMeIMManager()->FilterKeyword(text.c_str(), &level);
  }
  callback->invoke(std::vector<std::shared_ptr<JavascriptObject>>{
    JavascriptObject::fromString(result),
    JavascriptObject::fromInt(level)});
}
