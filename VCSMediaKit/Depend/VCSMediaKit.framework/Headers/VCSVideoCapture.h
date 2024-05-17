//
//  VCSVideoCapture.h
//  VCSMediaKit
//
//  Created by SailorGa on 2022/7/14.
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

@class VCSVideoCapture;

#pragma mark - 采集回调代理
@protocol VCSVideoCaptureDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 视频采集数据回调
/// 视频采集数据回调
/// @param capture 采集实例
/// @param pixelBuffer 像素数据
/// @param stamp 时间戳
/// @param frontCamera 是否为前置摄像头
/// @param viewChange 视图是否发生变化
- (void)videoCapture:(VCSVideoCapture *)capture pixelBuffer:(CVPixelBufferRef)pixelBuffer stamp:(CMTime)stamp frontCamera:(BOOL)frontCamera viewChange:(int)viewChange;

@end

#pragma mark - VCSVideoCapture
@interface VCSVideoCapture : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

/// 视频采集参数配置
@property (nonatomic, strong, readonly) VCSCaptureParam *captureParam;
/// 采集状态
@property (nonatomic, assign, readonly) BOOL enabledCapture;

/// 采集回调代理
@property (nonatomic, weak) id<VCSVideoCaptureDelegate> delegate;

#pragma mark 获取采集实例
/// 获取采集实例
+ (VCSVideoCapture *)sharedInstance;

#pragma mark 设置视频采集参数
/// 设置视频采集参数
/// @param captureParam 视频采集参数
- (void)setVideoCaptureParam:(VCSCaptureParam *)captureParam;

#pragma mark 开启本地摄像头的预览画面
/// 开启本地摄像头的预览画面
/// @param frontCamera YES-前置摄像头 NO-后置摄像头
/// @param view 承载视频画面的控件
- (VCSError)startLocalPreview:(BOOL)frontCamera view:(VIEW_CLASS *)view;

#pragma mark 更新本地摄像头的预览画面
/// 更新本地摄像头的预览画面
/// @param view 承载视频画面的控件
- (VCSError)updateLocalView:(VIEW_CLASS *)view;

#pragma mark 停止摄像头预览
/// 停止摄像头预览
- (VCSError)stopLocalPreview;

#pragma mark 切换摄像头
/// 切换摄像头
- (VCSError)switchCamera;

#pragma mark 修正预览界面
/// 修正预览界面
/// @param size 视图大小
- (VCSError)revisePreviewSize:(CGSize)size;

#pragma mark 设置画面预览方向
/// 设置画面预览方向
/// @param deviceOrientation 预览方向
- (VCSError)setPreviewOrientation:(UIDeviceOrientation)deviceOrientation;

#pragma mark 设置摄像头的缩放倍数
/// 设置摄像头的缩放倍数
/// @param zoomRatio 缩放系数(1.0~5.0)
- (VCSError)setCameraZoomRatio:(CGFloat)zoomRatio;

#pragma mark 设置摄像头的对焦位置
/// 设置摄像头的对焦位置
/// @param position 对焦位置
- (VCSError)setCameraFocusPosition:(CGPoint)position;

#pragma mark 设置摄像头的曝光系数
/// 设设置摄像头的曝光系数
/// @param exposureRatio 曝光系数(-8.0~8.0)
- (VCSError)setCameraExposureRatio:(CGFloat)exposureRatio;

#pragma mark 设置闪光灯状态
/// 设置闪光灯状态
/// @param enabled 是否开启闪光灯(YES-开启 NO-关闭)
- (VCSError)enableCameraTorch:(BOOL)enabled;

#pragma mark 渲染CVPixelBufferRef数据
/// 渲染CVPixelBufferRef数据
/// @param pixelBuffer 像素数据
- (void)displayCVPixleBuffer:(CVPixelBufferRef)pixelBuffer;

#pragma mark 资源销毁
/// 资源销毁
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
