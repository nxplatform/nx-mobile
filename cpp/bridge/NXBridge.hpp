//
//  NXBridge.hpp
//  NXFramework
//
//  Created by heart on 2/8/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#ifndef NXBridge_hpp
#define NXBridge_hpp

#include <stdio.h>
#include "NXMacro.h"
#include "core/Object.h"
#include "NXPacket.hpp"
#include <functional>

BEGIN_NS_NX

class NXBridge:public Object{
    
public:
    NXBridge();
    typedef std::function< void(NXPacket* packet) > OnSendToNativeFunction;
    OnSendToNativeFunction onSendToNative;
    void sendToNative(NXPacket* packet);
    void setOnSendToNative(OnSendToNativeFunction func);
    
    static NXBridge* sharedInstance();
    static NXBridge* create();
    
};

END_NS_NX

#endif /* NXBridge_hpp */
