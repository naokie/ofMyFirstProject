#ifndef _OF_SPOT
#define _OF_SPOT

#include "ofMain.h"

class Spot {
    public:
        Spot(ofPoint pos, ofPoint velocity, float diameter);
        void update();
        void display();
        ofPoint pos;
        ofPoint velocity;
        float diameter;
        float gravity;
        float friction;
};

#endif
