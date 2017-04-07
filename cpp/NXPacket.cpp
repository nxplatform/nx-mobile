//
//  NXPacket.cpp
//  NXFramework
//
//  Created by heart on 2/7/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#include "NXPacket.hpp"
#include "core/Integer.h"

USING_NX

NXPacket::NXPacket():extra(nullptr),path(Array::create()){
    
}

NXPacket* NXPacket::create(){
    NXPacket* p = new NXPacket();
    return p;
}

void NXPacket::setExtra(Dictionary* dict){
    extra = dict;
}

Dictionary* NXPacket::getExtra(){
    return extra;
}
std::string NXPacket::getStringExtra(std::string key, std::string defaultValue){
    if(extra!=nullptr){
        Object *v = extra->get(key);
        if(v != NULL){
            return v->toString();
        }
    }
    return defaultValue;
}
int NXPacket::getIntExtra(std::string key, int defaultValue){
    if(extra!=nullptr){
        Object *v = extra->get(key);
        if(v != NULL){
            Integer* i = (Integer*)v;
            return i->getInt();
        }
    }
    return defaultValue;
}
