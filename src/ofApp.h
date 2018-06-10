#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "wave.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    ofxPanel gui;
    bool showgui;
    void syncGuiValsInt(int &v);
    void syncGuiValsFloat(float &v);
    void syncGuiValsBool(bool &v);
    void syncGuiVals();
    ofParameter<int> wid,hei,resw,resh;
    ofParameter<float> amp,speed,freq,yang;
    ofParameter<bool> drawnorms;
    ofxButton switchtex;
    void switchTexPressed();
    ofxLabel currenttex;
    ofParameter<float> texr;

    ofEasyCam cam;
    ofLight light1, light2;
    ofParameter<float> attc,attl,attq,lightz;

    vector<ofTexture> texs;
    ofMaterial mat;
    ofParameter<float> shi;

    wave wav;
};
