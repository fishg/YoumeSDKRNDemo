#pragma once

#include <list>
#include <vector>
#include <memory>
#include "YIMPlatformDefine.h"


#ifdef WIN32
    #ifdef YOUMEDLL_EXPORTS
        #define YOUMEDLL_API __declspec(dllexport)
    #else
        #define YOUMEDLL_API __declspec(dllimport)
    #endif
#else
    #define YOUMEDLL_API __attribute__ ((visibility("default")))
#endif


/************************************************************************/
/*								错误码									*/
/************************************************************************/
enum YIMErrorcode
{
	YIMErrorcode_Success = 0,					//成功
	YIMErrorcode_EngineNotInit = 1,				//未初始化
	YIMErrorcode_NotLogin = 2,					//未登录
	YIMErrorcode_ParamInvalid = 3,				//参数错误
	YIMErrorcode_TimeOut = 4,					//超时
	YIMErrorcode_StatusError = 5,				//状态错误
	YIMErrorcode_SDKInvalid = 6,				//SDK验证识别
	YIMErrorcode_AlreadyLogin = 7,				//已经登录
	YIMErrorcode_ServerError = 8,				//服务器错误
	YIMErrorcode_NetError = 9,					//网络错误
	YIMErrorcode_LoginSessionError = 10,		//session错误
	YIMErrorcode_NotStartUp = 11,				//未启动
	YIMErrorcode_FileNotExist = 12,				//文件不存在
	YIMErrorcode_SendFileError = 13,			//发送文件失败
	YIMErrorcode_UploadFailed = 14,				//上传失败
	YIMErrorcode_UsernamePasswordError = 15,	//用户名密码错误	
	YIMErrorcode_UserStatusError = 16,			//用户状态错误(无效用户)
	YIMErrorcode_MessageTooLong = 17,			//消息太长
	YIMErrorcode_ReceiverTooLong = 18,			//接收方ID过长(检查房间名)
	YIMErrorcode_InvalidChatType = 19,			//无效聊天类型(私聊、聊天室)
	YIMErrorcode_InvalidReceiver = 20,			//无效用户ID
	YIMErrorcode_UnknowError = 21,
	YIMErrorcode_InvalidAppkey = 22,			//无效APPKEY
	YIMErrorcode_ForbiddenSpeak = 23,			//被禁言
	YIMErrorcode_CreateFileFailed = 24,			//创建文件失败
	YIMErrorcode_UnsupportFormat = 25,			//不支持的文件格式
	YIMErrorcode_ReceiverEmpty = 26,			//接收方为空
	YIMErrorcode_RoomIDTooLong = 27,			//房间名太长
	YIMErrorcode_ContentInvalid =28,			//聊天内容严重非法
	YIMErrorcode_NoLocationAuthrize = 29,		//未打开定位权限
	YIMErrorcode_UnknowLocation = 30,			//未知位置
	YIMErrorcode_Unsupport = 31,				//不支持该接口
	YIMErrorcode_NoAudioDevice = 32,			//无音频设备
	YIMErrorcode_AudioDriver = 33,				//音频驱动问题
	YIMErrorcode_DeviceStatusInvalid = 34,		//设备状态错误
	YIMErrorcode_ResolveFileError = 35,			//文件解析错误
	YIMErrorcode_ReadWriteFileError = 36,		//文件读写错误
	YIMErrorcode_NoLangCode = 37,				//语言编码错误
	YIMErrorcode_TranslateUnable = 38,			//翻译接口不可用
	YIMErrorcode_SpeechAccentInvalid = 39,		//语音识别方言无效
	YIMErrorcode_SpeechLanguageInvalid = 40,	//语音识别语言无效
	YIMErrorcode_HasIllegalText = 41,			//消息含非法字符
	YIMErrorcode_AdvertisementMessage = 42,		//消息涉嫌广告
	YIMErrorcode_AlreadyBlock = 43,				//用户已经被屏蔽
	YIMErrorcode_NotBlock = 44,					//用户未被屏蔽
	YIMErrorcode_MessageBlocked = 45,			//消息被屏蔽
	YIMErrorcode_LocationTimeout = 46,			//定位超时
	YIMErrorcode_NotJoinRoom = 47,				//未加入该房间
	YIMErrorcode_LoginTokenInvalid = 48,		//登录token错误
	YIMErrorcode_CreateDirectoryFailed = 49,	//创建目录失败
	YIMErrorcode_InitFailed = 50,				//初始化失败
	YIMErrorcode_Disconnect = 51,				//与服务器断开
    
    YIMErrorcode_TheSameParam = 52,             //设置参数相同
    YIMErrorcode_QueryUserInfoFail = 53,        //查询用户信息失败
    YIMErrorcode_SetUserInfoFail = 54,          //设置用户信息失败
    YIMErrorcode_UpdateUserOnlineStateFail = 55,//更新用户在线状态失败
    YIMErrorcode_NickNameTooLong = 56,          //昵称太长(> 64 bytes)
    YIMErrorcode_SignatureTooLong = 57,         //个性签名太长(> 120 bytes)
	YIMErrorcode_NeedFriendVerify = 58,			//需要好友验证信息
	YIMErrorcode_BeRefuse = 59,					//添加好友被拒绝
    YIMErrorcode_HasNotRegisterUserInfo = 60,   //未注册用户信息
	YIMErrorcode_AlreadyFriend = 61,			//已经是好友
	YIMErrorcode_NotFriend = 62,				//非好友
	YIMErrorcode_NotBlack = 63,					//不在黑名单中
    YIMErrorcode_PhotoUrlTooLong = 64,          //头像url过长(>500 bytes)
    YIMErrorcode_PhotoSizeTooLarge = 65,        //头像太大（>100 kb）
	YIMErrorcode_ChannelMemberOverflow = 66,	// 达到频道人数上限

	//服务器的错误码
	YIMErrorcode_ALREADYFRIENDS = 1000,
	YIMErrorcode_LoginInvalid = 1001,

    //语音部分错误码
    YIMErrorcode_PTT_Start = 2000,
    YIMErrorcode_PTT_Fail = 2001,
    YIMErrorcode_PTT_DownloadFail = 2002,			//下载语音失败
	YIMErrorcode_PTT_GetUploadTokenFail = 2003,		//获取token失败
	YIMErrorcode_PTT_UploadFail = 2004,				//上传失败
    YIMErrorcode_PTT_NotSpeech = 2005,				//未检测到语音或未开始语音
	YIMErrorcode_PTT_DeviceStatusError = 2006,		//音频设备状态错误
	YIMErrorcode_PTT_IsSpeeching = 2007,			//正在录音
	YIMErrorcode_PTT_FileNotExist = 2008,			//文件不存在
	YIMErrorcode_PTT_ReachMaxDuration = 2009,		//达到语音最大时长限制
	YIMErrorcode_PTT_SpeechTooShort = 2010,			//语音时长太短
	YIMErrorcode_PTT_StartAudioRecordFailed = 2011,	//启动录音失败
	YIMErrorcode_PTT_SpeechTimeout = 2012,			//音频输入超时
	YIMErrorcode_PTT_IsPlaying = 2013,				//正在播放
	YIMErrorcode_PTT_NotStartPlay = 2014,			//未开始播放
	YIMErrorcode_PTT_CancelPlay = 2015,				//主动取消播放
	YIMErrorcode_PTT_NotStartRecord = 2016,			//未开始语音
	YIMErrorcode_PTT_NotInit = 2017,				// 未初始化
	YIMErrorcode_PTT_InitFailed = 2018,				// 初始化失败
	YIMErrorcode_PTT_Authorize = 2019,				// 录音权限
	YIMErrorcode_PTT_StartRecordFailed = 2020,		// 启动录音失败
	YIMErrorcode_PTT_StopRecordFailed = 2021,		// 停止录音失败
	YIMErrorcode_PTT_UnsupprtFormat = 2022,			// 不支持的格式
	YIMErrorcode_PTT_ResolveFileError = 2023,		// 解析文件错误
	YIMErrorcode_PTT_ReadWriteFileError = 2024,		// 读写文件错误
	YIMErrorcode_PTT_ConvertFileFailed = 2025,		// 文件转换失败
	YIMErrorcode_PTT_NoAudioDevice = 2026,			// 无音频设备
	YIMErrorcode_PTT_NoDriver = 2027,				// 驱动问题
	YIMErrorcode_PTT_StartPlayFailed = 2028,		// 启动播放失败
	YIMErrorcode_PTT_StopPlayFailed = 2029,			// 停止播放失败
	YIMErrorcode_PTT_RecognizeFailed = 2030,		// 识别失败

	YIMErrorcode_Fail = 10000
};

/************************************************************************/
/*                              服务器区域编码                          */
/************************************************************************/
enum ServerZone
{
	ServerZone_China = 0,		// 中国
	ServerZone_Singapore = 1,	// 新加坡
	ServerZone_America = 2,		// 美国
	ServerZone_HongKong = 3,	// 香港
	ServerZone_Korea = 4,		// 韩国
	ServerZone_Australia = 5,	// 澳洲
	ServerZone_Deutschland = 6,	// 德国
	ServerZone_Brazil = 7,		// 巴西
	ServerZone_India = 8,		// 印度
	ServerZone_Japan = 9,		// 日本
	ServerZone_Ireland = 10,	// 爱尔兰
	ServerZone_Thailand = 11,	// 泰国
	ServerZone_Taiwan = 12,		// 台湾
	ServerZone_Unknow = 9999
};

/************************************************************************/
/*								登录 登出								*/
/************************************************************************/
class IYIMLoginCallback
{
public:
	/*
	* 功能：登录回调
	* @param errorcode：错误码
	* @param userID：用户ID
	*/
	virtual void OnLogin(YIMErrorcode errorcode, const XString& userID,XUINT64 serverTime) {}
	
	/*
	* 功能：登出回调
	* @param errorcode：错误码
	*/
	virtual void OnLogout(YIMErrorcode errorcode) {}

	/*
	* 功能：被踢下线
	*/
	virtual void OnKickOff() {}
};


/************************************************************************/
/*                              频道接口								*/
/************************************************************************/

class YIMChatRoomManager
{
public:
	~YIMChatRoomManager();

	/*
	* 功能：加入房间
	* @param chatRoomID：房间ID
	* @return 错误码
	*/
	virtual YIMErrorcode JoinChatRoom(const XCHAR* chatRoomID) = 0;
	
	/*
	* 功能：离开房间
	* @param chatRoomID：房间ID
	* @return 错误码
	*/
	virtual YIMErrorcode LeaveChatRoom(const XCHAR* chatRoomID) = 0;
	
	/*
	* 功能：离开所有房间
	* @return 错误码
	*/
    virtual YIMErrorcode LeaveAllChatRooms() = 0;

	/*
	* 功能：获取房间成员数量
	* @param chatRoomID：房间ID(已成功加入该房间)
	* @return 错误码
	*/
	virtual YIMErrorcode GetRoomMemberCount(const XCHAR* chatRoomID) = 0;
};

//频道回调
class IYIMChatRoomCallback
{
public:
	/*
	* 功能：加入频道回调
	* @param chatRoomID：房间ID
	* @param errorcode：错误码
	*/
	virtual void OnJoinChatRoom(YIMErrorcode errorcode, const XString& chatRoomID) {}
	
	/*
	* 功能：离开频道回调
	* @param chatRoomID：房间ID
	* @param errorcode：错误码
	*/
	virtual void OnLeaveChatRoom(YIMErrorcode errorcode, const XString& chatRoomID) {}

	/*
	* 功能：离开所有已加入房间
	* @param errorcode：错误码
	*/
    virtual void OnLeaveAllChatRooms(YIMErrorcode errorcode) {}

	/*
	* 功能：其他用户加入频道通知
	* @param chatRoomID：房间ID
	* @param userID：用户ID
	*/
	virtual void OnUserJoinChatRoom(const XString& chatRoomID, const XString& userID)  {}

	/*
	* 功能：其他用户退出频道通知
	* @param chatRoomID：房间ID
	* @param userID：用户ID
	*/
	virtual void OnUserLeaveChatRoom(const XString& chatRoomID, const XString& userID) {}

	/*
	* 功能：获取房间成员数量回调
	* @param errorcode：错误码
	* @param chatRoomID：房间ID
	* @param count：成员数量
	*/
	virtual void OnGetRoomMemberCount(YIMErrorcode errorcode, const XString& chatRoomID, unsigned int count){}
};


/************************************************************************/
/*                              地理位置接口							*/
/************************************************************************/

// 行政区划等级
enum DistrictLevel
{
	DISTRICT_UNKNOW,
	DISTRICT_COUNTRY,	// 国家
	DISTRICT_PROVINCE,	// 省份
	DISTRICT_CITY,		// 市
	DISTRICT_COUNTY,	// 区县
	DISTRICT_STREET		// 街道
};

//地理位置信息
class GeographyLocation
{
public:
	virtual ~GeographyLocation();
	// 经度
	virtual double GetLongitude() = 0;
	// 纬度
	virtual double GetLatitude() = 0;
	// 行政区域编码
	virtual unsigned int GetDistrictCode() = 0;
	// 国家
	virtual const XCHAR* GetCountry() = 0;
	// 省份
	virtual const XCHAR* GetProvince() = 0;
	// 城市
	virtual const XCHAR* GetCity() = 0;
	// 区县
	virtual const XCHAR* GetDistrictCounty() = 0;
	// 街道
	virtual const XCHAR* GetStreet() = 0;
};

// 相对地理位置信息
class RelativeLocation 
{
public:
	virtual ~RelativeLocation();
	// UserID
	virtual const XCHAR* GetUserID() = 0;
	// 与对方的距离(千米)
	virtual unsigned int GetDistance() = 0;
	// 经度
	virtual double GetLongitude() = 0;
	// 纬度
	virtual double GetLatitude() = 0;
	// 国家
	virtual const XCHAR* GetCountry() = 0;
	// 省份
	virtual const XCHAR* GetProvince() = 0;
	// 城市
	virtual const XCHAR* GetCity() = 0;
	// 区县
	virtual const XCHAR* GetDistrictCounty() = 0;
	// 街道
	virtual const XCHAR* GetStreet() = 0;
};

// 地理位置回调
class IYIMLocationCallback
{
public:
	/*
	* 功能：获取自己位置回调
	* @param errorcode：错误码
	* @param location：地理位置信息
	*/
	virtual void OnUpdateLocation(YIMErrorcode errorcode, std::shared_ptr<GeographyLocation> location) {}

	/*
	* 功能：获取附近目标回调
	* @param errorcode：错误码
	* @param neighbourList：附近的目标列表
	* @param startDistance：起始距离(本次获取的附近目标距离自己最近的距离)
	* @param endDistance：终止距离(本次获取的附近目标距离自己最远的距离)
	*/
	virtual void OnGetNearbyObjects(YIMErrorcode errorcode, std::list< std::shared_ptr<RelativeLocation> > neighbourList, unsigned int startDistance, unsigned int endDistance) {}

	/*
	* 功能：获取与指定用户距离回调
	* @param errorcode：错误码
	* @param userID 用户ID
	* @param distance 距离（米）
	*/
	virtual void OnGetDistance(YIMErrorcode errorcode, const XString& userID, unsigned int distance){}
};

class YIMLocationManager
{
public:
    virtual ~YIMLocationManager() ;
	
	/*
	* 功能：获取当前地理位置
	* @return 错误码
	*/
	virtual YIMErrorcode GetCurrentLocation() = 0;
	
	/*
	* 功能：获取附近的目标（玩家的区服ID必须一致）
	* @param count：获取数量（一次最大200）
	* @param serverAreaID：区服ID（SetUserInfo接口设置）
	* @param districtlevel：行政区划等级
	* @param resetStartDistance：是否重置查找起始距离（true：重新从距离自己0米查找	false：从上次结果中距离最远的位置查找）
	* @return 错误码
	* comments：获取附近的目标之前必须先成功获取到自己的地理位置，成功回调OnUpdateLocation
	*/
	virtual YIMErrorcode GetNearbyObjects(int count, const XCHAR* serverAreaID, DistrictLevel districtlevel = DISTRICT_UNKNOW, bool resetStartDistance = false) = 0;

	/*
	* 功能：获取与指定用户距离
	* @param errorcode：错误码
	* @param userID 用户ID
	*/
	virtual YIMErrorcode GetDistance(const XCHAR* userID) = 0;

	/*
	* 功能：设置位置更新间隔（默认不进行位置更新自动检测，如非必要请不要开启自动更新）
	* @param interval：更新时间间隔(单位：分钟)
	*/
	virtual void SetUpdateInterval(unsigned int interval) = 0;
};


/************************************************************************/
/*								消息接口                                */
/************************************************************************/

//聊天类型
enum YIMChatType
{
	ChatType_Unknow = 0,
	ChatType_PrivateChat = 1,	//私聊
	ChatType_RoomChat = 2,		//聊天室
	ChatType_Multi
};

//文件类型
enum YIMFileType
{
	FileType_Other = 0,		// 其他
	FileType_Audio = 1,		// 音频
	FileType_Image = 2,		// 图片
	FileType_Video = 3		// 视频
};

//消息类型
enum YIMMessageBodyType
{
	MessageBodyType_Unknow = 0,
	MessageBodyType_TXT = 1,
	MessageBodyType_CustomMesssage = 2,
    MessageBodyType_Emoji = 3,
    MessageBodyType_Image = 4,
    MessageBodyType_Voice = 5,
    MessageBodyType_Video = 6,
    MessageBodyType_File = 7,
	MessageBodyType_Gift = 8
};

//禁言原因
enum YIMForbidSpeakReason
{
    ForbidReason_Unkown = 0,        //未知
    ForbidReason_AD      = 1,       //发广告
    ForbidReason_Insult  = 2,       //侮辱
    ForbidReason_Politics  = 3,     //政治敏感
    ForbidReason_Terrorism  = 4,    //恐怖主义
    ForbidReason_Reaction  = 5,     //反动
    ForbidReason_Sexy  = 6,         //色情
    ForbidReason_Other  = 7,        //其他
};

//所有消息的基类
class IYIMMessageBodyBase
{
public:
	virtual ~IYIMMessageBodyBase();
	//获取消息类型
	virtual YIMMessageBodyType GetMessageType() = 0;
};

//自定义消息
class IYIMMessageBodyCustom :public IYIMMessageBodyBase
{
public:
	//消息内容
	virtual std::string GetCustomMessage() = 0;
};

//文本消息
class IYIMMessageBodyText :public IYIMMessageBodyBase
{
public:
	//消息内容
	virtual const XCHAR* GetMessageContent() = 0;
    //发送文本附加信息（SendTextMessage传入，格式及如何解析由调用方自定）
    virtual const XCHAR* GetAttachParam() = 0;
};

//语音消息
class IYIMMessageBodyAudio :public IYIMMessageBodyBase
{
public:
	//语音翻译文字
    virtual const XCHAR* GetText() = 0;
	//语音大小（单位：字节）
	virtual unsigned int GetFileSize() = 0;
	//语音时长（单位：秒）
	virtual unsigned int GetAudioTime() = 0;
	//发送语音附加信息（StopAudioMessage传入，格式及如何解析由调用方自定）
	virtual const XCHAR* GetExtraParam() = 0;
	//音频路径
	virtual const XCHAR* GetLocalPath() = 0;
    //是否已播放，true-已播放，false-未播放
    virtual bool IsPlayed() = 0;
};

//文件消息
class IYIMMessageBodyFile :public IYIMMessageBodyBase
{
public:
	//文件大小（单位：字节）
	virtual unsigned int GetFileSize() = 0;
	//原文件名
	virtual const XCHAR* GetFileName() = 0;
	//文件扩展名
	virtual const XCHAR* GetFileExtension() = 0;
	//文件类型
	virtual YIMFileType GetFileType() = 0;
	//发送文件附加信息（SendFile传入，格式及如何解析由调用方自定）
	virtual const XCHAR* GetExtraParam() = 0;
	//文件路径
	virtual const XCHAR* GetLocalPath() = 0;
};

//礼物
class IYIMMessageGift : public IYIMMessageBodyBase
{
public:
	//礼物ID
	virtual int GetGiftID() = 0;
	//数量
	virtual unsigned int GetGiftCount() = 0;
	//主播
	virtual const XCHAR* GetAnchor() = 0;
	//附加字段
	virtual const XCHAR* GetExtraParam() = 0;
};

//完整消息
class IYIMMessage
{
public:
	virtual ~IYIMMessage();
    //消息ID
    virtual XUINT64 GetID() = 0;
	//消息ID
	virtual XUINT64 GetMessageID() = 0;
	//聊天类型
	virtual YIMChatType GetChatType() = 0;
	//接收者(聊天室：频道ID)
	virtual const XCHAR* GetReceiveID() = 0;
	//发送者
	virtual const XCHAR* GetSenderID() = 0;
	//消息体
	virtual IYIMMessageBodyBase* GetMessageBody() = 0;
	//发送时间（秒）
	virtual unsigned int GetCreateTime() = 0;
	//距离
	virtual unsigned int GetDistance() = 0;
	//是否已读
	virtual bool IsRead() = 0;
};

class IAudioSpeechInfo
{
public:
	//requestID(StartAudioSpeech返回)
	virtual XUINT64 GetRequestID() = 0;
	//语音翻译文字
	virtual const XCHAR* GetText() = 0;
	//语音大小（单位：字节）
	virtual unsigned int GetFileSize() = 0;
	//语音时长（单位：秒）
	virtual unsigned int GetAudioTime() = 0;
	//语音本地路径
	virtual const XCHAR* GetLocalPath() = 0;
	//语音下载路径
	virtual const XCHAR* GetDownloadURL() = 0;
};

// 翻译语言编码
//enum LanguageCode
//{
//    LANG_AUTO,
//    LANG_AB,            // 阿布哈西亚语 A
//    LANG_AA,            // 阿法尔 A
//    LANG_AK,            // 印尼语 A
//    LANG_AF,            // 南非荷兰语
//    LANG_AM,            // 阿姆哈拉语
//    LANG_AR,            // 阿拉伯语
//    LANG_AN,            // 阿拉贡语 A
//    LANG_AS,            // 阿萨姆语 A
//    LANG_AV,            // 阿瓦尔语 A
//    LANG_AE,            // 阿维斯陀语 A O
//    LANG_AY,            // 艾马拉 A
//    LANG_AZ,            // 阿塞拜疆
//    LANG_BM,            // 曼丁哥语 A
//    LANG_BA,            // 巴什基尔语 A
//    LANG_BE,            // 白俄罗斯语
//    LANG_BN,            // 孟加拉
//    LANG_BH,            // 比哈尔语 A O
//    LANG_BI,            // 比斯拉马语 A
//    LANG_BS,            // 波斯尼亚语
//    LANG_BR,            // 布列塔尼语 A
//    LANG_BG,            // 保加利亚语 A O
//    LANG_CA,            // 加泰罗尼亚语
//    LANG_CH,            // 查莫罗语 A
//    LANG_CE,            // 车臣 A
//    LANG_CV,            // 楚瓦什语 A
//    LANG_CO,            // 科西嘉
//    LANG_CR,            // 克里 A
//    LANG_CS,            // 捷克语
//    LANG_DA,            // 丹麦语
//    LANG_DE,            // 德语
//    LANG_DV,            // 迪维西语 A
//    LANG_DZ,            // 宗喀语 A O
//    LANG_EL,            // 希腊语
//    LANG_EN,            // 英语
//    LANG_EO,            // 世界语
//    LANG_ET,            // 爱沙尼亚语
//    LANG_EE,            // 埃维语 A
//    LANG_FO,            // 法罗语 A
//    LANG_FJ,            // 斐济语 A
//    LANG_FI,            // 芬兰语
//    LANG_FR,            // 法语
//    LANG_FF,            // 富拉赫语 A
//    LANG_FA,            // 波斯语
//    LANG_GL,            // 加利西亚
//    LANG_KA,            // 格鲁吉亚语
//    LANG_GA,            // 爱尔兰语
//    LANG_GV,            // 马恩岛语 A
//    LANG_GN,            // 瓜拉尼语 A
//    LANG_GU,            // 古吉拉特文
//    LANG_HT,            // 海地克里奥尔
//    LANG_HA,            // 豪撒语
//    LANG_HE,            // 希伯来语 A
//    LANG_HZ,            // 赫雷罗语 A
//    LANG_HI,            // 印地语
//    LANG_HO,            // 希利摩陀语 A
//    LANG_HU,            // 匈牙利语
//    LANG_IA,            // 国际语 A
//    LANG_ID,            // 印度尼西亚语
//    LANG_IE,            // 英语+爱尔兰 O
//    LANG_IG,            // 伊博
//    LANG_IK,            // 伊努皮克 A
//    LANG_IO,            // 世界语 A
//    LANG_IS,            // 冰岛语
//    LANG_IT,            // 意大利语
//    LANG_IU,            // 因纽特语 A
//    LANG_JA,            // 日语
//    LANG_JV,            // 爪哇语 A
//    LANG_RW,            // 卢旺达语 A
//    LANG_KL,            // 格陵兰语 A
//    LANG_KN,            // 卡纳达
//    LANG_KR,            // 卡努里语 A
//    LANG_KS,            // 克什米尔语 A
//    LANG_KK,            // 哈萨克语
//    LANG_KM,            // 高棉语
//    LANG_KI,            // 基库尤语 A
//    LANG_KY,            // 吉尔吉斯斯坦
//    LANG_KG,            // 斯瓦希里语 A
//    LANG_KO,            // 朝鲜语
//    LANG_KU,            // 库尔德
//    LANG_KJ,            // 库瓦亚马语 A
//    LANG_LA,            // 拉丁语
//    LANG_LB,            // 卢森堡语
//    LANG_LG,            // 甘达 A
//    LANG_LI,            // 林堡语 A
//    LANG_LN,            // 林加拉语 A
//    LANG_LO,            // 老挝
//    LANG_LT,            // 立陶宛语
//    LANG_LU,            // 鲁巴加丹加语 A
//    LANG_LV,            // 拉托维亚语+列托
//    LANG_MK,            // 马其顿语
//    LANG_MG,            // 马尔加什
//    LANG_MS,            // 马来语
//    LANG_ML,            // 马拉雅拉姆
//    LANG_MT,            // 马耳他
//    LANG_MI,            // 毛利
//    LANG_MR,            // 马拉地语
//    LANG_MH,            // 马绍尔语 A
//    LANG_MN,            // 蒙古
//    LANG_NA,            // 瑙鲁 A
//    LANG_NV,            // 纳瓦霍 A
//    LANG_ND,            // 北恩德贝勒语 A
//    LANG_NE,            // 尼泊尔
//    LANG_NG,            // 尼东阁语 A
//    LANG_NB,            // 书面挪威语 A
//    LANG_NN,            // 挪威尼诺斯克语 A
//    LANG_NO,            // 挪威语
//    LANG_II,            // 彝族 A
//    LANG_NR,            // 南恩德贝勒语 A
//    LANG_SQ,            // 阿尔巴尼亚语
//    LANG_NY,            // 齐切瓦语
//    LANG_ZH,            // 汉语
//    LANG_EU,            // 巴斯克
//    LANG_OC,            // 奥克西唐语 A
//    LANG_OJ,            // 奥吉布瓦 A
//    LANG_CU,            // 斯拉夫语 A
//    LANG_OM,            // 奥罗莫语 A
//    LANG_OR,            // 奥里雅语 A
//    LANG_OS,            // 奥塞特语 A
//    LANG_PA,            // 旁遮普语 A
//    LANG_PI,            // 巴利语 A
//    LANG_PL,            // 波兰语
//
//
//
//    LANG_AR_EG,            // 阿拉伯语+埃及
//    LANG_AR_IQ,            // 阿拉伯语+伊拉克
//    LANG_AR_JO,            // 阿拉伯语+约旦
//    LANG_AR_KW,            // 阿拉伯语+科威特
//    LANG_AR_LB,            // 阿拉伯语+黎巴嫩
//    LANG_AR_LY,            // 阿拉伯语+利比亚
//    LANG_AR_MA,            // 阿拉伯语+摩洛哥
//    LANG_AR_OM,            // 阿拉伯语+阿曼
//    LANG_AR_QA,            // 阿拉伯语+卡塔尔
//    LANG_AR_SA,            // 阿拉伯语+沙特阿拉伯
//    LANG_AR_SD,            // 阿拉伯语+苏丹
//    LANG_AR_SY,            // 阿拉伯语+叙利亚
//    LANG_AR_TN,            // 阿拉伯语+突尼斯
//    LANG_AR_YE,            // 阿拉伯语+也门
//    LANG_BE_BY,            // 白俄罗斯语+白俄罗斯
//    LANG_CA_ES,            // 加泰罗尼亚语+西班牙
//    LANG_CA_ES_EURO,    // 加泰罗尼亚语+西班牙,euro
//    LANG_CS_CZ,            // 捷克语+捷克共和国
//    LANG_CY,            // 威尔士语
//    LANG_DA_DK,            // 丹麦语+丹麦
//    LANG_DE_AT,            // 德语+奥地利
//    LANG_DE_AT_EURO,    // 德语+奥地利,euro
//    LANG_DE_CH,            // 德语+瑞士
//    LANG_DE_DE,            // 德语+德国
//    LANG_DE_DE_EURO,    // 德语+德国,euro
//    LANG_DE_LU,            // 德语+卢森堡
//    LANG_DE_LU_EURO,    // 德语+卢森堡,euro
//    LANG_EL_GR,            // 希腊语+希腊
//    LANG_EN_AU,            // 英语+澳大利亚
//    LANG_EN_CA,            // 英语+加拿大
//    LANG_EN_GB,            // 英语+英国
//    LANG_EN_IE_EURO,    // 英语+爱尔兰,euro
//    LANG_EN_NZ,            // 英语+新西兰
//    LANG_EN_US,            // 英语+美国
//    LANG_EN_ZA,            // 英语+南非
//    LANG_ES,            // 西班牙语
//    LANG_ES_BO,            // 西班牙语+玻利维亚
//    LANG_ES_AR,            // 西班牙语+阿根廷
//    LANG_ES_CL,            // 西班牙语+智利
//    LANG_ES_CO,            // 西班牙语+哥伦比亚
//    LANG_ES_CR,            // 西班牙语+哥斯达黎加
//    LANG_ES_DO,            // 西班牙语+多米尼加共和国
//    LANG_ES_EC,            // 西班牙语+厄瓜多尔
//    LANG_ES_ES,            // 西班牙语+西班牙
//    LANG_ES_ES_EURO,    // 西班牙语+西班牙,euro
//    LANG_ES_GT,            // 西班牙语+危地马拉
//    LANG_ES_HN,            // 西班牙语+洪都拉斯
//    LANG_ES_MX,            // 西班牙语+墨西哥
//    LANG_ES_NI,            // 西班牙语+尼加拉瓜
//    LANG_ES_PA,            // 西班牙语+巴拿马
//    LANG_ES_PE,            // 西班牙语+秘鲁
//    LANG_ES_PR,            // 西班牙语+波多黎哥
//    LANG_ES_PY,            // 西班牙语+巴拉圭
//    LANG_ES_SV,            // 西班牙语+萨尔瓦多
//    LANG_ES_UY,            // 西班牙语+乌拉圭
//    LANG_ES_VE,            // 西班牙语+委内瑞拉
//    LANG_FI_FI,            // 芬兰语+芬兰
//    LANG_FI_FI_EURO,    // 芬兰语+芬兰,euro
//    LANG_FR_BE,            // 法语+比利时
//    LANG_FR_BE_EURO,    // 法语+比利时,euro
//    LANG_FR_CA,            // 法语+加拿大
//    LANG_FR_CH,            // 法语+瑞士
//    LANG_FR_FR,            // 法语+法国
//    LANG_FR_FR_EURO,    // 法语+法国,euro
//    LANG_FR_LU,            // 法语+卢森堡
//    LANG_FR_LU_EURO,    // 法语+卢森堡,euro
//    LANG_FY,            // 弗里斯兰
//    LANG_GD,            // 苏格兰盖尔语
//    LANG_HAW,            // 夏威夷语
//    LANG_HR,            // 克罗地亚语
//    LANG_HR_HR,            // 克罗地亚语+克罗地亚
//    LANG_HU_HU,            // 匈牙利语+匈牙利
//    LANG_HY,            // 亚美尼亚
//    LANG_IS_IS,            // 冰岛语+冰岛
//    LANG_IT_CH,            // 意大利语+瑞士
//    LANG_IT_IT,            // 意大利语+意大利
//    LANG_IT_IT_EURO,    // 意大利语+意大利,euro
//    LANG_IW,            // 希伯来语
//    LANG_IW_IL,            // 希伯来语+以色列
//    LANG_JA_JP,            // 日语+日本
//    LANG_JW,            // 爪哇
//    LANG_KO_KR,            // 朝鲜语+南朝鲜
//    LANG_KW,            // 凯尔特语 A
//    LANG_LT_LT,            // 立陶宛语+立陶宛
//    LANG_LV_LV,            // 拉托维亚语+列托
//    LANG_MK_MK,            // 马其顿语+马其顿王国
//    LANG_MA,            // 旁遮普语
//    LANG_MY,            // 缅甸
//    LANG_NL,            // 荷兰语
//    LANG_NL_BE,            // 荷兰语+比利时
//    LANG_NL_BE_EURO,    // 荷兰语+比利时,euro
//    LANG_NL_NL,            // 荷兰语+荷兰
//    LANG_NL_NL_EURO,    // 荷兰语+荷兰,euro
//    LANG_NO_NO,            // 挪威语+挪威
//    LANG_NO_NO_NY,        // 挪威语+挪威,nynorsk
//
//    LANG_PL_PL,            // 波兰语+波兰
//    LANG_PS,            // 普什图语
//    LANG_PT,            // 葡萄牙语
//    LANG_PT_BR,            // 葡萄牙语+巴西
//    LANG_PT_PT,            // 葡萄牙语+葡萄牙
//    LANG_PT_PT_EURO,    // 葡萄牙语+葡萄牙,euro
//    LANG_RO,            // 罗马尼亚语
//    LANG_RO_RO,            // 罗马尼亚语+罗马尼亚
//    LANG_RU,            // 俄语
//    LANG_RU_RU,            // 俄语+俄罗斯
//    LANG_SD,            // 信德
//    LANG_SH,            // 塞波尼斯_克罗地亚语
//    LANG_SH_YU,            // 塞波尼斯_克罗地亚语+南斯拉夫
//    LANG_SI,            // 僧伽罗语
//    LANG_SK,            // 斯洛伐克语
//    LANG_SK_SK,            // 斯洛伐克语+斯洛伐克
//    LANG_SL,            // 斯洛语尼亚语
//    LANG_SL_SI,            // 斯洛语尼亚语+斯洛文尼亚
//    LANG_SM,            // 萨摩亚
//    LANG_SN,            // 修纳
//    LANG_SO,            // 索马里
//    LANG_SQ_AL,            // 阿尔巴尼亚语+阿尔巴尼亚
//    LANG_SR,            // 塞尔维亚语
//    LANG_SR_YU,            // 塞尔维亚语+南斯拉夫
//    LANG_ST,            // 塞索托语
//    LANG_SU,            // 巽他语
//    LANG_SV,            // 瑞典语
//    LANG_SV_SE,            // 瑞典语+瑞典
//    LANG_SW,            // 斯瓦希里语
//    LANG_TA,            // 泰米尔
//    LANG_TE,            // 泰卢固语
//    LANG_TG,            // 塔吉克斯坦
//    LANG_TH,            // 泰语
//    LANG_TH_TH,            // 泰语+泰国
//    LANG_TL,            // 菲律宾
//    LANG_TR,            // 土耳其语
//    LANG_TR_TR,            // 土耳其语+土耳其
//    LANG_UK,            // 乌克兰语
//    LANG_UK_UA,            // 乌克兰语+乌克兰
//    LANG_UR,            // 乌尔都语
//    LANG_UZ,            // 乌兹别克斯坦
//    LANG_VI,            // 越南
//    LANG_XH,            // 科萨
//    LANG_YID,            // 意第绪语
//    LANG_YO,            // 约鲁巴语
//    LANG_ZH_CN,            // 汉语+中国
//    LANG_ZH_HK,            // 汉语+香港
//    LANG_ZH_TW,            // 汉语+台湾
//    LANG_ZU                // 祖鲁语
//};
enum LanguageCode
{
    LANG_AUTO,
    LANG_AF,            // 南非荷兰语
    LANG_AM,            // 阿姆哈拉语
    LANG_AR,            // 阿拉伯语
    LANG_AR_AE,            // 阿拉伯语+阿拉伯联合酋长国
    LANG_AR_BH,            // 阿拉伯语+巴林
    LANG_AR_DZ,            // 阿拉伯语+阿尔及利亚
    LANG_AR_KW,            // 阿拉伯语+科威特
    LANG_AR_LB,            // 阿拉伯语+黎巴嫩
    LANG_AR_OM,            // 阿拉伯语+阿曼
    LANG_AR_SA,            // 阿拉伯语+沙特阿拉伯
    LANG_AR_SD,            // 阿拉伯语+苏丹
    LANG_AR_TN,            // 阿拉伯语+突尼斯
    LANG_AZ,            // 阿塞拜疆
    LANG_BE,            // 白俄罗斯语
    LANG_BG,            // 保加利亚语
    LANG_BN,            // 孟加拉
    LANG_BS,            // 波斯尼亚语
    LANG_CA,            // 加泰罗尼亚语
    LANG_CA_ES,            // 加泰罗尼亚语+西班牙
    LANG_CO,            // 科西嘉
    LANG_CS,            // 捷克语
    LANG_CY,            // 威尔士语
    LANG_DA,            // 丹麦语
    LANG_DE,            // 德语
    LANG_DE_CH,            // 德语+瑞士
    LANG_DE_LU,            // 德语+卢森堡
    LANG_EL,            // 希腊语
    LANG_EN,            // 英语
    LANG_EN_CA,            // 英语+加拿大
    LANG_EN_IE,            // 英语+爱尔兰
    LANG_EN_ZA,            // 英语+南非
    LANG_EO,            // 世界语
    LANG_ES,            // 西班牙语
    LANG_ES_BO,            // 西班牙语+玻利维亚
    LANG_ES_AR,            // 西班牙语+阿根廷
    LANG_ES_CO,            // 西班牙语+哥伦比亚
    LANG_ES_CR,            // 西班牙语+哥斯达黎加
    LANG_ES_ES,            // 西班牙语+西班牙
    LANG_ET,            // 爱沙尼亚语
    LANG_ES_PA,            // 西班牙语+巴拿马
    LANG_ES_SV,            // 西班牙语+萨尔瓦多
    LANG_ES_VE,            // 西班牙语+委内瑞拉
    LANG_ET_EE,            // 爱沙尼亚语+爱沙尼亚
    LANG_EU,            // 巴斯克
    LANG_FA,            // 波斯语
    LANG_FI,            // 芬兰语
    LANG_FR,            // 法语
    LANG_FR_BE,            // 法语+比利时
    LANG_FR_CA,            // 法语+加拿大
    LANG_FR_CH,            // 法语+瑞士
    LANG_FR_LU,            // 法语+卢森堡
    LANG_FY,            // 弗里斯兰
    LANG_GA,            // 爱尔兰语
    LANG_GD,            // 苏格兰盖尔语
    LANG_GL,            // 加利西亚
    LANG_GU,            // 古吉拉特文
    LANG_HA,            // 豪撒语
    LANG_HI,            // 印地语
    LANG_HR,            // 克罗地亚语
    LANG_HT,            // 海地克里奥尔
    LANG_HU,            // 匈牙利语
    LANG_HY,            // 亚美尼亚
    LANG_ID,            // 印度尼西亚
    LANG_IG,            // 伊博
    LANG_IS,            // 冰岛语
    LANG_IT,            // 意大利语
    LANG_IT_CH,            // 意大利语+瑞士
    LANG_JA,            // 日语
    LANG_KA,            // 格鲁吉亚语
    LANG_KK,            // 哈萨克语
    LANG_KN,            // 卡纳达
    LANG_KM,            // 高棉语
    LANG_KO,            // 朝鲜语
    LANG_KO_KR,            // 朝鲜语+南朝鲜
    LANG_KU,            // 库尔德
    LANG_KY,            // 吉尔吉斯斯坦
    LANG_LA,            // 拉丁语
    LANG_LB,            // 卢森堡语
    LANG_LO,            // 老挝
    LANG_LT,            // 立陶宛语
    LANG_LV,            // 拉托维亚语+列托
    LANG_MG,            // 马尔加什
    LANG_MI,            // 毛利
    LANG_MK,            // 马其顿语
    LANG_ML,            // 马拉雅拉姆
    LANG_MN,            // 蒙古
    LANG_MR,            // 马拉地语
    LANG_MS,            // 马来语
    LANG_MT,            // 马耳他
    LANG_MY,            // 缅甸
    LANG_NL,            // 荷兰语
    LANG_NL_BE,            // 荷兰语+比利时
    LANG_NE,            // 尼泊尔
    LANG_NO,            // 挪威语
    LANG_NY,            // 齐切瓦语
    LANG_PL,            // 波兰语
    LANG_PS,            // 普什图语
    LANG_PT,            // 葡萄牙语
    LANG_PT_BR,            // 葡萄牙语+巴西
    LANG_RO,            // 罗马尼亚语
    LANG_RU,            // 俄语
    LANG_SD,            // 信德
    LANG_SI,            // 僧伽罗语
    LANG_SK,            // 斯洛伐克语
    LANG_SL,            // 斯洛语尼亚语
    LANG_SM,            // 萨摩亚
    LANG_SN,            // 修纳
    LANG_SO,            // 索马里
    LANG_SQ,            // 阿尔巴尼亚语
    LANG_SR,            // 塞尔维亚语
    LANG_ST,            // 塞索托语
    LANG_SU,            // 巽他语
    LANG_SV,            // 瑞典语
    LANG_SV_SE,            // 瑞典语+瑞典
    LANG_SW,            // 斯瓦希里语
    LANG_TA,            // 泰米尔
    LANG_TE,            // 泰卢固语
    LANG_TG,            // 塔吉克斯坦
    LANG_TH,             //泰语
    LANG_TL,            // 菲律宾
    LANG_TR,            // 土耳其语
    LANG_UK,            // 乌克兰语
    LANG_UR,            // 乌尔都语
    LANG_UZ,            // 乌兹别克斯坦
    LANG_VI,            // 越南
    LANG_XH,            // 科萨
    LANG_YID,            // 意第绪语
    LANG_YO,            // 约鲁巴语
    LANG_ZH,            // 汉语
    LANG_ZH_TW,         // 繁体
    LANG_ZU               // 祖鲁语
};

// 举报处理结果
enum AccusationDealResult
{
	ACCUSATIONRESULT_IGNORE,			// 忽略
	ACCUSATIONRESULT_WARNING,			// 警告
	ACCUSATIONRESULT_FROBIDDEN_SPEAK	// 禁言
};

// 禁言结果
class IYIMForbidSpeakInfo
{
public:
    virtual ~IYIMForbidSpeakInfo();
    // 频道ID
    virtual const XCHAR* GetChannelID() = 0;
    // 是否封禁整个频道
    virtual bool GetIsForbidRoom() = 0;
    // 禁言原因类型
    virtual int GetReasonType() = 0;
    // 禁言结束时间
    virtual XUINT64 GetEndTime() = 0;
};

//消息回调
class IYIMMessageCallback
{
public:
	/*
	* 功能：发送消息回调
	* @param requestID：请求ID（与SendXXMessage发送消息的输出参数requestID一致）
	* @param errorcode：错误码
	* @param sendTime：发送时间戳
	* @param isForbidRoom：是否被禁言
	* @param reasonType：禁言原因
	* @param forbidEndTime：禁言结束时间
	*/
	virtual void OnSendMessageStatus(XUINT64 requestID, YIMErrorcode errorcode, unsigned int sendTime, bool isForbidRoom, int reasonType, XUINT64 forbidEndTime) {}

	/*
	* 功能：停止语音回调（发送端停止语音，发送语音消息之前，发送端可在此时显示消息）
	* @param requestID：请求ID（与SendAudioMessage输出参数requestID一致）
	* @param errorcode：错误码
	* @param text：语音识别结果
	* @param audioPath：语音文件路径
	* @param audioTime：语音时长（单位：秒）
	*/
    virtual void OnStartSendAudioMessage(XUINT64 requestID, YIMErrorcode errorcode, const XString& text, const XString& audioPath, unsigned int audioTime) {}

	/*
	* 功能：发送语音消息回调
	* @param requestID：请求ID（与SendAudioMessage输出参数requestID一致）
	* @param errorcode：错误码
	* @param text：语音识别结果
	* @param audioPath：语音文件路径
	* @param audioTime：语音时长（单位：秒）
	* @param sendTime：发送时间戳
	* @param isForbidRoom：是否被禁言
	* @param reasonType：禁言原因
	* @param forbidEndTime：禁言结束时间
	*/
	virtual void OnSendAudioMessageStatus(XUINT64 requestID, YIMErrorcode errorcode, const XString& text, const XString& audioPath, unsigned int audioTime, unsigned int sendTime, bool isForbidRoom,  int reasonType, XUINT64 forbidEndTime) {}
	
	/*
	* 功能：接收消息回调
	* @param message：消息
	*/
	virtual void OnRecvMessage( std::shared_ptr<IYIMMessage> message) {}

	/*
	* 功能：获取本地历史消息纪录回调
	* @param errorcode：错误码
	* @param targetID：目标ID
	* @param remain：剩余条数
	* @param messageList：消息列表
	*/
	virtual void OnQueryHistoryMessage(YIMErrorcode errorcode, const XString& targetID, int remain, std::list<std::shared_ptr<IYIMMessage> > messageList) {}
	
	/*
	* 功能：从服务器查询房间历史消息回调（每次最多30条）
	* @param errorcode：错误码
	* @param roomID 房间ID
	* @param remain 剩余消息数量
	* @param messageList 消息列表
	*/
	virtual void OnQueryRoomHistoryMessageFromServer(YIMErrorcode errorcode, const XString& roomID, int remain, std::list<std::shared_ptr<IYIMMessage> >& messageList){};

	/*
	* 功能：只录音语音结束回调（只录音接口StartAudioSpeech和StopAudioSpeech）
	* @param errorcode：错误码
	* @param audioSpeechInfo：语音消息
	*/
	virtual void OnStopAudioSpeechStatus(YIMErrorcode errorcode, std::shared_ptr<IAudioSpeechInfo> audioSpeechInfo) {}

	/*
	* 功能：新消息通知（默认自动接收消息，只有调用SetReceiveMessageSwitch设置为不自动接收消息，才会收到该回调）
	* @param errorcode：错误码
	* @param messageList：消息列表
	*/
	virtual void OnReceiveMessageNotify(YIMChatType chatType,  const XString&  targetID) {}

	/*
	* 功能：文本翻译回调
	* @param errorcode：错误码
	* @param requestID：请求ID（与TranslateText接口输出参数requestID一致）
	* @param text：翻译结果
	* @param srcLangCode：源语言编码
	* @param destLangCode：目标语言编码
	*/
	virtual void OnTranslateTextComplete(YIMErrorcode errorcode, unsigned int requestID, const XString& text, LanguageCode srcLangCode, LanguageCode destLangCode) {}
	
	/*
	* 功能：举报处理结果通知
	* @param result：举报处理结果
	* @param userID：用户ID
	* @param accusationTime：举报时间戳
	*/
	virtual void OnAccusationResultNotify(AccusationDealResult result, const XString& userID, unsigned int accusationTime) {}
    
	/*
	* 功能：获取禁言回调
	* @param errorcode：错误码
	* @param vecForbiddenSpeakInfos：禁言结果列表
	*/
    virtual void OnGetForbiddenSpeakInfo( YIMErrorcode errorcode, std::vector< std::shared_ptr<IYIMForbidSpeakInfo> > vecForbiddenSpeakInfos ) {}
    
	/*
	* 功能：仅语音识别回调（需要调用SetOnlyRecognizeSpeechText设置仅需要语音识别结果才会有该回调，不会发送语音消息，停止语音后回调）
	* @param requestID：请求ID（与SendAudioMessage输出参数requestID一致）
	* @param errorcode：错误码
	* @param text：语音识别结果
	*/
	virtual void OnGetRecognizeSpeechText(XUINT64 requestID, YIMErrorcode errorcode, const XString& text) {}	
	/*
	* 功能：屏蔽/解除屏蔽用户消息回调
	* @param errorcode：错误码
	* @param userID
	* @param block true-屏蔽 false-解除屏蔽
	*/
	virtual void OnBlockUser(YIMErrorcode errorcode, const XString& userID, bool block) {}

	/*
	* 功能：解除所有已屏蔽用户回调
	* @param errorcode 错误码
	*/
	virtual void OnUnBlockAllUser(YIMErrorcode errorcode) {}

	/*
	* 功能：获取被屏蔽消息用户回调
	* @param errorcode：错误码
	* @param userList userID集
	*/
	virtual void OnGetBlockUsers(YIMErrorcode errorcode, std::list<XString> userList) {}

	/*
	* 功能：录音音量变化回调
	* @param volume：音量值(0到1)
	*/
	virtual void OnRecordVolumeChange(float volume) {}
};

//下载回调
class IYIMDownloadCallback
{
public:
	/*
	* 功能：下载回调（根据messageID下载）
	* @param errorcode：错误码
	* @param msg 消息
	* @param savePath 保存路径
	*/
    virtual void OnDownload( YIMErrorcode errorcode, std::shared_ptr<IYIMMessage> msg, const XString& savePath ){}
    
	/*
	* 功能：下载回调（根据messageID下载）
	* @param errorcode：错误码
	* @param strFromUrl URL
	* @param savePath 保存路径
	*/
    virtual void OnDownloadByUrl( YIMErrorcode errorcode, const XString& strFromUrl, const XString& savePath ){}
};

//语音识别语言
enum SpeechLanguage
{
	SPEECHLANG_MANDARIN,	// 普通话(Android IOS Windows)
	SPEECHLANG_YUEYU,		// 粤语(Android IOS Windows)
	SPEECHLANG_SICHUAN,		// 四川话(Android IOS)
	SPEECHLANG_HENAN,		// 河南话(IOS)
	SPEECHLANG_ENGLISH,		// 英语(Android IOS Windows)
	SPEECHLANG_TRADITIONAL	// 繁体中文(Android IOS Windows)
};

//消息管理器
class YIMMessageManager
{
public:
    virtual ~YIMMessageManager();
	
	/*
	* 功能：发送文本消息
	* @param receiverID：接收方ID
	* @param chatType：聊天类型
	* @param text：消息内容
	* @param requestID：请求ID
	* @return 错误码
	*/
	virtual YIMErrorcode SendTextMessage(const XCHAR* receiverID, YIMChatType chatType, const XCHAR* text, const XCHAR* attachParam, XUINT64* requestID) = 0;
	
	/*
	* 功能：群发文本消息
	* @param vecReceiver：接收方ID列表
	* @param text：消息内容
	* @return 错误码
	*/
    virtual YIMErrorcode MultiSendTextMessage( const std::vector<XString>&  vecReceiver, const XCHAR* text) = 0;

	/*
	* 功能：发送自定义消息
	* @param receiverID：接收方ID
	* @param chatType：聊天类型
	* @param content：消息内容
	* @param size：消息内容字节长度
	* @param requestID：请求ID
	* @return 错误码
	*/
	virtual YIMErrorcode SendCustomMessage(const XCHAR* receiverID, YIMChatType chatType, const char* content, unsigned int size, XUINT64* requestID) = 0;
	
	/*
	* 功能：发送文件
	* @param receiverID：接收方ID
	* @param chatType：聊天类型
	* @param filePath：文件路径
	* @param requestID：请求ID
	* @param extraParam：附加参数
	* @param fileType：文件类型
	* @return 错误码
	*/
	virtual YIMErrorcode SendFile(const XCHAR* receiverID, YIMChatType chatType, const XCHAR* filePath, XUINT64* requestID, const XCHAR* extraParam, YIMFileType fileType = FileType_Other) = 0;

	/*
	* 功能：发送语音消息（带语音识别）
	* @param receiverID：接收方ID
	* @param chatType：聊天类型
	* @param requestID：请求ID
	* @return 错误码
	*/
	virtual YIMErrorcode SendAudioMessage(const XCHAR* receiverID, YIMChatType chatType, XUINT64* requestID) = 0;
	
	/*
	* 功能：发送语音消息（不带语音识别）
	* @param receiverID：接收方ID
	* @param chatType：聊天类型
	* @param requestID：请求ID
	* @return 错误码
	*/
	virtual YIMErrorcode SendOnlyAudioMessage(const XCHAR* receiverID, YIMChatType chatType, XUINT64* requestID) = 0;

	/*
	* 功能：停止语音
	* @param extraParam：语音消息附加参数
	* @return 错误码
	*/
	virtual YIMErrorcode StopAudioMessage(const XCHAR* extraParam) = 0;
	
	/*
	* 功能：取消语音
	* @return 错误码
	*/
    virtual YIMErrorcode CancleAudioMessage() =0;
	
	/*
	* 功能：发送礼物
	* @param anchorID：主播ID
	* @param channel：频道
	* @param giftId：礼物ID
	* @param giftCount：礼物数量
	* @param extraParam：附加参数（格式为json {"nickname":"昵称","server_area":"区服","location":"位置","score":"积分","level":"等级","vip_level":"VIP等级","extra":"附加参数"}）
	* @param requestID：请求ID
	* @return 错误码
	*/
	virtual YIMErrorcode SendGift(const XCHAR* anchorID, const XCHAR* channel, int giftId, int giftCount, const char* extraParam, XUINT64* requestID) = 0;

	/*
	* 功能：下载语音消息
	* @param messageID：消息ID
	* @param savePath：保存路径（若调用SetDownloadDir设置保存路径，可为空；否则须指定全路径）
	* @return 错误码
	*/
	virtual YIMErrorcode DownloadFile(XUINT64 messageID, const XCHAR* savePath) = 0;

	/*
	* 功能：下载文件
	* @param downloadURL：URL
	* @param savePath：保存路径（若调用SetDownloadDir设置保存路径，可为空；否则须指定全路径）
	* @return 错误码
	*/
	virtual YIMErrorcode DownloadFile(const XCHAR* downloadURL, const XCHAR* savePath) = 0;

	/*
	* 功能：设置下载保存目录（DownloadFile的默认下载目录）
	* @param path：下载目录
	* @return 错误码
	*/
	virtual YIMErrorcode SetDownloadDir(const XCHAR* path) = 0;

	/*
	* 功能：查询本地历史消息记录
	* @param targetID：目标ID
	* @param chatType：聊天类型
	* @param startMessageID：起始消息ID（默认为0，从最新一条消息ID开始查询）
	* @param count：消息数量（一次最大100条）
	* @param direction：查询方向 0：向前查找（比startMessageID时间更早）	1：向后查找（比startMessageID时间更晚）
	* @return 错误码
	*/
	virtual YIMErrorcode QueryHistoryMessage(const XCHAR* targetID, YIMChatType chatType, XUINT64 startMessageID = 0, int count = 30, int direction = 0) = 0;
	
	/*
	* 功能：删除历史消息
	* @param chatType：聊天类型
	* @param time：时间戳（删除指定时间之前的消息）
	* @return 错误码
	*/
	virtual YIMErrorcode DeleteHistoryMessage(YIMChatType chatType = ChatType_Unknow, XUINT64 time = 0) = 0;
	
	/*
	* 功能：删除历史消息（删除startMessageID时间之前count条消息）
	* @param targetID：userID或roomID
	* @param chatType：聊天类型
	* @param startMessageID：起始消息ID（默认0 最近一条消息）
	* @param count：消息数量（默认0 删除所有消息）
	* @return 错误码
	*/
	virtual YIMErrorcode DeleteHistoryMessage(const XCHAR* targetID, YIMChatType chatType, XUINT64 startMessageID = 0, unsigned int count = 0) = 0;

	/*
	* 功能：删除指定messageID对应消息
	* @param messageID：消息ID
	* @return 错误码
	*/
	virtual YIMErrorcode DeleteHistoryMessageByID(XUINT64 messageID) = 0;

    /*删除指定用户的本地聊天历史记录，保留指定的消息ID列表记录
     *targetID:userID
     *chatType:聊天类型(指定私聊)
     *excludeMesList:保留的消息ID列表
     *return 错误码
     */
    virtual YIMErrorcode DeleteSpecifiedHistoryMessage(const XCHAR* targetID, YIMChatType chatType, const std::vector<XUINT64>& excludeMesList) = 0;
    
	/*
	* 功能：从服务器查询房间最近历史消息
	* @param roomID：房间id
	* @param count：消息数量(最大200条)
	* @param direction：历史消息排序方向 0：按时间戳升序	1：按时间戳逆序
	* @return 错误码
	*/
	virtual YIMErrorcode QueryRoomHistoryMessageFromServer(const XCHAR* roomID, int count = 0, int direction = 0) = 0;

	/*
	* 功能：只录音开始语音（不通过游密发送该语音消息，由调用方发送，调用StopAudioSpeech停止语音及上传后会回调OnStopAudioSpeechStatus）
	* @param requestID：消息ID
	* @param translate：是否需要语音识别
	* @return 错误码
	*/
	virtual YIMErrorcode StartAudioSpeech(XUINT64* requestID, bool translate = true) = 0;

	/*
	* 功能：只录音停止语音（不通过游密发送该语音消息，由调用方发送，调用StopAudioSpeech停止语音及上传后会回调OnStopAudioSpeechStatus）
	* @param requestID：消息ID
	* @param translate：是否需要语音识别
	* @return 错误码
	*/
	virtual YIMErrorcode StopAudioSpeech() = 0;

	/*
	* 功能：转换AMR格式到WAV格式
	* @param amrFilePath：AMR文件路径
	* @param wavFielPath：WAV文件保存路径
	* @return 错误码
	*/
	virtual YIMErrorcode ConvertAMRToWav(const XCHAR* amrFilePath, const XCHAR* wavFielPath = NULL) = 0;

	/*
	* 功能：是否自动下载语音消息
	* @param download：true：自动下载语音消息  false：不自动下载语音消息(默认)
	* @return 错误码
	*/
    virtual YIMErrorcode SetDownloadAudioMessageSwitch(bool download) = 0;

	/*
	* 功能：设置是否自动接收消息（房间消息 ）
	* @param vecRoomIDs：房间ID列表
	* @param receive：true:自动接收(默认)	false:不自动接收消息,有新消息达到时，SDK会发出OnReceiveMessageNotify回调，调用方需要调用GetMessage获取新消息
	* @return 错误码
	*/
    virtual YIMErrorcode SetReceiveMessageSwitch( const std::vector<XString>& vecRoomIDs, bool receive) = 0;
	
	/*
	* 功能：获取新消息（只有SetReceiveMessageSwitch设置为不自动接收消息，才需要在收到OnReceiveMessageNotify回调时调用该函数）
	* @param vecRoomIDs：房间ID列表
	* @return 错误码
	*/
	virtual YIMErrorcode GetNewMessage(const std::vector<XString>& vecRoomIDs) = 0;

	/*
	* 功能：是否保存房间消息到本地历史记录
	* @param vecRoomIDs：房间ID列表
	* @param save：是否保存（默认不保存）
	* @return 错误码
	*/
	virtual YIMErrorcode SetRoomHistoryMessageSwitch(const std::vector<XString>& vecRoomIDs, bool save) = 0;

	/*
	* 功能：是否保存房间消息到本地历史记录
	* @param roomID：房间ID
	* @param save：是否保存（默认不保存）
	* @return 错误码
	*/
	virtual YIMErrorcode SetRoomHistoryMessageSwitch(const XCHAR* roomID, bool save) = 0;

	/*
	* 功能：设置消息是否已读
	* @param messageID：消息ID
	* @param read：是否已读
	* @return 错误码
	*/
	virtual YIMErrorcode SetMessageRead(XUINT64 messageID, bool read) = 0;

    // 设置某用户的所有消息为已读
    virtual YIMErrorcode SetAllMessageRead(const XCHAR* userID, bool read) = 0;
    
    // 设置语音消息为已播放,true-已播放，false-未播放
    virtual YIMErrorcode SetVoiceMsgPlayed(XUINT64 messageID, bool played) = 0;
    
	/*
	* 功能：暂停消息接收
	* @param pause：true: 暂停接收消息； false: 不暂停接收消息(默认)
	* @return 错误码
	*/
    virtual YIMErrorcode PauseReceiveMessage(bool pause) = 0;

	/*
	* 功能：国际语言文本翻译
	* @param requestID：请求ID
	* @param text：内容
	* @param destLangCode：目标语言编码
	* @param srcLangCode：源语言编码
	* @return 错误码
	*/
	virtual YIMErrorcode TranslateText(unsigned int* requestID, const XCHAR* text, LanguageCode destLangCode, LanguageCode srcLangCode = LANG_AUTO) = 0;

	/*
	* 功能：设置语音识别语言
	* @param language：语音方言语言
	* @return 错误码
	*/
	virtual YIMErrorcode SetSpeechRecognizeLanguage(SpeechLanguage language) = 0;
    
	/*
	* 功能：设置仅识别语音文字，不发送语音消息
	* @param recognition：false:识别语音文字并发送语音消息，true:仅识别语音文字
	* @return 错误码
	*/
    virtual YIMErrorcode SetOnlyRecognizeSpeechText(bool recognition) = 0;
	/*
	* 功能：举报
	* @param userID：被举报人ID
	* @param source：举报来源（私聊/房间）
	* @param reason：举报原因
	* @param description：举报原因描述（最长180字）
	* @param extraParam：附加参数（JSON格式 {"nickname":"","server_area":"","level":"","vip_level":""}）
	* @return 错误码
	*/
	virtual YIMErrorcode Accusation(const XCHAR* userID, YIMChatType source, int reason, const XCHAR* description, const XCHAR* extraParam) = 0;
    
	/*
	* 功能：获取禁言信息
	* @return 错误码
	*/
    virtual YIMErrorcode GetForbiddenSpeakInfo() = 0 ;

	/*
	* 功能：屏蔽/解除屏蔽用户消息
	* @param userID：用户ID
	* @param block：true-屏蔽 false-解除屏蔽
	* @return 错误码
	*/
	virtual YIMErrorcode BlockUser(const XCHAR* userID, bool block) = 0;

	/*
	* 功能：解除所有已屏蔽用户
	* @return 错误码
	*/
	virtual YIMErrorcode UnBlockAllUser() = 0;

	/*
	* 功能：获取被屏蔽消息用户
	* @return 错误码
	*/
	virtual YIMErrorcode GetBlockUsers() = 0;
};


/************************************************************************/
/*                                  公告	    						*/
/************************************************************************/

// 公告信息
class YIMNotice
{
public:
	virtual ~YIMNotice();
	// 公告ID
	virtual XUINT64 GetNoticeID() = 0;
	// 频道ID
	virtual const XCHAR* GetChannelID() = 0;
	// 公告类型		1:跑马灯公告  2:聊天框公告  3:置顶公告
	virtual int GetNoticeType() = 0;
	// 公告内容
	virtual const XCHAR* GetContent() = 0;
	// 链接关键字
	virtual const XCHAR* GetLinkText() = 0;
	// 链接地址
	virtual const XCHAR* GetLinkAddr() = 0;
	// 起始时间(置顶公告)
	virtual unsigned int GetBeginTime() = 0;
	// 结束时间(置顶公告)
	virtual unsigned int GetEndTime() = 0;
};

// 公告回调
class IYIMNoticeCallback
{
public:
	/*
	* 功能：接收公告
	* @param notice：公告信息
	*/
    virtual void OnRecvNotice(YIMNotice* notice) {}
	
	/*
	* 功能：撤销公告
	* @param noticeID：公告ID
	* @param channelID：频道（房间）ID
	*/
	virtual void OnCancelNotice(XUINT64 noticeID, const XString& channelID)  {}
};


/************************************************************************/
/*                                  联系人	    						*/
/************************************************************************/

//用户状态
enum YIMUserStatus
{
	STATUS_ONLINE,	 //在线
	STATUS_OFFLINE,	 //离线
    STATUS_INVISIBLE //隐身
};

//最近联系人消息
class IYIMContactsMessageInfo
{
public:
	virtual ~IYIMContactsMessageInfo();
	//联系人
	virtual const XCHAR* GetContactID() = 0;
	//消息时间
	virtual unsigned int GetCreateTime() = 0;
	//消息内容
	virtual const XCHAR* GetMessageContent() = 0;
	//消息类型
	virtual YIMMessageBodyType GetMessageType() = 0;
    //未读消息数量
    virtual unsigned int GetNotReadMsgNum() = 0;
    //本地路径
    virtual const XCHAR* GetLocalPath() = 0;
//    //额外信息
//    virtual const XCHAR* GetExtra() = 0;
};

// 联系人回调
class IYIMContactCallback
{
public:
	/*
	* 功能：获取最近联系人回调
	* @param errorcode：错误码
	* @param contactList：联系人列表
	*/
	virtual void OnGetRecentContacts(YIMErrorcode errorcode, std::list<std::shared_ptr<IYIMContactsMessageInfo> >& contactList) {}
	
	/*
	* 功能：获取用户信息回调
	* @param errorcode：错误码
	* @param userID：用户ID
	* @param userInfo：用户信息（JSON格式 SetUserInfo接口所设置）
	*/
	virtual void OnGetUserInfo(YIMErrorcode errorcode, const XString& userID, const XString&  userInfo) {}
	
	/*
	* 功能：查询用户状态回调
	* @param errorcode：错误码
	* @param userID：用户ID
	* @param status：状态
	*/
	virtual void OnQueryUserStatus(YIMErrorcode errorcode, const XString&  userID, YIMUserStatus status){}
};


/************************************************************************/
/*                                 语音播放 	    					*/
/************************************************************************/

// 麦克风状态
enum AudioDeviceStatus
{
	STATUS_AVAILABLE,		// 可用
	STATUS_NO_AUTHORITY,	// 无权限
	STATUS_MUTE,			// 静音
	STATUS_UNAVAILABLE		// 不可用
};

//语音播放回调
class IYIMAudioPlayCallback
{
public:
	/*
	* 功能：播放完成回调
	* @param errorcode：错误码
	* @param path： 播放文件路径
	*/
	virtual void OnPlayCompletion(YIMErrorcode errorcode, const XString& path) {}

	/*
	* 功能：获取麦克风状态回调
	* @param status：麦克风状态
	*/
	virtual void OnGetMicrophoneStatus(AudioDeviceStatus status) {}
};


enum ReconnectResult
{
	RECONNECTRESULT_SUCCESS,        // 重连成功
	RECONNECTRESULT_FAIL_AGAIN,     // 重连失败，再次重连
	RECONNECTRESULT_FAIL           // 重连失败
};

// 重连回调
class IYIMReconnectCallback
{
public:
	// 开始重连
	virtual void OnStartReconnect() {}
	// 收到重连结果
	virtual void OnRecvReconnectResult(ReconnectResult result) {}
};

/************************************************************************/
/*                              用户信息管理接口								*/
/************************************************************************/
////用户状态
//enum IMUserStatus
//{
//    USER_STATUS_ONLINE,	  //在线，默认值（已登录）
//    USER_STATUS_OFFLINE,  //离线
//    USER_STATUS_INVISIBLE //隐身
//};

//用户性别
enum IMUserSex
{
    SEX_UNKNOWN, //未知性别
    SEX_MALE,    //男性
    SEX_FEMALE   //女性
};

enum IMUserBeAddPermission
{
    NOT_ALLOW_ADD,     //不允许被添加
    NEED_VALIDATE,     //需要验证
    NO_ADD_PERMISSION  //允许被添加，不需要验证, 默认值
};

enum IMUserFoundPermission
{
    CAN_BE_FOUND,        //能被其它用户查找到，默认值
    CAN_NOT_BE_FOUND     //不能被其它用户查找到
};

// 用户基本信息
struct IMUserSettingInfo
{
    XString nickName;                //昵称
    IMUserSex sex;                   //性别
    XString personalSignature;       //个性签名
    XString country;                 //国家
    XString province;                //省份
    XString city;                    //城市
    XString extraInfo;               //扩展信息，json格式
    
    IMUserSettingInfo():sex(SEX_UNKNOWN){}
};

struct IMUserProfileInfo
{
    XString userID;                      //用户ID
    XString photoURL;                    //头像url
    YIMUserStatus onlineState;            //在线状态
    IMUserBeAddPermission beAddPermission;    //被好友添加权限
    IMUserFoundPermission foundPermission; //能否被查找权限
    
    IMUserSettingInfo settingInfo;       // 用户基本信息
    
	IMUserProfileInfo() :onlineState(STATUS_ONLINE), beAddPermission(NO_ADD_PERMISSION), foundPermission(CAN_BE_FOUND){}
};

class YIMUserProfileManager
{
public:
    virtual ~YIMUserProfileManager();
    
    /*
     * 功能：设置用户基本资料
     * @param userSettingInfo：用户基本信息
     * @return 错误码
     */
    virtual YIMErrorcode SetUserProfileInfo(const IMUserSettingInfo &userSettingInfo) = 0;
    
    /*
     * 功能：设置用户头像
     * @param photoPath：本地图片绝对路径
     * @return 错误码
     */
    virtual YIMErrorcode SetUserProfilePhoto(const XCHAR* photoPath) = 0;
    
    /*
     * 功能：查询用户基本资料
     * @param userID：指定用户ID
     * @return 错误码
     */
    virtual YIMErrorcode GetUserProfileInfo(const XCHAR* userID = __XT("")) = 0;
    
    /*
     * 功能：切换用户状态
     * @param userID：用户ID
     * @param userStatus：用户状态，在线 | 隐身 | 离线
     * @return 错误码
     */
    virtual YIMErrorcode SwitchUserStatus(const XCHAR* userID, YIMUserStatus userStatus) = 0;
    
    /*
     * 功能：设置好友添加权限
     * @param beFound：是否被别人查找到，true-能被查找，false-不能被查找
     * @param beAddPermission：被其它用户添加的权限
     * @return 错误码
     */
    virtual YIMErrorcode SetAddPermission(bool beFound, IMUserBeAddPermission beAddPermission) = 0;
};

//用户信息管理回调
class IYIMUserProfileCallback
{
public:    
    /*
     * 功能：查询用户信息回调
     * @param errorcode：错误码
     * @param userInfo：用户信息
     */
    virtual void OnQueryUserInfo(YIMErrorcode errorcode, const IMUserProfileInfo &userInfo) {}
    
    /*
     * 功能：设置用户信息回调
     * @param errorcode：错误码
     */
    virtual void OnSetUserInfo(YIMErrorcode errorcode) {}
    
    /*
     * 功能：切换用户在线状态回调
     * @param errorcode：错误码
     */
    virtual void OnSwitchUserOnlineState(YIMErrorcode errorcode) {}
    
    /*
     * 功能：设置头像回调
     * @param photoUrl：图片下载路径
     * @param errorcode：错误码
     */
    virtual void OnSetPhotoUrl(YIMErrorcode errorcode, const XString &photoUrl) {}

	/*
	* 功能：用户信息变更通知
	* @param users：用户ID
	*/
	virtual void OnUserInfoChangeNotify(const XString& userID){}
};


/************************************************************************/
/*                              好友接口								*/
/************************************************************************/

// 用户简要信息
class IYIMUserBriefInfo
{
public:
	// 用户ID
	virtual const XCHAR* GetUserID() = 0;
	// 用户昵称
	virtual const XCHAR* GetNickname() = 0;
	// 用户状态
	virtual YIMUserStatus GetUserStatus() = 0;
};

// 添加好友请求状态
enum YIMAddFriendStatus
{
	STATUS_ADD_SUCCESS = 0,			// 添加完成
	STATUS_ADD_FAILED = 1,			// 添加失败
	STATUS_WAIT_OTHER_VALIDATE = 2,	// 等待对方验证
	STATUS_WAIT_ME_VALIDATE = 3		// 等待我验证
};

// 添加好友请求
class IYIMFriendRequestInfo
{
public:
	// 请求方ID
	virtual const XCHAR* GetAskerID() = 0;
	// 请求方昵称
	virtual const XCHAR* GetAskerNickname() = 0;
	// 受邀方
	virtual const XCHAR* GetInviteeID() = 0;
	// 受邀方昵称
	virtual const XCHAR* GetInviteeNickname() = 0;
	// 验证信息
	virtual const XCHAR* GetValidateInfo() = 0;
	// 状态
	virtual YIMAddFriendStatus GetStatus() = 0;
	// 时间
	virtual unsigned int GetCreateTime() = 0;
};


class YIMFriendManager
{
public:
	/*
	* 功能：查找添加好友（获取用户简要信息）
	* @param findType：查找类型	0：按ID查找	1：按昵称查找
	* @param targets：对应查找类型用户ID或昵称
	* @return 错误码
	*/
	virtual YIMErrorcode FindUser(int findType, const XCHAR* target) = 0;

	/*
	* 功能：添加好友
	* @param userID：用户ID
	* @param comments：备注或验证信息(长度最大128)
	* @return 错误码
	*/
	virtual YIMErrorcode RequestAddFriend(std::vector<XString>& users, const XCHAR* comments) = 0;

	/*
	* 功能：处理被请求添加好友
	* @param userID：用户ID
	* @param dealResult：处理结果	0：同意	1：拒绝
	* @return 错误码
	*/
	virtual YIMErrorcode DealBeRequestAddFriend(const XCHAR* userID, int dealResult) = 0;

	/*
	* 功能：删除好友
	* @param users：用户ID
	* @param deleteType：删除类型	0：双向删除	1：单向删除(删除方在被删除方好友列表依然存在)
	* @return 错误码
	*/
	virtual YIMErrorcode DeleteFriend(std::vector<XString>& users, int deleteType = 1) = 0;

	/*
	* 功能：拉黑好友
	* @param type：0：拉黑	1：解除拉黑
	* @param users：用户ID
	* @return 错误码
	*/
	virtual YIMErrorcode BlackFriend(int type, std::vector<XString>& users) = 0;

	/*
	* 功能：查询我的好友
	* @param type：0：正常好友	1：被拉黑好友
	* @param startIndex：起始序号
	* @param count：数量（一次最大100）
	* @return 错误码
	*/
	virtual YIMErrorcode QueryFriends(int type = 0, int startIndex = 0, int count = 50) = 0;

	/*
	* 功能：查询好友请求列表
	* @param startIndex：起始序号
	* @param count：数量（一次最大20）
	* @return 错误码
	*/
	virtual YIMErrorcode QueryFriendRequestList(int startIndex = 0, int count = 20) = 0;
};

class IYIMFriendCallback
{
public:
	/*
	* 功能：查找用户回调
	* @param errorcode：错误码
	* @param users：用户简要信息
	*/
	virtual void OnFindUser(YIMErrorcode errorcode, std::list<std::shared_ptr<IYIMUserBriefInfo> >& users){}

	/*
	* 功能：请求添加好友回调
	* @param errorcode：错误码
	* @param userID：用户ID
	*/
	virtual void OnRequestAddFriend(YIMErrorcode errorcode, const XString& userID){}

	/*
	* 功能：被邀请添加好友通知（需要验证）
	* @param userID：用户ID
	* @param comments：备注或验证信息
	* commonts：显示用户信息可以根据userID查询
	*/
	virtual void OnBeRequestAddFriendNotify(const XString& userID, const XString& comments){}

	/*
	* 功能：被添加为好友通知（不需要验证）
	* @param userID：用户ID
	* @param comments：备注或验证信息
	*/
	virtual void OnBeAddFriendNotify(const XString& userID, const XString& comments){}
	
	/*
	* 功能：处理被请求添加好友回调
	* @param errorcode：错误码
	* @param userID：用户ID
	* @param comments：备注或验证信息
	* @param dealResult：处理结果	0：同意	1：拒绝
	*/
	virtual void OnDealBeRequestAddFriend(YIMErrorcode errorcode, const XString& userID, const XString& comments, int dealResult){}

	/*
	* 功能：请求添加好友结果通知(需要好友验证，待被请求方处理后回调)
	* @param userID：用户ID
	* @param comments：备注或验证信息
	* @param dealResult：处理结果	0：同意	1：拒绝
	*/
	virtual void OnRequestAddFriendResultNotify(const XString& userID, const XString& comments, int dealResult){}

	/*
	* 功能：删除好友结果回调
	* @param errorcode：错误码
	* @param userID：用户ID
	*/
	virtual void OnDeleteFriend(YIMErrorcode errorcode, const XString& userID){}

	/*
	* 功能：被好友删除通知
	* @param userID：用户ID
	*/
	virtual void OnBeDeleteFriendNotify(const XString& userID){}

	/*
	* 功能：拉黑或解除拉黑好友回调
	* @param errorcode：错误码
	* @param type：0：拉黑	1：解除拉黑
	* @param userID：用户ID
	*/
	virtual void OnBlackFriend(YIMErrorcode errorcode, int type, const XString& userID){}

	/*
	* 功能：查询我的好友回调
	* @param errorcode：错误码
	* @param type：0：正常好友	1：被拉黑好友
	* @param startIndex：起始序号
	* @param hasMore：是否还有更多数据
	* @param friends：好友列表
	*/
	virtual void OnQueryFriends(YIMErrorcode errorcode, int type, int startIndex, std::list<std::shared_ptr<IYIMUserBriefInfo> >& friends){}

	/*
	* 功能：查询好友请求列表回调
	* @param errorcode：错误码
	* @param startIndex：起始序号
	* @param hasMore：是否还有更多数据
	* @param validateList：验证消息列表
	*/
	virtual void OnQueryFriendRequestList(YIMErrorcode errorcode, int startIndex, std::list<std::shared_ptr<IYIMFriendRequestInfo> >& requestList){}
};


class YOUMEDLL_API YIMManager
{
public:
	virtual ~YIMManager();

	/******************下面函数可在启动引擎和初始化之前调用******************/
	
	/*
	* 功能：获取SDK版本号
	* @return 版本号
	*/
	static int GetSDKVersion();

	/*
	* 功能：设置服务器区域
	* @param zone：服务器区域编码
	*/
	static void SetServerZone(ServerZone zone);

    static void SetMode(int mode);
	
	/*
	* 功能：设置语音缓存目录
	* @param audioCacheDir：语音缓存目录
	*/
	static void SetAudioCacheDir(const XCHAR* audioCacheDir);
	/************************************************************************/
    
	//创建实例
	static YIMManager* CreateInstance();
	
	/*
	* 功能：初始化
	* @param appKey：appkey
	* @param appSecurity：secret
	* @param packageName：包名
	* @return 错误码
	*/
	virtual YIMErrorcode Init(const XCHAR* appKey, const XCHAR* appSecurity, const XCHAR* packageName) = 0;
    
	//设置登陆和登出回调
	virtual void SetLoginCallback(IYIMLoginCallback* pCallback) = 0;
    //设置消息回调
    virtual void SetMessageCallback(IYIMMessageCallback* pCallback) = 0;
    //设置群组回调
    virtual void SetChatRoomCallback(IYIMChatRoomCallback* pCallback) = 0;
	//设置下载回调
	virtual void SetDownloadCallback(IYIMDownloadCallback* pCallback) =0;
	//设置联系人回调
	virtual void SetContactCallback(IYIMContactCallback* pCallback) = 0;
	//设置语音播放回调
	virtual void SetAudioPlayCallback(IYIMAudioPlayCallback* pCallback) = 0;
	// 设置地理位置回调
	virtual void SetLocationCallback(IYIMLocationCallback* pCallback) = 0;
	// 设置通知回调
	virtual void SetNoticeCallback(IYIMNoticeCallback* pCallback) = 0;
	// 设置重连回调
	virtual void SetReconnectCallback(IYIMReconnectCallback* pCallback) = 0;
	// 设置好友回调
	virtual void SetFriendCallback(IYIMFriendCallback* pCallback) = 0;
    
	//获取聊天室管理器
	virtual YIMChatRoomManager* GetChatRoomManager() = 0;
	//获取消息管理器
	virtual YIMMessageManager* GetMessageManager() = 0;
	//获取地理位置
	virtual YIMLocationManager* GetLocationManager() = 0;
        
    //设置用户信息回调
    virtual void SetUserProfileCallback(IYIMUserProfileCallback* pCallback) = 0;
    //获取用户信息管理器
    virtual YIMUserProfileManager* GetUserProfileManager() = 0;
    
	//获取好友关系管理
	virtual YIMFriendManager* GetFriendManager() = 0;
	/*
	* 功能：登录
	* @param userID：用户ID
	* @param password：密码
	* @param token：登录token（可以为空字符串，若需要token登录，需要服务端获取）
	* @return 错误码
	*/
	virtual YIMErrorcode Login(const XCHAR* userID, const XCHAR* password, const XCHAR* token) = 0;
	
	/*
	* 功能：登出
	* @return 错误码
	*/
	virtual YIMErrorcode Logout() = 0;

	/*
	* 功能：获取最近联系人信息（最大100条）
	* @return 错误码
	*/
	virtual YIMErrorcode GetRecentContacts() = 0;

	/*
	* 功能：设置用户信息
	* @param userInfo：用户信息 JSON格式：{"nickname":"","server_area_id":"","server_area":"","location_id":"","location":"","level":"","vip_level":"","platform_id":"","platform":""} (前七个必填，可以添加其他字段)
	* @return 错误码
	*/
	virtual YIMErrorcode SetUserInfo(const XCHAR* userInfo) = 0;
	
	/*
	* 功能：查询用户信息
	* @param userID：用户ID
	* @return 错误码
	*/
	virtual YIMErrorcode GetUserInfo(const XCHAR* userID) = 0;

	/*
	* 功能：查询用户在线状态
	* @param userID：用户ID
	* @return 错误码
	*/
	virtual YIMErrorcode QueryUserStatus(const XCHAR* userID) = 0;
	
	/*
	* 功能：消息关键词过滤
	* @param text：消息内容
	* @param level：过滤等级
	* @return 错误码
	*/
	static XString FilterKeyword(const XCHAR* text, int* level);

	/*
	* 功能：程序切到后台运行
	* @param pauseReceiveMessage：是否暂停接收消息 true-暂停接收 false-不暂停接收
	*/
	virtual void OnPause(bool pauseReceiveMessage) = 0;

	/*
	* 功能：程序切恢复前台运行
	*/
	virtual void OnResume() = 0;

	/*
	* 功能：设置语音播放音量
	* @param volume：取值范围0.0到1.0
	*/
	void SetVolume(float volume);

	/*
	* 功能：播放语音
	* @param path：语音文件路径
	* @return 错误码
	*/
	YIMErrorcode StartPlayAudio(const XCHAR* path);

	/*
	* 功能：停止语音播放
	* @return 错误码
	*/
	YIMErrorcode StopPlayAudio();
	
	/*
	* 功能：获取播放状态
	* @return 是否正在播放语音
	*/
	bool IsPlaying();

	/*
	* 功能：语音结束后是否保持原Category(IOS)
	* @param keep：是否保持
	*/
	void SetKeepRecordModel(bool keep);

	/*
	* 功能：获取麦克风状态
	*/
	void GetMicrophoneStatus();

	/*
	* 功能：获取语音缓存目录
	* @return 语音缓存目录
	*/
	XString GetAudioCachePath();

	/*
	* 功能：清理语音缓存目录（注意清空语音缓存目录后历史记录中会无法读取到音频文件，调用清理历史记录接口也会自动删除对应的音频缓存文件）
	* @return 清理结果
	*/
	bool ClearAudioCachePath();

	/*
	* 功能：查询公告
	*/
	virtual YIMErrorcode QueryNotice() = 0;
};
