#pragma once

#include "ofMain.h"

typedef struct {
    string URLname;
    int position;
    int numLinks;
    int numImages;
} topURL;


class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void keyPressed  (int key);

    vector < topURL > urls;
};
