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

/**----------------------------地理位置管理---------------------------- */
@ReactModule(name = "RNYIMLocationManager")
public final class RNYIMLocationManager extends ReactContextBaseJavaModule {
    private final CppProxy mModule;

    public RNYIMLocationManager(ReactApplicationContext reactContext) {
        super(reactContext);
        mModule = create(ReactDjinni.createReactBridge(reactContext));
    }

    @Override
    public String getName() {
        return "RNYIMLocationManager";
    }

    private static native CppProxy create(com.youme.reactcpp.ReactBridge bridge);

    /** 获取当前地理位置 */
    @ReactMethod
    public void GetCurrentLocation(Callback callback) {
        mModule.GetCurrentLocation(ReactDjinni.wrap(callback));
    }

    /** 获取附近的人 */
    @ReactMethod
    public void GetNearbyObjects(int count, String serverAreaID, int districtLevel, boolean resetStartDistance, Callback callback) {
        mModule.GetNearbyObjects(count, serverAreaID, districtLevel, resetStartDistance, ReactDjinni.wrap(callback));
    }

    /** 获取与指定用户距离 */
    @ReactMethod
    public void GetDistance(String userID, Callback callback) {
        mModule.GetDistance(userID, ReactDjinni.wrap(callback));
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

        public void GetCurrentLocation(com.youme.reactcpp.JavascriptCallback callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_GetCurrentLocation(this.nativeRef, callback);
        }
        private native void native_GetCurrentLocation(long _nativeRef, com.youme.reactcpp.JavascriptCallback callback);

        public void GetNearbyObjects(int count, String serverAreaID, int districtLevel, boolean resetStartDistance, com.youme.reactcpp.JavascriptCallback callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_GetNearbyObjects(this.nativeRef, count, serverAreaID, districtLevel, resetStartDistance, callback);
        }
        private native void native_GetNearbyObjects(long _nativeRef, int count, String serverAreaID, int districtLevel, boolean resetStartDistance, com.youme.reactcpp.JavascriptCallback callback);

        public void GetDistance(String userID, com.youme.reactcpp.JavascriptCallback callback)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_GetDistance(this.nativeRef, userID, callback);
        }
        private native void native_GetDistance(long _nativeRef, String userID, com.youme.reactcpp.JavascriptCallback callback);
    }
}