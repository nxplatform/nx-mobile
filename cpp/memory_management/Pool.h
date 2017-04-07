//
//  Pool.h
//  nx
//
//  Created by heart on 11/7/2559 BE.
//  Copyright © 2559 3dsinteractive.com. All rights reserved.
//

#ifndef Pool_h
#define Pool_h

#include "NXMacro.h"
#include "Array.h"
#include "core/Object.h"

#define AUTO_RELEASE_POOL Pool::openNewPool();
#define POOL_DRAIN Pool::drainCurrentPool();

BEGIN_NS_NX

class Pool : public Object{
    
private:
    typedef Array ObjectPool;
    typedef Array PoolStack;
    
    static Pool* getInstance();
    PoolStack* poolStack;
    
public:
    Pool();
    static void openNewPool();
    static void drainCurrentPool();
    static void putToCurrentPool(Object *obj);
    
};


END_NS_NX

#endif /* Pool_h */
