#include "IMManager.h"
#include "ReactBridge.hpp"
#include "JobDispatcher.hpp"
#include "JobQueueImpl.hpp"
#include "JavascriptMap.hpp"
#include "JavascriptArray.hpp"
#include "RNYIMCommon.hpp"


class RNYIMCommonImpl : public RNYIMCommon
{
public:
  RNYIMCommonImpl(const std::shared_ptr<::ReactBridge> &bridge){}
  ~RNYIMCommonImpl(){}
};

std::shared_ptr<RNYIMCommon> RNYIMCommon::create(const std::shared_ptr<::ReactBridge> & bridge)
{
  return std::make_shared<RNYIMCommonImpl>(bridge);
}


IMManager::IMManager() : m_pYoumeIMManager(NULL)
, m_bridge(NULL)
, m_queue(NULL)
, m_dispatcher(NULL)
, m_bInit(false)
{

}

IMManager::~IMManager()
{
    Uninit();
}

IMManager* IMManager::Instance()
{
  static IMManager instance;
  return &instance;
}

YIMErrorcode IMManager::Init(const std::string& appkey, const std::string& secret, const std::string& packageName, int model)
{
  if (m_bInit)
  {
    return YIMErrorcode_Success;
  }
  YIMManager::SetMode(model == RNYIMCommon::MODEL_TEST ? 2 : 0);
  YIMManager::SetServerZone(ServerZone_China);
  m_pYoumeIMManager = YIMManager::CreateInstance();
  if (m_pYoumeIMManager == NULL)
  {
    return YIMErrorcode_InitFailed;
  }
  m_queue = JobQueueImpl::create();
  if (m_queue == NULL || m_bridge == NULL)
  {
    return YIMErrorcode_InitFailed;
  }
  m_dispatcher = m_bridge->createJobDispatcher(m_queue);
  if (m_dispatcher != NULL)
  {
    m_dispatcher->start();
  }
  
  YIMErrorcode errorcode = m_pYoumeIMManager->Init(appkey.c_str(), secret.c_str(), packageName.c_str());
  if (YIMErrorcode_Success == errorcode)
  {
    m_bInit = true;
  }
  m_pYoumeIMManager->SetLoginCallback(this);
  m_channelCallback.Init();
  m_messageCallback.Init();
  m_locationCallback.Init();
  m_audioPlayCallback.Init();
  m_userInfoCallback.Init();
  m_friendCallback.Init();
  
  return errorcode;
}

void IMManager::Uninit()
{
  if (m_dispatcher != NULL)
  {
    m_dispatcher->quit();
  }
}

YIMManager* IMManager::GetYouMeIMManager()
{
  return m_pYoumeIMManager;
}

void IMManager::SetBridge(const std::shared_ptr<::ReactBridge>& bridge)
{
  m_bridge = bridge;
}

void IMManager::DispatchCallback(const std::string& event, std::shared_ptr<JavascriptMap>& result)
{
  if (m_queue != NULL)
  {
    m_queue->enqueue([=]() {
      m_bridge->emitEventWithMap(event, result);
    });
  }
}

void IMManager::OnLogin(YIMErrorcode errorcode, const XString& userID,XUINT64 serverTime)
{
  //std::shared_ptr<JavascriptMap> result = m_bridge->createMap();
  //result->putInt("Command", RNYIMCommon::CMD_LOGIN);
  //result->putInt("Errorcode", errorcode);
  //result->putString("UserID", userID);
  //DispatchCallback(RNYIMCommon::EVENT_LOGIN, result);

  m_queue->enqueue([=]() {
      char serverTimeStr[32] = {0};
      snprintf(serverTimeStr, sizeof(serverTimeStr), "%llu", serverTime);
      std::shared_ptr<JavascriptMap> result = m_bridge->createMap();
      result->putInt("Command", RNYIMCommon::CMD_LOGIN);
      result->putInt("Errorcode", errorcode);
      result->putString("UserID", userID);
      result->putString("ServerTime", serverTimeStr);
      m_bridge->emitEventWithMap(RNYIMCommon::EVENT_LOGIN, result);
  });
  /*if (m_loginCallback != NULL)
  {
    mQueue->enqueue([=]() {
      m_loginCallback->invoke(std::vector<std::shared_ptr<JavascriptObject>>{
        JavascriptObject::fromInt(errorcode),
        JavascriptObject::fromString(userID)});
    });
  }*/
}

void IMManager::OnLogout(YIMErrorcode errorcode)
{
  m_queue->enqueue([=]() {
      std::shared_ptr<JavascriptMap> result = m_bridge->createMap();
      result->putInt("Command", RNYIMCommon::CMD_LOGOUT);
      result->putInt("Errorcode", errorcode);
      m_bridge->emitEventWithMap(RNYIMCommon::EVENT_LOGIN, result);
  });
}

void IMManager::OnKickOff()
{
  m_queue->enqueue([=]() {
      std::shared_ptr<JavascriptMap> result = m_bridge->createMap();
      result->putInt("Command", RNYIMCommon::CMD_KICKOFF);
      m_bridge->emitEventWithMap(RNYIMCommon::EVENT_LOGIN, result);
  });
}

/*void IMManager::Login(const std::string & userID, const std::string & password, const std::shared_ptr<::JavascriptCallback> & callback)
{
    m_loginCallback = callback;
    if (m_pYoumeIMManager != NULL)
    {
        m_pYoumeIMManager->Login(userID.c_str(), password.c_str(), "");
    }
}*/
