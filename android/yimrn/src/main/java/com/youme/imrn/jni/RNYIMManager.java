// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from main.djinni

package com.youme.imrn.jni;

import com.facebook.react.bridge.Callback;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReadableArray;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.WritableArray;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.module.annotations.ReactModule;
import com.youme.reactcpp.ReactDjinni;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.atomic.AtomicBoolean;

/**----------------------------IM管理类---------------------------- */
@ReactModule(name = "RNYIMManager")
public final class RNYIMManager extends ReactContextBaseJavaModule {
    private final CppProxy mModule;

    public RNYIMManager(ReactApplicationContext reactContext) {
        super(reactContext);
        mModule = create(ReactDjinni.createReactBridge(reactContext));
    }

    @Override
    public String getName() {
        return "RNYIMManager";
    }

    private static native CppProxy create(com.youme.reactcpp.ReactBridge bridge);

    /** 初始化 */
    @ReactMethod
    public void Init(String appkey, String secret, String packageName, int model, Callback callback) {
        mModule.Init(appkey, secret, packageName, model, ReactDjinni.wrap(callback));
    }

    /**
     * 登录
     *Login(userID:string, password:string, promise:JavascriptPromise);	      				
     */
    @ReactMethod
    public void Login(String userID, String password, String token, Callback callback) {
        mModule.Login(userID, password,token, ReactDjinni.wrap(callback));
    }

    /** 登出 */
    @ReactMethod
    public void Logout(Callback callback) {
        mModule.Logout(ReactDjinni.wrap(callback));
    }

    /** 播放语音 */
    @ReactMethod
    public void StartPlayAudio(String path, Callback callback) {
        mModule.StartPlayAudio(path, ReactDjinni.wrap(callback));
    }

    /** 停止播放 */
    @ReactMethod
    public void StopPlayAudio(Callback callback) {
        mModule.StopPlayAudio(ReactDjinni.wrap(callback));
    }

    /** 获取最近联系人(最大100条) */
    @ReactMethod
    public void GetRecentContacts(Callback callback) {
        mModule.GetRecentContacts(ReactDjinni.wrap(callback));
    }

    /** 程序切到后台运行 */
    @ReactMethod
    public void OnPause() {
        mModule.OnPause();
    }

    /** 程序切到前台运行 */
    @ReactMethod
    public void OnResume() {
        mModule.OnResume();
    }

    /** 设置录音缓存目录 */
    @ReactMethod
    public void SetAudioRecordCacheDir(String path) {
        mModule.SetAudioRecordCacheDir(path);
    }

    /** 获取语音缓存目录(返回值 path:string) */
    @ReactMethod
    public void GetAudioCachePath(Callback callback) {
        mModule.GetAudioCachePath(ReactDjinni.wrap(callback));
    }

    /** 清理语音缓存目录(返回值 result:bool) */
    @ReactMethod
    public void ClearAudioCachePath() {
        mModule.ClearAudioCachePath();
    }

    /** 关键词过滤（返回值 text:string 过滤后文本, level:int 关键字等级） */
    @ReactMethod
    public void FilterKeyword(String text, Callback callback) {
        mModule.FilterKeyword(text, ReactDjinni.wrap(callback));
    }

    private static final class CppProxy
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            destroy();
            super.finalize();
        }

        public void Init(String appkey, String secret, String packageName, int model, com.youme.reactcpp.JavascriptCallback callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_Init(this.nativeRef, appkey, secret, packageName, model, callback);
        }
        private native void native_Init(long _nativeRef, String appkey, String secret, String packageName, int model, com.youme.reactcpp.JavascriptCallback callback);

        public void Login(String userID, String password,String token, com.youme.reactcpp.JavascriptCallback callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_Login(this.nativeRef, userID, password, token,callback);
        }
        private native void native_Login(long _nativeRef, String userID, String password,String token, com.youme.reactcpp.JavascriptCallback callback);

        public void Logout(com.youme.reactcpp.JavascriptCallback callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_Logout(this.nativeRef, callback);
        }
        private native void native_Logout(long _nativeRef, com.youme.reactcpp.JavascriptCallback callback);

        public void StartPlayAudio(String path, com.youme.reactcpp.JavascriptCallback callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_StartPlayAudio(this.nativeRef, path, callback);
        }
        private native void native_StartPlayAudio(long _nativeRef, String path, com.youme.reactcpp.JavascriptCallback callback);

        public void StopPlayAudio(com.youme.reactcpp.JavascriptCallback callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_StopPlayAudio(this.nativeRef, callback);
        }
        private native void native_StopPlayAudio(long _nativeRef, com.youme.reactcpp.JavascriptCallback callback);

        public void GetRecentContacts(com.youme.reactcpp.JavascriptCallback callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_GetRecentContacts(this.nativeRef, callback);
        }
        private native void native_GetRecentContacts(long _nativeRef, com.youme.reactcpp.JavascriptCallback callback);

        public void OnPause()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_OnPause(this.nativeRef);
        }
        private native void native_OnPause(long _nativeRef);

        public void OnResume()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_OnResume(this.nativeRef);
        }
        private native void native_OnResume(long _nativeRef);

        public void SetAudioRecordCacheDir(String path)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_SetAudioRecordCacheDir(this.nativeRef, path);
        }
        private native void native_SetAudioRecordCacheDir(long _nativeRef, String path);

        public void GetAudioCachePath(com.youme.reactcpp.JavascriptCallback callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_GetAudioCachePath(this.nativeRef, callback);
        }
        private native void native_GetAudioCachePath(long _nativeRef, com.youme.reactcpp.JavascriptCallback callback);

        public void ClearAudioCachePath()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_ClearAudioCachePath(this.nativeRef);
        }
        private native void native_ClearAudioCachePath(long _nativeRef);

        public void FilterKeyword(String text, com.youme.reactcpp.JavascriptCallback callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_FilterKeyword(this.nativeRef, text, callback);
        }
        private native void native_FilterKeyword(long _nativeRef, String text, com.youme.reactcpp.JavascriptCallback callback);
    }
}
