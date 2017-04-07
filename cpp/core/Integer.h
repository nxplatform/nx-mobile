//
//  Integer.hpp
//  nx
//
//  Created by heart on 10/24/2559 BE.
//  Copyright © 2559 3dsinteractive.com. All rights reserved.
//

#ifndef Integer_hpp
#define Integer_hpp

#include <stdio.h>
#include "NXMacro.h"
#include "Object.h"

BEGIN_NS_NX

class Integer : public Object{
private:
    int value;
    
public:
    Integer();
    ~Integer();
    
    static Integer* create();
    static Integer* create(int v);
    static Integer* createFromString(const string &str);
    Integer* set(int v);
    int getInt();
    virtual string toString();
    
    Integer* operator=(int v);
    Integer* operator=(Integer* v);
    
    Integer* operator+(int v);
    Integer* operator+(Integer* v);
    string operator+(string v);
    
    Integer* operator-(int v);
    Integer* operator-(Integer* v);
    
    Integer* operator*(int v);
    Integer* operator*(Integer* v);
    
    
    Integer* operator/(int v);
    Integer* operator/(Integer* v);
    
    Integer* operator++();
    
    Integer* operator--();
    
    Integer* operator+=(int v);
    Integer* operator+=(Integer* v);
    
    Integer* operator-=(int v);
    Integer* operator-=(Integer* v);

    Integer* operator*=(int v);
    Integer* operator*=(Integer* v);

    Integer* operator/=(int v);
    Integer* operator/=(Integer* v);

    
};
END_NS_NX

#endif /* Integer_hpp */
