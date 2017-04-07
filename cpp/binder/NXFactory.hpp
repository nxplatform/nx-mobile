//
//  NXFactory.hpp
//  NXFramework
//
//  Created by heart on 2/7/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#ifndef NXFactory_hpp
#define NXFactory_hpp


#include <stdio.h>
#include "NXMacro.h"
#include "core/Object.h"
#include <functional>

BEGIN_NS_NX

typedef std::function< Object*() > OnCreateFunction;

class NXFactory:public Object{
    
public:
    static NXFactory* create(OnCreateFunction func);
    Object* createObject();
    void setOnCreate(OnCreateFunction func);
    
    
};

END_NS_NX


#endif /* NXFactory_hpp */
