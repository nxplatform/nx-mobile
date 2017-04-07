//
//  NXFactory.cpp
//  NXFramework
//
//  Created by heart on 2/7/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

#include "NXFactory.hpp"

USING_NX

OnCreateFunction onCreate;

void NXFactory::setOnCreate(OnCreateFunction func ){
    onCreate = func;
}

NXFactory* NXFactory::create(OnCreateFunction func){
    NXFactory *factory = new NXFactory();
    factory->setOnCreate(func);
    return factory;
}

Object* NXFactory::createObject(){
    return onCreate();
}
