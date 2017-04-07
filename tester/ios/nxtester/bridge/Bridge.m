//
//  Bridge.m
//  NXFramework
//
//  Created by heart on 2/6/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#import "Bridge.h"
#import "CPPBridge.h"
#import "nxtester-Swift.h"

@implementation Bridge

AppDelegate *appDelegate;

+ (Bridge*)sharedInstance{
    static Bridge *instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[self alloc] init];
    });
    return instance;
}

-(void)startNXApplication:(id)app{
    appDelegate = (AppDelegate*)app;
    [[CPPBridge sharedInstance] startNXApplication];
}

-(void)sendToCPP:(Packet*)packet{
    [[CPPBridge sharedInstance] sendToCPP:packet];
}

-(void)sendToNative:(Packet*)packet{
    [appDelegate onReceivePacketWithPacket:packet];
}

@end
