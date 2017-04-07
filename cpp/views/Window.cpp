//
//  Window.cpp
//  NXFramework
//
//  Created by heart on 2/8/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#include "Window.hpp"
#include "core/NXString.h"
USING_NX

void Window::onReceivePacket(NXPacket* packet){
    std::string command = packet->command;
    
    if(command == COMMAND_CALL_METHOD ){
        std::string methodName = packet->getStringExtra("methodName", "");
        if(methodName == "onLoad"){
            onLoad();
        }else if(methodName == "onAppear"){
            onAppear();
        }else if(methodName == "onDisappear"){
            onDisappear();
        }
    }
}

void Window::onLoad(){
    
}
void Window::onAppear(){
    
}
void Window::onDisappear(){
    
}

void Window::loadLayout(std::string file){
    Dictionary *extra = Dictionary::create();
    extra->set("file", file );
    extra->set("methodName","loadLayout");
    
    NXPacket *p = NXPacket::create();
    p->command = COMMAND_CALL_METHOD;
    p->setExtra(extra);
    
    sendToNative(p);
}


std::string Window::getID(){
    return NXRouteNode::getID();
}

void Window::setID(std::string uid){
    NXRouteNode::setID(uid);
}

