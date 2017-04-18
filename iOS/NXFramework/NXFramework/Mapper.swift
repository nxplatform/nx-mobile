//
//  Mapper.swift
//  NXFramework
//
//  Created by heart on 4/16/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

import Foundation

open class Mapper{
    
    init(tag:String , createFunc:@escaping (_ attrs:Dictionary<String, Any>)->NXObject ){
        self.tag = tag
        self.create = createFunc
    }
    
    var tag:String?
    var create:(_ attrs:Dictionary<String, Any>)->NXObject
}
