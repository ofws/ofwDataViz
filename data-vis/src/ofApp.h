#pragma once
#include "ofMain.h"

typedef struct {
    
    int year;
    int ny;
    int lou;
    int ala;
    
} popData;


class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    
    vector < popData > dataPoints;
    
    int minYear;
    int maxYear;
    float maxValue;
    
    ofRectangle dimensions;
    
    int which;
    
    ofTrueTypeFont font;
    ofTrueTypeFont labelFont;

};
