//
//  Pool.cpp
//  nx
//
//  Created by heart on 11/7/2559 BE.
//  Copyright © 2559 3dsinteractive.com. All rights reserved.
//

#include <stdio.h>
#include "memory_management/Pool.h"

USING_NX

Pool* Pool::getInstance(){
    static Pool *instance;
    if(instance == NULL){
        instance = new Pool();
    }
    return instance;
}

Pool::Pool():poolStack(NULL){
    poolStack = PoolStack::create();
}

void Pool::openNewPool(){
    ObjectPool *p = ObjectPool::create();
    Pool::getInstance()->poolStack->push(p);
}

void Pool::drainCurrentPool(){
    ObjectPool *topPool = (ObjectPool*)Pool::getInstance()->poolStack->last();
    for(int i=topPool->count()-1 ; i>=0; i-- ){
        topPool->get(i)->release();
    }
    Pool::getInstance()->poolStack->pop();
}

void Pool::putToCurrentPool(Object *obj){
    obj->retain();
   ObjectPool* pool = (ObjectPool*)Pool::getInstance()->poolStack->last();
    pool->push(obj);
}

