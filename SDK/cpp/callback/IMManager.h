#ifndef IM_MANAGER_H
#define IM_MANAGER_H


#include "JavascriptCallback.hpp"
#include "YIM.h"
#include "ChannelCallback.h"
#include "MessageCallback.h"
#include "AudioPlayCallback.h"
#include "LocationCallback.h"
#include "UserInfoCallback.h"
#include "FriendCallback.h"


class JobQueueImpl;
class JobDispatcher;
class ReactBridge;
class JavascriptMap;

class IMManager : public IYIMLoginCallback
{
public:
  static IMManager* Instance();
  YIMErrorcode Init(const std::string& appkey, const std::string& secret, const std::string& packageName, int model);
  void Uninit();
  YIMManager* GetYouMeIMManager();
  void SetBridge(const std::shared_ptr<::ReactBridge>& bridge);
  void DispatchCallback(const std::string& event, std::shared_ptr<JavascriptMap>& result);
  std::shared_ptr<JobQueueImpl> GetCallbackQueue(){return m_queue;};
  std::shared_ptr<ReactBridge> GetBridge(){return m_bridge;};
  //void Login(const std::string & userID, const std::string & password, const std::shared_ptr<::JavascriptCallback> & callback);
  
private:
  IMManager();
  ~IMManager();
  
  virtual void OnLogin(YIMErrorcode errorcode, const XString& userID,XUINT64 serverTime);
  virtual void OnLogout(YIMErrorcode errorcode);
  virtual void OnKickOff();
  
  bool m_bInit;
  YIMManager* m_pYoumeIMManager;
  ChannelCallback m_channelCallback;
  MessageCallback m_messageCallback;
  MessageCallback m_locationCallback;
  AudioPlayCallback m_audioPlayCallback;
  UserInfoCallback m_userInfoCallback;
  FriendCallback m_friendCallback;
  
  std::shared_ptr<ReactBridge> m_bridge;
  std::shared_ptr<JobQueueImpl> m_queue;
  std::shared_ptr<JobDispatcher> m_dispatcher;
  //std::shared_ptr<::JavascriptCallback> m_loginCallback;
};

#endif
