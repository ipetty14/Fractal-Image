//
//  FractalCreator.cpp
//  fractalImageProject
//
//  Created by Ian Petty on 2/9/17.
//  Copyright © 2017 Ian Petty. All rights reserved.
//

#include "FractalCreator.h"

namespace fractalImage {
    
    /**********************************************************
     * FRACTAL CREATOR : RUN
     * Public method that calls the private methods of the
     * FractalCreator class (see fractal.cpp).
     *********************************************************/
    void FractalCreator::run(string name)
    {
        calculateIterations();
        calculateTotalIterations();
        calculateRangeTotals();
        drawFractal();
        writeBitmap(name);
    }
    
    /**********************************************************
     * FRACTAL CREATOR : NON-DEFAULT CONSTRUCTOR
     * Public constructor that initializes the member
     * variables of the FractalCreator class. Also sets a
     * standard zoom to begin.
     *********************************************************/
    FractalCreator::FractalCreator(int width, int height) : m_width(width), m_height(height),
        m_histogram(new int [Mandelbrot::MAX_ITERATIONS]{}), m_fractal(new int [m_width * m_height]{}),
        m_bitmap(m_width, m_height), m_zoomList(m_width, m_height)
    {
        m_zoomList.add(Zoom(m_width/2, m_height/2, 4.0/m_width));
    }
    
    /**********************************************************
     * FRACTAL CREATOR : DESTRUCTOR
     * Public destructor
     *********************************************************/
    FractalCreator::~FractalCreator()
    {
        
    }
    
    /**********************************************************
     * FRACTAL CREATOR : ADD ZOOM
     * Public method that calls the add method of the ZoomList
     * member variable. It scales and centers the bitmap at
     * specified coordinantes.
     *********************************************************/
    void FractalCreator::addZoom(const Zoom & zoom)
    {
        m_zoomList.add(zoom);
    }
    
    /**********************************************************
     * FRACTAL CREATOR : ADD RANGE
     * Public method that calls the private methods of the
     * FractalCreator class (see fractal.cpp).
     *********************************************************/
    void FractalCreator::addRange(double rangeEnd, const RGB & rgb)
    {
        m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
        m_colors.push_back(rgb);
        
        if (m_GotFirstRange) {
            m_rangeTotals.push_back(0);
        }
        
        m_GotFirstRange = true;
    }
    
    /**********************************************************
     * FRACTAL CREATOR : GET RANGE
     * Public method that gets the range that a pixel is in.
     *********************************************************/
    int FractalCreator::getRange(int iterations) const
    {
        int range = 0;
        
        for (int i = 1; i < m_ranges.size(); i++) {
            range = i;
            
            if(m_ranges[i] > iterations) {
                break;
            }
        }
        
        range--;
        
        assert(range > -1);
        assert(range < m_ranges.size());
        
        return range;
    }

    /**********************************************************
     * FRACTAL CREATOR : CALCULATE ITERATIONS
     * Private method that calculates the number of iterations
     * the Mandelbrot algorithm computes per pixel.
     * (see Mandelbrot.h)
     *********************************************************/
    void FractalCreator::calculateIterations()
    {
        for (int y = 0; y < m_height; y++) {
            for (int x = 0; x < m_width; x++) {
                
                pair<double, double> coordinates = m_zoomList.doZoom(x, y);
                
                int iterations = Mandelbrot::getIterations(coordinates.first, coordinates.second);
                
                m_fractal[y * m_width + x] = iterations;
                
                if(iterations != Mandelbrot::MAX_ITERATIONS) {
                    m_histogram[iterations]++;
                }
                
            }
        }
    }
    
    /**********************************************************
     * FRACTAL CREATOR : CALCULATE TOTAL ITERATIONS
     * Private method that simply calculates the total number
     * of iterations the program does based on the number of
     * iterations of each pixel.
     *********************************************************/
    void FractalCreator::calculateTotalIterations()
    {
        for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
            m_total += m_histogram[i];
        }
    }
    
    /**********************************************************
     * FRACTAL CREATOR : CALCULATE RANGE TOTALS
     * Private method that simply calculates the total number
     * of pixels per range set in fractal.cpp.
     *********************************************************/
    void FractalCreator::calculateRangeTotals()
    {
        int rangeIndex = 0;
        
        for(int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
            int pixels = m_histogram[i];
            
            if(i >= m_ranges[rangeIndex + 1]) {
                rangeIndex++;
            }
            
            m_rangeTotals[rangeIndex] += pixels;
        }
    }
    
    /**********************************************************
     * FRACTAL CREATOR : DRAW FRACTAL
     * Private method that uses a loop based on the a number of
     * iterations to draw the fractal using color. 
     * (see Mandelbrot.h and RGB.h)
     *********************************************************/
    void FractalCreator::drawFractal()
    {
        for (int y = 0; y < m_height; y++) {
            for (int x = 0; x < m_width; x++) {
                
                uint8_t red = 0;
                uint8_t green = 0;
                uint8_t blue = 0;
                
                int iterations = m_fractal[y * m_width + x];
                int range = getRange(iterations);
                int rangeTotal = m_rangeTotals[range];
                int rangeStart = m_ranges[range];
                
                RGB & startColor = m_colors[range];
                RGB & endColor = m_colors[range + 1];
                RGB colorDiff = endColor - startColor;
                
                if(iterations != Mandelbrot::MAX_ITERATIONS) {
                    
                    int totalPixels = 0.0;
                    
                    for(int i = rangeStart; i <= iterations; i++) {
                        totalPixels += m_histogram[i];
                    }
                    
                    red = startColor.r + colorDiff.r * (double)totalPixels / rangeTotal;
                    green = startColor.g + colorDiff.g * (double)totalPixels / rangeTotal;
                    blue = startColor.b + colorDiff.b * (double)totalPixels / rangeTotal;
                }
                
                m_bitmap.setPixel(x, y, red, green, blue);
                
            }
        }
    }
    
    /**********************************************************
     * FRACTAL CREATOR : WRITE BITMAP
     * Private method that writes our bitmap to the file 
     * at a location specified in fractal.cpp
     * This function makes use of the Bitmap class.
     *********************************************************/
    void FractalCreator::writeBitmap(string name)
    {
        m_bitmap.write(name);
    }
    
}
