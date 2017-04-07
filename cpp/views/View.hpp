//
//  View.hpp
//  NXFramework
//
//  Created by heart on 2/8/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#ifndef View_hpp
#define View_hpp

#include <stdio.h>
#include "NXMacro.h"
#include "core/Object.h"
#include "core/Dictionary.h"

BEGIN_NS_NX

class View:public Object{
    
public:
    void updateProperty(std::string propertyName, Dictionary *value);
    
    
};

END_NS_NX


#endif /* View_hpp */
