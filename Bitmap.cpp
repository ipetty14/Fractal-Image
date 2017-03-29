//
//  Bitmap.cpp
//  fractalImageProject
//
//  Created by Ian Petty on 2/7/17.
//  Copyright © 2017 Ian Petty. All rights reserved.
//

#include <fstream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace std;
using namespace fractalImage;

namespace fractalImage {

    bool Bitmap::write(string fileName)
    {
        BitmapFileHeader fileHeader;
        BitmapInfoHeader infoHeader;
        
        fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + (m_width * m_height * 3);
        fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
        
        infoHeader.width = m_width;
        infoHeader.height = m_height;
        
        ofstream fileOut;
        fileOut.open(fileName, ios::binary);
        
        fileOut.write((char *) &fileHeader, sizeof(fileHeader));
        fileOut.write((char *) &infoHeader, sizeof(infoHeader));
        fileOut.write((char *) m_pPixels.get(), m_width * m_height * 3);


        
        fileOut.close();
        
        if(!fileOut)
        {
            return false;
        }
        
        return true;
    }
    
    void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
    {
        uint8_t * pPixel = m_pPixels.get();
        
        pPixel += (y * 3) * m_width + (x * 3);
        
        pPixel[0] = blue;
        pPixel[1] = green;
        pPixel[2] = red;

        
        
        
    }
    
    Bitmap::~Bitmap()
    {
        
    }
    
    
    
    
    
    
    
    
}
