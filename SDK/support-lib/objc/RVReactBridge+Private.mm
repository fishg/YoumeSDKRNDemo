// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from react.djinni

#import "RVReactBridge+Private.h"
#import "RVReactBridge.h"
#import "DJIMarshal+Private.h"
#import "DJIObjcWrapperCache+Private.h"
#import "RVJavascriptArray+Private.h"
#import "RVJavascriptMap+Private.h"
#import "RVJobDispatcher+Private.h"
#import "RVJobQueue+Private.h"
#include <stdexcept>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

namespace djinni_generated {

class ReactBridge::ObjcProxy final
: public ::ReactBridge
, private ::djinni::ObjcProxyBase<ObjcType>
{
    friend class ::djinni_generated::ReactBridge;
public:
    using ObjcProxyBase::ObjcProxyBase;
    std::shared_ptr<::JavascriptMap> createMap() override
    {
        @autoreleasepool {
            auto objcpp_result_ = [djinni_private_get_proxied_objc_object() createMap];
            return ::djinni_generated::JavascriptMap::toCpp(objcpp_result_);
        }
    }
    std::shared_ptr<::JavascriptArray> createArray() override
    {
        @autoreleasepool {
            auto objcpp_result_ = [djinni_private_get_proxied_objc_object() createArray];
            return ::djinni_generated::JavascriptArray::toCpp(objcpp_result_);
        }
    }
    std::shared_ptr<::JavascriptMap> copyMap(const std::shared_ptr<::JavascriptMap> & c_map) override
    {
        @autoreleasepool {
            auto objcpp_result_ = [djinni_private_get_proxied_objc_object() copyMap:(::djinni_generated::JavascriptMap::fromCpp(c_map))];
            return ::djinni_generated::JavascriptMap::toCpp(objcpp_result_);
        }
    }
    std::shared_ptr<::JavascriptArray> copyArray(const std::shared_ptr<::JavascriptArray> & c_array) override
    {
        @autoreleasepool {
            auto objcpp_result_ = [djinni_private_get_proxied_objc_object() copyArray:(::djinni_generated::JavascriptArray::fromCpp(c_array))];
            return ::djinni_generated::JavascriptArray::toCpp(objcpp_result_);
        }
    }
    void emitEventWithMap(const std::string & c_name, const std::shared_ptr<::JavascriptMap> & c_params) override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() emitEventWithMap:(::djinni::String::fromCpp(c_name))
                                                                params:(::djinni_generated::JavascriptMap::fromCpp(c_params))];
        }
    }
    void emitEventWithArray(const std::string & c_name, const std::shared_ptr<::JavascriptArray> & c_params) override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() emitEventWithArray:(::djinni::String::fromCpp(c_name))
                                                                  params:(::djinni_generated::JavascriptArray::fromCpp(c_params))];
        }
    }
    std::shared_ptr<::JobDispatcher> createJobDispatcher(const std::shared_ptr<::JobQueue> & c_queue) override
    {
        @autoreleasepool {
            auto objcpp_result_ = [djinni_private_get_proxied_objc_object() createJobDispatcher:(::djinni_generated::JobQueue::fromCpp(c_queue))];
            return ::djinni_generated::JobDispatcher::toCpp(objcpp_result_);
        }
    }
};

}  // namespace djinni_generated

namespace djinni_generated {

auto ReactBridge::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return ::djinni::get_objc_proxy<ObjcProxy>(objc);
}

auto ReactBridge::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return dynamic_cast<ObjcProxy&>(*cpp).djinni_private_get_proxied_objc_object();
}

}  // namespace djinni_generated