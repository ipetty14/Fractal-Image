//
//  FractalCreator.h
//  fractalImageProject
//
//  Created by Ian Petty on 2/9/17.
//  Copyright © 2017 Ian Petty. All rights reserved.
//

#ifndef FractalCreator_h
#define FractalCreator_h

#include <cassert>
#include <iostream>
#include <math.h>
#include <memory>
#include <string>
#include <vector>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "RGB.h"
#include "ZoomList.h"

using namespace std;

namespace fractalImage {
    
    class FractalCreator
    {
    //Private Member Variables
    private:
        int m_width;
        int m_height;
        int m_total{0};
        unique_ptr<int[]> m_histogram;
        unique_ptr<int[]> m_fractal;
        Bitmap m_bitmap;
        ZoomList m_zoomList;
        
        vector<int> m_ranges;
        vector<RGB> m_colors;
        vector<int> m_rangeTotals;
        
        bool m_GotFirstRange{false};

    //Public Methods
    public:
        void run(string name);
        
        FractalCreator(int width, int height);
        virtual ~FractalCreator();
        
        void addZoom(const Zoom & zoom);
        void addRange(double rangeEnd, const RGB & rgb);
        int getRange(int iterations) const;
        
    //Private Methods
    private:
        void calculateIterations();
        void calculateTotalIterations();
        void calculateRangeTotals();
        void drawFractal();
        void writeBitmap(string name);
    };
}


#endif /* FractalCreator_h */
