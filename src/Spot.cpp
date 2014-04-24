#include "Spot.h"

Spot::Spot(ofPoint _pos, ofPoint _velocity, float _diameter) {
    pos = _pos;
    velocity = _velocity;
    diameter = _diameter;
}

void Spot::update() {
    velocity *= friction;
    velocity.y += gravity;
    pos.x += velocity.x;
    pos.y += velocity.y;
    
    if (pos.x < diameter || pos.x > ofGetWidth() - diameter) {
        velocity.x *= -1;
    }
    if (pos.y > ofGetHeight() - diameter) {
        velocity.y *= -1;
        pos.y = ofGetHeight() - diameter;
    }
}

void Spot::display() {
    ofSetColor(0, 127, 255, 200);
    ofCircle(pos.x, pos.y, diameter);
}