package com.youme.imrn.jni;

import com.facebook.react.ReactPackage;
import com.facebook.react.bridge.NativeModule;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.uimanager.ViewManager;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class DjinniModulesPackage implements ReactPackage {
    static {
        System.loadLibrary("yimrn-lib");
    }

    @Override
    public List<ViewManager> createViewManagers(ReactApplicationContext reactContext) { return Collections.emptyList(); }

    @Override
    public List<NativeModule> createNativeModules(ReactApplicationContext reactContext) {
        List<NativeModule> modules = new ArrayList<>();
        modules.add(new RNYIMCommon(reactContext));
        modules.add(new RNYIMManager(reactContext));
        modules.add(new RNYIMChannelManager(reactContext));
        modules.add(new RNYIMMessageManager(reactContext));
        modules.add(new RNYIMHistoryMessageManager(reactContext));
        modules.add(new RNYIMLocationManager(reactContext));
        modules.add(new RNYIMUserInfoManager(reactContext));
        modules.add(new RNYIMFriendManager(reactContext));
        modules.add(new RNVoiceEngine(reactContext));
        return modules;
    }
}