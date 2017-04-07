//
//  Log.hpp
//  nx-framework
//
//  Created by heart on 10/18/2559 BE.
//  Copyright © 2559 3dsinteractive.com. All rights reserved.
//

#ifndef Log_hpp
#define Log_hpp

#include <stdio.h>
#include <string>
#include "NXMacro.h"
#include "NXPacket.hpp"

#define LOG_DEBUG   0b001
#define LOG_WARN    0b010
#define LOG_ERROR   0b100
#define LOG_VERBOSE 0b111
#define LOG_NONE    0b000

using namespace std;

BEGIN_NS_NX

class Log{
    
public:
    Log();
    void static debug(const string &fmt, ...);
    void static warn(const string &fmt, ...);
    void static error(const string &fmt, ...);
    
    void static logPacket(NXPacket *p);
    
    int static setLogLevel(int flag);
    int logFlag;
    static Log *getInstance();
    
private:
    void printLog(char *fmt, ...);
    
    
};

END_NS_NX


#endif /* Log_hpp */
