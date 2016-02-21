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
            valuesSmoothed.push_back(0);
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
    
    which = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
    for (int i = 0; i < valuesSmoothed.size(); i++){
        
        if (which == 0) valuesSmoothed[i] = 0.97f * valuesSmoothed[i] + 0.03 * dataPoints[i].milk;
        if (which == 1) valuesSmoothed[i] = 0.97f * valuesSmoothed[i] + 0.03 * dataPoints[i].tea;
        if (which == 2) valuesSmoothed[i] = 0.97f * valuesSmoothed[i] + 0.03 * dataPoints[i].coffee;

        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    ofDrawRectangle(dimensions.x, dimensions.y, dimensions.width, dimensions.height);
    
    ofSetColor(90);
    
    ofBeginShape();
    ofVertex(dimensions.x, dimensions.y + dimensions.height);
    for (int i = 0; i < dataPoints.size(); i++){
        
        float value = valuesSmoothed[i];
      
        float x = dimensions.x + ofMap( dataPoints[i].year, minYear, maxYear, 0,dimensions.width);
        float y = dimensions.y + ofMap( value, 0, maxValue, dimensions.height, 0);
        
        if (i == 0) ofVertex(x,y); 
        ofCurveVertex(x,y);
         if (i == dataPoints.size()-1) ofVertex(x,y); 
        
        //ofCircle(x,y, 2);
    }
    ofVertex(dimensions.x + dimensions.width, dimensions.y + dimensions.height);
    ofEndShape();
    
    if (which == 0) ofSetColor(180,90,90);
    else ofSetColor(90);
    font.drawString("Milk", dimensions.x, dimensions.y-15);
    
    if (which == 1) ofSetColor(180,90,90);
    else ofSetColor(90);
    font.drawString("Tea", dimensions.x + 80, dimensions.y-15);
    
    if (which == 2) ofSetColor(180,90,90);
    else ofSetColor(90);
    font.drawString("Coffee", dimensions.x + 160, dimensions.y-15);
    
    // draw tick marks and labels
    
    for (int i = 0; i < dataPoints.size(); i++){
        
        if (dataPoints[i].year % 10 == 0){
            float x = dimensions.x + ofMap( dataPoints[i].year, minYear, maxYear, 0,dimensions.width);
            float y = dimensions.y + dimensions.height;
            ofSetColor(90);
            labelFont.drawString(ofToString( dataPoints[i].year), x, y + 20);
            ofSetColor(220);
            //ofLine(x, y, x,  dimensions.y);
        }
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

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ofRectangle rect = font.getStringBoundingBox("Milk", dimensions.x, dimensions.y-15);
    if (rect.inside(ofPoint(x,y))){
        which = 0;
    }
    
    rect = font.getStringBoundingBox("Tea", dimensions.x + 80, dimensions.y-15);
    if (rect.inside(ofPoint(x,y))){
        which = 1;
    }
    
    rect = font.getStringBoundingBox("Coffee", dimensions.x + 160, dimensions.y-15);
    if (rect.inside(ofPoint(x,y))){
        which = 2;
    }
}