 /**
 @file YouMeConstDefine.h
 @brief 游密音频通话引擎回调事件和错误码定义
 
 该文件主要用于定义游密音频通话引擎回调事件和错误码
 
 @version 1.0 Copyright(c) 2015-2020 YOUME All rights reserved.
 @author YOUME

 */
 
#ifndef cocos2d_x_sdk_YouMeErrorCode_h
#define cocos2d_x_sdk_YouMeErrorCode_h

/// 频道状态
typedef enum ChannelState {
    CHANNEL_STATE_JOINIING = 0,  ///< 正在加入频道
    CHANNEL_STATE_JOINED,        ///< 已经加入频道
    CHANNEL_STATE_LEAVING_ONE,   ///< 正在离开单个频道
    CHANNEL_STATE_LEAVING_ALL,   ///< 正在离开所有频道
    CHANNEL_STATE_LEAVED         ///< 已经离开频道
} ChannelState_t;

/// 用户角色
typedef enum YouMeUserRole {
    YOUME_USER_NONE = 0,         ///< 非法用户，调用API时不能传此参数
    YOUME_USER_TALKER_FREE,      ///< 自由讲话者，适用于小组通话（建议小组成员数最多10个），每个人都可以随时讲话, 同一个时刻只能在一个语音频道里面
    YOUME_USER_TALKER_ON_DEMAND, ///< 需要通过抢麦等请求麦克风权限之后才可以讲话，适用于较大的组或工会等（比如几十个人），同一个时刻只能有一个或几个人能讲话, 同一个时刻只能在一个语音频道里面
    YOUME_USER_LISTENER,         ///< 听众，主播/指挥/嘉宾的听众，同一个时刻只能在一个语音频道里面，只听不讲
    YOUME_USER_COMMANDER,        ///< 指挥，国家/帮派等的指挥官，同一个时刻只能在一个语音频道里面，可以随时讲话，可以播放背景音乐，戴耳机情况下可以监听自己语音
    YOUME_USER_HOST,             ///< 主播，广播型语音频道的主持人，同一个时刻只能在一个语音频道里面，可以随时讲话，可以播放背景音乐，戴耳机情况下可以监听自己语音
    YOUME_USER_GUSET,            ///< 嘉宾，主播或指挥邀请的连麦嘉宾，同一个时刻只能在一个语音频道里面， 可以随时讲话
} YouMeUserRole_t;

/// 事件通知
typedef enum YouMeEvent {
    YOUME_EVENT_INIT_OK              = 0,  ///< SDK初始化成功
    YOUME_EVENT_INIT_FAILED          = 1,  ///< SDK初始化失败
    YOUME_EVENT_JOIN_OK              = 2,  ///< 进入语音频道成功
    YOUME_EVENT_JOIN_FAILED          = 3,  ///< 进入语音频道失败
    YOUME_EVENT_LEAVED_ONE           = 4,  ///< 退出单个语音频道完成
    YOUME_EVENT_LEAVED_ALL           = 5,  ///< 退出所有语音频道完成
    YOUME_EVENT_PAUSED               = 6,  ///< 暂停语音频道完成
    YOUME_EVENT_RESUMED              = 7,  ///< 恢复语音频道完成
    YOUME_EVENT_SPEAK_SUCCESS        = 8,  ///< 切换对指定频道讲话成功（适用于多频道模式）
    YOUME_EVENT_SPEAK_FAILED         = 9,  ///< 切换对指定频道讲话失败（适用于多频道模式）
    YOUME_EVENT_RECONNECTING         = 10, ///< 断网了，正在重连
    YOUME_EVENT_RECONNECTED          = 11, ///< 断网重连成功
    YOUME_EVENT_REC_PERMISSION_STATUS= 12, ///< 通知录音权限状态，成功获取权限时错误码为YOUME_SUCCESS，获取失败为YOUME_ERROR_REC_NO_PERMISSION（此时不管麦克风mute状态如何，都没有声音输出）
    YOUME_EVENT_BGM_STOPPED          = 13, ///< 通知背景音乐播放结束
    YOUME_EVENT_BGM_FAILED           = 14, ///< 通知背景音乐播放失败
    //YOUME_EVENT_MEMBER_CHANGE        = 15, ///< 频道成员变化
    YOUME_EVENT_OTHERS_MIC_ON        = 16, ///< 其他用户麦克风打开
    YOUME_EVENT_OTHERS_MIC_OFF       = 17, ///< 其他用户麦克风关闭
    YOUME_EVENT_OTHERS_SPEAKER_ON    = 18, ///< 其他用户扬声器打开
    YOUME_EVENT_OTHERS_SPEAKER_OFF   = 19, ///< 其他用户扬声器关闭
    YOUME_EVENT_OTHERS_VOICE_ON      = 20, ///< 其他用户进入讲话状态
    YOUME_EVENT_OTHERS_VOICE_OFF     = 21, ///< 其他用户进入静默状态
    YOUME_EVENT_MY_MIC_LEVEL         = 22, ///< 麦克风的语音级别

    YOUME_EVENT_MIC_CTR_ON           = 23, ///< 麦克风被其他用户打开
    YOUME_EVENT_MIC_CTR_OFF          = 24, ///< 麦克风被其他用户关闭    
	YOUME_EVENT_SPEAKER_CTR_ON       = 25, ///< 扬声器被其他用户打开
    YOUME_EVENT_SPEAKER_CTR_OFF      = 26, ///< 扬声器被其他用户关闭
    YOUME_EVENT_LISTEN_OTHER_ON      = 27, ///< 取消屏蔽某人语音
    YOUME_EVENT_LISTEN_OTHER_OFF     = 28, ///< 屏蔽某人语音
	
	YOUME_EVENT_LOCAL_MIC_ON		 = 29, ///< 自己的麦克风打开	
	YOUME_EVENT_LOCAL_MIC_OFF		 = 30, ///< 自己的麦克风关闭	
	YOUME_EVENT_LOCAL_SPEAKER_ON	 = 31, ///< 自己的扬声器打开
	YOUME_EVENT_LOCAL_SPEAKER_OFF	 = 32, ///< 自己的扬声器关闭

	YOUME_EVENT_GRABMIC_START_OK	 = 33, ///< 发起抢麦活动成功
	YOUME_EVENT_GRABMIC_START_FAILED = 34, ///< 发起抢麦活动失败
	YOUME_EVENT_GRABMIC_STOP_OK		 = 35, ///< 停止抢麦活动成功
	YOUME_EVENT_GRABMIC_STOP_FAILED  = 36, ///< 停止抢麦活动失败
	YOUME_EVENT_GRABMIC_REQUEST_OK	   = 37, ///< 抢麦成功（可以说话）
	YOUME_EVENT_GRABMIC_REQUEST_FAILED = 38, ///< 抢麦失败
	YOUME_EVENT_GRABMIC_REQUEST_WAIT	= 39, ///< 进入抢麦等待队列（仅权重模式下会回调此事件）
	YOUME_EVENT_GRABMIC_RELEASE_OK	   = 40, ///< 释放麦成功
	YOUME_EVENT_GRABMIC_RELEASE_FAILED = 41, ///< 释放麦失败
	YOUME_EVENT_GRABMIC_ENDMIC		   = 42, ///< 不再占用麦（到麦使用时间或者其他原因）

	YOUME_EVENT_GRABMIC_NOTIFY_START   = 43, ///< [通知]抢麦活动开始
	YOUME_EVENT_GRABMIC_NOTIFY_STOP    = 44, ///< [通知]抢麦活动结束
	YOUME_EVENT_GRABMIC_NOTIFY_HASMIC = 45, ///< [通知]有麦可以抢
	YOUME_EVENT_GRABMIC_NOTIFY_NOMIC = 46, ///< [通知]没有麦可以抢

	YOUME_EVENT_INVITEMIC_SETOPT_OK = 47, ///< 连麦设置成功
	YOUME_EVENT_INVITEMIC_SETOPT_FAILED = 48, ///< 连麦设置失败
	YOUME_EVENT_INVITEMIC_REQUEST_OK	 = 49, ///< 请求连麦成功（连上了，需等待对方回应）
	YOUME_EVENT_INVITEMIC_REQUEST_FAILED = 50, ///< 请求连麦失败
	YOUME_EVENT_INVITEMIC_RESPONSE_OK		= 51, ///< 响应连麦成功（被叫方无论同意/拒绝都会收到此事件，错误码是YOUME_ERROR_INVITEMIC_REJECT表示拒绝）
	YOUME_EVENT_INVITEMIC_RESPONSE_FAILED	= 52, ///< 响应连麦失败
	YOUME_EVENT_INVITEMIC_STOP_OK			= 53, ///< 停止连麦成功
	YOUME_EVENT_INVITEMIC_STOP_FAILED		= 54, ///< 停止连麦失败

	YOUME_EVENT_INVITEMIC_CAN_TALK			= 55, ///< 双方可以通话了（响应方已经同意）
	YOUME_EVENT_INVITEMIC_CANNOT_TALK		= 56, ///< 双方不可以再通话了（有一方结束了连麦或者连麦时间到）

	YOUME_EVENT_INVITEMIC_NOTIFY_CALL		= 57, ///< [通知]有人请求与你连麦
	YOUME_EVENT_INVITEMIC_NOTIFY_ANSWER		= 58, ///< [通知]对方对你的连麦请求作出了响应（同意/拒绝/超时，同意的话双方就可以通话了）
	YOUME_EVENT_INVITEMIC_NOTIFY_CANCEL		= 59, ///< [通知]连麦过程中，对方结束了连麦或者连麦时间到
    
    YOUME_EVENT_SEND_MESSAGE_RESULT         = 60, ///< sendMessage成功与否的通知，param为回传的requestID
    YOUME_EVENT_MESSAGE_NOTIFY              = 61, ///< 收到Message, param为message内容
  

    YOUME_EVENT_SET_WHITE_USER_LIST_OK      = 62, ///< 对指定频道设置白名单成功，但可能有异常用户
    YOUME_EVENT_SET_WHITE_USER_LIST_FAILED  = 63, ///< 对指定频道设置白名单失败
	
	YOUME_EVENT_KICK_RESULT                 = 64,   ///< 踢人的应答
    YOUME_EVENT_KICK_NOTIFY                 = 65,   ///< 被踢通知   ,param: （踢人者ID，被踢原因，被禁时间）
    
    YOUME_EVENT_FAREND_VOICE_LEVEL           = 66,  ///< 远端说话人音量大小
    YOUME_EVENT_OTHERS_BE_KICKED             = 67,   ///< 房间里其他人被踢出房间

	YOUME_EVENT_SPEAK_RECORD_ON				= 68,	///< 扬声器内录开启通知（成功、失败）
	YOUME_EVENT_SPEAK_RECORD_OFF			= 69,	///< 扬声器内录关闭通知（成功、失败）
	YOUME_EVENT_SPEAK_RECORD_RESET			= 70,	///< 扬声器内录重启通知（成功、失败）
    
    YOUME_EVENT_EFFECT_PLAY_COMPLETE        = 71,   ///< 音效播放完成
    //72-74 video已占用
    YOUME_EVENT_SWITCH_OUTPUT               = 75,   ///< 切换扬声器/听筒
    
    YOUME_EVENT_CHECK_DEVICE_MUTE_RESULT             = 76,   ///获取设备是否禁音的回调，errcode为1表示静音了，为0表示没禁音
	YOUME_EVENT_EOF					 = 1000,
} YouMeEvent_t;


typedef enum YouMeKickReason
{
    YOUME_KICK_ADMIN = 1,           ///< 管理员踢人
    YOUME_KICK_RELOGIN = 2,         ///< 多端登录被踢
} YouMeKickReason_t;

/// 房间内的广播消息
typedef enum YouMeBroadcast
{
	YOUME_BROADCAST_NONE = 0,
	YOUME_BROADCAST_GRABMIC_BROADCAST_GETMIC = 1,	///< 有人抢到了麦
	YOUME_BROADCAST_GRABMIC_BROADCAST_FREEMIC = 2,	///< 有人释放了麦
	YOUME_BROADCAST_INVITEMIC_BROADCAST_CONNECT = 3,	///< A和B正在连麦
	YOUME_BROADCAST_INVITEMIC_BROADCAST_DISCONNECT = 4, ///< A和B取消了连麦
}YouMeBroadcast_t;

typedef enum YouMeErrorCode {
    YOUME_SUCCESS                            = 0,    ///< 成功
    
    // 参数和状态检查
    YOUME_ERROR_API_NOT_SUPPORTED            = -1,   ///< 正在使用的SDK不支持特定的API
    YOUME_ERROR_INVALID_PARAM                = -2,   ///< 传入参数错误
    YOUME_ERROR_ALREADY_INIT                 = -3,   ///< 已经初始化
    YOUME_ERROR_NOT_INIT                     = -4,   ///< 还没有初始化，在调用某函数之前要先调用初始化并且要根据返回值确保初始化成功
    YOUME_ERROR_CHANNEL_EXIST                = -5,   ///< 要加入的频道已经存在
    YOUME_ERROR_CHANNEL_NOT_EXIST            = -6,   ///< 对频道进入（检查参数为true时）、退出、讲话、设置白名单、抢麦等接口时频道不存在
    YOUME_ERROR_WRONG_STATE                  = -7,   ///< 状态错误
    YOUME_ERROR_NOT_ALLOWED_MOBILE_NETWROK   = -8,   ///< 不允许使用移动网络
    YOUME_ERROR_WRONG_CHANNEL_MODE           = -9,   ///< 在单频道模式下调用了多频道接口，或者反之
    YOUME_ERROR_TOO_MANY_CHANNELS            = -10,  ///< 同时加入了太多频道
    YOUME_ERROR_TOKEN_ERROR                  = -11,  ///< 传入的token认证错误
    YOUME_ERROR_NOT_IN_CHANNEL               = -12,  ///< 用户不在该频道
    YOUME_ERROR_BE_KICK                      = -13,  ///< 被踢了，还在禁止时间内，不允许进入房间

    // 内部操作错误
    YOUME_ERROR_MEMORY_OUT                   = -100, ///< 内存错误
    YOUME_ERROR_START_FAILED                 = -101, ///< 启动引擎失败
    YOUME_ERROR_STOP_FAILED                  = -102, ///<  停止引擎失败
    YOUME_ERROR_ILLEGAL_SDK                  = -103, ///< 非法使用SDK
    YOUME_ERROR_SERVER_INVALID               = -104, ///< 语音服务不可用
    YOUME_ERROR_NETWORK_ERROR                = -105, ///< 网络错误
    YOUME_ERROR_SERVER_INTER_ERROR           = -106, ///< 服务器内部错误
    YOUME_ERROR_QUERY_RESTAPI_FAIL           = -107, ///< 请求RestApi信息失败了
    YOUME_ERROR_USER_ABORT                   = -108, ///< 用户请求中断当前操作
    YOUME_ERROR_SEND_MESSAGE_FAIL            = -109, ///< 发送消息失败

    
    // 麦克风错误
    YOUME_ERROR_REC_INIT_FAILED              = -201, ///< 录音模块初始化失败
    YOUME_ERROR_REC_NO_PERMISSION            = -202, ///< 没有录音权限
    YOUME_ERROR_REC_NO_DATA                  = -203, ///< 虽然初始化成功，但没有音频数据输出，比如oppo系列手机在录音权限被禁止的时候
    YOUME_ERROR_REC_OTHERS                   = -204, ///< 其他录音模块的错误
    YOUME_ERROR_REC_PERMISSION_UNDEFINED     = -205, ///< 录音权限未确定，iOS显示是否允许录音权限对话框时，返回的是这个错误码
    
	// 抢麦错误
	YOUME_ERROR_GRABMIC_FULL				 = -301, ///< 抢麦失败，人数满
	YOUME_ERROR_GRABMIC_HASEND				 = -302, ///< 抢麦失败，活动已经结束
	// 连麦错误
	YOUME_ERROR_INVITEMIC_NOUSER			 = -401, ///< 连麦失败，用户不存在
	YOUME_ERROR_INVITEMIC_OFFLINE			 = -402, ///< 连麦失败，用户已离线
	YOUME_ERROR_INVITEMIC_REJECT			 = -403, ///< 连麦失败，用户拒绝
	YOUME_ERROR_INVITEMIC_TIMEOUT			 = -404, ///< 连麦失败，两种情况：1.连麦时，对方超时无应答 2.通话中，双方通话时间到

    // 频道白名单错误
    YOUME_ERROR_WHITE_SOMEUSER_ABNORMAL		 = -501, ///< 设置白名单部分用户异常：已不在房间
    
    // 变声相关错误
    YOUME_ERROR_MAGICVOICE_EXPIRED           = -601, ///< 变声音效已过期

    YOUME_ERROR_UNKNOWN = -1000,         ///< 未知错误

} YouMeErrorCode_t;

typedef enum SERVER_MODE {
    SERVER_MODE_FORMAL               = 0,
    SERVER_MODE_TEST                 = 1,
    SERVER_MODE_DEV                  = 2,
    SERVER_MODE_DEMO                 = 3,
    SERVER_MODE_FIXED_IP_VALIDATE    = 4,
    SERVER_MODE_FIXED_IP_REDIRECT    = 5,
    SERVER_MODE_FIXED_IP_MCU         = 6
}SERVER_MODE_t;

typedef enum TEST_MODE {
    ONLINE_SERVER = 0,
    TEST_SERVER = 1,
    DEV_SERVER = 2,
    DEMO_SERVER = 3
}TEST_MODE_t;

typedef enum YOUME_RTC_SERVER_REGION {
    RTC_CN_SERVER       = 0,  // 中国
    RTC_HK_SERVER       = 1,  // 香港
    RTC_US_SERVER       = 2,  // 美国东部
    RTC_SG_SERVER       = 3,  // 新加坡
    RTC_KR_SERVER       = 4,  // 韩国
    RTC_AU_SERVER       = 5,  // 澳洲
    RTC_DE_SERVER       = 6,  // 德国
    RTC_BR_SERVER       = 7,  // 巴西
    RTC_IN_SERVER       = 8,  // 印度
    RTC_JP_SERVER       = 9,  // 日本
    RTC_IE_SERVER       = 10, // 爱尔兰
    RTC_USW_SERVER      = 11, // 美国西部
    RTC_USM_SERVER      = 12, // 美国中部
    RTC_CA_SERVER       = 13, // 加拿大
    RTC_LON_SERVER      = 14, // 伦敦
    RTC_FRA_SERVER      = 15, // 法兰克福
    RTC_DXB_SERVER      = 16, // 迪拜
    
    RTC_EXT_SERVER     = 10000, // 使用扩展服务器
    RTC_DEFAULT_SERVER = 10001, // 缺省服务器
}YOUME_RTC_SERVER_REGION_t;

typedef enum CallbackType {
    CALLBACK_TYPE_EVENT = 0,
    CALLBACK_TYPE_REST_API_RESPONSE,
    CALLBACK_TYPE_MEM_CHANGE,
    CALLBACK_TYPE_BROADCAST
} CallbackType_t;

typedef enum PcmCallBackFlag{
    PcmCallbackFlag_Remote = 0x1,       //远端pcm回调
    PcmCallbackFlag_Record = 0x2,       //本地录音回调
    PcmCallbackFlag_Mix = 0x4,          //本地录音和远端pcm进行mix之后的回调
} PcmCallBackFlag_t;

#endif // cocos2d_x_sdk_YouMeErrorCode_h
