//
//  ATInteractionRatingDialogController.m
//  ApptentiveConnect
//
//  Created by Peter Kamb on 3/3/14.
//  Copyright (c) 2014 Apptentive, Inc. All rights reserved.
//

#import "ATInteractionRatingDialogController.h"
#import "ATInteraction.h"
#import "ATBackend.h"
#import "ATConnect_Private.h"
#import "ATAppRatingMetrics.h"

@implementation ATInteractionRatingDialogController

- (id)initWithInteraction:(ATInteraction *)interaction {
	NSAssert([interaction.type isEqualToString:@"RatingDialog"], @"Attempted to load a Rating Dialog with an interaction of type: %@", interaction.type);
	self = [super init];
	if (self != nil) {
		_interaction = interaction;
	}
	return self;
}

- (void)showRatingDialogFromViewController:(UIViewController *)viewController {
	self.viewController = viewController;
	
	//TODO: title, etc., should come from interaction

	NSString *title = ATLocalizedString(@"Thank You", @"Rate app title.");
	NSString *message = [NSString stringWithFormat:ATLocalizedString(@"We're so happy to hear that you love %@! It'd be really helpful if you rated us. Thanks so much for spending some time with us.", @"Rate app message. Parameter is app name."), [[ATBackend sharedBackend] appName]];
	NSString *rateAppTitle = [NSString stringWithFormat:ATLocalizedString(@"Rate %@", @"Rate app button title"), [[ATBackend sharedBackend] appName]];
	NSString *noThanksTitle = ATLocalizedString(@"No Thanks", @"cancel title for app rating dialog");
	NSString *remindMeTitle = ATLocalizedString(@"Remind Me Later", @"Remind me later button title");
	
	if (!self.ratingDialog) {
		self.ratingDialog = [[UIAlertView alloc] initWithTitle:title message:message delegate:self cancelButtonTitle:noThanksTitle otherButtonTitles:rateAppTitle, remindMeTitle, nil];
		[self.ratingDialog show];
	}
	
	[[NSNotificationCenter defaultCenter] postNotificationName:ATAppRatingDidPromptForRatingNotification object:nil];
	//[self setRatingDialogWasShown];
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
	if (alertView == self.ratingDialog) {
		[self.ratingDialog release], self.ratingDialog = nil;
		if (buttonIndex == 1) { // rate
			[self postNotification:ATAppRatingDidClickRatingButtonNotification forButton:ATAppRatingButtonTypeRateApp];
			//[self userAgreedToRateApp];
		} else if (buttonIndex == 2) { // remind later
			[self postNotification:ATAppRatingDidClickRatingButtonNotification forButton:ATAppRatingButtonTypeRemind];
			//[self setRatingDialogWasShown];
		} else if (buttonIndex == 0) { // no thanks
			[self postNotification:ATAppRatingDidClickRatingButtonNotification forButton:ATAppRatingButtonTypeNo];
			//[self setDeclinedToRateThisVersion];
		}
		self.viewController = nil;
	}
}

- (void)postNotification:(NSString *)name forButton:(int)button {
	NSDictionary *userInfo = @{ATAppRatingButtonTypeKey: @(button)};
	[[NSNotificationCenter defaultCenter] postNotificationName:name object:self userInfo:userInfo];
}

@end
