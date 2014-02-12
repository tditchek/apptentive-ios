//
//  ATInteractionUsageData.h
//  ApptentiveConnect
//
//  Created by Peter Kamb on 10/14/13.
//  Copyright (c) 2013 Apptentive, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATInteraction.h"

@interface ATInteractionUsageData : NSObject

@property (nonatomic, retain) ATInteraction *interaction;
@property (nonatomic, retain) NSNumber *timeSinceInstallTotal;
@property (nonatomic, retain) NSNumber *timeSinceInstallVersion;
@property (nonatomic, retain) NSNumber *timeSinceInstallBuild;
@property (nonatomic, retain) NSString *applicationVersion;
@property (nonatomic, retain) NSString *applicationBuild;
@property (nonatomic, retain) NSNumber *isUpdateVersion;
@property (nonatomic, retain) NSNumber *isUpdateBuild;
@property (nonatomic, retain) NSDictionary *codePointInvokesTotal;
@property (nonatomic, retain) NSDictionary *codePointInvokesVersion;
@property (nonatomic, retain) NSDictionary *codePointInvokesTimeAgo;
@property (nonatomic, retain) NSDictionary *interactionInvokesTotal;
@property (nonatomic, retain) NSDictionary *interactionInvokesVersion;
@property (nonatomic, retain) NSDictionary *interactionInvokesTimeAgo;

- (id)initWithInteraction:(ATInteraction *)interaction;
+ (ATInteractionUsageData *)usageDataForInteraction:(ATInteraction *)interaction;
+ (ATInteractionUsageData *)usageDataForInteraction:(ATInteraction *)interaction
							  timeSinceInstallTotal:(NSNumber *)timeSinceInstallTotal
							timeSinceInstallVersion:(NSNumber *)timeSinceInstallVersion
							  timeSinceInstallBuild:(NSNumber *)timeSinceInstallBuild
								 applicationVersion:(NSString *)applicationVersion
								   applicationBuild:(NSString *)applicationBuild
									isUpdateVersion:(NSNumber *)isUpdateVersion
									  isUpdateBuild:(NSNumber *)isUpdateBuild
							  codePointInvokesTotal:(NSDictionary *)codePointInvokesTotal
							codePointInvokesVersion:(NSDictionary *)codePointInvokesVersion
							codePointInvokesTimeAgo:(NSDictionary *)codePointInvokesTimeAgo
							interactionInvokesTotal:(NSDictionary *)interactionInvokesTotal
						  interactionInvokesVersion:(NSDictionary *)interactionInvokesVersion
						  interactionInvokesTimeAgo:(NSDictionary *)interactionInvokesTimeAgo;

- (NSDictionary *)predicateEvaluationDictionary;

@end
