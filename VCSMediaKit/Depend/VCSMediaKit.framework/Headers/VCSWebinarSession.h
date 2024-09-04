//
//  VCSWebinarSession.h
//  VCSMediaKit
//
//  Created by SailorGa on 2024/3/6.
//  Copyright © 2024 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<VCSMediaKit/VCSMediaKit.h>)
#import <VCSMediaKit/VCSMediaObjects.h>
#else
#import "VCSMediaObjects.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class VCSWebinarSession;

#pragma mark - 研讨会代理回调
@protocol VCSWebinarSessionDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----

#pragma mark 远端视频数据回调
/// 远端视频数据回调
/// - Parameters:
///   - session: 研讨会实例
///   - streamId: 用户标识
///   - trackId: 轨道标识
///   - type: 视频存储格式(0-I420，1-NV12，2-NV21)
///   - width: 视频宽度
///   - height: 视频高度
///   - yData: 像素数据
///   - uData: 像素数据
///   - vData: 像素数据
- (void)webinarSession:(VCSWebinarSession *)session onRemoteStreamWithStreamId:(NSString *)streamId trackId:(VCSTrackIdentifierFlags)trackId type:(int)type width:(int)width height:(int)height yData:(void *)yData uData:(void *)uData vData:(void *)vData;

#pragma mark 远端音频功率数据回调
/// 远端音频功率数据回调
/// - Parameter session: 研讨会实例
/// - Parameter audioArray: 音频功率列表
- (void)webinarSession:(VCSWebinarSession *)session onRemoteAudioStatus:(NSMutableArray<VCSStreamAudioModel *> *)audioArray;

#pragma mark 音频路由变更回调
/// 音频路由变更回调
/// @param session 研讨会实例
/// @param route 音频路由
/// @param routeName 音频路由名称
/// @param previousRoute 变更前的音频路由
/// @param previousRouteName 变更前的音频路由名称
- (void)webinarSession:(VCSWebinarSession *)session onAudioRouteChanged:(VCSAudioRoute)route routeName:(NSString *)routeName previousRoute:(VCSAudioRoute)previousRoute previousRouteName:(NSString *)previousRouteName;

#pragma mark 设备性能使用情况回调
/// 设备性能使用情况回调
/// - Parameters:
///   - session: 研讨会实例
///   - memory: 内存使用
///   - cpu: CPU占用率
- (void)webinarSession:(VCSWebinarSession *)session onDevicePerformance:(double)memory cpu:(double)cpu;

@end

@interface VCSWebinarSession : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

#pragma mark 获取单例
/// 获取单例
+ (VCSWebinarSession *)sharedInstance;

#pragma mark 加入房间
/// 加入房间
/// - Parameters:
///   - webinarConfig: 研讨会配置
///   - delegate: 回调代理
- (void)enterRoomWithWebinarConfig:(nonnull VCSWebinarConfig *)webinarConfig delegate:(nullable id <VCSWebinarSessionDelegate>)delegate;

#pragma mark 订阅远端用户的视频流
/// 订阅远端用户的视频流
/// - Parameters:
///   - streamId: 指定远端用户标识
///   - trackId: 指定远端轨道标识
///   - subscribe: YES-订阅 NO-取消订阅
- (void)subscribeRemoteVideo:(NSString *)streamId trackId:(VCSTrackIdentifierFlags)trackId subscribe:(BOOL)subscribe;

#pragma mark 取消订阅远端所有视频流
/// 取消订阅远端所有视频流
- (void)unSubscribeRemoteAllVideo;

#pragma mark 订阅远端用户的音频流
/// 订阅远端用户的音频流
/// - Parameters:
///   - streamId: 指定远端用户标识
///   - subscribe: YES-订阅 NO-取消订阅
- (void)subscribeRemoteAudio:(NSString *)streamId subscribe:(BOOL)subscribe;

#pragma mark 取消订阅远端所有音频流
/// 取消订阅远端所有音频流
- (void)unSubscribeRemoteAllAudio;

#pragma mark 设置音频路由
/// 设置音频路由
/// - Parameter route: 音频路由
- (void)setAudioRoute:(VCSAudioRoute)route;

#pragma mark 获取当前音频路由
/// 获取当前音频路由
- (VCSAudioRoute)currentAudioRoute;

#pragma mark 设置音频是否播放
/// 设置音频是否播放
/// - Parameter enabled: YES-播放 NO-静音
- (void)enabledAudio:(BOOL)enabled;

#pragma mark 离开房间
/// 离开房间
- (void)exitRoom;

@end

NS_ASSUME_NONNULL_END
