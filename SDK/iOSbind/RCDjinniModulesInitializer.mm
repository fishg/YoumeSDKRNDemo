#import "RCDjinniModulesInitializer.h"
#import "RVReactDjinni.h"

#import "RCRNYIMManager.h"
#import "RCRNYIMCommon.h"
#import "RCRNYIMChannelManager.h"
#import "RCRNYIMMessageManager.h"
#import "RCRNYIMHistoryMessageManager.h"
#import "RCRNYIMLocationManager.h"
#import "RCRNYIMUserInfoManager.h"
#import "RCRNYIMFriendManager.h"
#import "RCRNVoiceEngine.h"


@interface RCDjinniModulesInitializer ()

@property (readonly) NSURL *url;
@property NSArray<id<RCTBridgeModule>> *modules;

@end

@implementation RCDjinniModulesInitializer

- (instancetype)initWithURL:(NSURL *)url {
  if (self = [super init]) {
    _url = url;
    _modules = nil;
  }
  return self;
}

- (NSURL *)sourceURLForBridge:(RCTBridge *)bridge {
  return self.url;
}

- (NSArray<id<RCTBridgeModule>> *)extraModulesForBridge:(RCTBridge *)bridge {
  if (self.modules == nil) {
    self.modules = @[[RCRNYIMManager create:[RVReactDjinni createReactBridge:bridge]],
                     [RCRNYIMCommon create:[RVReactDjinni createReactBridge:bridge]],
                     [RCRNYIMChannelManager create:[RVReactDjinni createReactBridge:bridge]],
                     [RCRNYIMMessageManager create:[RVReactDjinni createReactBridge:bridge]],
                     [RCRNYIMHistoryMessageManager create:[RVReactDjinni createReactBridge:bridge]],
                     [RCRNYIMLocationManager create:[RVReactDjinni createReactBridge:bridge]],
                     [RCRNYIMUserInfoManager create:[RVReactDjinni createReactBridge:bridge]],
                     [RCRNYIMFriendManager create:[RVReactDjinni createReactBridge:bridge]],
                     [RCRNVoiceEngine create:[RVReactDjinni createReactBridge:bridge]]];
  }
  return self.modules;
}

@end
