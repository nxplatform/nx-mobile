//
//  ViewController.swift
//  nxtester
//
//  Created by heart on 2/6/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//
import NXFramework
import UIKit
import AEXML

class ViewController: UIViewController ,RouteNode{

    var id:String?
    var childs:Array<RouteNode>? = Array<RouteNode>()
    public var parentNode:RouteNode?
    public var rootNode:RouteNode?
    
    func onReceivePacket(packet:Packet){
        if( isMyPacket(packet: packet) ){
            let methodName = packet.getStringExtra(key: "methodName", defaultValue:"")
            
            if(methodName == "loadLayout"){
                let file = packet.getStringExtra(key: "file", defaultValue:"")
                loadLayout(file)
            }
            
        }
    }
    
    func loadLayout(_ file:String){
        let path = Bundle.main.path(forResource:file , ofType:nil)
        do {
            let data = try? Data(contentsOf: URL(fileURLWithPath: path!))
            
            var options = AEXMLOptions()
            options.parserSettings.shouldProcessNamespaces = false
            options.parserSettings.shouldReportNamespacePrefixes = false
            options.parserSettings.shouldResolveExternalEntities = false
            
            let xmlDoc = try AEXMLDocument(xml: data!, options: options)
            
            print(xmlDoc.xml)
            
            if let createdView = createViewFromXML(xml:xmlDoc.root, parent:nil){
                let v = createdView as! UIView
                self.view.addSubview(v)
            }
            
        } catch {
            print("\(error)")
        }
    }
    
    func createViewFromXML( xml:AEXMLElement , parent:UIView? )->NXObject?{
        let element = xml.name.lowercased()
        let rootView = NX.sharedInstance.create(element) as! UIView
        
        if let p = parent{
            p.addSubview(rootView)
        }
        
        for child in xml.children {
            
            print("create >\(child.name) attributes > \(child.attributes)")
            let view = createViewFromXML(xml: child,parent: rootView) as! UIView
            rootView.addSubview(view)
        }
        
        return  rootView as! NXObject;
    }
    
    override func viewDidLoad() {
        //print("Swift onLoad")
        super.viewDidLoad()
        callCPPWindowMethod("onLoad");
    }

    override func viewDidAppear(_ animated: Bool) {
        //print("Swift onAppear")
        callCPPWindowMethod("onAppear");
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        //print("Swift onDisappear")
        callCPPWindowMethod("onDisappear");
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func isMyPacket(packet:Packet)->Bool{
        if(packet.path.count != 1){
            return false
        }
        if(packet.path.last! == id!){
           return true
        }
        return false
    }

    func callCPPWindowMethod(_ methodName:String ){
        
        let extra = ["methodName":methodName];
        
        let packet = Packet()
        packet.destination = Packet.toCPP
        packet.command = .CallMethod
        packet.extra = extra;
        
        sendToCPP(packet: packet);
    }
    
    func sendToCPP(packet:Packet){
        if let p = parentNode{
            packet.path.append(id!)
            p.sendToCPP(packet:packet);
        }
    }
    
}

