//
//  HomeWindow.cpp
//  nxtester
//
//  Created by heart on 2/8/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#include "HomeWindow.hpp"
#include "Log.h"
#include "core/NXString.h"
#include "NXApplication.hpp"
#include "Application.hpp"

HomeWindow* HomeWindow::create(){
    HomeWindow* w = new HomeWindow();
    return w;
}

void HomeWindow::onLoad(){
    Log::debug("onLoad");
    loadLayout("views/HomeWindow.xml");
}
void HomeWindow::onAppear(){
    Log::debug("onAppear");
}
void HomeWindow::onDisappear(){
    Log::debug("onDisappear");
}


void HomeWindow::onReceivePacket(NXPacket* packet){
    Window::onReceivePacket(packet);
}


