//
//  Apptentive_Private.h
//  ApptentiveConnect
//
//  Created by Andrew Wooster on 1/20/13.
//  Copyright (c) 2013 Apptentive, Inc. All rights reserved.
//

#if NO_USE_FRAMEWORKS
#import "Apptentive.h"
#else
#import <Apptentive/Apptentive.h>
#endif

extern NSString *const ApptentiveCustomPersonDataChangedNotification;
extern NSString *const ApptentiveCustomDeviceDataChangedNotification;
extern NSString *const ApptentiveInteractionsDidUpdateNotification;
extern NSString *const ApptentiveConversationCreatedNotification;
extern NSString *const ApptentiveInteractionsShouldDismissNotification;

extern NSString *const ApptentiveCustomDeviceDataPreferenceKey;
extern NSString *const ApptentiveCustomPersonDataPreferenceKey;
extern NSString *const ApptentiveInteractionsShouldDismissAnimatedKey;

@class ApptentiveMessage, ApptentiveWebClient, ApptentiveBackend, ApptentiveEngagementBackend;


@interface Apptentive ()

+ (NSString *)supportDirectoryPath;
@property (readonly, nonatomic) NSDictionary *customPersonData;
@property (readonly, nonatomic) NSDictionary *customDeviceData;
- (NSDictionary *)integrationConfiguration;

@property (readonly, nonatomic) ApptentiveWebClient *webClient;
@property (readonly, nonatomic) ApptentiveBackend *backend;
@property (readonly, nonatomic) ApptentiveEngagementBackend *engagementBackend;

@property (copy, nonatomic) NSDictionary *pushUserInfo;
@property (strong, nonatomic) UIViewController *pushViewController;

@property (readonly, nonatomic) BOOL didAccessStyleSheet;
@property (readonly, nonatomic) NSString *distributionName;
@property (readonly, nonatomic) NSString *distributionVersion;

@property (strong, nonatomic) id<ApptentiveStyle> style;

/*!
 * Returns the NSBundle corresponding to the bundle containing Apptentive's
 * images, xibs, strings files, etc.
 */
+ (NSBundle *)resourceBundle;
+ (UIStoryboard *)storyboard;

- (void)showNotificationBannerForMessage:(ApptentiveMessage *)message;

+ (NSDictionary *)timestampObjectWithNumber:(NSNumber *)seconds;
+ (NSDictionary *)versionObjectWithVersion:(NSString *)version;
+ (NSDictionary *)timestampObjectWithDate:(NSDate *)date;

- (UIViewController *)viewControllerForInteractions;

@end

/*! Replacement for NSLocalizedString within ApptentiveConnect. Pulls
 localized strings out of the resource bundle. */
extern NSString *ApptentiveLocalizedString(NSString *key, NSString *comment);


@interface ApptentiveNavigationController (AboutView)

- (void)pushAboutApptentiveViewController;

@end
