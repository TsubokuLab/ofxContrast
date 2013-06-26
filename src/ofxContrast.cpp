//
//  ofxContrast.cpp
//
//  Created by kohack_v on 2013/06/19.
//
//

#include "ofxContrast.h"

//--------------------------------------------------------------
ofImage ofxContrast::setBrightness(ofImage& _img, float brightnessAmount){
    ofxCvColorImage cvimg;
    cvimg.allocate(_img.width, _img.height);
    cvimg.setFromPixels(_img.getPixels(), _img.width, _img.height);
    
	float brightnessVal = MAX(-127, MIN(127, brightnessAmount));
	
	unsigned char data[ 256 ];
	CvMat * matrix;
	
	matrix = cvCreateMatHeader( 1, 256, CV_8UC1 );
    cvSetData( matrix, data, 0 );
	
	for( int i=0; i<256; i++ ) {
		int value = cvRound( i+brightnessVal );
		data[i]	= (unsigned char) min( max(0,value), 255 );
	}
	
    cvLUT( cvimg.getCvImage(), cvimg.getCvImage(), matrix );
	cvReleaseMat( &matrix );
    
    ofImage ofimg;
    ofimg.allocate(_img.width, _img.height, OF_IMAGE_COLOR);
    ofimg.setFromPixels(cvimg.getPixels(), _img.width, _img.height, OF_IMAGE_COLOR);
	return ofimg;
}

//--------------------------------------------------------------
ofImage ofxContrast::setContrast(ofImage& _img, float contrastAmount){
    ofxCvColorImage cvimg;
    cvimg.allocate(_img.width, _img.height);
    cvimg.setFromPixels(_img.getPixels(), _img.width, _img.height);
    
	float contrastVal = MAX(-127, MIN(127, contrastAmount));
	
	unsigned char data[ 256 ];
	CvMat * matrix;
	double delta, a;
	
	matrix = cvCreateMatHeader( 1, 256, CV_8UC1 );
    cvSetData( matrix, data, 0 );
	
	if ( contrastVal>0 ) {
        delta = (127.0f*contrastVal) / 128.0f;
        a = 255.0f / ( 255.0f-(delta*2.0f) );
    }
    else {
		delta = (-128.0f*contrastVal) / 128.0f;
		a = ( 256.0f-(delta*2.0f) ) / 255.0f;
    }
	
	for( int i=0; i<256; i++ ) {
		int value = cvRound( (a*i) );
		data[i]	= (unsigned char) min( max(0,value), 255 );
	}
	
    cvLUT( cvimg.getCvImage(), cvimg.getCvImage(), matrix );
	cvReleaseMat( &matrix );
    
    ofImage ofimg;
    ofimg.allocate(_img.width, _img.height, OF_IMAGE_COLOR);
    ofimg.setFromPixels(cvimg.getPixels(), _img.width, _img.height, OF_IMAGE_COLOR);
	return ofimg;
}

//--------------------------------------------------------------
ofImage ofxContrast::setBrightnessAndContrast(ofImage& _img, float brightnessAmount, float contrastAmount){
    ofxCvColorImage cvimg;
    cvimg.allocate(_img.width, _img.height);
    cvimg.setFromPixels(_img.getPixels(), _img.width, _img.height);
    
	float brightnessVal = MAX(-127, MIN(127, brightnessAmount));
	float contrastVal = MAX(-127, MIN(127, contrastAmount));
	
	unsigned char data[ 256 ];
	CvMat * matrix;
	double delta, a, b;
	
	matrix = cvCreateMatHeader( 1, 256, CV_8UC1 );
    cvSetData( matrix, data, 0 );
	
	if ( contrastVal>0 ) {
        delta = (127.0f*contrastVal) / 128.0f;
        a = 255.0f / ( 255.0f-(delta*2.0f) );
        b = a * (brightnessVal-delta);
    }
    else {
		delta = (-128.0f*contrastVal) / 128.0f;
		a = ( 256.0f-(delta*2.0f) ) / 255.0f;
		b = ( a*brightnessVal )+delta;
    }
	
	for( int i=0; i<256; i++ ) {
		int value = cvRound( (a*i)+b );
		data[i]	= (unsigned char) min( max(0,value), 255 );
	}
	
    cvLUT( cvimg.getCvImage(), cvimg.getCvImage(), matrix );
	cvReleaseMat( &matrix );
    
    ofImage ofimg;
    ofimg.allocate(_img.width, _img.height, OF_IMAGE_COLOR);
    ofimg.setFromPixels(cvimg.getPixels(), _img.width, _img.height, OF_IMAGE_COLOR);
	return ofimg;
}