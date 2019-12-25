// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from main.djinni

#include "NativeRNYIMMessageManager.hpp"  // my header
#include "Marshal.hpp"
#include "NativeJavascriptCallback.hpp"
#include "NativeReactBridge.hpp"

namespace djinni_generated {

NativeRNYIMMessageManager::NativeRNYIMMessageManager() : ::djinni::JniInterface<::RNYIMMessageManager, NativeRNYIMMessageManager>("com/youme/imrn/jni/RNYIMMessageManager$CppProxy") {}

NativeRNYIMMessageManager::~NativeRNYIMMessageManager() = default;


CJNIEXPORT void JNICALL Java_com_youme_imrn_jni_RNYIMMessageManager_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::RNYIMMessageManager>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_com_youme_imrn_jni_RNYIMMessageManager_create(JNIEnv* jniEnv, jobject /*this*/, ::djinni_generated::NativeReactBridge::JniType j_bridge)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::RNYIMMessageManager::create(::djinni_generated::NativeReactBridge::toCpp(jniEnv, j_bridge));
        return ::djinni::release(::djinni_generated::NativeRNYIMMessageManager::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_com_youme_imrn_jni_RNYIMMessageManager_00024CppProxy_native_1SendTextMessage(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_receiverID, jint j_chatType, jstring j_text,jstring j_extra, ::djinni_generated::NativeJavascriptCallback::JniType j_callback)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::RNYIMMessageManager>(nativeRef);
        ref->SendTextMessage(::djinni::String::toCpp(jniEnv, j_receiverID),
                             ::djinni::I32::toCpp(jniEnv, j_chatType),
                             ::djinni::String::toCpp(jniEnv, j_text),
                             ::djinni::String::toCpp(jniEnv, j_extra),
                             ::djinni_generated::NativeJavascriptCallback::toCpp(jniEnv, j_callback));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_youme_imrn_jni_RNYIMMessageManager_00024CppProxy_native_1SendAudioMessage(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_receiverID, jint j_chatType, ::djinni_generated::NativeJavascriptCallback::JniType j_callback)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::RNYIMMessageManager>(nativeRef);
        ref->SendAudioMessage(::djinni::String::toCpp(jniEnv, j_receiverID),
                              ::djinni::I32::toCpp(jniEnv, j_chatType),
                              ::djinni_generated::NativeJavascriptCallback::toCpp(jniEnv, j_callback));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_youme_imrn_jni_RNYIMMessageManager_00024CppProxy_native_1SendOnlyAudioMessage(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_receiverID, jint j_chatType, ::djinni_generated::NativeJavascriptCallback::JniType j_callback)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::RNYIMMessageManager>(nativeRef);
        ref->SendOnlyAudioMessage(::djinni::String::toCpp(jniEnv, j_receiverID),
                                  ::djinni::I32::toCpp(jniEnv, j_chatType),
                                  ::djinni_generated::NativeJavascriptCallback::toCpp(jniEnv, j_callback));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_youme_imrn_jni_RNYIMMessageManager_00024CppProxy_native_1SendFile(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_receiverID, jint j_chatType, jstring j_filePath, jint j_fileType, jstring j_extraParam, ::djinni_generated::NativeJavascriptCallback::JniType j_callback)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::RNYIMMessageManager>(nativeRef);
        ref->SendFile(::djinni::String::toCpp(jniEnv, j_receiverID),
                      ::djinni::I32::toCpp(jniEnv, j_chatType),
                      ::djinni::String::toCpp(jniEnv, j_filePath),
                      ::djinni::I32::toCpp(jniEnv, j_fileType),
                      ::djinni::String::toCpp(jniEnv, j_extraParam),
                      ::djinni_generated::NativeJavascriptCallback::toCpp(jniEnv, j_callback));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_youme_imrn_jni_RNYIMMessageManager_00024CppProxy_native_1StopAudioMessage(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_extraParam, ::djinni_generated::NativeJavascriptCallback::JniType j_callback)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::RNYIMMessageManager>(nativeRef);
        ref->StopAudioMessage(::djinni::String::toCpp(jniEnv, j_extraParam),
                              ::djinni_generated::NativeJavascriptCallback::toCpp(jniEnv, j_callback));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_youme_imrn_jni_RNYIMMessageManager_00024CppProxy_native_1CancelAudioMessage(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, ::djinni_generated::NativeJavascriptCallback::JniType j_callback)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::RNYIMMessageManager>(nativeRef);
        ref->CancelAudioMessage(::djinni_generated::NativeJavascriptCallback::toCpp(jniEnv, j_callback));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_youme_imrn_jni_RNYIMMessageManager_00024CppProxy_native_1DownloadFile(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_messageID, jstring j_savePath, ::djinni_generated::NativeJavascriptCallback::JniType j_callback)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::RNYIMMessageManager>(nativeRef);
        ref->DownloadFile(::djinni::String::toCpp(jniEnv, j_messageID),
                          ::djinni::String::toCpp(jniEnv, j_savePath),
                          ::djinni_generated::NativeJavascriptCallback::toCpp(jniEnv, j_callback));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_youme_imrn_jni_RNYIMMessageManager_00024CppProxy_native_1SetMessageRead(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_messageID, jboolean j_isRead, ::djinni_generated::NativeJavascriptCallback::JniType j_callback)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::RNYIMMessageManager>(nativeRef);
        ref->SetMessageRead(::djinni::String::toCpp(jniEnv, j_messageID),
                               ::djinni::Bool::toCpp (jniEnv, j_isRead),
                               ::djinni_generated::NativeJavascriptCallback::toCpp(jniEnv, j_callback));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_youme_imrn_jni_RNYIMMessageManager_00024CppProxy_native_1SetAllMessageRead(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_userID, jboolean j_isRead, ::djinni_generated::NativeJavascriptCallback::JniType j_callback)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::RNYIMMessageManager>(nativeRef);
        ref->SetAllMessageRead(::djinni::String::toCpp(jniEnv, j_userID),
                               ::djinni::Bool::toCpp (jniEnv, j_isRead),
                               ::djinni_generated::NativeJavascriptCallback::toCpp(jniEnv, j_callback));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}


}  // namespace djinni_generated