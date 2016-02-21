#pragma once
#include "ofMain.h"

typedef struct {
    int year;
    float milk;
    float tea;
    float coffee;
} timeData;

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    vector < timeData > dataPoints;
    
    int minYear;
    int maxYear;
    float maxValue;
    
    ofRectangle dimensions;
    
};
