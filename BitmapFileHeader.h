//
//  BitmapFileHeader.h
//  fractalImageProject
//
//  Created by Ian Petty on 2/7/17.
//  Copyright © 2017 Ian Petty. All rights reserved.
//

#ifndef BitmapFileHeader_h
#define BitmapFileHeader_h

#include <cstdint>

using namespace std;

#pragma pack(2)

namespace fractalImage {

    struct BitmapFileHeader
    {
        char header[2]{'B', 'M'};
        int32_t fileSize;
        int32_t reserved{0};
        int32_t dataOffset;
    };

}
#endif /* BitmapFileHeader_h */
