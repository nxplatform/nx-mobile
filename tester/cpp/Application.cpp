//
//  Application.cpp
//  nxtester
//
//  Created by heart on 2/7/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#include "Application.hpp"
#include "Log.h"
#include "core/Object.h"
#include "HomeWindow.hpp"
#include "core/NXString.h"


Application::Application(){
    setID("Application");
}

Application* Application::create(){
    Application *app = new Application();
    return app;
}

void Application::onStart(){
    openWindow("home");
}

void Application::onWindowBinding(NXBinder *binder){
    
    binder->bind("home", [](){
        return HomeWindow::create();
    } );
    
}


void Application::onReceivePacket(NXPacket* packet){
    
    //Log::logPacket(packet);
    
    if(isMyPacket(packet)){
        if( packet->command == COMMAND_CALL_METHOD ){
            
            std::string methodName = packet->getStringExtra("methodName", "");

            if( methodName == "applicationWillResignActive"){
                applicationWillResignActive();
            }else if(methodName == "applicationDidEnterBackground"){
                applicationDidEnterBackground();
            }else if(methodName == "applicationWillEnterForeground"){
                applicationWillEnterForeground();
            }else if(methodName == "applicationDidBecomeActive"){
                applicationDidBecomeActive();
            }
            
        }
    }else{
        packet->path->remove( packet->path->count()-1 );

        int last_id = packet->path->count()-1;
        if(last_id<0){
            last_id = 0;
        }
        
        std::string targetID = packet->path->last()->toString();
        
        Window* window = findWindowFromID(targetID);
        if( window != nullptr ){
            window->onReceivePacket(packet);
        }
    }
}

void Application::applicationWillResignActive(){
    
}
void  Application::applicationDidEnterBackground(){
    
}
void  Application::applicationWillEnterForeground(){
    
}
void  Application::applicationDidBecomeActive(){
    
}

bool Application::isMyPacket(NXPacket* packet){
    
    if(packet->path->count() != 1){
        return false;
    }
    
    String *receiver = (String*)packet->path->last();
    
    if( receiver->toString() == getID() ){
        return true;
    }
    
    return false;
}

void Application::sendToNative(NXPacket *packet){
    NXApplication::sendToNative(packet);
}
