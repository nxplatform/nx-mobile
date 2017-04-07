//
//  Application.hpp
//  nxtester
//
//  Created by heart on 2/7/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#ifndef Application_hpp
#define Application_hpp

#include <stdio.h>
#include "NXApplication.hpp"
#include "NXMacro.h"

USING_NX

class Application:public NXApplication{
    
public:
    Application();
    static Application* create();
    
    virtual void  applicationWillResignActive();
    virtual void  applicationDidEnterBackground();
    virtual void  applicationWillEnterForeground();
    virtual void  applicationDidBecomeActive();
    
    virtual void onReceivePacket(NXPacket* packet);
    virtual bool isMyPacket(NXPacket* packet);
    
    virtual void onStart();
    virtual void onWindowBinding(NXBinder *binder);
    
    virtual void sendToNative(NXPacket *packet);
};

#endif /* Application_hpp */
