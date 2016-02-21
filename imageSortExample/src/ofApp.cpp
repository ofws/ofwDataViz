#include "ofApp.h"



bool sortFunction(  const imgAndColor  a,  const imgAndColor b){
    return a.avg.getBrightness() > b.avg.getBrightness();
}


ofColor avgPixelValue ( ofImage & img){
    
    int w = img.getWidth();
    int h = img.getHeight();
    int nPixels = w * h;
    
    int red = 0;
    int green = 0;
    int blue = 0;
    
    ofPixelsRef ref = img.getPixels();
    
    for (int i = 0; i < w; i++){
        for (int j = 0; j < h; j++){
                
                ofColor pixel = ref.getColor(i,j);
                red += pixel.r;
                green += pixel.g;
                blue += pixel.b;
            
        }
    }

    red = red / (float)nPixels;
    green = green / (float)nPixels;
    blue = blue / (float)nPixels;
    
    ofColor result;
    result.set(red, green, blue);
    return result;
    
    
}



//--------------------------------------------------------------
void ofApp::setup(){

    
    dir.listDir("images");
    
    for (int i = 0; i < dir.size(); i++){
        
        
        
        imgAndColor temp;
        temp.img.load(dir.getPath(i));
        temp.avg = avgPixelValue(temp.img);
        images.push_back(temp);
        //cout << dir.getPath(i) << endl;
        
    }
    
    
    sort(images.begin(), images.end(), sortFunction);
    
        
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    int pos = ofMap( mouseX, 0, ofGetWidth(), 0, images.size()-1, true);
    cout << pos << endl;
    
    ofSetColor(255,255,255);
    images[pos].img.draw(0,0,ofGetWidth(), ofGetHeight());
    
    ofSetColor(images[pos].avg);
    ofRect(0,0,100,100);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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