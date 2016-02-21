#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//img.loadImage("test.jpg");
	finder.setup("haarcascade_frontalface_default.xml");
	//finder.findHaarObjects(img);
    grabber.initGrabber(320,240);
    
    color = 255;
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
    finder.findHaarObjects(grabber.getPixelsRef());
    
     ofBackground(color, color, color);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    grabber.draw(0, 0);
	
	for(int i = 0; i < finder.blobs.size(); i++) {
		
        ofRectangle cur = finder.blobs[i].boundingRect;
		ofSetColor(255,255,255); //, <#int g#>, <#int b#>)
        ofRect(cur.x, cur.y, cur.width, cur.height);
        
        if (i == 0){
            ofPoint midPt;
            midPt.set(cur.x + cur.width/2, cur.y + cur.height/2);
            color = ofMap(midPt.x, 0,320,0,255);

            
        }
        
        
        
	}
    
    
    
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}