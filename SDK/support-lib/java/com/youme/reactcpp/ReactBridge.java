// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from react.djinni

package com.youme.reactcpp;

public abstract class ReactBridge {
    public abstract JavascriptMap createMap();

    public abstract JavascriptArray createArray();

    public abstract JavascriptMap copyMap(JavascriptMap map);

    public abstract JavascriptArray copyArray(JavascriptArray array);

    public abstract void emitEventWithMap(String name, JavascriptMap params);

    public abstract void emitEventWithArray(String name, JavascriptArray params);

    public abstract JobDispatcher createJobDispatcher(JobQueue queue);
}
