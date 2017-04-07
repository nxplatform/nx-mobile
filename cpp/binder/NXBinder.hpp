//
//  NXBinder.hpp
//  NXFramework
//
//  Created by heart on 2/7/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#ifndef NXBinder_hpp
#define NXBinder_hpp

#include <stdio.h>
#include "NXMacro.h"
#include "core/Dictionary.h"
#include "binder/NXFactory.hpp"

BEGIN_NS_NX

class NXBinder{
    
public:
    NXBinder();
    static NXBinder* create();
    void bind(std::string tag, OnCreateFunction onCreate);
    NXFactory* getFactory(std::string name);
    
private:
    Dictionary *factoryTable;
    
};

END_NS_NX

#endif /* NXBinder_hpp */
