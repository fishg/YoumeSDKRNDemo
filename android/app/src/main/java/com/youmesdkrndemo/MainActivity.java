package com.youmesdkrndemo;

import android.content.Intent;
import android.os.Bundle;

import com.facebook.react.ReactActivity;

// youme add
import com.youme.im.IMEngine;
import com.youme.voiceengine.mgr.YouMeManager;

public class MainActivity extends ReactActivity {

  /**
   * Returns the name of the main component registered from JavaScript. This is used to schedule
   * rendering of the component.
   */
  @Override
  protected String getMainComponentName() {
    return "YoumeSDKRNDemo";
  }

  @Override
  protected void onCreate(Bundle savedInstanceState){
    IMEngine.init(this);
    YouMeManager.Init(this);
    super.onCreate(savedInstanceState);
  }

}
