// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from main.djinni

#include "NativeRNYIMHistoryMessageManager.hpp"  // my header
#include "Marshal.hpp"
#include "NativeJavascriptCallback.hpp"
#include "NativeReactBridge.hpp"

namespace djinni_generated {

NativeRNYIMHistoryMessageManager::NativeRNYIMHistoryMessageManager() : ::djinni::JniInterface<::RNYIMHistoryMessageManager, NativeRNYIMHistoryMessageManager>("com/youme/imrn/jni/RNYIMHistoryMessageManager$CppProxy") {}

NativeRNYIMHistoryMessageManager::~NativeRNYIMHistoryMessageManager() = default;


CJNIEXPORT void JNICALL Java_com_youme_imrn_jni_RNYIMHistoryMessageManager_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::RNYIMHistoryMessageManager>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_com_youme_imrn_jni_RNYIMHistoryMessageManager_create(JNIEnv* jniEnv, jobject /*this*/, ::djinni_generated::NativeReactBridge::JniType j_bridge)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::RNYIMHistoryMessageManager::create(::djinni_generated::NativeReactBridge::toCpp(jniEnv, j_bridge));
        return ::djinni::release(::djinni_generated::NativeRNYIMHistoryMessageManager::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_com_youme_imrn_jni_RNYIMHistoryMessageManager_00024CppProxy_native_1QueryHistoryMessage(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_targetID, jint j_chatType, jstring j_startMessageID, jint j_count, jint j_direction, ::djinni_generated::NativeJavascriptCallback::JniType j_callback)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::RNYIMHistoryMessageManager>(nativeRef);
        ref->QueryHistoryMessage(::djinni::String::toCpp(jniEnv, j_targetID),
                                 ::djinni::I32::toCpp(jniEnv, j_chatType),
                                 ::djinni::String::toCpp(jniEnv, j_startMessageID),
                                 ::djinni::I32::toCpp(jniEnv, j_count),
                                 ::djinni::I32::toCpp(jniEnv, j_direction),
                                 ::djinni_generated::NativeJavascriptCallback::toCpp(jniEnv, j_callback));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_youme_imrn_jni_RNYIMHistoryMessageManager_00024CppProxy_native_1QueryRoomHistoryMessageFromServer(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_roomID, jint j_count, jint j_direction, ::djinni_generated::NativeJavascriptCallback::JniType j_callback)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::RNYIMHistoryMessageManager>(nativeRef);
        ref->QueryRoomHistoryMessageFromServer(::djinni::String::toCpp(jniEnv, j_roomID),
                                               ::djinni::I32::toCpp(jniEnv, j_count),
                                               ::djinni::I32::toCpp(jniEnv, j_direction),
                                               ::djinni_generated::NativeJavascriptCallback::toCpp(jniEnv, j_callback));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_youme_imrn_jni_RNYIMHistoryMessageManager_00024CppProxy_native_1DeleteHistoryMessage(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_targetID, jint j_chatType, jstring j_startMessageID, jint j_count, ::djinni_generated::NativeJavascriptCallback::JniType j_callback)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::RNYIMHistoryMessageManager>(nativeRef);
        ref->DeleteHistoryMessage(::djinni::String::toCpp(jniEnv, j_targetID),
                                  ::djinni::I32::toCpp(jniEnv, j_chatType),
                                  ::djinni::String::toCpp(jniEnv, j_startMessageID),
                                  ::djinni::I32::toCpp(jniEnv, j_count),
                                  ::djinni_generated::NativeJavascriptCallback::toCpp(jniEnv, j_callback));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_youme_imrn_jni_RNYIMHistoryMessageManager_00024CppProxy_native_1DeleteHistoryMessageByID(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_messageID, ::djinni_generated::NativeJavascriptCallback::JniType j_callback)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::RNYIMHistoryMessageManager>(nativeRef);
        ref->DeleteHistoryMessageByID(::djinni::String::toCpp(jniEnv, j_messageID),
                                      ::djinni_generated::NativeJavascriptCallback::toCpp(jniEnv, j_callback));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_youme_imrn_jni_RNYIMHistoryMessageManager_00024CppProxy_native_1SetRoomHistoryMessageSwitch(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring roomID,jboolean save, ::djinni_generated::NativeJavascriptCallback::JniType j_callback)
{
  try {
    DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
    const auto& ref = ::djinni::objectFromHandleAddress<::RNYIMHistoryMessageManager>(nativeRef);
    ref->SetRoomHistoryMessageSwitch(::djinni::String::toCpp(jniEnv, roomID), ::djinni::Bool::toCpp(jniEnv,save),
                                  ::djinni_generated::NativeJavascriptCallback::toCpp(jniEnv, j_callback));
  } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated