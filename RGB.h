//
//  RGB.h
//  fractalImageProject
//
//  Created by Ian Petty on 2/9/17.
//  Copyright © 2017 Ian Petty. All rights reserved.
//

#ifndef RGB_h
#define RGB_h

namespace fractalImage {

    struct RGB
    {
        double r;
        double g;
        double b;

        RGB(double r, double g, double b) : r(r), g(g), b(b) {}
    };
    
    RGB operator-(const RGB & first, const RGB & second);
}

#endif /* RGB_h */
