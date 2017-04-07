//
//  NXApplication.hpp
//  NXFramework
//
//  Created by heart on 2/6/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#ifndef NXApplication_hpp
#define NXApplication_hpp

#include <stdio.h>
#include "NXRouteNode.hpp"
#include "binder/NXBinder.hpp"
#include "views/Window.hpp"
BEGIN_NS_NX

class NXApplication:public NXRouteNode{
    
public:
    NXApplication();
    std::string id;
    
    virtual void start();
    
    virtual void  applicationWillResignActive();
    virtual void  applicationDidEnterBackground();
    virtual void  applicationWillEnterForeground();
    virtual void  applicationDidBecomeActive();
    virtual void  onStart();
    
    virtual void  onWindowBinding(NXBinder *binder);
    
    virtual void openWindow(std::string windowName);
    
    Window* findWindowFromID(std::string windowid);
    
    virtual void sendToNative(NXPacket *packet);
    
private:
    int viewCount;
    Array *windowList;
    NXBinder *windowBinder;
    std::string generateID();
    
};

END_NS_NX

#endif /* NXApplication_hpp */
