#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(30);
	vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(320, 240);
    colorImg.allocate(320, 240, OF_IMAGE_COLOR);
    
    brightnessAmount = 0;
    contrastAmount = 0;
    
    ofSetWindowShape(320 * 3, 240 * 3);
}

//--------------------------------------------------------------
void testApp::update(){
    vidGrabber.grabFrame();
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void testApp::draw(){
    colorImg.setFromPixels(vidGrabber.getPixels(), 320, 240, OF_IMAGE_COLOR);
    
    cont.setBrightnessAndContrast(colorImg, brightnessAmount + 50,  contrastAmount - 50 ).draw(0,     0);
    cont.setBrightnessAndContrast(colorImg, brightnessAmount + 50,  contrastAmount      ).draw(320,   0);
    cont.setBrightnessAndContrast(colorImg, brightnessAmount + 50,  contrastAmount + 50 ).draw(320*2, 0);
    cont.setBrightnessAndContrast(colorImg, brightnessAmount,       contrastAmount - 50 ).draw(0,     240);
    cont.setBrightnessAndContrast(colorImg, brightnessAmount,       contrastAmount      ).draw(320,   240);
    cont.setBrightnessAndContrast(colorImg, brightnessAmount,       contrastAmount + 50 ).draw(320*2, 240);
    cont.setBrightnessAndContrast(colorImg, brightnessAmount - 50,  contrastAmount - 50 ).draw(0,     240*2);
    cont.setBrightnessAndContrast(colorImg, brightnessAmount - 50,  contrastAmount      ).draw(320,   240*2);
    cont.setBrightnessAndContrast(colorImg, brightnessAmount - 50,  contrastAmount + 50 ).draw(320*2, 240*2);
    
    ofDrawBitmapString("brightnessAmount : "    + ofToString(brightnessAmount)  + "\n"
                       "contrastAmount : "      + ofToString(contrastAmount)    + "\n"
                       , 20, 20);
    
    ofDrawBitmapString(" -50      <------    Contrast    ------>      +50", 280, 240 * 3 - 20);
    ofPushMatrix();
    ofRotateZ(90);
    ofDrawBitmapString(" +50      <------    Brightness    ------>      -50", 150, - 20);
    ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == OF_KEY_UP){
        if(brightnessAmount < 127)brightnessAmount += 5;
    }
    if(key == OF_KEY_DOWN){
        if(brightnessAmount > -127)brightnessAmount -= 5;
    }
    if(key == OF_KEY_RIGHT){
        if(contrastAmount < 127)contrastAmount += 5;
    }
    if(key == OF_KEY_LEFT){
        if(contrastAmount > -127)contrastAmount -= 5;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}