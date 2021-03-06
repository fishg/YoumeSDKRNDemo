// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from main.djinni

#import "RVJavascriptCallback.h"
#import "RVReactBridge.h"
#import <Foundation/Foundation.h>
#import <React/RCTBridgeModule.h>
@class RCRNYIMLocationManager;


/**----------------------------地理位置管理---------------------------- */
@interface RCRNYIMLocationManager : NSObject<RCTBridgeModule>

+ (nullable RCRNYIMLocationManager *)create:(nullable id<RVReactBridge>)bridge;

/** 获取当前地理位置 */
- (void)GetCurrentLocation:(nonnull RCTResponseSenderBlock)callback;

/** 获取附近的人 */
- (void)GetNearbyObjects:(int)count
            serverAreaID:(nullable NSString *)serverAreaID
           districtLevel:(int)districtLevel
      resetStartDistance:(BOOL)resetStartDistance
                callback:(nonnull RCTResponseSenderBlock)callback;

/** 获取与指定用户距离 */
- (void)GetDistance:(nullable NSString *)userID
           callback:(nonnull RCTResponseSenderBlock)callback;

@end
