#pragma once
#include "ofMain.h"

typedef struct {
    string zip;  //90210, 11211, 60201 "00391"           // let's keep this as a zip, because otherwise we'll need to pad 0s on zips like 01099
    float longitude;
    float latitude;
    string placeName;
    float color;
    float colorTarget;
} zipCode;


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed  (int key);
		
        vector < zipCode > zipCodes;
    
        ofRectangle map;
        
        float minX, maxX, minY, maxY;
    
        string enteredZip;
        
        float scale;
        float scaleTarget;
        ofPoint center;
        ofPoint centerTarget;
    
    
};
