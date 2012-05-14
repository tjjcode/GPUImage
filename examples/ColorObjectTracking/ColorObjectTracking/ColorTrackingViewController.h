#import <UIKit/UIKit.h>
#import "GPUImage.h"

typedef enum { PASSTHROUGH_VIDEO, SIMPLE_THRESHOLDING, POSITION_THRESHOLDING, OBJECT_TRACKING} ColorTrackingDisplayMode;

@interface ColorTrackingViewController : UIViewController <GPUImageRawDataProcessor>
{
    CALayer *trackingDot;

    GPUImageVideoCamera *videoCamera;
    GPUImageFilter *thresholdFilter, *positionFilter;
    GPUImageRawData *positionRawData, *videoRawData;
    GPUImageView *filteredVideoView;
    
    ColorTrackingDisplayMode displayMode;
	
	BOOL shouldReplaceThresholdColor;
	CGPoint currentTouchPoint;
	GLfloat thresholdSensitivity;
	GLfloat thresholdColor[3];
}

- (void)configureVideoFiltering;
- (void)configureToolbar;
- (void)configureTrackingDot;

// Image processing
- (CGPoint)centroidFromTexture:(GLubyte *)pixels ofSize:(CGSize)textureSize;

@end
