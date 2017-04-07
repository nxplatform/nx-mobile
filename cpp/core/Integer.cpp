//
//  Integer.cpp
//  nx
//
//  Created by heart on 10/24/2559 BE.
//  Copyright © 2559 3dsinteractive.com. All rights reserved.
//

#include "core/Integer.h"

USING_NX

Integer::Integer():value(0){
    
}

Integer::~Integer(){
    
}


Integer* createFromString(const string &str){
    Integer *i = Integer::create();
    return i->set( stoi(str) );
}

Integer* Integer::create(){
    return new Integer();
}

Integer* Integer::create(int v){
    Integer *i = Integer::create();
    i->set(v);
    return i;
}

Integer* Integer::set(int v){
    value = v;
    return this;
}

int Integer::getInt(){
    return value;
}

Integer* Integer::operator=(int v){
    return set(v);
}

Integer* Integer::operator=(Integer* v){
    return operator=( v->getInt() );
}


Integer* Integer::operator+(int v){
    return Integer::create(getInt()+v);
}

Integer* Integer::operator+(Integer* v){
    return operator+(v->getInt());
}

string Integer::operator+(string v){
    return to_string( getInt() )+v;
}

Integer* Integer::operator-(int v){
    return Integer::create(getInt()-v);
}

Integer* Integer::operator-(Integer* v){
    return operator-(v->getInt());
}

Integer* Integer::operator*(int v){
    return Integer::create(getInt()*v);
}

Integer* Integer::operator*(Integer* v){
    return operator*(v->getInt());
}

Integer* Integer::operator/(int v){
    return Integer::create(getInt()/v);
}

Integer* Integer::operator/(Integer* v){
    return operator/(v->getInt());
}

Integer* Integer::operator++(){
    return set(getInt()+1);
}

Integer* Integer::operator--(){
    return set(getInt()-1);
}

Integer* Integer::operator+=(int v){
    return set(getInt()+v);
}
Integer* Integer::operator+=(Integer* v){
    return operator+=(v->getInt());
}

Integer* Integer::operator-=(int v){
    return set(getInt()-v);
}
Integer* Integer::operator-=(Integer* v){
    return operator-=(v->getInt());
}


Integer* Integer::operator*=(int v){
    return set(getInt()*v);
}
Integer* Integer::operator*=(Integer* v){
    return operator*=(v->getInt());
}


Integer* Integer::operator/=(int v){
    return set(getInt()/v);
}
Integer* Integer::operator/=(Integer* v){
    return operator/=(v->getInt());
}



string Integer::toString(){
    return to_string(getInt());
}




