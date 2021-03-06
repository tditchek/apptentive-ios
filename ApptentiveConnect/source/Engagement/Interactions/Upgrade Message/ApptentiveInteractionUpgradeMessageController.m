//
//  ApptentiveInteractionUpgradeMessageController.m
//  ApptentiveConnect
//
//  Created by Frank Schmitt on 7/18/16.
//  Copyright © 2016 Apptentive, Inc. All rights reserved.
//

#import "ApptentiveInteractionUpgradeMessageController.h"
#import "ApptentiveInteractionUpgradeMessageViewController.h"
#import "Apptentive_Private.h"
#import "ApptentiveInteraction.h"

NSString *const ATInteractionUpgradeMessageEventLabelLaunch = @"launch";
NSString *const ATInteractionUpgradeMessageEventLabelDismiss = @"dismiss";


@implementation ApptentiveInteractionUpgradeMessageController

+ (void)load {
	[self registerInteractionControllerClass:self forType:@"UpgradeMessage"];
}

- (void)presentInteractionFromViewController:(UIViewController *)viewController {
	[super presentInteractionFromViewController:viewController];

	UINavigationController *navigationController = [[Apptentive storyboard] instantiateViewControllerWithIdentifier:@"UpgradeMessageNavigation"];
	ApptentiveInteractionUpgradeMessageViewController *result = (ApptentiveInteractionUpgradeMessageViewController *)navigationController.viewControllers.firstObject;

	result.upgradeMessageInteraction = self.interaction;

	// Add owning reference to self so we stick around until VC is dismissed. 
	result.interactionController = self;

	[viewController presentViewController:navigationController animated:YES completion:nil];

	[result.upgradeMessageInteraction engage:ATInteractionUpgradeMessageEventLabelLaunch fromViewController:viewController];
}

- (NSString *)programmaticDismissEventLabel {
	return ATInteractionUpgradeMessageEventLabelDismiss;
}

@end
