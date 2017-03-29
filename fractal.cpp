//
//  main.cpp
//  fractalImageProject
//
//  Created by Ian Petty on 2/7/17.
//  Copyright © 2017 Ian Petty. All rights reserved.
//

#include "FractalCreator.h"

using namespace std;
using namespace fractalImage;

int main(int argc, const char * argv[]) {
    
    FractalCreator fractalCreator(800, 600);
    
    fractalCreator.addRange(0.0, RGB(0, 0, 0));
    fractalCreator.addRange(0.3, RGB(83, 112, 168));
    fractalCreator.addRange(0.5, RGB(223, 82, 68));
    fractalCreator.addRange(1.0, RGB(43, 182, 115));
    
    fractalCreator.addZoom(Zoom(295, 202, 0.1));
    fractalCreator.addZoom(Zoom(312, 304, 0.1));
    fractalCreator.run("/Users/ipetty/Documents/cppBegAndAdv/Fractal-Image/test.bmp");
    
    cout << "Finished" << endl;
    return 0;
}
