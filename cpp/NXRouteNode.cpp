//
//  NXRouteNode.cpp
//  NXFramework
//
//  Created by heart on 2/7/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#include "NXRouteNode.hpp"
#include "core/NXString.h"
#include "Log.h"

USING_NX

NXRouteNode::NXRouteNode():
    childs(nullptr),
    parentNode(nullptr),
    rootNode(nullptr),
    id("NXRouteNode"){
    
        childs = new Vector<NXRouteNode*>();
}

void NXRouteNode::onReceivePacket(NXPacket* packet){
    
}

std::string NXRouteNode::getID(){
    return id;
}

void NXRouteNode::setID(std::string uid){
    id = uid;
}

void NXRouteNode::addNode(NXRouteNode* node){
    childs->push(node);
}

void NXRouteNode::removeNode(NXRouteNode* node){
    for(int i=0;i<childs->count(); i++){
        NXRouteNode* n = childs->get(i);
        if(n == node){
            //childs->remove(i);
        }
    }
}

bool NXRouteNode::isMyPacket(NXPacket *packet){
    if(packet->path->count() != 1){
        return false;
    }
    if( packet->path->last()->toString() == getID() ){
        return true;
    }
    
    return false;
}

void NXRouteNode::sendToNative(NXPacket *packet){
    packet->path->push(String::create( getID() ));
    packet->destination = TO_NATIVE;
    this->parentNode->sendToNative(packet);
}






