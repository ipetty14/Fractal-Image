//
//  Bitmap.hpp
//  fractalImageProject
//
//  Created by Ian Petty on 2/7/17.
//  Copyright © 2017 Ian Petty. All rights reserved.
//

#ifndef Bitmap_h
#define Bitmap_h

#include <string>
#include <cstdint>
using namespace std;

namespace fractalImage {
    
    class Bitmap
    {
    private:
        int m_width{0};
        int m_height{0};
        unique_ptr<uint8_t[]> m_pPixels{nullptr};
    
    public:
        Bitmap(int width, int height) : m_width(width), m_height(height), m_pPixels(new uint8_t[width * height * 3]{}) {}
        virtual ~Bitmap();

        bool write(string fileName);
        void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
    
    };
    
    
}


#endif /* Bitmap_h */
