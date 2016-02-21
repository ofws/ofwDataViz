#pragma once
#include "ofMain.h"


typedef struct {
    string word;
    int count;
} wordCountValue;


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		vector < wordCountValue > words;
    
};
