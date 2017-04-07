//
//  Object.cpp
//  nx
//
//  Created by heart on 10/20/2559 BE.
//  Copyright © 2559 3dsinteractive.com. All rights reserved.
//

#include "Object.h"
#include <string>
#include "memory_management/Pool.h"

using namespace std;
USING_NX

string Object::toString(){
    return "Object";
}
Object::Object():retainCount(0){
    
}
void Object::retain(){
    ++retainCount;
}
void Object::release(){
    if(--retainCount <= 0){
        delete this;
    }
}
void Object::autoRelease(){
    Pool::putToCurrentPool(this);
    //retain();
}
int Object::getRetainCount(){
    return retainCount;
}
