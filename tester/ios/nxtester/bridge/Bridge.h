//
//  Bridge.h
//  NXFramework
//
//  Created by heart on 2/6/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NXFramework/NXFramework-Swift.h>
#import <UIKit/UIKit.h>

@interface Bridge : NSObject

+ (Bridge*)sharedInstance;

-(void)sendToCPP:(Packet*)packet;
-(void)sendToNative:(Packet*)packet;
-(void)startNXApplication:(id)app;

@end
