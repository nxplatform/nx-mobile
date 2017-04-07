//
//  Object.hpp
//  nx
//
//  Created by heart on 10/20/2559 BE.
//  Copyright © 2559 3dsinteractive.com. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include <string>
#include "NXMacro.h"

#define MANUAL_RETAIN(obj) obj->retain();
#define MANUAL_RELEASE(obj) obj->release();

BEGIN_NS_NX
using namespace std;

class Object{
private:
    int retainCount;
    
public:
    virtual string toString();
    
    Object();
    void retain();
    void release();
    void releaseAndDelete();
    void autoRelease();
    int getRetainCount();
    
};
END_NS_NX

#endif /* Object_hpp */
