//
//  Log.swift
//  NXFramework
//
//  Created by heart on 3/22/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

import Foundation

public class Log{
    
    public static func debug(_ msg:String){
        print("🐛🐛🐛🐛🐛🐛🐛 DEBUG 🐛🐛🐛🐛🐛🐛🐛")
        print(msg)
    }
    
    public static func warn(_ msg:String){
        print("😩😩😩😩😩😩😩 WARN 😩😩😩😩😩😩😩")
        print(msg)
    }
    
    public static func error(_ msg:String){
        print("💔💔💔💔💔💔💔 ERROR 💔💔💔💔💔💔💔")
        print(msg)
    }
    
    public static func logPacket(_ p:Packet){
        print("📦📦📦📦 Swift Packet Log 📦📦📦📦")
        print("command : \(p.command?.rawValue)")
        
        if(p.destination == Packet.toCPP ){
            print("destination : Send to CPP")
        }else if(p.destination == Packet.toNative){
            print("destination : Send to Native")
        }
        
        print("path : \(p.path)")
        print("extra : \(p.extra)")
        print("📦📦📦📦📦📦📦📦📦📦📦📦")
    }
    
    
}
