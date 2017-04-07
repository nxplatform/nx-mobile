//
//  NXBridge.cpp
//  NXFramework
//
//  Created by heart on 2/8/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#include "NXBridge.hpp"

USING_NX

NXBridge::NXBridge():onSendToNative(nullptr){

}

NXBridge* NXBridge::sharedInstance(){
    static NXBridge* instance;
    if(instance == nullptr){
        instance = NXBridge::create();
    }
    return instance;
}

NXBridge* NXBridge::create(){
    NXBridge* bridge = new NXBridge();
    return bridge;
}

void NXBridge::sendToNative(NXPacket* packet){
    onSendToNative(packet);
}
void NXBridge::setOnSendToNative(OnSendToNativeFunction func){
    onSendToNative = func;
}


