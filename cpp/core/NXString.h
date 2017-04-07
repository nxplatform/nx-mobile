//
//  String.hpp
//  nx
//
//  Created by heart on 10/24/2559 BE.
//  Copyright © 2559 3dsinteractive.com. All rights reserved.
//

#ifndef String_hpp
#define String_hpp

#include <stdio.h>
#include "NXMacro.h"
#include "Object.h"

using namespace std;

BEGIN_NS_NX

class String : public Object{
    
//private:
    
public:
    string value;

    String();
    ~String();
    
    String* set(string v);
   
    static String* create();
    static String* create(string v);
  //  static String* createWithFormat();
    
    int toInt();
    float toFloat();
    double toDouble();
    
    const char* toCString();
    virtual string toString();
    
    
    String* operator=(string v);
    String* operator=(String* v);
    
    String* operator+(string v);
    String* operator+(String* v);
    
    String* operator+=(string v);
    String* operator+=(String* v);
    
};

END_NS_NX

#endif /* String_hpp */

