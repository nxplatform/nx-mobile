//
//  NXImageView.swift
//  NXFramework
//
//  Created by heart on 4/7/2560 BE.
//  Copyright © 2560 3dsinteractive.com. All rights reserved.
//

import Foundation
import UIKit

class NXImageView:UIImageView,NXObject{
    
    public init(){
        super.init(frame:CGRect.zero)
    }
    
    required public init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    
}
