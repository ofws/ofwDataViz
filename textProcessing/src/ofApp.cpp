#include "ofApp.h"



bool sortByCount(const wordCountValue & a, const wordCountValue & b){
    
    return a.count > b.count;
}


//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0,0,0);
    ofSetCircleResolution(100);
    ofEnableAlphaBlending();
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    // let's get the top 100 sites in text files.  Use CURL so we can handle redirects, etc. 
    
    
     
    
    
    ofBuffer file = ofBufferFromFile("kingSpeech.txt");
    string textAsString = file;
    
    //let's get rid of every period, comma, tab, newline
    
    for (int i = 0; i < textAsString.size(); i++){
        if (textAsString[i] == '.'){
            textAsString[i] = ' ';
        }
        if (textAsString[i] == '\n'){
            textAsString[i] = ' ';
        }
        if (textAsString[i] == '\t'){
            textAsString[i] = ' ';
        }
        if (textAsString[i] == ','){
            textAsString[i] = ' ';
        }
        if (textAsString[i] == '!'){
            textAsString[i] = ' ';
        }
        if (textAsString[i] == '!'){
            textAsString[i] = ' ';
        }
        if (textAsString[i] == ':'){
            textAsString[i] = ' ';
        }
        if (textAsString[i] == '\"'){
            textAsString[i] = ' ';
        }
    }
    
    
    vector < string > textBrokenUp = ofSplitString(textAsString, " ", true, true);
    for (int i = 0; i < textBrokenUp.size(); i++){
        bool bAnyMatch = false;
        int whichMatch = -1;
        for (int j = 0; j < words.size(); j++){
            if (textBrokenUp[i] == words[j].word){
                whichMatch = j;
                bAnyMatch = true;
            }
        }
        
        if (bAnyMatch == true){
            words[whichMatch].count++;
        } else {
            wordCountValue temp;
            temp.word = textBrokenUp[i];
            temp.count = 1;
            words.push_back(temp);
        }
    }
    
    sort(words.begin(), words.end(), sortByCount);
    
    for (int i = 0; i < words.size(); i++){
        cout << words[i].word << " " << words[i].count << endl;
    }
    
   
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
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