//
//  VCSVideoRender.h
//  VCSMediaKit
//
//  Created by SailorGa on 2024/3/5.
//  Copyright © 2024 SailorGa. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import <Foundation/Foundation.h>

#if __has_include(<VCSMediaKit/VCSMediaKit.h>)
#import <VCSMediaKit/VCSMediaObjects.h>
#else
#import "VCSMediaObjects.h"
#endif

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 渲染填充模式
/**
 渲染填充模式

 - VCSVideoRenderContentModeScaleAspectFill: 等比例短边充满
 - VCSVideoRenderContentModeScaleToFill: 拉伸铺满
 - VCSVideoRenderContentModeScaleAspectFit: 等比例长边充满
*/
typedef NS_ENUM(NSInteger, VCSVideoRenderContentMode) {
    
    VCSVideoRenderContentModeScaleAspectFill = 0,
    VCSVideoRenderContentModeScaleToFill = 1,
    VCSVideoRenderContentModeScaleAspectFit = 2,
};

#pragma mark - VCSVideoRender
@interface VCSVideoRender : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedInstance instead")));
- (instancetype)init __attribute__((unavailable("Use +sharedInstance instead")));

#pragma mark - ------------ Core Service ------------

/// 渲染组件启用状态
@property (nonatomic, assign, readonly) BOOL moduleEnabled;
/// 美颜功能启用状态
@property (nonatomic, assign, readonly) BOOL beautyEnabled;
/// 预览模块启用状态
@property (nonatomic, assign, readonly) BOOL displayEnabled;

/// 磨皮等级，取值范围 0.0-1.0，默认0.5
@property (nonatomic, assign, readonly) float blurLevel;
/// 美白等级，取值范围 0.0-1.0，默认值0.3
@property (nonatomic, assign, readonly) float whiteLevel;
/// 红润等级，取值范围 0.0-1.0，默认值0.3
@property (nonatomic, assign, readonly) float redLevel;
/// 锐化等级，取值范围 0.0-1.0，默认值0.3
@property (nonatomic, assign, readonly) float sharpenLevel;
/// 滤镜等级，取值范围 0.0-1.0，默认值0.8
@property (nonatomic, assign, readonly) float filterLevel;
/// 滤镜效果，默认值为 “origin” ，origin即为使用原图效果
@property (nonatomic, strong, readonly) NSString *filterName;

#pragma mark 获取视频渲染实例
/// 获取视频渲染实例
+ (VCSVideoRender *)sharedInstance;

#pragma mark 装载视频渲染组件
/// 装载视频渲染组件
/// @param authData 密钥
/// @param authDataSize 密钥长度
/// @param logLevel 日志等级
- (VCSError)installRenderModule:(char *)authData authDataSize:(int)authDataSize logLevel:(VCSLogLevel)logLevel;

#pragma mark 卸载视频渲染组件
/// 卸载视频渲染组件
- (void)uninstallRenderModule;

#pragma mark 美颜功能开关
/// 美颜功能开关
/// @param enabled YES-开启美颜 NO-关闭美颜
- (VCSError)enabledBeauty:(BOOL)enabled;

#pragma mark 磨皮等级
/// 磨皮等级
/// @param blurLevel 磨皮等级，取值范围 0.0-1.0，默认0.5
- (void)setBlurLevel:(float)blurLevel;

#pragma mark 美白等级
/// 美白等级
/// @param whiteLevel 美白等级，取值范围 0.0-1.0，默认值0.3
- (void)setWhiteLevel:(float)whiteLevel;

#pragma mark 红润等级
/// 红润等级
/// @param redLevel 红润等级，取值范围 0.0-1.0，默认值0.3
- (void)setRedLevel:(float)redLevel;

#pragma mark 锐化等级
/// 锐化等级
/// @param sharpenLevel 锐化等级，取值范围 0.0-1.0，默认值0.3
- (void)setSharpenLevel:(float)sharpenLevel;

#pragma mark 滤镜等级
/// 滤镜等级
/// @param filterLevel 滤镜等级，取值范围 0.0-1.0，默认值0.8
- (void)setFilterLevel:(float)filterLevel;

#pragma mark 滤镜效果
/// 滤镜效果
/// @param filterName 滤镜效果，默认值为 “origin” ，origin即为使用原图效果
- (void)setFilterName:(NSString *)filterName;

#pragma mark 渲染视频数据
/// 渲染视频数据
/// @param pixelBuffer 原数据
- (CVPixelBufferRef)renderWithInput:(CVPixelBufferRef)pixelBuffer;


#pragma mark - ------------ 额外扩展方法 ------------

#pragma mark 装载渲染本地预览
/// 装载渲染本地预览
/// @param superView 父类视图
/// @param frame 预览布局
- (void)installLocalDisplayViewReady:(UIView *)superView frame:(CGRect)frame;

#pragma mark 开启预览
/// 开启预览
- (void)startPreview;

#pragma mark 停止预览
/// 停止预览
- (void)stopPreview;

#pragma mark 修改预览分辨率
/// 修改预览分辨率
/// @param sessionPreset 分辨率
- (BOOL)changeSessionPreset:(AVCaptureSessionPreset)sessionPreset;

#pragma mark 卸载渲染本地预览
/// 卸载渲染本地预览
- (void)uninstallLocalDisplay;

#pragma mark 更新渲染填充模式
/// 更新渲染填充模式
/// @param contentMode 填充模式
- (void)renewDisplayWithContentMode:(VCSVideoRenderContentMode)contentMode;

#pragma mark 更新渲染组件布局
/// 更新渲染组件布局
/// @param frame Frame
- (void)renewDisplayWithFrame:(CGRect)frame;

#pragma mark 切换渲染摄像头
/// 切换渲染摄像头
- (void)changeCameraDevice;

@end

NS_ASSUME_NONNULL_END
