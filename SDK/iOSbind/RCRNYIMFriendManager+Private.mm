// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from main.djinni

#import "RCRNYIMFriendManager+Private.h"
#import "RCRNYIMFriendManager.h"
#import "RVReactDjinni.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#import "RVJavascriptCallback+Private.h"
#import "RVReactBridge+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface RCRNYIMFriendManager ()

- (id)initWithCpp:(const std::shared_ptr<::RNYIMFriendManager>&)cppRef;

@end

@implementation RCRNYIMFriendManager {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::RNYIMFriendManager>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::RNYIMFriendManager>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}
+ (NSString *)moduleName
{
    return @"RNYIMFriendManager";
}

+ (nullable RCRNYIMFriendManager *)create:(nullable id<RVReactBridge>)bridge {
    try {
        auto objcpp_result_ = ::RNYIMFriendManager::create(::djinni_generated::ReactBridge::toCpp(bridge));
        return ::djinni_generated::RNYIMFriendManager::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_EXPORT_METHOD(RequestAddFriend:(nullable NSString *)userID
                          comments:(nullable NSString *)comments
                          callback:(nonnull RCTResponseSenderBlock)callback) {
    try {
        _cppRefHandle.get()->RequestAddFriend(::djinni::String::toCpp(userID),
                                              ::djinni::String::toCpp(comments),
                                              ::djinni_generated::JavascriptCallback::toCpp([RVReactDjinni wrapCallback:callback]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_EXPORT_METHOD(DealBeRequestAddFriend:(nullable NSString *)userID
                              dealResult:(int)dealResult
                                callback:(nonnull RCTResponseSenderBlock)callback) {
    try {
        _cppRefHandle.get()->DealBeRequestAddFriend(::djinni::String::toCpp(userID),
                                                    ::djinni::I32::toCpp(dealResult),
                                                    ::djinni_generated::JavascriptCallback::toCpp([RVReactDjinni wrapCallback:callback]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_EXPORT_METHOD(DeleteFriend:(nullable NSString *)userID
                    deleteType:(int)deleteType
                      callback:(nonnull RCTResponseSenderBlock)callback) {
    try {
        _cppRefHandle.get()->DeleteFriend(::djinni::String::toCpp(userID),
                                          ::djinni::I32::toCpp(deleteType),
                                          ::djinni_generated::JavascriptCallback::toCpp([RVReactDjinni wrapCallback:callback]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_EXPORT_METHOD(BlackFriend:(int)type
                       userID:(nullable NSString *)userID
                     callback:(nonnull RCTResponseSenderBlock)callback) {
    try {
        _cppRefHandle.get()->BlackFriend(::djinni::I32::toCpp(type),
                                         ::djinni::String::toCpp(userID),
                                         ::djinni_generated::JavascriptCallback::toCpp([RVReactDjinni wrapCallback:callback]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_EXPORT_METHOD(QueryFriends:(int)type
                    startIndex:(int)startIndex
                         count:(int)count
                      callback:(nonnull RCTResponseSenderBlock)callback) {
    try {
        _cppRefHandle.get()->QueryFriends(::djinni::I32::toCpp(type),
                                          ::djinni::I32::toCpp(startIndex),
                                          ::djinni::I32::toCpp(count),
                                          ::djinni_generated::JavascriptCallback::toCpp([RVReactDjinni wrapCallback:callback]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

RCT_EXPORT_METHOD(QueryFriendRequestList:(int)startIndex
                                   count:(int)count
                                callback:(nonnull RCTResponseSenderBlock)callback) {
    try {
        _cppRefHandle.get()->QueryFriendRequestList(::djinni::I32::toCpp(startIndex),
                                                    ::djinni::I32::toCpp(count),
                                                    ::djinni_generated::JavascriptCallback::toCpp([RVReactDjinni wrapCallback:callback]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}
/*
RCT_EXPORT_METHOD(GetRecommandUser:(int)startIndex
                             count:(int)count
                          callback:(nonnull RCTResponseSenderBlock)callback) {
    try {
        _cppRefHandle.get()->GetRecommandUser(::djinni::I32::toCpp(startIndex),
                                              ::djinni::I32::toCpp(count),
                                              ::djinni_generated::JavascriptCallback::toCpp([RVReactDjinni wrapCallback:callback]));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}
 */

namespace djinni_generated {

auto RNYIMFriendManager::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto RNYIMFriendManager::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<RCRNYIMFriendManager>(cpp);
}

}  // namespace djinni_generated

@end