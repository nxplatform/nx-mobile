//
//  Dictionary.cpp
//  nx
//
//  Created by heart on 10/24/2559 BE.
//  Copyright © 2559 3dsinteractive.com. All rights reserved.
//

#include <stdio.h>
#include "Dictionary.h"
#include "Integer.h"
#include "NXString.h"
#include <boost/foreach.hpp>
#include <json.hpp>

USING_NX
using namespace std;

//TODO: ทำ Memory Management ใน Dict ด้วย แล้วก็อย่าลืมว่า ถ้า Set ทับด้วย Object อาจต้อง release ตัวเก่า หากไม่ใช่ Object เดิม
Dictionary::Dictionary(){
   
}

Dictionary::~Dictionary(){
    hashmap.clear();
}

Dictionary* Dictionary::set(const string &key,int val){
    hashmap[key] = Integer::create(val);
    return this;
}

Dictionary* Dictionary::set(const string &key,string val){
    hashmap[key] = String::create(val);
    return this;
}

Dictionary* Dictionary::set(const string &key,Object* val){
    hashmap[key] = val;
    return this;
}


Object* Dictionary::get(const string &key){
    if( hashmap.find(key) == hashmap.end() ){
        return NULL;
    }
    return hashmap[key];
}

void Dictionary::remove(string key){
    hashmap.erase(key);
}


int Dictionary::count(){
    return (int)hashmap.size();
}

bool Dictionary::isEmpty(){
    return hashmap.empty();
}

Array* Dictionary::getKeyTable(){
    Array *list = Array::create();
    
    BOOST_FOREACH(map::value_type i, hashmap) {
        string key_name = i.first;
        list->push( String::create(key_name) );
    }
    return list;
}

Dictionary* Dictionary::create(){
    return new Dictionary();
}

string Dictionary::toString(){
    
    nlohmann::json j;
    
    BOOST_FOREACH(map::value_type i, hashmap) {
        string keyName = i.first;
        Object *object = i.second;
        if( dynamic_cast<Integer*>(object) != NULL ){
            Integer *it = (Integer*)object;
            j[keyName] = it->getInt();
        }else{
            j[keyName] = object->toString();
        }
    }
    
    return j.dump();
}
