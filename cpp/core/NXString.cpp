//
//  String.cpp
//  nx
//
//  Created by heart on 10/24/2559 BE.
//  Copyright © 2559 3dsinteractive.com. All rights reserved.
//


#include "core/NXString.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

//using namespace std;
USING_NX

#define kMaxStringLen (1024*100)

string String::toString(){
    return value;
}

const char* String::toCString(){
    return toString().c_str();
}

String* String::create(string v){
    String *s = String::create();
    s->set(v);
    return s;
}

String* String::create(){
    return new String();
}


/*
String* String::createWithFormat(const char* format, ...){
    
    string str;
    
    va_list arg_list;
    va_start(arg_list, format);
    
    // SUSv2 version doesn't work for buf NULL/size 0, so try printing
    // into a small buffer that avoids the double-rendering and alloca path too...
    char short_buf[256];
    const size_t needed = vsnprintf(short_buf, sizeof short_buf,
                                    format, arg_list) + 1;
    if (needed <= sizeof short_buf)
        str = short_buf;
    
    // need more space...
    
    // OPTION 1
   // std::string result(needed, ' ');
    //vsnprintf(result.data(), needed, format, arg_list);
    //str = result;  // RVO ensures this is cheap
   // OR
    // OPTION 2
    char* p = static_cast<char*>(alloca(needed)); // on stack
    vsnprintf(p, needed, format, arg_list);
    str = p;  // text copied into returned string
    
    printf("\n\n STR = \n\n %s \n\n" , str.c_str() );
    return String::create()->set( str );
}*/

String* String::set(string v){
    value = v;
    return this;
}

String::String():value(""){
    
}

String::~String(){
    
}

String* String::operator=(string v){
    return set(v);
}

String* String::operator=(String* v){
    return set(v->toString());
}


String* String::operator+(string v){
    return String::create(toString()+v);
}

String* String::operator+(String* v){
    return String::create(v->toString()+v->toString());
}

String* String::operator+=(string v){
    return set( toString()+v );
}

String* String::operator+=(String* v){
    return set( toString()+v->toString() );
}


int String::toInt(){
    return stoi(toString());
}

float String::toFloat(){
    return stof(toString());
}

double String::toDouble(){
    return stod(toString());
}


