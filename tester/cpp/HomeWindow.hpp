//
//  HomeWindow.hpp
//  nxtester
//
//  Created by heart on 2/8/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#ifndef HomeWindow_hpp
#define HomeWindow_hpp

#include <stdio.h>
#include "views/Window.hpp"

USING_NX

class HomeWindow:public Window{
    
public:
    static HomeWindow* create();
    virtual void onLoad();
    virtual void onAppear();
    virtual void onDisappear();
    
    virtual void onReceivePacket(NXPacket* packet);

};

#endif /* HomeWindow_hpp */
