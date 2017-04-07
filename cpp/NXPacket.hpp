//
//  NXPacket.hpp
//  NXFramework
//
//  Created by heart on 2/7/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#ifndef NXPacket_hpp
#define NXPacket_hpp

#include <stdio.h>
#include <string>
#include "NXMacro.h"
#include "core/Dictionary.h"

#define COMMAND_CALL_METHOD "callMethod"
#define TO_NATIVE 0
#define TO_CPP 1

BEGIN_NS_NX

class NXPacket{
    
private:
    Dictionary* extra;
    
public:
    NXPacket();
    static NXPacket* create();
    std::string command;
    Array *path;
    
    void setExtra(Dictionary* dict);
    
    Dictionary* getExtra();
    std::string getStringExtra(std::string key, std::string defaultValue);
    int getIntExtra(std::string key, int defaultValue);
    
    int destination;
    
};

END_NS_NX

#endif /* NXPacket_hpp */
