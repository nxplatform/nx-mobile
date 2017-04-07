//
//  Vector.hpp
//  NXFramework
//
//  Created by heart on 2/17/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>
#include <iostream>
#include "NXMacro.h"
#include "Object.h"
#include <vector>

BEGIN_NS_NX


template <class A_Type> class Vector : public Object{
    private :
    typedef vector<A_Type> VectorType;
    VectorType vec;
    
public:
    
    template<typename T>
    static Vector<T> create(){
        return new Vector<T>();
    }
    
    ~Vector<A_Type>(){
        vec.clear();
    }
    
    void push(A_Type obj){
        vec.push_back(obj);
    }
    
    int count(){
        return (int)vec.size();
    }
    
    A_Type get(uint i){
        return vec[i];
    }
    
    A_Type pop(){
        A_Type obj = vec.back();
        vec.pop_back();
        return obj;
    }
    
    bool isEmpty(){
        return vec.empty();
    }
    
    A_Type last(){
        return get(count()-1);
    }
    
    A_Type first(){
        return get(0);
    }
};

END_NS_NX


#endif /* Vector_hpp */
