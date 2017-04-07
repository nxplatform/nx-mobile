//
//  RouteNode.swift
//  NXFramework
//
//  Created by heart on 2/7/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

import UIKit

@objc
public protocol RouteNode{
    
    var id:String?{get set}
    var childs:Array<RouteNode>?{get set}
    var parentNode:RouteNode?{get set}
    var rootNode:RouteNode?{get set}
    
    func isMyPacket(packet:Packet)->Bool
    func onReceivePacket(packet:Packet)
    
    func sendToCPP(packet:Packet)
    
    
    
}
