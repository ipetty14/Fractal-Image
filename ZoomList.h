//
//  ZoomList.h
//  fractalImageProject
//
//  Created by Ian Petty on 2/9/17.
//  Copyright © 2017 Ian Petty. All rights reserved.
//

#ifndef ZoomList_h
#define ZoomList_h

#include <vector>
#include <utility>
#include "Zoom.h"

using namespace std;

namespace fractalImage {
    
    class ZoomList
    {
    private:
        int m_width{0};
        int m_height{0};
        vector<Zoom> zooms;
        
        double m_xCenter{0};
        double m_yCenter{0};
        double m_scale{1.0};
        
    public:
        ZoomList(int width, int height);
        void add(const Zoom & zoom);
        pair<double, double> doZoom(int x, int y);
    };
}

#endif /* ZoomList_h */
