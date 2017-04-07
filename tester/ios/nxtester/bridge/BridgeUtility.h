//
//  BridgeUtility.h
//  nxtester
//
//  Created by heart on 2/8/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NXPacket.hpp"
#import "NXFramework/NXFramework-Swift.h"

@interface BridgeUtility : NSObject

+(Packet*)convertToNativePacket:(nx::NXPacket*)packet;
+(nx::NXPacket*)convertToCPPPacket:(Packet*)packet;

@end
