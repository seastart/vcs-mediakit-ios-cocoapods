//
//  VCSStreamMedia.h
//  VCSMediaKit
//
//  Created by SailorGa on 2022/7/8.
//  Copyright © 2022 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>

#if __has_include(<VCSMediaKit/VCSMediaKit.h>)
#import <VCSMediaKit/VCSMediaObjects.h>
#else
#import "VCSMediaObjects.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class VCSStreamMedia;

#pragma mark - 流媒体回调代理
@protocol VCSStreamMediaDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 流媒体连接成功回调
/// 流媒体连接成功回调
/// @param stream 流媒体组件实例
/// @param finish 完成状态
- (void)streamMedia:(VCSStreamMedia *)stream didConnectionFinish:(BOOL)finish;

#pragma mark 流媒体重连完成回调
/// 流媒体重连完成回调
/// @param stream 流媒体组件实例
/// @param finish 完成状态
- (void)streamMedia:(VCSStreamMedia *)stream didReconnectionFinish:(BOOL)finish;

#pragma mark 应用性能使用情况回调
/// 应用性能使用情况回调
/// @param stream 流媒体组件实例
/// @param memory 内存占用
/// @param cpuUsage CUP使用率
- (void)streamMedia:(VCSStreamMedia *)stream onApplicationPerformance:(double)memory cpuUsage:(double)cpuUsage;

#pragma mark 视频方向变化回调
/// 视频方向变化回调
/// @param stream 流媒体组件实例
/// @param track 视频轨道
/// @param angle 视频角度
- (void)streamMedia:(VCSStreamMedia *)stream didVideoOrientationChange:(VCSTrackIdentifierFlags)track angle:(int)angle;

#pragma mark 远程成员音频状态回调
/// 远程成员音频状态回调
/// @param stream 流媒体组件实例
/// @param audioArray 成员音频列表
- (void)streamMedia:(VCSStreamMedia *)stream onRemoteMemberAudioStatus:(NSArray<VCSStreamAudioModel *> *)audioArray;

#pragma mark 服务是否允许发言
/// 服务是否允许发言
/// @param stream 流媒体组件实例
/// @param enabled 是否允许发言，YES-允许发言 NO-不允许发言
- (void)streamMedia:(VCSStreamMedia *)stream onServiceEnabledSpeak:(BOOL)enabled;

#pragma mark 远程流数据回调
/// 远程流数据回调
/// @param stream 流媒体组件实例
/// @param streamId 远程成员标识
/// @param stamp 视频时间戳
/// @param track 视频轨道
/// @param type 视频存储格式
/// @param angle 视频角度
/// @param width 视频宽
/// @param height 视频高
/// @param yData 像素数据
/// @param uData 像素数据
/// @param vData 像素数据
- (void)streamMedia:(VCSStreamMedia *)stream didRemoteStreamDataStreamId:(int)streamId stamp:(int)stamp track:(int)track type:(int)type angle:(int)angle width:(int)width height:(int)height yData:(void *)yData uData:(void *)uData vData:(void *)vData;

#pragma mark 下行码率自适应状态回调
/// 下行码率自适应状态回调
/// @param stream 流媒体组件实例
/// @param streamId 远程成员标识
/// @param state 下行码率自适应状态
- (void)streamMedia:(VCSStreamMedia *)stream onDownBitrateAdaptiveStreamId:(int)streamId state:(VCSDownBitrateAdaptiveState)state;

#pragma mark 上行码率自适应状态回调
/// 上行码率自适应状态回调
/// @param stream 流媒体组件实例
/// @param state 上行码率自适应状态
- (void)streamMedia:(VCSStreamMedia *)stream onUploadBitrateAdaptiveState:(VCSUploadBitrateAdaptiveState)state;

#pragma mark 下行平均丢包档位变化回调
/// 下行平均丢包档位变化回调
/// @param stream 流媒体组件实例
/// @param state 下行平均丢包档位
- (void)streamMedia:(VCSStreamMedia *)stream onDownLossLevelChangeState:(VCSDownLossLevelState)state;

#pragma mark 下行平均丢包率回调
/// 下行平均丢包率回调
/// @param stream 流媒体组件实例
/// @param average 下行平均丢包率
- (void)streamMedia:(VCSStreamMedia *)stream onDownLossRateAverage:(CGFloat)average;

#pragma mark 流媒体发送状态数据回调
/// 流媒体发送状态数据回调
/// @param stream 流媒体组件实例
/// @param sendModel 流媒体发送状态数据
- (void)streamMedia:(VCSStreamMedia *)stream onSendStreamModel:(VCSStreamSendModel *)sendModel;

#pragma mark 流媒体接收状态数据回调
/// 流媒体接收状态数据回调
/// @param stream 流媒体组件实例
/// @param receiveModel 流媒体接收状态数据
- (void)streamMedia:(VCSStreamMedia *)stream onReceiveStreamModel:(VCSStreamReceiveModel *)receiveModel;

#pragma mark 音频路由变更回调
/// 音频路由变更回调
/// @param stream 流媒体组件实例
/// @param route 音频路由
/// @param routeName 音频路由名称
/// @param previousRoute 变更前的音频路由
/// @param previousRouteName 变更前的音频路由名称
- (void)streamMedia:(VCSStreamMedia *)stream onAudioRouteChanged:(VCSAudioRoute)route routeName:(NSString *)routeName previousRoute:(VCSAudioRoute)previousRoute previousRouteName:(NSString *)previousRouteName;

@end

/// 释放完成回调
typedef void (^VCSStreamMediaDestroyBlock)(void);

#pragma mark - VCSStreamMedia
@interface VCSStreamMedia : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

/// 流媒体配置
@property (nonatomic, strong, readonly) VCSMediaConfig *mediaConfig;
/// 媒体配置参数
@property (nonatomic, strong, readonly) VCSMediaParam *mediaParam;
/// 网络质量控制参数
@property (nonatomic, strong, readonly) VCSNetworkQosParam *networkQosParam;
/// 调试参数
@property (nonatomic, strong, readonly) VCSDebugParam *debugParam;

/// 主码流信息
@property (nonatomic, strong, readonly) VCSStreamModel *streamMain;
/// 子码流信息
@property (nonatomic, strong, readonly) VCSStreamModel *streamSub;
/// 音频码流信息
@property (nonatomic, strong, readonly) VCSStreamModel *streamAudio;

/// 视频推流状态
@property (nonatomic, assign, readonly) BOOL enabledPublishVideo;
/// 音频推流状态
@property (nonatomic, assign, readonly) BOOL enabledPublishAudio;
/// 流媒体连接状态
@property (nonatomic, assign, readonly) BOOL streamConnect;

#pragma mark 获取流媒体实例
/// 获取流媒体实例
+ (VCSStreamMedia *)sharedInstance;

#pragma mark 设置媒体配置参数
/// 设置媒体配置参数
/// @param mediaParam 媒体配置参数
- (void)setStreamMediaParam:(VCSMediaParam *)mediaParam;

#pragma mark 设置网络质量控制参数
/// 设置网络质量控制参数
/// @param param 质量控制参数
- (void)setStreamNetworkQosParam:(VCSNetworkQosParam *)param;

#pragma mark 设置远程调试参数
/// 设置远程调试参数
/// @param param 调试参数
- (void)setRemoteDebugParam:(VCSDebugParam *)param;

#pragma mark 初始化流媒体
/// 初始化流媒体
/// @param mediaConfig 流媒体配置
/// @param delegate 代理回调
- (void)initializeWithMediaConfig:(VCSMediaConfig *)mediaConfig delegate:(nullable id <VCSStreamMediaDelegate>)delegate;

#pragma mark 资源销毁
/// 资源销毁
/// @param finishBlock 完成回调
- (void)destroy:(nullable VCSStreamMediaDestroyBlock)finishBlock;

#pragma mark 恢复/暂停推流
/// 恢复/暂停推流
/// @param enabled YES-恢复 NO-暂停
- (void)enabledPublish:(BOOL)enabled;

#pragma mark 发布视频数据流
/// 发布视频数据流
/// @param sampleBuffer 视频数据
/// @param stamp 时间戳
/// @param frontCamera 是否为前置摄像头
/// @param viewChange 视图是否发生变化
- (void)publishVideoWithSampleBuffer:(CVPixelBufferRef)sampleBuffer stamp:(CMTime)stamp frontCamera:(BOOL)frontCamera viewChange:(int)viewChange;

#pragma mark 发布音频数据流
/// 发布音频数据流
/// @param streamData 音频数据
/// @param stamp 显示时间戳
/// @param dts 解码时间戳
- (void)publishAudioWithStreamData:(NSData *)streamData stamp:(uint32_t)stamp dts:(uint32_t)dts;

#pragma mark 设置音频路由
/// 设置音频路由
/// - Parameter route: 音频路由
- (void)setAudioRoute:(VCSAudioRoute)route;

#pragma mark 获取当前音频路由
/// 获取当前音频路由
- (VCSAudioRoute)currentAudioRoute;

#pragma mark 获取音频路由列表
/// 获取音频路由列表
- (NSArray<VCSAudioRouteModel *> *)getAvailableAudioRoutes;

#pragma mark 音频发送状态
/// 音频发送状态
/// @param enabled YES-开启 NO-关闭
- (VCSError)enabledSendAudio:(BOOL)enabled;

#pragma mark 视频发送状态
/// 视频发送状态
/// @param enabled YES-开启 NO-关闭
- (VCSError)enabledSendVideo:(BOOL)enabled;

#pragma mark 订阅远程流
/// 订阅远程流
/// @param streamId 远程成员标识
/// @param state 订阅远程流类型
- (void)subscribeRemoteStreamWithStreamId:(int)streamId state:(VCSPickerState)state;

#pragma mark 订阅远程流轨道
/// 订阅远程流轨道
/// @param streamId 远程成员标识
/// @param trackMask 轨道掩码
/// @param synchro 是否采用同步切换，YES-同步切换轨道(如该轨道没有流会一直等待即：无论有无数据流都将切换成功) NO-异步切换轨道(如该轨道没有流会默认切换失败，服务自动丢弃该消息)
- (void)subscribeRemoteStreamTrackWithStreamId:(int)streamId trackMask:(int)trackMask synchro:(BOOL)synchro;

#pragma mark 设置音频优先策略
/// 设置音频优先策略
/// @param streamId 远程成员标识
/// @param enabled  YES-开启 NO-关闭
- (VCSError)setAudioPriorityWithStreamId:(int)streamId enabled:(BOOL)enabled;

#pragma mark 发布屏幕共享流
/// 发布编码模式屏幕共享流
/// @param streamData 共享流数据
/// @param stamp 显示时间戳
/// @param dts 解码时间戳
/// @param displayAngle 显示角度
- (void)publishScreenEncoderWithStreamData:(NSData *)streamData stamp:(uint32_t)stamp dts:(uint32_t)dts displayAngle:(int)displayAngle;

#pragma mark 设置扬声器状态
/// 设置扬声器状态
/// @param enabled 是否开启扬声器(YES-开启 NO-关闭)
- (VCSError)enabledAudioSpeaker:(BOOL)enabled;

#pragma mark 设置云录制轨道
/// 设置云录制轨道
/// @param trackMask 轨道掩码
- (void)setCloudRecordStreamWithTrackMask:(int)trackMask;

#pragma mark 发布自定义码流
/// 发布自定义码流
/// @param streamData 码流数据
/// @param bitslen 数据长度
/// @param pts 显示时间戳
/// @param dts 解码时间戳
/// @param trackId 轨道ID
/// @param streamType 媒体流类型
- (void)publishCustomStreamWithStreamData:(const unsigned char *)streamData bitslen:(int)bitslen pts:(uint32_t)pts dts:(uint32_t)dts trackId:(VCSTrackIdentifierFlags)trackId streamType:(VCSStreamType)streamType;

@end

NS_ASSUME_NONNULL_END
