//
//  ofxContrast.h
//
//  Created by kohack_v on 2013/06/19.
//
//

#ifndef _OFX_CONTRAST_H
#define _OFX_CONTRAST_H

#define OF_ADDON_USING_OFOPENCV

#include "ofxOpenCv.h"

//stupid ball class
class ofxContrast
{

public:
    ofImage setBrightness(ofImage& _img, float brightnessAmount);
    ofImage setContrast(ofImage& _img, float contrastAmount);
    ofImage setBrightnessAndContrast(ofImage& _img, float brightnessAmount, float contrastAmount);
};
#endif