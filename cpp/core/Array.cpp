//
//  Array.cpp
//  nx
//
//  Created by heart on 11/8/2559 BE.
//  Copyright © 2559 3dsinteractive.com. All rights reserved.
//

#include <stdio.h>
#include "core/Array.h"

USING_NX

Array::Array(){
    
}

Array::~Array(){
    vec.clear();
}

Array* Array::create(){
    return new Array();
}

void Array::push(Object* obj){
    obj->retain();
    vec.push_back(obj);
}
int Array::count(){
    return (int)vec.size();
}

Object* Array::get(uint i){
    return vec[i];
}

Object* Array::pop(){
    Object* obj = vec.back();
    obj->release();
    vec.pop_back();
    return obj;
}

bool Array::isEmpty(){
    return vec.empty();
}

Object* Array::last(){
    return get(count()-1);
}
Object* Array::first(){
    return get(0);
}

void Array::remove(int position){
    Object* obj = vec[position];
    obj->release();
    vec.erase(vec.begin() + position);
}
