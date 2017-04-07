//
//  Array.h
//  nx
//
//  Created by heart on 10/23/2559 BE.
//  Copyright © 2559 3dsinteractive.com. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include <stdio.h>
#include <iostream>
#include "NXMacro.h"
#include "Object.h"
#include <vector>

BEGIN_NS_NX


class Array : public Object{
private :
    typedef vector<Object*> V;
    V vec;
    
public:
    Array();
    ~Array();
    static Array* create();
    void push(Object* obj);
    int count();
    Object* get(uint i);
    Object* pop();
    bool isEmpty();
    Object* last();
    Object* first();
    void remove(int position);
};

END_NS_NX

#endif /* Array_h */
