//
//  Dictionary.hpp
//  nx
//
//  Created by heart on 10/21/2559 BE.
//  Copyright © 2559 3dsinteractive.com. All rights reserved.
//

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <stdio.h>
#include <iostream>
#include "NXMacro.h"
#include "Object.h"
#include "core/Array.h"

#include <boost/unordered_map.hpp>

BEGIN_NS_NX

using namespace boost;

class Dictionary : public Object{
    

    
public:
    
    typedef boost::unordered_map<std::string, Object* > map;
    map hashmap;
    
    Dictionary();
    ~Dictionary();
    
    Dictionary* set(const string &key,Object* val);
    
    Dictionary* set(const string &key,int val);
    Dictionary* set(const string &key,string val);
    
    Object* get(const string &key);
    void remove(string key);
    int count();
    bool isEmpty();
    
    Array *getKeyTable();
    
    static Dictionary* create();
    
    virtual string toString();
    

};



END_NS_NX


#endif /* Dictionary_hpp */
