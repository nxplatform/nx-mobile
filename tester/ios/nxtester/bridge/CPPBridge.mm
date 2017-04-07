//
//  CPPBridge.m
//  NXFramework
//
//  Created by heart on 2/6/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#import "CPPBridge.h"
#import "Application.hpp"
#import "NXFramework/NXFramework-Swift.h"
#import "bridge/NXBridge.hpp"
#import "BridgeUtility.h"
#import "Bridge.h"

@implementation CPPBridge{
    nx::NXBridge::OnSendToNativeFunction callBack;
}

Application* application;

+ (CPPBridge*)sharedInstance{
    static CPPBridge *instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[self alloc] init];
    });
    return instance;
}

-(void)sendToCPP:(Packet*)packet{
    NXPacket *p = [BridgeUtility convertToCPPPacket:packet];
    application->onReceivePacket(p);
}

-(void)sendToNative:(Packet*)packet{
    [[Bridge sharedInstance] sendToNative:packet];
}

-(void)startNXApplication{
    
    callBack = [&,self](NXPacket* packet){
        Packet *p = [BridgeUtility convertToNativePacket:packet];
        [self sendToNative:p];
    };
    
    NXBridge::sharedInstance()->setOnSendToNative(callBack);
    
    application = Application::create();
    application->start();
}

@end
