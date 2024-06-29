//
//  VCSMediaObjects.h
//  VCSMediaKit
//
//  Created by SailorGa on 2022/3/3.
//  Copyright © 2022 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<VCSMediaKit/VCSMediaKit.h>)
#import <VCSMediaKit/VCSMediaEnum.h>
#else
#import "VCSMediaEnum.h"
#endif

#import <UIKit/UIKit.h>
typedef UIView VIEW_CLASS;
typedef UIColor COLOR_CLASS;

NS_ASSUME_NONNULL_BEGIN

@class VCSStreamAudioModel;
@class VCSStreamSendModel;
@class VCSStreamReceiveModel;

@class VCSLoggerParamItem;
@class VCSMetricParamItem;
@class VCSMetricNetworkParam;
@class VCSMetricDeviceParam;
@class VCSMetricAudioParam;
@class VCSMetricVideoParam;
@class VCSMetricGearsParam;

#pragma mark - 视频采集参数
/// 视频采集参数
@interface VCSCaptureParam : NSObject

/// 获取默认配置对象
+ (instancetype)defaultConfig;

/// 视频分辨率宽必须是16的倍数 高必须是2的倍数 否则容易出现绿边等问题(已做了兼容)
/// 1080P---1920x1080
/// 720P---1280x720
/// 480P---640x480
/// 180P---320x180
/// 视频分辨率宽，默认480
@property (nonatomic, assign) int videoWidth;
/// 视频分辨率高，默认640
@property (nonatomic, assign) int videoHeight;
/// 视频镜像，默认YES
@property (nonatomic, assign) BOOL videoMirror;

@end


#pragma mark - 流媒体配置
/// 流媒体配置
@interface VCSMediaConfig : NSObject

/// 流媒体地址
@property (nonatomic, copy) NSString *streamHost;
/// 流媒体端口
@property (nonatomic, assign) int streamPort;

/// 用户标识
@property (nonatomic, assign) int streamId;
/// 房间标识
@property (nonatomic, assign) int roomSdkNo;

/// 用户密钥
@property (nonatomic, copy) NSString *sessionKey;

@end


#pragma mark - 流媒体配置参数
/// 流媒体配置参数
@interface VCSMediaParam : NSObject

/// 获取默认配置对象
+ (instancetype)defaultConfig;

/// 回声消除AEC，默认12
@property (nonatomic, assign) int aec;
/// 自动增益控制AGC，默认16000
@property (nonatomic, assign) int agc;
/// 音频采样率，默认48000
@property (nonatomic, assign) int audioSampe;
/// 音频编码格式，默认AAC
@property (nonatomic, assign) VCSCodecType audioEncode;

/// 视频分辨率宽必须是16的倍数 高必须是2的倍数 否则容易出现绿边等问题(已做了兼容)
/// 1080P---1920x1080
/// 720P---1280x720
/// 480P---640x480
/// 180P---320x180
/// 视频分辨率宽，默认480
@property (nonatomic, assign) int videoWidth;
/// 视频分辨率高，默认640
@property (nonatomic, assign) int videoHeight;
/// 视频镜像，默认YES
@property (nonatomic, assign) BOOL videoMirror;

/// 视频帧率，默认25
@property (nonatomic, assign) int fps;
/// 视频码率，默认0.9*1024，单位kbps
@property (nonatomic, assign) int bitrate;

/// 是否启用媒体流加密 YES开启 NO关闭，默认 NO
@property (nonatomic, assign) BOOL enableEncrypt;

@end


#pragma mark - 码流信息
/// 码流信息
@interface VCSStreamModel : NSObject

/// 码流标识
@property (nonatomic, assign) VCSTrackIdentifierFlags id;
/// 码流类型
@property (nonatomic, assign) NSInteger type;
/// 编码类型
@property (nonatomic, assign) VCSCodecType codecType;
/// 媒体类型
@property (nonatomic, assign) VCSMediaType mediaType;
/// 画面宽
@property (nonatomic, assign) NSInteger width;
/// 画面高
@property (nonatomic, assign) NSInteger height;
/// 帧率
@property (nonatomic, assign) NSInteger fps;
/// 码率
@property (nonatomic, assign) NSInteger bitrate;
/// 画面旋转角度
@property (nonatomic, assign) NSInteger angle;

/// 扩展字段
@property (nonatomic, assign) id props;

@end


#pragma mark - 网络质量配置参数
/// 网络质量配置参数
@interface VCSNetworkQosParam : NSObject

/// 获取默认配置对象
+ (instancetype)defaultConfig;

/// 接收自适应延迟二档位，默认 500
@property (nonatomic, assign) int secondGear;
/// 接收自适应延迟三档位，默认 1200
@property (nonatomic, assign) int thirdGear;

/// 获取云端音频数据信息周期，默认为500毫秒
@property (nonatomic, assign) float onAudioCycle;

/// 开启硬件解码 YES开启 NO关闭，默认 YES
@property (nonatomic, assign) BOOL isHardwarede;
/// 开启网络自适应延迟 YES开启 NO关闭，默认 YES
@property (nonatomic, assign) BOOL isNetworkAdaptive;
/// 开启码率自适应 YES开启 NO关闭，默认 YES
@property (nonatomic, assign) BOOL isBitrateAdaptive;

/// 网络延时抗抖动等级，默认VCSNetworkQosShakeLevelMedium
@property (nonatomic, assign) VCSNetworkQosShakeLevel shakeLevel;

@end


#pragma mark - 调试配置参数
/// 调试配置参数
@interface VCSDebugParam : NSObject

/// 获取默认配置对象
+ (instancetype)defaultConfig;

/// 远程调试地址
@property (nonatomic, copy, nullable) NSString *debugHost;

/// 保存视频流，默认 NO
@property (nonatomic, assign) BOOL enableSaveVideo;
/// 保存采集音频流，默认 NO
@property (nonatomic, assign) BOOL enableSaveAudioCapture;
/// 保存远程音频流，默认 NO
@property (nonatomic, assign) BOOL enableSaveAudioReceive;

@end


#pragma mark - 测速配置参数
/// 测速配置参数
@interface VCSSpeedTestParams : NSObject

/// 用户标识
@property (nonatomic, copy) NSString *streamId;

/// 流媒体地址
@property (nonatomic, copy) NSString *streamHost;
/// 流媒体端口
@property (nonatomic, assign) int streamPort;

/// 预期的上行带宽，默认 2000kbps，设置为0时不对上行做检测
@property (nonatomic, assign) int expectedUpBandwidth;
/// 预期的下行带宽，默认 2000kbps，设置为0时不对下行做检测
@property (nonatomic, assign) int expectedDownBandwidth;
/// 测试时长，默认 30s
@property (nonatomic, assign) int duration;

@end


#pragma mark - 测速结果
/// 测速结果
@interface VCSSpeedTestResult : NSObject

/// 接收/发送包数
@property (nonatomic, assign) NSInteger recv;
/// 错序数
@property (nonatomic, assign) NSInteger miss;
/// 丢包数
@property (nonatomic, assign) NSInteger losf;
/// 速率/码率(kbps)
@property (nonatomic, assign) NSInteger speed;
/// 网络延迟
@property (nonatomic, assign) NSInteger delay;

/// 丢包率
@property (nonatomic, assign) float dropRate;
/// 网络状况
@property (nonatomic, assign) VCSNetworkState state;

@end


#pragma mark - 测速连接状态结果
/// 测速连接状态结果
@interface VCSSpeedTestConnectResult : NSObject

/// 网络回环延迟
@property (nonatomic, assign) NSInteger delay;

/// 互联网连接情况，YES-正常 NO-异常
@property (nonatomic, assign) BOOL internetConnect;
/// 流媒体连接情况，YES-正常 NO-异常
@property (nonatomic, assign) BOOL streamConnect;
/// 会控服务连接情况，YES-正常 NO-异常
@property (nonatomic, assign) BOOL signalingConnect;

@end


#pragma mark - 流媒体音频信息列表
/// 流媒体音频信息列表
@interface VCSStreamAudioStatus : NSObject

@property (nonatomic, copy) NSArray <VCSStreamAudioModel *> *audioInfo;

@end


#pragma mark - 流媒体音频信息
/// 流媒体音频信息
@interface VCSStreamAudioModel : NSObject

/// 用户标识
@property (nonatomic, copy) NSString *streamId;
/// 音频功率
@property (nonatomic, assign) NSInteger power;
/// 音频分贝
@property (nonatomic, assign) NSInteger db;

/// 创建远端音频对象
/// - Parameters:
///   - streamId: 远端用户标识
///   - power: 音频功率
///   - db: 音频分贝
- (instancetype)initWithStreamId:(nullable NSString *)streamId power:(int)power db:(int)db;

@end


#pragma mark - 流媒体发送状态信息列表
/// 流媒体发送状态信息列表
@interface VCSStreamSendStatus : NSObject

@property (nonatomic, copy) NSArray <VCSStreamSendModel *> *uploadinfo;

@end


#pragma mark - 流媒体发送状态信息
/// 流媒体发送状态信息
@interface VCSStreamSendModel : NSObject

/// 上传缓冲包数
@property (nonatomic, assign) int buffer;
/// 上传延迟
@property (nonatomic, assign) int delay;
/// 溢出缓冲包数
@property (nonatomic, assign) int overflow;
/// 视频上传速率(单位kps)
@property (nonatomic, copy) NSString *speed;
/// 音频上传速率(单位kps)
@property (nonatomic, copy) NSString *audio_speed;
/// 上传状态
@property (nonatomic, assign) NSInteger status;
/// 补偿前丢包率
@property (nonatomic, assign) float loss_r;
/// 补偿后丢包率
@property (nonatomic, assign) float loss_c;

/// 网络等级
@property (nonatomic, assign) int netLevel;

@end


#pragma mark - 流媒体接收状态信息列表
/// 流媒体接收状态信息列表
@interface VCSStreamReceiveStatus : NSObject

@property (nonatomic, copy) NSArray <VCSStreamReceiveModel *> *recvinfo;

@end


#pragma mark - 流媒体接收状态信息
/// 流媒体接收状态信息
@interface VCSStreamReceiveModel : NSObject

/// 用户标识
@property (nonatomic, copy) NSString *streamId;
/// 接收包数
@property (nonatomic, assign) int recv;
/// 补偿包数
@property (nonatomic, assign) int comp;
/// 总丢包数
@property (nonatomic, assign) int losf;
/// 端到端丢包率
@property (nonatomic, assign) float lrl;
/// 服务器到端丢包率
@property (nonatomic, assign) float lrd;
/// 音频包数
@property (nonatomic, assign) int audio;
/// 视频包数
@property (nonatomic, assign) int video;

///  ------ 传输速率(码率-单位kps) ------
/// 总速率
@property (nonatomic, assign) float total_speed;
/// 音频速率
@property (nonatomic, assign) float audio_speed;
/// 视频速率
@property (nonatomic, assign) float video_speed;

@end


#pragma mark - 投屏配置参数
@interface VCSScreenCastingConfig : NSObject

/// 获取默认配置对象
+ (instancetype)defaultConfig;

/// 投屏地址
@property (nonatomic, copy) NSString *castingHost;
/// 用户名称
@property (nonatomic, copy) NSString *username;
/// 媒体流是否启用加密，默认 NO
@property (nonatomic, assign) BOOL enableEncrypt;

/// 编码宽度，默认720
@property (nonatomic, assign) int encoderWidth;
/// 编码高度，默认1280
@property (nonatomic, assign) int encoderHeight;
/// 编码帧率，默认20，注：已失效，不再支持配置
@property (nonatomic, assign) int framerate;

/// 远程调试地址
@property (nonatomic, copy, nullable) NSString *debugHost;
/// 保存视频流，默认 NO
@property (nonatomic, assign) BOOL enableSaveVideo;
/// 保存音频流，默认 NO
@property (nonatomic, assign) BOOL enableSaveAudio;

@end


#pragma mark - 投屏指令基础类
@interface VCSScreenCastingBaseModel : NSObject

/// 指令类型(指示包用途，如：发起投屏、心跳等)
@property (nonatomic, copy) NSString *action;
/// 数据包类型(指示包类型，如：请求、响应等)
@property (nonatomic, copy) NSString *type;
/// 消息编号
@property (nonatomic, copy) NSString *seq;
/// 平台类型
@property (nonatomic, assign) NSInteger terminalType;

@end


#pragma mark - 投屏指令对象
@interface VCSScreenCastingModel : VCSScreenCastingBaseModel

/// 发送用户标识
@property (nonatomic, copy) NSString *senderId;
/// 发送用户名称
@property (nonatomic, copy) NSString *senderName;

/// 错误码(如：发起投屏时，0-接受 1-拒绝)
@property (nonatomic, assign) VCSScreenCastingStatus status;

/// 接收用户标识
@property (nonatomic, copy) NSString *targetId;
/// 附加数据
@property (nonatomic, copy) NSString *extra;

/// 当前时间戳
@property (nonatomic, assign) NSInteger timetick;
/// 心跳指令凑包数据
@property (nonatomic, assign) NSString *ext;
/// 调试信息
@property (nonatomic, assign) NSString *info;

@end


#pragma mark - 投屏发送堆栈溢出对象
@interface VCSScreenCastingOverflow : NSObject

/// 溢出开始时间，秒级时间戳
@property (nonatomic, assign) NSInteger startDate;

@end


#pragma mark - 研讨会配置
/// 研讨会配置
@interface VCSWebinarConfig : NSObject

/// 服务地址
@property (nonatomic, copy) NSString *webinarHost;
/// 房间标识
@property (nonatomic, copy) NSString *roomSdkNo;

/// 请求云端音频数据周期，默认为500毫秒
@property (nonatomic, assign) float onAudioCycle;
/// 音频路由，默认 VCSAudioRouteSpeaker
@property (nonatomic, assign) VCSAudioRoute route;
/// 是否播放音频，默认 YES
@property (nonatomic, assign) BOOL enablePlayAudio;

@end


#pragma mark - 行为日志上报对象
@interface VCSLoggerParam : NSObject

/// 设备标识
@property (nonatomic, copy) NSString *device_id;
/// 设备类型，默认 VCSTerminalTypeIOS
@property (nonatomic, assign) NSInteger device_type;

/// 日志列表
@property (nonatomic, strong) NSMutableArray <VCSLoggerParamItem *> *logs;

@end


#pragma mark - 行为日志对象
@interface VCSLoggerParamItem : NSObject

/// 日志时间戳
@property (nonatomic, assign) NSInteger time;
/// 日志等级，默认 VCSLoggerLevelInfo
@property (nonatomic, assign) VCSLoggerLevel serverity;
/// 日志类型
@property (nonatomic, copy) NSString *type;

/// 用户标识
@property (nonatomic, copy, nullable) NSString *uid;
/// 用户会议昵称(入会必传)
@property (nonatomic, copy, nullable) NSString *uname;

/// 模块名称
@property (nonatomic, copy, nullable) NSString *mname;
/// 模块标识
@property (nonatomic, copy, nullable) NSString *mid;

/// 会议记录标识(入会必传)
@property (nonatomic, copy, nullable) NSString *conf_log_id;
/// 参会记录标识(入会必传)
@property (nonatomic, copy, nullable) NSString *trace_id;

/// 日志内容
@property (nonatomic, assign) id body;

/// 创建行为日志对象
/// - Parameters:
///   - serverity: 日志等级
///   - type: 日志类型
///   - mname: 模块名称
///   - mid: 模块标识
///   - body: 日志内容
- (instancetype)initWithServerity:(VCSLoggerLevel)serverity type:(NSString *)type mname:(nullable NSString *)mname mid:(nullable NSString *)mid body:(id)body;

@end


#pragma mark - 实时日志上报对象
@interface VCSMetricParam : NSObject

/// 设备标识
@property (nonatomic, copy) NSString *device_id;
/// 设备类型，默认 VCSTerminalTypeIOS
@property (nonatomic, assign) NSInteger device_type;

/// 日志列表
@property (nonatomic, strong) NSMutableArray <VCSMetricParamItem *> *metrics;

@end


#pragma mark - 实时日志对象
@interface VCSMetricParamItem : NSObject

/// 日志时间戳
@property (nonatomic, assign) NSInteger time;

/// 用户标识
@property (nonatomic, copy, nullable) NSString *uid;
/// 房间号码
@property (nonatomic, copy, nullable) NSString *room_no;
/// 会议记录标识
@property (nonatomic, copy, nullable) NSString *conf_log_id;
/// 参会记录标识
@property (nonatomic, copy, nullable) NSString *trace_id;

/// 网络信息
@property (nonatomic, strong, nullable) VCSMetricNetworkParam *network;
/// 设备信息采样
@property (nonatomic, strong, nullable) VCSMetricDeviceParam *device;

/// 本地音频信息
@property (nonatomic, strong, nullable) VCSMetricAudioParam *local_audio;
/// 本地视频信息
@property (nonatomic, strong, nullable) NSArray <VCSMetricVideoParam *> *local_videos;
/// 本地共享信息
@property (nonatomic, strong, nullable) VCSMetricVideoParam *local_share;

/// 远程音频信息
@property (nonatomic, strong, nullable) NSArray <VCSMetricAudioParam *> *remote_audios;
/// 远程视频信息
@property (nonatomic, strong, nullable) NSArray <VCSMetricVideoParam *> *remote_videos;
/// 远程共享信息
@property (nonatomic, strong, nullable) NSArray <VCSMetricVideoParam *> *remote_shares;

/// 远端下行档位信息
@property (nonatomic, strong, nullable) NSArray <VCSMetricGearsParam *> *net_level;

/// 创建实时日志对象
/// - Parameters:
///   - userId: 用户标识
///   - roomNo: 房间号码
///   - networkParam: 流媒体网络信息
///   - localAudio: 本地音频信息
///   - localVideos: 本地视频信息列表
///   - localShare: 本地共享信息
///   - remoteAudios: 远程音频信息列表
///   - remoteVideos: 远程视频信息列表
///   - remoteShares: 远程共享信息列表
///   - remoteGears: 远程档位信息列表
- (instancetype)initWithUserId:(nullable NSString *)userId roomNo:(nullable NSString *)roomNo networkParam:(nullable VCSMetricNetworkParam *)networkParam localAudio:(nullable VCSMetricAudioParam *)localAudio localVideos:(nullable NSArray <VCSMetricVideoParam *> *)localVideos localShare:(nullable VCSMetricVideoParam *)localShare remoteAudios:(nullable NSArray <VCSMetricAudioParam *> *)remoteAudios remoteVideos:(nullable NSArray <VCSMetricVideoParam *> *)remoteVideos remoteShares:(nullable NSArray <VCSMetricVideoParam *> *)remoteShares remoteGears:(nullable NSArray <VCSMetricGearsParam *> *)remoteGears;

@end


#pragma mark - 实时日志网络信息对象
@interface VCSMetricNetworkParam : NSObject

/// 上行码率
@property (nonatomic, assign) CGFloat bitrate_up;
/// 下行码率
@property (nonatomic, assign) CGFloat bitrate_down;
/// 上行丢包率(补偿后)
@property (nonatomic, assign) CGFloat lossrate_up;
/// 下行丢包率(补偿后)
@property (nonatomic, assign) CGFloat lossrate_down;
/// 上行网络延时
@property (nonatomic, assign) CGFloat delay;

@end


#pragma mark - 实时日志设备信息采样对象
@interface VCSMetricDeviceParam : NSObject

/// 系统占用CPU百分比
@property (nonatomic, assign) CGFloat cpu_system;
/// 应用占用CPU百分比
@property (nonatomic, assign) CGFloat cpu_app;

/// 系统占用内存百分比
@property (nonatomic, assign) CGFloat mem_system;
/// 应用占用内存百分比
@property (nonatomic, assign) CGFloat mem_app;

/// 系统占用内存大小
@property (nonatomic, assign) CGFloat mem_system_val;
/// 应用占用内存大小
@property (nonatomic, assign) CGFloat mem_app_val;

/// 获取当前资源占用
+ (instancetype)defaultConfig;

@end

#pragma mark - 实时日志音频对象
@interface VCSMetricAudioParam : NSObject

/// 用户标识
@property (nonatomic, copy, nullable) NSString *uid;
/// 音频码率
@property (nonatomic, assign) CGFloat bitrate;
/// 音频分贝值
@property (nonatomic, assign) CGFloat db;
/// 编码格式
@property (nonatomic, copy, nullable) NSString *codec;
/// 内部字段(流媒体标识)
@property (nonatomic, assign, readonly) NSInteger linkId;

/// 创建音频日志对象
/// - Parameters:
///   - userId: 用户标识
///   - linkId: 流媒体标识
///   - bitrate: 音频码率
///   - db: 音频分贝值
///   - codec: 编码格式
- (instancetype)initWithUserId:(nullable NSString *)userId linkId:(NSInteger)linkId bitrate:(CGFloat)bitrate db:(CGFloat)db codec:(nullable NSString *)codec;

@end


#pragma mark - 实时日志视频对象
@interface VCSMetricVideoParam : NSObject

/// 用户标识
@property (nonatomic, copy, nullable) NSString *uid;
/// 视频码率
@property (nonatomic, assign) CGFloat bitrate;
/// 视频分辨率
@property (nonatomic, assign) CGFloat height;
/// 视频分辨率
@property (nonatomic, assign) CGFloat width;
/// 视频帧率
@property (nonatomic, assign) CGFloat frame_rate;

/// 视频轨道
@property (nonatomic, assign) int track;
/// 编码格式
@property (nonatomic, copy, nullable) NSString *codec;

/// 接收共享桌面流独有属性，共享屏幕0帧版本引入
/// 是否图片模式，0-否 1-是
@property (nonatomic, assign) int img_mode;
/// 是否在收流，0-否 1-是
@property (nonatomic, assign) int is_load_stream;

/// 创建视频日志对象
/// - Parameters:
///   - userId: 用户标识
///   - bitrate: 视频码率
///   - height: 视频分辨率
///   - width: 视频分辨率
///   - framerate: 视频帧率
///   - track: 视频轨道
///   - codec: 编码格式
- (instancetype)initWithUserId:(nullable NSString *)userId bitrate:(CGFloat)bitrate height:(CGFloat)height width:(CGFloat)width framerate:(CGFloat)framerate track:(int)track codec:(nullable NSString *)codec;

@end


#pragma mark - 实时日志档位对象
@interface VCSMetricGearsParam : NSObject

/// 用户标识(为local时，表示当前用户)
@property (nonatomic, copy, nullable) NSString *uid;
/// 档位值(成员时，表示下行延时自适应档位；自己时，表示码率自适应档位)
@property (nonatomic, assign) int level;

/// 创建档位对象
/// - Parameters:
///   - userId: 用户标识
///   - level: 档位值
- (instancetype)initWithUserId:(nullable NSString *)userId level:(int)level;

@end


#pragma mark - 黑窗口重定向日志对象
@interface VCSRedirectParam : NSObject

/// 设备标识
@property (nonatomic, copy) NSString *device_id;
/// 设备类型，默认 VCSTerminalTypeIOS
@property (nonatomic, assign) NSInteger device_type;

/// 用户标识
@property (nonatomic, copy, nullable) NSString *uid;
/// 会议记录标识(入会必传)
@property (nonatomic, copy, nullable) NSString *conf_log_id;

/// 创建重定向日志对象
/// - Parameters:
///   - deviceId: 设备标识
- (instancetype)initWithDeviceId:(NSString *)deviceId;

@end


NS_ASSUME_NONNULL_END
