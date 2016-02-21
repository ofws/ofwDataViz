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
    
    
    // let's round up to the next "10" on the max value
    maxValue = ceil(maxValue / 10) * 10;
    
    
    
    dimensions.x = 150;
    dimensions.y = 150;
    dimensions.width = 700;
    dimensions.height = 400;
    
    font.load("bfont.ttf", 20);
    labelFont.load("bFont.ttf", 10);
    
    ofBackground(220);
    
    
    
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
        float y = dimensions.y + ofMap( dataPoints[i].milk, 0, maxValue, dimensions.height, 0);
        
        //ofRect(x, dimensions.y + dimensions.height, 3, -y);
        ofDrawCircle(x,y, 2);
    }
    font.drawString("Milk", dimensions.x, dimensions.y-5);
    
    // draw tick marks and labels
    
    for (int i = 0; i < dataPoints.size(); i++){
        
        //if (dataPoints[i].year % 10 == 0){
            float x = dimensions.x + ofMap( dataPoints[i].year, minYear, maxYear, 0,dimensions.width);
            float y = dimensions.y + dimensions.height;
            ofSetColor(90);
            if (i % 10 == 0) labelFont.drawString(ofToString( dataPoints[i].year), x, y + 20);
            ofSetColor(220);
        if (i % 10 == 0) ofSetColor(0);
        if (i % 10 == 5) ofSetColor(180,90,90);
            ofDrawLine(x, y, x,  dimensions.y);
       // }
    }
    
    for (int i = 0; i <= (int)maxValue; i++){
        if (i % 10 == 0){
            float x = dimensions.x;
            float y = dimensions.y + ofMap(i, 0, maxValue, dimensions.height, 0);
            
            ofSetColor(90);
            labelFont.drawString(ofToString( i ), x - 30, y + 5);
            ofDrawLine(x,y, x-5,y);
        }
    }
    
}
