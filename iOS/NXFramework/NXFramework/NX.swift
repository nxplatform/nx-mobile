//
//  NX.swift
//  NXFramework
//
//  Created by heart on 2/6/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

import Foundation

public class NX{
    
    public static let  sharedInstance = NX()
    
    public init(){
        
    }
    
    public func startNXApplication(_ callback:(Void)->Void  ){
        callback()
    }
    
    public func registerProvidor(){
        
    }
    
    public func create(_ elementName:String )->NXObject?{
        
        var v:NXObject?
        
        if(elementName == "view"){
            v = NXView()
        }else if(elementName == "textview"){
            v = NXTextView()
        }else if(elementName == "imageview"){
            v = NXImageView()
        }
        
        
        return v
    }
    
}
