// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from react.djinni

#pragma once

#include "JavascriptArray.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class NativeJavascriptArray final : ::djinni::JniInterface<::JavascriptArray, NativeJavascriptArray> {
public:
    using CppType = std::shared_ptr<::JavascriptArray>;
    using CppOptType = std::shared_ptr<::JavascriptArray>;
    using JniType = jobject;

    using Boxed = NativeJavascriptArray;

    ~NativeJavascriptArray();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeJavascriptArray>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeJavascriptArray>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeJavascriptArray();
    friend ::djinni::JniClass<NativeJavascriptArray>;
    friend ::djinni::JniInterface<::JavascriptArray, NativeJavascriptArray>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::JavascriptArray
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        int32_t size() override;
        bool isNull(int32_t index) override;
        bool getBoolean(int32_t index) override;
        double getDouble(int32_t index) override;
        int32_t getInt(int32_t index) override;
        std::string getString(int32_t index) override;
        std::shared_ptr<::JavascriptArray> getArray(int32_t index) override;
        std::shared_ptr<::JavascriptMap> getMap(int32_t index) override;
        std::shared_ptr<::JavascriptObject> getObject(int32_t index) override;
        ::JavascriptType getType(int32_t index) override;
        void pushNull() override;
        void pushBoolean(bool value) override;
        void pushDouble(double value) override;
        void pushInt(int32_t value) override;
        void pushString(const std::string & value) override;
        void pushArray(const std::shared_ptr<::JavascriptArray> & array) override;
        void pushMap(const std::shared_ptr<::JavascriptMap> & map) override;
        void pushObject(const std::shared_ptr<::JavascriptObject> & object) override;
        void append(const std::shared_ptr<::JavascriptArray> & source) override;

    private:
        friend ::djinni::JniInterface<::JavascriptArray, ::djinni_generated::NativeJavascriptArray>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/youme/reactcpp/JavascriptArray") };
    const jmethodID method_size { ::djinni::jniGetMethodID(clazz.get(), "size", "()I") };
    const jmethodID method_isNull { ::djinni::jniGetMethodID(clazz.get(), "isNull", "(I)Z") };
    const jmethodID method_getBoolean { ::djinni::jniGetMethodID(clazz.get(), "getBoolean", "(I)Z") };
    const jmethodID method_getDouble { ::djinni::jniGetMethodID(clazz.get(), "getDouble", "(I)D") };
    const jmethodID method_getInt { ::djinni::jniGetMethodID(clazz.get(), "getInt", "(I)I") };
    const jmethodID method_getString { ::djinni::jniGetMethodID(clazz.get(), "getString", "(I)Ljava/lang/String;") };
    const jmethodID method_getArray { ::djinni::jniGetMethodID(clazz.get(), "getArray", "(I)Lcom/youme/reactcpp/JavascriptArray;") };
    const jmethodID method_getMap { ::djinni::jniGetMethodID(clazz.get(), "getMap", "(I)Lcom/youme/reactcpp/JavascriptMap;") };
    const jmethodID method_getObject { ::djinni::jniGetMethodID(clazz.get(), "getObject", "(I)Lcom/youme/reactcpp/JavascriptObject;") };
    const jmethodID method_getType { ::djinni::jniGetMethodID(clazz.get(), "getType", "(I)Lcom/youme/reactcpp/JavascriptType;") };
    const jmethodID method_pushNull { ::djinni::jniGetMethodID(clazz.get(), "pushNull", "()V") };
    const jmethodID method_pushBoolean { ::djinni::jniGetMethodID(clazz.get(), "pushBoolean", "(Z)V") };
    const jmethodID method_pushDouble { ::djinni::jniGetMethodID(clazz.get(), "pushDouble", "(D)V") };
    const jmethodID method_pushInt { ::djinni::jniGetMethodID(clazz.get(), "pushInt", "(I)V") };
    const jmethodID method_pushString { ::djinni::jniGetMethodID(clazz.get(), "pushString", "(Ljava/lang/String;)V") };
    const jmethodID method_pushArray { ::djinni::jniGetMethodID(clazz.get(), "pushArray", "(Lcom/youme/reactcpp/JavascriptArray;)V") };
    const jmethodID method_pushMap { ::djinni::jniGetMethodID(clazz.get(), "pushMap", "(Lcom/youme/reactcpp/JavascriptMap;)V") };
    const jmethodID method_pushObject { ::djinni::jniGetMethodID(clazz.get(), "pushObject", "(Lcom/youme/reactcpp/JavascriptObject;)V") };
    const jmethodID method_append { ::djinni::jniGetMethodID(clazz.get(), "append", "(Lcom/youme/reactcpp/JavascriptArray;)V") };
};

}  // namespace djinni_generated
