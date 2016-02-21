#pragma once
#include "ofMain.h"

// ---------------------------------------------
typedef struct  {
    string  word;
    int     occurrences;
} LyricWord;

// ---------------------------------------------
class ofApp : public ofBaseApp {
	
public:
    
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    static bool sortOnABC(const LyricWord &a, const LyricWord &b);
    static bool sortOnOccurrences(const LyricWord &a, const LyricWord &b);
    static bool sortOnLength(const LyricWord &a, const LyricWord &b);
    static bool removeWordIf(LyricWord &wrd);
    
    ofTrueTypeFont      font;
    string              sortTypeInfo;
    vector <LyricWord>  words;
};
