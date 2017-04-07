//
//  NXView.swift
//  NXFramework
//
//  Created by heart on 4/5/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

import Foundation
import UIKit

class NXView:UIView,NXObject{
    
    override init(frame: CGRect) {
        super.init(frame: frame)
    }
    
    convenience init() {
        self.init(frame: CGRect.zero)
    }
    
    required public init(coder aDecoder: NSCoder) {
        fatalError("This class does not support NSCoding")
    }
    
    
}
