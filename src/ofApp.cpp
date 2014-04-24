#include "ofApp.h"
#include "Spot.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(ofColor::black);
    ofSetFrameRate(60);
    
    myCircleX = 300;
    myCircleY = 200;
    angle = 0;
    
    numSpot = 100;
    sp = new Spot*[numSpot];
    
    for (int i = 0; i < numSpot; i++) {
        ofPoint _pos, _velocity;
        _pos.x = ofRandom(0, ofGetWidth());
        _pos.y = ofRandom(0, ofGetHeight());
        _velocity.x = ofRandom(-10, 10);
        _velocity.y = ofRandom(-30, -10);
        float _diameter = ofRandom(1, 20);
        sp[i] = new Spot(_pos, _velocity, _diameter);
        sp[i]->gravity = 0.5;
        sp[i]->friction = 0.999;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    angle++;
    
    ofSetColor(0, 0, 0, 31);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    for (int i = 0; i < numSpot; i++) {
        sp[i]->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableSmoothing();
    for (int i = 0; i < numSpot; i++) {
        sp[i]->display();
    }
    
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    ofRotateZ(angle);
    
    ofEnableAlphaBlending();
    glBlendFunc(GL_ONE, GL_ONE);
    
    ofSetColor(255, 0, 255);
    ofCircle(myCircleX, myCircleY, 60);
    
    ofSetColor(0, 200, 0);
    ofDrawBitmapString("Hello World!", 100, 100);
    ofDrawBitmapString(ofToString(ofGetFrameRate()) + "fps", 10, 15);
    
    ofSetColor(100, 100, 100);
    ofEllipse(30, 30, 100, 100);
    
    ofDisableAlphaBlending();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    cout << "keyPressed:" << (char)key << endl;
    
    if (key == 115) {
        myCircleY++;
    }
    if (key == 119) {
        myCircleY--;
    }
    if (key == 100) {
        myCircleX++;
    }
    if (key == 97) {
        myCircleX--;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    cout << "keyReleased:" << (char)key << endl;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ofBackground(ofColor::white);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    ofBackground(ofColor::black);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}