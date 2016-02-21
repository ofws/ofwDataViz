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
    void mousePressed(int x, int y, int button);
    
    vector < timeData > dataPoints;
    vector < float > valuesSmoothed;
    
    int minYear;
    int maxYear;
    float maxValue;

    ofRectangle dimensions;

    ofTrueTypeFont font;
    ofTrueTypeFont labelFont;

    int which;
        
        
};
