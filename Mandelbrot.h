//
//  Mandelbrot.h
//  fractalImageProject
//
//  Created by Ian Petty on 2/9/17.
//  Copyright © 2017 Ian Petty. All rights reserved.
//

#ifndef Mandelbrot_h
#define Mandelbrot_h

namespace fractalImage {
    
    class Mandelbrot
    {
    public:
        static const int MAX_ITERATIONS = 1000;
        
    public:
        Mandelbrot();
        virtual ~Mandelbrot();
        
        static int getIterations(double x, double y);
        
    };
}

#endif /* Mandelbrot_h */
