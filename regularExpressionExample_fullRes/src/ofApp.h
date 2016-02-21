#pragma once

#include "ofMain.h"

class URLImage : public ofImage {
public:
    bool    bDoneLoading;
    string  url;
};


class ofApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();
    void keyPressed  (int key);
    
    void              searchGoogleImages();
    int               page;
    string            rawData;
    vector <string>   urls;
    vector <URLImage> images;
};
