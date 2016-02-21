#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofBuffer file = ofBufferFromFile("milk-tea-coffee.tsv");
    
    // grab the first line, which is just names.
    string nameLine = file.getLines().begin().asString();
    
    for (auto l: file.getLines()){
        string line = l;
        if (l != nameLine && !l.empty()) {
            vector<string> split = ofSplitString(line, "\t");
            
            timeData data;
            data.year = ofToInt(split[0]);
            data.milk = ofToFloat(split[1]);
            data.tea = ofToFloat(split[2]);
            data.coffee = ofToFloat(split[3]);
            dataPoints.push_back(data);
        }
    }
    
    
    // let's find the min and max years, and the max value for the data.
    // years are easy, we know it's the first and last year of the array.
    
    minYear = dataPoints[0].year;
    ofLog() << "min year = " << minYear;
    maxYear = dataPoints[dataPoints.size()-1].year;
    ofLog() << "max year = " << maxYear;
    
    // search lineraly through the data to find the max value;
    
    maxValue = 0;
    for (int i = 0; i < dataPoints.size(); i++){
        if (dataPoints[i].milk > maxValue){
            maxValue = dataPoints[i].milk;
        }
        if (dataPoints[i].coffee > maxValue){
            maxValue = dataPoints[i].coffee;
        }
        if (dataPoints[i].tea > maxValue){
            maxValue = dataPoints[i].tea;
        }
    }

    
    
    dimensions.x = 150;
    dimensions.y = 150;
    dimensions.width = 700;
    dimensions.height = 400;
    
    
    ofBackground(180);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    ofDrawRectangle(dimensions.x, dimensions.y, dimensions.width, dimensions.height);
    
    ofSetColor(90);
    for (int i = 0; i < dataPoints.size(); i++){
        
        float x = dimensions.x + ofMap( dataPoints[i].year, minYear, maxYear, 0,dimensions.width);
        float y = dimensions.y + ofMap( dataPoints[i].coffee, 0, maxValue, dimensions.height, 0);
        
        ofDrawCircle(x,y, 2);
    }
    
}
