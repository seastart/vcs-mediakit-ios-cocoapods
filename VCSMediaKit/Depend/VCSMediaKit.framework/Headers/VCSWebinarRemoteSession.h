//
//  VCSWebinarRemoteSession.h
//  VCSMediaKit
//
//  Created by SailorGa on 2024/3/13.
//  Copyright © 2024 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<VCSMediaKit/VCSMediaKit.h>)
#import <VCSMediaKit/VCSMediaObjects.h>
#else
#import "VCSMediaObjects.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface VCSWebinarRemoteSession : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

#pragma mark 获取管理实例
/// 获取管理实例
+ (VCSWebinarRemoteSession *)sharedInstance;

#pragma mark 清空缓存数据
/// 清空缓存数据
- (void)cleanData;


#pragma mark - ------------ 远程流数据管理相关接口 ------------

#pragma mark 订阅远端用户的视频流
/// 订阅远端用户的视频流
/// @param streamId 指定远端用户标识
/// @param trackId 指定要观看的轨道标识
/// @param view 承载视频画面的控件
- (void)startRemoteView:(NSString *)streamId trackId:(VCSTrackIdentifierFlags)trackId view:(VIEW_CLASS *)view;

#pragma mark 更新远端用户的视频流
/// 更新远端用户的视频流
/// @param streamId 指定远端用户标识
/// @param trackId 指定要观看的轨道标识
/// @param view 承载视频画面的控件
- (void)updateRemoteView:(NSString *)streamId trackId:(VCSTrackIdentifierFlags)trackId view:(VIEW_CLASS *)view;

#pragma mark 停止订阅远端用户的视频流
/// 停止订阅远端用户的视频流
/// @param streamId 指定远端用户标识
/// @param trackId 指定要观看的轨道标识
- (void)stopRemoteView:(NSString *)streamId trackId:(VCSTrackIdentifierFlags)trackId;

#pragma mark 停止订阅所有远端用户的视频流
/// 停止订阅所有远端用户的视频流
- (void)stopAllRemoteView;

#pragma mark 重置远程流订阅
/// 重置远程流订阅
- (void)resetRemoteStream;

#pragma mark 渲染远程流数据
/// 渲染远程流数据
/// @param streamId 成员标识
/// @param stamp 视频时间戳
/// @param trackId 视频轨道
/// @param type 视频存储格式
/// @param angle 视频角度
/// @param width 视频宽
/// @param height 视频高
/// @param yData 像素数据
/// @param uData 像素数据
/// @param vData 像素数据
- (void)remoteStreamDataStreamId:(NSString *)streamId stamp:(int)stamp trackId:(VCSTrackIdentifierFlags)trackId type:(int)type angle:(int)angle width:(int)width height:(int)height yData:(void *)yData uData:(void *)uData vData:(void *)vData;

@end

NS_ASSUME_NONNULL_END
