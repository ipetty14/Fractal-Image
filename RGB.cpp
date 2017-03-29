//
//  RGB.cpp
//  fractalImageProject
//
//  Created by Ian Petty on 2/9/17.
//  Copyright © 2017 Ian Petty. All rights reserved.
//

#include "RGB.h"

namespace fractalImage {
    
    RGB operator-(const RGB & first, const RGB & second)
    {
        return RGB(first.r - second.r, first.g - second.g, first.b - second.b);
    }
}
