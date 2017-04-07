//
//  Log.cpp
//  nx-framework
//
//  Created by heart on 10/18/2559 BE.
//  Copyright © 2559 3dsinteractive.com. All rights reserved.
//

#include "Log.h"
#include <stdarg.h>

#define PRINTF_WRAP_INLINE(tag) \
va_list args;\
fprintf( stderr, "\n\n"#tag"\n\n" );\
va_start( args, fmt );\
vfprintf( stderr, fmt.c_str(), args );\
va_end( args );\
fprintf( stderr, "\n\n" );\

USING_NX

void Log::debug(const string &fmt, ...){
    if( Log::getInstance()->logFlag & LOG_DEBUG ){
       PRINTF_WRAP_INLINE(🐛🐛🐛🐛🐛🐛🐛 DEBUG 🐛🐛🐛🐛🐛🐛🐛)
    }
}

void Log::warn(const string &fmt, ...){
    if( Log::getInstance()->logFlag & LOG_WARN ){
        PRINTF_WRAP_INLINE(😩😩😩😩😩😩😩 WARN 😩😩😩😩😩😩😩)
    }
}

void Log::error(const string &fmt, ...){
    if( Log::getInstance()->logFlag & LOG_ERROR ){
        PRINTF_WRAP_INLINE(💔💔💔💔💔💔💔 ERROR 💔💔💔💔💔💔💔)
    }
}

void Log::logPacket(NXPacket *p){
    printf("📦📦📦📦 C++ Packet Log 📦📦📦📦\n");
    
    printf("command : %s\n", p->command.c_str() );
    
    if(p->destination == TO_NATIVE){
        printf("destination : Send To Native\n" );
    }else if(p->destination == TO_CPP){
        printf("destination : Send To CPP\n" );
    }
    
    std::string path = "";
    for(int i=0; i< p->path->count() ; i++){
        path += p->path->get(i)->toString()+",";
    }
    
    printf("path : [%s]\n", path.c_str() );
    printf("extra : %s\n", p->getExtra()->toString().c_str() );
    
    printf("📦📦📦📦📦📦📦📦📦📦📦📦\n");
}

int Log::setLogLevel(int flag){
    Log::getInstance()->logFlag = flag;
    return Log::getInstance()->logFlag;
}
Log* Log::getInstance(){
    static Log *instance;
    if(instance == nullptr){
        instance = new Log();
    }
    return instance;
}

Log::Log():logFlag(LOG_VERBOSE){
    
}

