//
//  AppDelegate.swift
//  nxtester
//
//  Created by heart on 2/6/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

import UIKit
import NXFramework

@UIApplicationMain
@objc
class AppDelegate: UIResponder, UIApplicationDelegate, RouteNode {

    var window: UIWindow?
    
    var childs:Array<RouteNode>? = Array<RouteNode>()
    public var parentNode:RouteNode?
    public var rootNode:RouteNode?

    
    var navigationController:UINavigationController!
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        
        id = "Application"
        
        if let window = self.window{
            navigationController = UINavigationController()
            navigationController.navigationBar.isHidden = true
            window.rootViewController = navigationController
        }
        
        Bridge.sharedInstance().startNXApplication(self)
        
        return true
    }
    
    func openWindow(windowID:String){
        
        let w = ViewController();
        w.id = windowID
        w.parentNode = self
        w.rootNode = self
        childs?.append(w)
        
        navigationController.pushViewController(w, animated:true )
    }
    
    //---
    public var path: String?
    public var id: String?
    
    public func onReceivePacket(packet:Packet){

        if(isMyPacket(packet: packet)){
            
            if packet.command! == Packet.Command.CallMethod {
                let methodName = packet.getStringExtra(key:"methodName" , defaultValue:"")
                if methodName == "openWindow"{
                    let windowID = packet.getStringExtra(key:"windowID", defaultValue:"no value");
                    openWindow(windowID: windowID)
                }
            }
            
        }else{
            
            //Log.logPacket(packet)

            packet.path.remove(at:packet.path.count-1 )
            let targetID = packet.path.last;
            
            if let c = childs{
                for i in c{
                    let targetWindow = i as! ViewController
                    if targetWindow.id == targetID{
                        targetWindow.onReceivePacket(packet: packet)
                        break;
                    }
                    
                }
            }
            
        }
    }
    

    //---

    func applicationWillResignActive(_ application: UIApplication) {
        callCPPAppMethod("applicationWillResignActive")
    }

    func applicationDidEnterBackground(_ application: UIApplication) {
        callCPPAppMethod("applicationDidEnterBackground")
    }

    func applicationWillEnterForeground(_ application: UIApplication) {
        callCPPAppMethod("applicationWillEnterForeground")
    }

    func applicationDidBecomeActive(_ application: UIApplication) {
        callCPPAppMethod("applicationDidBecomeActive")
    }

    func isMyPacket(packet:Packet)->Bool{
        if(packet.path.count != 1){
            return false
        }
        let receiver = packet.path[0] as String;
        if(receiver == id!){
            return true
        }
        return false
    }
    
    func callCPPAppMethod(_ methodName:String){
        let packet = Packet()
        packet.command = .CallMethod
        packet.extra = ["methodName":methodName]
        sendToCPP(packet:packet )
    }
    
    public func sendToCPP(packet:Packet){
        packet.path.append(id!)
        packet.destination = Packet.toCPP
        Bridge.sharedInstance().send(toCPP:packet)
    }
}

