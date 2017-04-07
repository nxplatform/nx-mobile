//
//  NXApplication.cpp
//  NXFramework
//
//  Created by heart on 2/6/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#include "NXApplication.hpp"
#include "Log.h"
#include "bridge/NXBridge.hpp"
#include "NXString.h"

USING_NX

void NXApplication::start(){
    windowBinder = NXBinder::create();
    onWindowBinding(windowBinder);
    onStart();
}

NXApplication::NXApplication():viewCount(0),windowList(Array::create()){
    setID("NXApplication");
}

void  NXApplication::applicationWillResignActive(){
    
}
void  NXApplication::applicationDidEnterBackground(){
    
}
void  NXApplication::applicationWillEnterForeground(){
    
}
void  NXApplication::applicationDidBecomeActive(){
    
}
void NXApplication::onStart(){
    
}

void  NXApplication::onWindowBinding(NXBinder *binder){
    
}

void NXApplication::openWindow(std::string windowName){
    NXFactory* factory = windowBinder->getFactory(windowName);
    if(factory != nullptr){
        
        Window* window =  (Window*)factory->createObject();
        window->setID( generateID() );
        window->rootNode = this;
        window->parentNode = this;
        childs->push(window);
        
        Dictionary *extra = Dictionary::create();
        extra->set("methodName", "openWindow");
        extra->set("windowID",window->getID() );
        
        NXPacket *packet = NXPacket::create();
        packet->command = COMMAND_CALL_METHOD;
        packet->setExtra(extra);
        packet->destination = TO_NATIVE;
        packet->path->push( String::create(getID()) );
        
        NXBridge::sharedInstance()->sendToNative(packet);
        
    }
   
}

Window* NXApplication::findWindowFromID(std::string windowid){
    for(int i=0; i<childs->count();i++){
        NXRouteNode *node = (NXRouteNode*)childs->get(i);
        if(windowid == node->getID() ){
            return (Window*)node;
        }
    }
    return nullptr;
}

std::string NXApplication::generateID(){
    std::string genID("window"+std::to_string(viewCount));
    viewCount++;
    return genID;
}

void NXApplication::sendToNative(NXPacket *packet){
    packet->path->push( String::create(getID()) );
    NXBridge::sharedInstance()->sendToNative(packet);
}
