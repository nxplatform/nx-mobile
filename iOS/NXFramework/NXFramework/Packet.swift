//
//  Packet.swift
//  NXFramework
//
//  Created by heart on 2/7/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

import UIKit



@objc
public class Packet: NSObject {
    
    public enum Command:String {
        case CallMethod = "callMethod"
        case Unknow = "unknow"
    }
    
    public override init(){}
    
    public var command:Command?
    
    public var extra:Dictionary<String,Any>?
    
    public static let toNative:Int = 0
    public static let toCPP:Int = 1
    
    public var destination:Int = -1
    
    public var path = Array<String>()
    
    public func getStringExtra(key:String, defaultValue:String)->String{
        
        if let x = extra{
            if let v = x[key]{
                if v is String{
                    return v as! String
                }
            }
        }
        return defaultValue
    }
    
    public func getIntExtra(key:String, defaultValue:Int)->Int{
        if let x = extra{
            if let v = x[key]{
                if v is Int{
                    return v as! Int
                }
            }
        }
        return defaultValue
    }
    
    public func getCommandName()->String{
        return command!.rawValue
    }
    
    public func setCommandByName(_ cmdName:String){
        if let c = Command.init(rawValue:cmdName ) {
            command = c
            return
        }
        print("WARNING!! : you set '\(cmdName)' unknow command to setCommandByName")
        command = .Unknow
    }
    
}
