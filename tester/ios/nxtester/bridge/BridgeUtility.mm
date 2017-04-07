//
//  BridgeUtility.m
//  nxtester
//
//  Created by heart on 2/8/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#import "BridgeUtility.h"
#import "core/NXString.h"

@implementation BridgeUtility

using namespace nx;

+(Packet*)convertToNativePacket:(nx::NXPacket*)packet{
    
    Packet* p = [[Packet alloc] init];
    
    [p setCommandByName:[NSString stringWithUTF8String:packet->command.c_str()] ];
    
    Dictionary *extra = packet->getExtra();
    
    if(extra != nullptr ){
        Array *keys = extra->getKeyTable();
        
        NSMutableDictionary *extras = [NSMutableDictionary dictionary];
        
        for(int i =0; i<keys->count(); i++){
            Object *key = keys->get(i);
            Object *value = extra->get(key->toString());

            NSString *k = [NSString stringWithUTF8String:key->toString().c_str()];
            NSString *v = [NSString stringWithUTF8String:value->toString().c_str()];
            extras[k] = v;
        }
        
        p.extra = extras;
    }else{
        p.extra = [NSDictionary dictionary];
    }
    
    NSMutableArray *path = [NSMutableArray array];
    
    for(int i=0; i< packet->path->count() ; i++ ){
        NSString *pathString = [NSString stringWithUTF8String:packet->path->get(i)->toString().c_str()];
        [path addObject:pathString];
    }
    
    p.path = path;
    
    
    p.destination = packet->destination;
    return p;
}

+(nx::NXPacket*)convertToCPPPacket:(Packet*)packet{
    nx::NXPacket *p = new nx::NXPacket();
    
    NSString *command = [packet getCommandName];
    
    p->command = [command cStringUsingEncoding:NSUTF8StringEncoding];

    NSDictionary *extra = packet.extra;
    NSArray *keys = extra.allKeys;
    
    Dictionary *d = Dictionary::create();
    
    for(int i=0; i<keys.count; i++){
        NSString *key = keys[i];
        NSString *value = extra[key];
        
        std::string k = [key cStringUsingEncoding:NSUTF8StringEncoding];
        std::string v = [value cStringUsingEncoding:NSUTF8StringEncoding];

        d->set(k, v);
    }
    
    Array *path = Array::create();
    
    for(int i=0; i< packet.path.count ; i++ ){
        
        NSString *pathString = packet.path[i];
        std::string k = [pathString cStringUsingEncoding:NSUTF8StringEncoding];
        
        path->push( String::create(k) );
        
    }
    
    p->path = path;

    p->setExtra(d);
    p->destination = (int)packet.destination;
    
    return p;
}

@end
