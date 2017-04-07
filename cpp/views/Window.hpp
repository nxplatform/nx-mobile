//
//  Window.hpp
//  NXFramework
//
//  Created by heart on 2/8/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include <stdio.h>
#include "views/View.hpp"
#include "NXRouteNode.hpp"

BEGIN_NS_NX

class Window:public View,public NXRouteNode{
    
public:
    virtual void onLoad();
    virtual void onAppear();
    virtual void onDisappear();
    
    virtual void onReceivePacket(NXPacket* packet);
    
    virtual std::string getID();
    virtual void setID(std::string uid);
    
    void loadLayout(std::string file);
    
   // virtual void sendToNative(NXPacket* packet);
};


END_NS_NX

#endif /* Window_hpp */
