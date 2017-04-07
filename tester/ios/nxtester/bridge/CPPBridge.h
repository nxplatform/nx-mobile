//
//  CPPBridge.h
//  NXFramework
//
//  Created by heart on 2/6/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <NXFramework/NXFramework-Swift.h>


@interface CPPBridge : NSObject

+ (CPPBridge*)sharedInstance;

-(void)sendToCPP:(Packet*)packet;
-(void)sendToNative:(Packet*)packet;
-(void)startNXApplication;

@end
