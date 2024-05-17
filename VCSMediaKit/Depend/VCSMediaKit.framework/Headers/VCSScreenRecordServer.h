//
//  VCSScreenRecordServer.h
//  VCSMediaKit
//
//  Created by SailorGa on 2022/7/23.
//  Copyright © 2022 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<VCSMediaKit/VCSMediaKit.h>)
#import <VCSMediaKit/VCSMediaObjects.h>
#else
#import "VCSMediaObjects.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class VCSScreenRecordServer;

#pragma mark - 屏幕共享服务端回调代理
@protocol VCSScreenRecordServerDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 屏幕录制编码后数据回调
/// 屏幕录制编码后数据回调
/// @param server 服务端实例
/// @param streamData 共享流数据
/// @param pts 显示时间戳
/// @param dts 解码时间戳
/// @param angle 显示角度
/// @param keyframe 是否为关键帧
- (void)screenServer:(VCSScreenRecordServer *)server didStreamData:(NSData *)streamData pts:(uint32_t)pts dts:(uint32_t)dts angle:(int)angle keyframe:(BOOL)keyframe;

#pragma mark 屏幕录制音频原始数据回调
/// 屏幕录制音频原始数据回调
/// @param server 服务端实例
/// @param streamData 共享音频数据
/// @param pts 显示时间戳
/// @param dts 解码时间戳
- (void)screenServer:(VCSScreenRecordServer *)server didAudioStreamData:(NSData *)streamData pts:(uint32_t)pts dts:(uint32_t)dts;

#pragma mark 屏幕录制实时帧率回调
/// 屏幕录制实时帧率回调
/// @param server 服务端实例
/// @param framerate 当前帧率
/// @param bitrate 当前码率
/// @param height 当前分辨率
/// @param width 当前分辨率
- (void)screenServer:(VCSScreenRecordServer *)server didChangeFramerate:(int)framerate bitrate:(int)bitrate height:(int)height width:(int)width;

#pragma mark 屏幕录制状态码回调
/// 投屏状态码回调
/// @param server 服务端实例
/// @param status 屏幕录制状态
- (void)screenServer:(VCSScreenRecordServer *)server didProcessStatus:(VCSScreenRecordStatus)status;

@end

#pragma mark - VCSScreenRecordServer
@interface VCSScreenRecordServer : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

/// 设备分辨率(宽)
@property (nonatomic, assign, readonly) float screen_width;
/// 设备分辨率(高)
@property (nonatomic, assign, readonly) float screen_height;
/// 编码分辨率(宽)
@property (nonatomic, assign, readonly) int width;
/// 编码分辨率(高)
@property (nonatomic, assign, readonly) int height;
/// 编码帧率(当前帧率)
@property (nonatomic, assign, readonly) float fps;
/// 编码码率(当前码率)
@property (nonatomic, assign, readonly) int bitrate;
/// 当前视频角度
@property (nonatomic, assign, readonly) int videoAngle;
/// 屏幕共享流信息
@property (nonatomic, strong, readonly) VCSStreamModel *streamScreen;

#pragma mark 获取单例
/// 获取单例
+ (VCSScreenRecordServer *)sharedInstance;

#pragma mark 开启屏幕录制
/// 开启屏幕录制
/// - Parameters:
///   - appGroup: Application Group Identifier
///   - isCasting: 录屏模式 YES-投屏 NO-共享
///   - encoderWidth: 编码宽度
///   - encoderHeight: 编码高度
///   - framerate: 编码帧率
///   - delegate: 代理回调
- (void)startScreenRecordWithAppGroup:(NSString *)appGroup isCasting:(BOOL)isCasting encoderWidth:(int)encoderWidth encoderHeight:(int)encoderHeight framerate:(int)framerate delegate:(nullable id <VCSScreenRecordServerDelegate>)delegate;

#pragma mark 关闭屏幕录制
/// 关闭屏幕录制
- (void)stopScreenRecord;

#pragma mark 强制关键帧
/// 强制关键帧
- (BOOL)forceKeyFrame;

#pragma mark 变更编码帧率
/// 变更编码帧率
/// - Parameter framerate: 目标帧率
- (BOOL)changeEncoderFps:(int)framerate;

#pragma mark 资源销毁
/// 资源销毁
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
