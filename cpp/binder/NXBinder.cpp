//
//  NXBinder.cpp
//  NXFramework
//
//  Created by heart on 2/7/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#include "NXBinder.hpp"

USING_NX


NXBinder::NXBinder(){
    factoryTable = Dictionary::create();
}

NXBinder* NXBinder::create(){
    NXBinder *binder = new NXBinder();
    return binder;
}


void NXBinder::bind(std::string tag, OnCreateFunction onCreate ){
    NXFactory* factory = NXFactory::create(onCreate);
    factoryTable->set(tag, factory);
}

NXFactory* NXBinder::getFactory(std::string name){
  return (NXFactory*)factoryTable->get(name);
}
