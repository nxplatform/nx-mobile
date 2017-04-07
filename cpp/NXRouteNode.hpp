//
//  NXRouteNode.hpp
//  NXFramework
//
//  Created by heart on 2/7/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#ifndef NXRouteNode_hpp
#define NXRouteNode_hpp

#include <stdio.h>
#include "NXPacket.hpp"
#include "core/Object.h"
#include <string>
#include "core/Vector.hpp"

BEGIN_NS_NX

class NXRouteNode{
    
public:
    NXRouteNode();
    std::string  id;
    
    Vector<NXRouteNode*>* childs;
    
    NXRouteNode* parentNode;
    NXRouteNode* rootNode;
    virtual std::string getID();
    virtual void setID(std::string uid);
    
    virtual void addNode(NXRouteNode* node);
    virtual void removeNode(NXRouteNode* node);
    
    virtual void onReceivePacket(NXPacket* packet);
    bool isMyPacket(NXPacket *packet);
  
    virtual void sendToNative(NXPacket *packet);
    
};

END_NS_NX

#endif /* RouteNode_hpp */
