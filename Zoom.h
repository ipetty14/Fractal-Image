//
//  Zoom.h
//  fractalImageProject
//
//  Created by Ian Petty on 2/9/17.
//  Copyright © 2017 Ian Petty. All rights reserved.
//

#ifndef Zoom_h
#define Zoom_h

namespace fractalImage {
    
    struct Zoom
    {
        int x{0};
        int y{0};
        double scale{0.0};
        
        Zoom(int x, int y, double scale) : x(x), y(y), scale(scale) {}
    };
}

#endif /* Zoom_h */
