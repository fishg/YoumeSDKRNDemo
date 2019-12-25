#ifndef YIM_MANAGER_IMPL_H
#define YIM_MANAGER_IMPL_H


#include "RNYIMManager.hpp"

class JobQueueImpl;
class JobDispatcher;

class RNYIMManagerImpl : public RNYIMManager {
public:
  RNYIMManagerImpl(const std::shared_ptr<::ReactBridge> & bridge);
  ~RNYIMManagerImpl();
  
  virtual void Init(const std::string & appkey, const std::string & secret, const std::string & packageName, int32_t model, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void Login(const std::string & userID, const std::string & password,const std::string & token, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void Logout(const std::shared_ptr<::JavascriptCallback> & callback) override;
  
  virtual void StartPlayAudio(const std::string & path, const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void StopPlayAudio(const std::shared_ptr<::JavascriptCallback> & callback) override;

  virtual void GetRecentContacts(const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void OnPause() override;
  virtual void OnResume() override;
  virtual void SetAudioRecordCacheDir(const std::string & path) override;
  virtual void GetAudioCachePath(const std::shared_ptr<::JavascriptCallback> & callback) override;
  virtual void ClearAudioCachePath() override;
  virtual void FilterKeyword(const std::string & text, const std::shared_ptr<::JavascriptCallback> & callback) override;
};

#endif
