// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from main.djinni

#pragma once

#include "ReactBridge.hpp"
#include <cstdint>
#include <memory>
#include <string>

class RNYIMCommon {
public:
    virtual ~RNYIMCommon() {}

    /**----------------------------listen module---------------------------- */
    static std::string const EVENT_LOGIN;

    /** 登录登出 */
    static std::string const EVENT_CHANNEL;

    /** 频道 */
    static std::string const EVENT_USERINFO;

    /** 用户信息 */
    static std::string const EVENT_FRIEND;

    /** 好友 */
    static std::string const EVENT_MESSAGE;

    /** 消息管理 */
    static std::string const EVENT_PLAY;

    /** 语音播放 */
    static std::string const EVENT_HISTORYMESSAGE;
    static std::string const EVENT_HISTORYMESSAGE_SERVER;

    /** 历史消息 */
    static std::string const EVENT_LOCATION;

    /** 地理位置 */
    static std::string const EVENT_NOYYLOGIN;

    /** noyy登录 */
    static std::string const EVENT_NOYYCHANNEL;

    /** noyy频道 */
    static std::string const EVENT_VOICE;

    /**
     * talk实时语音
     *----------------------------command----------------------------
     * 登录登出
     */
    static int32_t const CMD_LOGIN;

    /** 登录 */
    static int32_t const CMD_LOGOUT;

    /** 登出   */
    static int32_t const CMD_KICKOFF;

    /**
     * 被踢
     * 频道
     */
    static int32_t const CMD_JOIN_ROOM;

    /** 进入房间 */
    static int32_t const CMD_LEAVE_ROOM;

    /**
     * 离开房间
     * 消息管理
     */
    static int32_t const CMD_SEND_MESSAGE_STATUS;

    /** 发送消息	 */
    static int32_t const CMD_STOP_AUDIO_MESSAGE;

    /** 停止语音（发送端可在该回调触发时消息上屏）  */
    static int32_t const CMD_SEND_AUDIO_MESSAGE_STATUS;

    /** 发送语音消息 */
    static int32_t const CMD_CANCEL_AUDIO_MESSAGE;

    /** 取消语音 */
    static int32_t const CMD_RECV_MAEESAG_NOTIFY;

    /** 接收消息通知 */
    static int32_t const CMD_DOWNLOAD_FILE;

    /** 下载文件（根据消息ID下载） */
    static int32_t const CMD_DOWNLOAD_FILEY_BY_URL;

    /** 下载文件（更加URL下载） */
    static int32_t const CMD_RECORD_VOLUME_CHANGE;

    /** 录音音量变化 */
    static int32_t const CMD_TEXT_TANSLATE;

    /** 文本翻译 */
    static int32_t const CMD_RECENT_CONTACTS;

    /**
     * 获取最近联系人
     * 语音播放
     */
    static int32_t const CMD_PLAY_COMPLETE_NOTIFY;

    /** 播放完成 */
    static int32_t const CMD_GET_MICROPHONE_STATUS;

    /**
     * 获取麦克状态
     * 用户信息
     */
    static int32_t const CMD_QUERY_USER_INFO;

    /** 查询用户信息 */
    static int32_t const CMD_SET_USER_INFO;

    /** 设置用户信息 */
    static int32_t const CMD_SWITCH_USER_STATUS;

    /** 切换用户在线状态 */
    static int32_t const CMD_SET_HEAD_IMAGE;

    /** 设置头像 */
    static int32_t const CMD_UNSER_INFO_CHANGE_NOTIFY;

    /** 用户信息变更通知 */
    static int32_t const CMD_SET_USER_EXTEND_STATUS;

    /**
     * 设置用户扩展状态
     * 好友
     */
    static int32_t const CMD_REQUEST_ADD_FRIEND;

    /** 请求添加好友 */
    static int32_t const CMD_BE_REQUEST_ADD_FRIEND;

    /** 被邀请添加好友通知（需要验证） */
    static int32_t const CMD_BE_ADD_FRIEND;

    /** 被添加为好友通知（不需要验证） */
    static int32_t const CMD_DEAL_BE_REQUEST_ADD_FRIEND;

    /** 处理被请求添加好友 */
    static int32_t const CMD_REQUEST_ADD_FRIEND_RESULT_NOTIFY;

    /** 请求添加好友结果通知 */
    static int32_t const CMD_DELETE_FRIEND;

    /** 删除好友 */
    static int32_t const CMD_BE_DELETE_FRIEND_NOTIFY;

    /** 被好友删除通知 */
    static int32_t const CMD_BLACK_FRIEND;

    /** 拉黑或解除拉黑好友 */
    static int32_t const CMD_QUERY_FRIENDS;

    /** 查询我的好友 */
    static int32_t const CMD_QUERY_FRIEND_REQUEST_LIST;

    /** 查询好友请求列表 */
    static int32_t const CMD_GET_RECOMMAND_USER;

    /**
     * 获取好友推荐  
     * 历史消息
     */
    static int32_t const CMD_QUERY_LOCAL_HISTORY_MSG;

    /** 查询本地历史消息 */
    static int32_t const CMD_QUERY_ROOM_HISTORY_MSG_SERVER;

    /**
     * 查询服务端房间历史消息
     * 地理位置
     */
    static int32_t const CMD_LOCATION_UPDATE;

    /** 自己位置更新 */
    static int32_t const CMD_LOCATION_GET_NEARBY_OBJECT;

    /** 获取附近的人 */
    static int32_t const CMD_LOCATION_GET_DISTANCE;

    /**
     * 获取与指定用户距离
     * noyy登录
     */
    static int32_t const CMD_REGISTE;

    /** 注册 */
    static int32_t const CMD_HXRLOGIN;

    /** 登录 */
    static int32_t const CMD_RESET_PASSWORD;

    /** 重置密码 */
    static int32_t const CMD_UPDATE_PASSWORD;

    /** 修改密码 */
    static int32_t const CMD_MOBILEPHONE_IDENTIFYING_CODE;

    /**
     * 获取手机验证码
     * noyy频道
     */
    static int32_t const CMD_CREATE_CHANNEL;

    /** 创建频道 */
    static int32_t const CMD_INVITE_JOIN_CHANNEL;

    /** 邀请用户加入频道 */
    static int32_t const CMD_ASKFOR_JOIN_CHANNEL;

    /** 请求加入频道 */
    static int32_t const CMD_LEAVE_CHANNEL;

    /** 离开频道 */
    static int32_t const CMD_MATCH_CHANNEL;

    /** 匹配频道 */
    static int32_t const CMD_MATCH_CHANNEL_RESULT_NOTIFY;

    /** 匹配频道结果通知 */
    static int32_t const CMD_GET_JOINED_CHANNEL;

    /** 获取当前已加入频道 */
    static int32_t const CMD_GET_CHANNEL_MEMBER;

    /** 获取频道成员 */
    static int32_t const CMD_CHANNEL_MEMBER_CHANGE_NOTIFY;

    /** 频道成员变化通知 */
    static int32_t const CMD_BE_INVITE_JOIN_CHANNEL;

    /** 被邀请加入频道通知 */
    static int32_t const CMD_SET_CHANNEL_MATCH_SWITCH;

    /** 设置频道是否开启匹配 */
    static int32_t const CMD_KICK_CHANNEL_MEMBER;

    /** 频道踢人 */
    static int32_t const CMD_BE_KICK_NOTIFY;

    /** 被踢出频道通知 */
    static int32_t const CMD_DEVOLVE_CHANNEL_OWNER;

    /** 转移频道主 */
    static int32_t const CMD_BECOM_CHANNEL_OWNER_NOTIFY;

    /** 成为频道主通知 */
    static int32_t const CMD_FOLLOW_JOIN_CHANNEL;

    /** 跟随进入频道 */
    static int32_t const CMD_FOLLOW_JOIN_CHANNEL_REQUEST_NOTIFY;

    /** 请求跟随进入频道通知 */
    static int32_t const CMD_VERIFY_FOLLOW_JOIN_CHANNEL;

    /** 验证跟随进入频道 */
    static int32_t const CMD_FOLLOW_JOIN_CHANNEL_RESULT_NOTIFY;

    /**
     * 跟随进入频道结果通知
     * talk实时语音
     */
    static int32_t const CMD_INIT;

    /** 初始化 */
    static int32_t const CMD_JOIN_CHANNEL;

    /** 加入频道 */
    static int32_t const CMD_LEAVE_ALL_CHANNEL;

    /** 离开所有语音频道 */
    static int32_t const CMD_SELF_SPEAKER_CHANGE;

    /** 扬声器状态变化 */
    static int32_t const CMD_SELF_MICROPHONE_CHANGE;

    /** 麦克风状态变化 */
    static int32_t const CMD_OTHER_SPEAKER_CHANGE;

    /** 其他成员扬声器状态变化 */
    static int32_t const CMD_OTHER_MICROPHONE_CHANGE;

    /** 其他成员麦克风状态变化 */
    static int32_t const CMD_SPEAKER_BE_CHANGE;

    /** 扬声器状态被改变 */
    static int32_t const CMD_MICROPHONE_BE_CHANGE;

    /** vad状态被改变 */
    static int32_t const CMD_OTHER_SPEECH_CHANGE;

    /** 自己的MIC音量 */
    static int32_t const CMD_MY_MIC_LEVEL;
    /** RestAPI变化 */
    static int32_t const CMD_REST_API;

    /**
     * 其他用户讲话状态变化
     *----------------------------command end----------------------------
     * 环境
     */
    static int32_t const MODEL_FORMAL;

    /** 线上环境 */
    static int32_t const MODEL_TEST;

    /**
     * 测试环境
     * 消息来源类型
     */
    static int32_t const CHATTYPE_PRIVATE;

    /** 私聊 */
    static int32_t const CHATTYPE_CHANNEL;

    /**
     * 频道消息
     * 消息类型
     */
    static int32_t const MESSAGETYPE_TEXT;

    /** 文本消息 */
    static int32_t const MESSAGETYPE_CUSTOM;

    /** 自定义消息 */
    static int32_t const MESSAGETYPE_VOICE;

    /** 语音消息 */
    static int32_t const MESSAGETYPE_FILE;

    /**
     * 文件消息
     * 文件类型
     */
    static int32_t const FILETYPE_OTHER;

    /** 其他 */
    static int32_t const FILETYPE_AUDIO;

    /** 音频 */
    static int32_t const FILETYPE_IMAGE;

    /** 图片 */
    static int32_t const FILETYPE_VIDEO;

    /**
     * 视频  
     * 语音识别语言
     */
    static int32_t const SPEECHLANG_MANDARIN;

    /** 普通话 */
    static int32_t const SPEECHLANG_YUEYU;

    /** 粤语 */
    static int32_t const SPEECHLANG_SICHUAN;

    /** 四川话 */
    static int32_t const SPEECHLANG_HENAN;

    /** 河南话 */
    static int32_t const SPEECHLANG_ENGLISH;

    /** 英语 */
    static int32_t const SPEECHLANG_TRADITIONAL;

    /**
     * 繁体中文
     * 行政区划等级
     */
    static int32_t const DISTRICTLEVEL_UNKNOW;

    static int32_t const DISTRICTLEVEL_COUNTRY;

    /** 国家 */
    static int32_t const DISTRICTLEVEL_PROVINCE;

    /** 省份 */
    static int32_t const DISTRICTLEVEL_CITY;

    /** 市 */
    static int32_t const DISTRICTLEVEL_COUNTY;

    /** 区县 */
    static int32_t const DISTRICTLEVEL_STREET;

    /**
     * 街道
     * 性别
     */
    static int32_t const SEX_UNKNOWN;

    static int32_t const SEX_MALE;

    static int32_t const SEX_FEMALE;

    /** 用户在线状态 */
    static int32_t const STATUS_ONLINE;

    /** 在线 */
    static int32_t const STATUS_OFFLINE;

    /** 离线 */
    static int32_t const STATUS_INVISIBLE;

    /**
     * 隐身
     * 好友添加权限
     */
    static int32_t const NOT_ALLOW_ADD;

    /** 不允许被添加 */
    static int32_t const NEED_VALIDATE;

    /** 需要验证 */
    static int32_t const NO_ADD_PERMISSION;

    /**
     * 允许被添加，不需要验证, 默认值
     *----------------------------errorcode----------------------------
     */
    static int32_t const YIMERRORCODE_SUCCESS;

    /** 成功 */
    static int32_t const YIMERRORCODE_ENGINENOTINIT;

    /** 未初始化 */
    static int32_t const YIMERRORCODE_NOTLOGIN;

    /** 未登录 */
    static int32_t const YIMERRORCODE_PARAMINVALID;

    /** 参数错误 */
    static int32_t const YIMERRORCODE_TIMEOUT;

    /** 超时 */
    static int32_t const YIMERRORCODE_STATUSERROR;

    /** 状态错误 */
    static int32_t const YIMERRORCODE_SDKINVALID;

    /** SDK验证识别 */
    static int32_t const YIMERRORCODE_ALREADYLOGIN;

    /** 已经登录 */
    static int32_t const YIMERRORCODE_SERVERERROR;

    /** 服务器错误 */
    static int32_t const YIMERRORCODE_NETERROR;

    /** 网络错误 */
    static int32_t const YIMERRORCODE_LOGINSESSIONERROR;

    /** session错误 */
    static int32_t const YIMERRORCODE_NOTSTARTUP;

    /** 未启动 */
    static int32_t const YIMERRORCODE_FILENOTEXIST;

    /** 文件不存在 */
    static int32_t const YIMERRORCODE_SENDFILEERROR;

    /** 发送文件失败 */
    static int32_t const YIMERRORCODE_UPLOADFAILED;

    /** 上传失败 */
    static int32_t const YIMERRORCODE_USERNAMEPASSWORDERROR;

    /** 用户名密码错误	 */
    static int32_t const YIMERRORCODE_USERSTATUSERROR;

    /** 用户状态错误(无效用户) */
    static int32_t const YIMERRORCODE_MESSAGETOOLONG;

    /** 消息太长 */
    static int32_t const YIMERRORCODE_RECEIVERTOOLONG;

    /** 接收方ID过长(检查房间名) */
    static int32_t const YIMERRORCODE_INVALIDCHATTYPE;

    /** 无效聊天类型(私聊、聊天室) */
    static int32_t const YIMERRORCODE_INVALIDRECEIVER;

    /** 无效用户ID */
    static int32_t const YIMERRORCODE_UNKNOWERROR;

    static int32_t const YIMERRORCODE_INVALIDAPPKEY;

    /** 无效APPKEY */
    static int32_t const YIMERRORCODE_FORBIDDENSPEAK;

    /** 被禁言 */
    static int32_t const YIMERRORCODE_CREATEFILEFAILED;

    /** 创建文件失败 */
    static int32_t const YIMERRORCODE_UNSUPPORTFORMAT;

    /** 不支持的文件格式 */
    static int32_t const YIMERRORCODE_RECEIVEREMPTY;

    /** 接收方为空 */
    static int32_t const YIMERRORCODE_ROOMIDTOOLONG;

    /** 房间名太长 */
    static int32_t const YIMERRORCODE_CONTENTINVALID;

    /** 聊天内容严重非法 */
    static int32_t const YIMERRORCODE_NOLOCATIONAUTHRIZE;

    /** 未打开定位权限 */
    static int32_t const YIMERRORCODE_UNKNOWLOCATION;

    /** 未知位置 */
    static int32_t const YIMERRORCODE_UNSUPPORT;

    /** 不支持该接口 */
    static int32_t const YIMERRORCODE_NOAUDIODEVICE;

    /** 无音频设备 */
    static int32_t const YIMERRORCODE_AUDIODRIVER;

    /** 音频驱动问题 */
    static int32_t const YIMERRORCODE_DEVICESTATUSINVALID;

    /** 设备状态错误 */
    static int32_t const YIMERRORCODE_RESOLVEFILEERROR;

    /** 文件解析错误 */
    static int32_t const YIMERRORCODE_READWRITEFILEERROR;

    /** 文件读写错误 */
    static int32_t const YIMERRORCODE_NOLANGCODE;

    /** 语言编码错误 */
    static int32_t const YIMERRORCODE_TRANSLATEUNABLE;

    /** 翻译接口不可用 */
    static int32_t const YIMERRORCODE_SPEECHACCENTINVALID;

    /** 语音识别方言无效 */
    static int32_t const YIMERRORCODE_SPEECHLANGUAGEINVALID;

    /** 语音识别语言无效 */
    static int32_t const YIMERRORCODE_HASILLEGALTEXT;

    /** 消息含非法字符 */
    static int32_t const YIMERRORCODE_ADVERTISEMENTMESSAGE;

    /** 消息涉嫌广告 */
    static int32_t const YIMERRORCODE_ALREADYBLOCK;

    /** 用户已经被屏蔽 */
    static int32_t const YIMERRORCODE_NOTBLOCK;

    /** 用户未被屏蔽 */
    static int32_t const YIMERRORCODE_MESSAGEBLOCKED;

    /** 消息被屏蔽 */
    static int32_t const YIMERRORCODE_LOCATIONTIMEOUT;

    /** 定位超时 */
    static int32_t const YIMERRORCODE_NOTJOINROOM;

    /** 未加入该房间 */
    static int32_t const YIMERRORCODE_LOGINTOKENINVALID;

    /** 登录token错误 */
    static int32_t const YIMERRORCODE_CREATEDIRECTORYFAILED;

    /** 创建目录失败 */
    static int32_t const YIMERRORCODE_INITFAILED;

    /** 初始化失败 */
    static int32_t const YIMERRORCODE_DISCONNECT;

    /** 与服务器断开 */
    static int32_t const YIMERRORCODE_THESAMEPARAM;

    /** 设置参数相同 */
    static int32_t const YIMERRORCODE_QUERYUSERINFOFAIL;

    /** 查询用户信息失败 */
    static int32_t const YIMERRORCODE_SETUSERINFOFAIL;

    /** 设置用户信息失败 */
    static int32_t const YIMERRORCODE_UPDATEUSERONLINESTATEFAIL;

    /** 更新用户在线状态失败 */
    static int32_t const YIMERRORCODE_NICKNAMETOOLONG;

    /** 昵称太长(> 64 bytes) */
    static int32_t const YIMERRORCODE_SIGNATURETOOLONG;

    /** 个性签名太长(> 120 bytes) */
    static int32_t const YIMERRORCODE_NEEDFRIENDVERIFY;

    /** 需要好友验证信息 */
    static int32_t const YIMERRORCODE_BEREFUSE;

    /** 添加好友被拒绝 */
    static int32_t const YIMERRORCODE_HASNOTREGISTERUSERINFO;

    /** 未注册用户信息 */
    static int32_t const YIMERRORCODE_ALREADYFRIEND;

    /** 已经是好友 */
    static int32_t const YIMERRORCODE_NOTFRIEND;

    /** 非好友 */
    static int32_t const YIMERRORCODE_NOTBLACK;

    /** 不在黑名单中 */
    static int32_t const YIMERRORCODE_PHOTOURLTOOLONG;

    /** 头像url过长(>500 bytes) */
    static int32_t const YIMERRORCODE_PHOTOSIZETOOLARGE;

    /**
     * 头像太大（>100 kb）
     * 服务错误码
     */
    static int32_t const YIMERRORCODE_ALREADYFRIENDS;

    static int32_t const YIMERRORCODE_LOGININVALID;

    /** 语音部分错误码 */
    static int32_t const YIMERRORCODE_PTT_START;

    static int32_t const YIMERRORCODE_PTT_FAIL;

    static int32_t const YIMERRORCODE_PTT_DOWNLOADFAIL;

    /** 下载语音失败 */
    static int32_t const YIMERRORCODE_PTT_GETUPLOADTOKENFAIL;

    /** 获取token失败 */
    static int32_t const YIMERRORCODE_PTT_UPLOADFAIL;

    /** 上传失败 */
    static int32_t const YIMERRORCODE_PTT_NOTSPEECH;

    /** 未检测到语音或未开始语音 */
    static int32_t const YIMERRORCODE_PTT_DEVICESTATUSERROR;

    /** 音频设备状态错误 */
    static int32_t const YIMERRORCODE_PTT_ISSPEECHING;

    /** 正在录音 */
    static int32_t const YIMERRORCODE_PTT_FILENOTEXIST;

    /** 文件不存在 */
    static int32_t const YIMERRORCODE_PTT_REACHMAXDURATION;

    /** 达到语音最大时长限制 */
    static int32_t const YIMERRORCODE_PTT_SPEECHTOOSHORT;

    /** 语音时长太短 */
    static int32_t const YIMERRORCODE_PTT_STARTAUDIORECORDFAILED;

    /** 启动录音失败 */
    static int32_t const YIMERRORCODE_PTT_SPEECHTIMEOUT;

    /** 音频输入超时 */
    static int32_t const YIMERRORCODE_PTT_ISPLAYING;

    /** 正在播放 */
    static int32_t const YIMERRORCODE_PTT_NOTSTARTPLAY;

    /** 未开始播放 */
    static int32_t const YIMERRORCODE_PTT_CANCELPLAY;

    /** 主动取消播放 */
    static int32_t const YIMERRORCODE_PTT_NOTSTARTRECORD;

    /** 未开始语音 */
    static int32_t const YIMERRORCODE_PTT_NOTINIT;

    /**  未初始化 */
    static int32_t const YIMERRORCODE_PTT_INITFAILED;

    /**  初始化失败 */
    static int32_t const YIMERRORCODE_PTT_AUTHORIZE;

    /**  录音权限 */
    static int32_t const YIMERRORCODE_PTT_STARTRECORDFAILED;

    /**  启动录音失败 */
    static int32_t const YIMERRORCODE_PTT_STOPRECORDFAILED;

    /**  停止录音失败 */
    static int32_t const YIMERRORCODE_PTT_UNSUPPRTFORMAT;

    /**  不支持的格式 */
    static int32_t const YIMERRORCODE_PTT_RESOLVEFILEERROR;

    /**  解析文件错误 */
    static int32_t const YIMERRORCODE_PTT_READWRITEFILEERROR;

    /**  读写文件错误 */
    static int32_t const YIMERRORCODE_PTT_CONVERTFILEFAILED;

    /**  文件转换失败 */
    static int32_t const YIMERRORCODE_PTT_NOAUDIODEVICE;

    /**  无音频设备 */
    static int32_t const YIMERRORCODE_PTT_NODRIVER;

    /**  驱动问题 */
    static int32_t const YIMERRORCODE_PTT_STARTPLAYFAILED;

    /**  启动播放失败 */
    static int32_t const YIMERRORCODE_PTT_STOPPLAYFAILED;

    /**
     *  停止播放失败
     * -------------------------- NOYY --------------------------
     */
    static int32_t const YIMERRORCODE_IDENTITYCODEERROR;

    /**  验证码错误 */
    static int32_t const YIMERRORCODE_USEREXIST;

    /**  用户已存在 */
    static int32_t const YIMERRORCODE_USERNOTEXIST;

    /**  用户不存在 */
    static int32_t const YIMERRORCODE_PASSWORDERROR;

    /**  密码错误 */
    static int32_t const YIMERRORCODE_NEWOLDPASSSAME;

    /**  新旧密码相同 */
    static int32_t const YIMERRORCODE_NOTJOINCHANNEL;

    /**  未加入频道 */
    static int32_t const YIMERRORCODE_ALREADYJOINCHANNEL;

    /**  已加入频道 */
    static int32_t const YIMERRORCODE_CHANNELMEMBERFULL;

    /**  频道成员已满 */
    static int32_t const YIMERRORCODE_MATCHTIMEOUT;

    /**  匹配超时 */
    static int32_t const YIMERRORCODE_CHANNELDISABLED;

    /**  频道不可用 */
    static int32_t const YIMERRORCODE_NOTCHANNELOWNER;

    /**
     *  频道不可用
     * -------------------------- NOYY --------------------------
     */
    static int32_t const YIMERRORCODE_FAIL;

    /** -------------------------- TALK -------------------------- */
    static int32_t const YOUME_USER_NONE;

    /** 非法用户 */
    static int32_t const YOUME_USER_TALKER_FREE;

    /** 自由讲话者 */
    static int32_t const YOUME_USER_TALKER_ON_DEMAND;

    /** 抢麦 */
    static int32_t const YOUME_USER_LISTENER;

    /** 听众 */
    static int32_t const YOUME_USER_COMMANDER;

    /** 指挥 */
    static int32_t const YOUME_USER_HOST;

    /** 主播 */
    static int32_t const YOUME_USER_GUSET;

    /**
     * 嘉宾
     * ---------------- errorcode ----------------
     */
    static int32_t const YOUME_SUCCESS;

    /**
     *成功
     * 参数和状态检查
     */
    static int32_t const YOUME_ERROR_API_NOT_SUPPORTED;

    /**正在使用的SDK不支持特定的API */
    static int32_t const YOUME_ERROR_INVALID_PARAM;

    /**传入参数错误 */
    static int32_t const YOUME_ERROR_ALREADY_INIT;

    /**已经初始化 */
    static int32_t const YOUME_ERROR_NOT_INIT;

    /**还没有初始化，在调用某函数之前要先调用初始化并且要根据返回值确保初始化成功 */
    static int32_t const YOUME_ERROR_CHANNEL_EXIST;

    /**要加入的频道已经存在 */
    static int32_t const YOUME_ERROR_CHANNEL_NOT_EXIST;

    /**对频道进入（检查参数为true时）、退出、讲话、设置白名单、抢麦等接口时频道不存在 */
    static int32_t const YOUME_ERROR_WRONG_STATE;

    /**状态错误 */
    static int32_t const YOUME_ERROR_NOT_ALLOWED_MOBILE_NETWROK;

    /**不允许使用移动网络 */
    static int32_t const YOUME_ERROR_WRONG_CHANNEL_MODE;

    /**在单频道模式下调用了多频道接口，或者反之 */
    static int32_t const YOUME_ERROR_TOO_MANY_CHANNELS;

    /**同时加入了太多频道 */
    static int32_t const YOUME_ERROR_TOKEN_ERROR;

    /**传入的token认证错误 */
    static int32_t const YOUME_ERROR_NOT_IN_CHANNEL;

    /**用户不在该频道 */
    static int32_t const YOUME_ERROR_BE_KICK;

    /**
     *被踢了，还在禁止时间内，不允许进入房间
     * 内部操作错误
     */
    static int32_t const YOUME_ERROR_MEMORY_OUT;

    /**内存错误 */
    static int32_t const YOUME_ERROR_START_FAILED;

    /**启动引擎失败 */
    static int32_t const YOUME_ERROR_STOP_FAILED;

    /** 停止引擎失败 */
    static int32_t const YOUME_ERROR_ILLEGAL_SDK;

    /**非法使用SDK */
    static int32_t const YOUME_ERROR_SERVER_INVALID;

    /**语音服务不可用 */
    static int32_t const YOUME_ERROR_NETWORK_ERROR;

    /**网络错误 */
    static int32_t const YOUME_ERROR_SERVER_INTER_ERROR;

    /**服务器内部错误 */
    static int32_t const YOUME_ERROR_QUERY_RESTAPI_FAIL;

    /**请求RestApi信息失败了 */
    static int32_t const YOUME_ERROR_USER_ABORT;

    /**用户请求中断当前操作 */
    static int32_t const YOUME_ERROR_SEND_MESSAGE_FAIL;

    /**
     *发送消息失败
     * 麦克风错误
     */
    static int32_t const YOUME_ERROR_REC_INIT_FAILED;

    /**录音模块初始化失败 */
    static int32_t const YOUME_ERROR_REC_NO_PERMISSION;

    /**没有录音权限 */
    static int32_t const YOUME_ERROR_REC_NO_DATA;

    /**虽然初始化成功，但没有音频数据输出，比如oppo系列手机在录音权限被禁止的时候 */
    static int32_t const YOUME_ERROR_REC_OTHERS;

    /**其他录音模块的错误 */
    static int32_t const YOUME_ERROR_REC_PERMISSION_UNDEFINED;

    /**
     *录音权限未确定，iOS显示是否允许录音权限对话框时，返回的是这个错误码
     * 抢麦错误
     */
    static int32_t const YOUME_ERROR_GRABMIC_FULL;

    /**抢麦失败，人数满 */
    static int32_t const YOUME_ERROR_GRABMIC_HASEND;

    /**
     *抢麦失败，活动已经结束
     * 连麦错误
     */
    static int32_t const YOUME_ERROR_INVITEMIC_NOUSER;

    /**连麦失败，用户不存在 */
    static int32_t const YOUME_ERROR_INVITEMIC_OFFLINE;

    /**连麦失败，用户已离线 */
    static int32_t const YOUME_ERROR_INVITEMIC_REJECT;

    /**连麦失败，用户拒绝 */
    static int32_t const YOUME_ERROR_INVITEMIC_TIMEOUT;

    /**
     *连麦失败，两种情况：1.连麦时，对方超时无应答 2.通话中，双方通话时间到
     * 频道白名单错误
     */
    static int32_t const YOUME_ERROR_WHITE_SOMEUSER_ABNORMAL;

    /**设置白名单部分用户异常：已不在房间 */
    static int32_t const YOUME_ERROR_UNKNOWN;

    static std::shared_ptr<RNYIMCommon> create(const std::shared_ptr<::ReactBridge> & bridge);
};