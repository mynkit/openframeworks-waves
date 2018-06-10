#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    gui.add(wid.set("Width",1000 ,1,3000));                 wid.addListener(this, &ofApp::syncGuiValsInt);
    gui.add(hei.set("Height",1800 ,1,3000));                hei.addListener(this, &ofApp::syncGuiValsInt);
    gui.add(resw.set("MeshResX",110 ,1,150));               resw.addListener(this, &ofApp::syncGuiValsInt);
    gui.add(resh.set("MeshResY",110 ,1,150));               resh.addListener(this, &ofApp::syncGuiValsInt);
    gui.add(speed.set("Speed",20 ,1,150));                  speed.addListener(this, &ofApp::syncGuiValsFloat);
    gui.add(amp.set("Height",23 ,1,70));                    amp.addListener(this, &ofApp::syncGuiValsFloat);
    gui.add(freq.set("Waves freq.", 0.0263,0,PI/80));          freq.addListener(this, &ofApp::syncGuiValsFloat);
    gui.add(yang.set("Waves ang.", 16.4,0,TWO_PI*9));      yang.addListener(this, &ofApp::syncGuiValsFloat);
    gui.add(drawnorms.set("Draw Norms", false));            drawnorms.addListener(this, &ofApp::syncGuiValsBool);
    gui.add(switchtex.setup("Change texture"));             switchtex.addListener(this, &ofApp::switchTexPressed);
    gui.add(currenttex.setup("Current", ofToString(4)));
    gui.add(texr.set("Texture repeat", 26,0.2,40));         texr.addListener(this, &ofApp::syncGuiValsFloat);
    gui.add(attc.set("Light const. att.", 0,0,2));          attc.addListener(this, &ofApp::syncGuiValsFloat);
    gui.add(attl.set("Light lin. att.", 0.002,0,0.008));         attl.addListener(this, &ofApp::syncGuiValsFloat);
    gui.add(attq.set("Light qua. att.", 0,0,0.00001));      attq.addListener(this, &ofApp::syncGuiValsFloat);
    gui.add(shi.set("Shine", 67,0,130));                 shi.addListener(this, &ofApp::syncGuiValsFloat);
    gui.add(lightz.set("Light Z", 540,-100,1000));                 lightz.addListener(this, &ofApp::syncGuiValsFloat);

    this->syncGuiVals();
    showgui=true;

    cam.setPosition(ofVec3f(0,-hei/2,200));
    cam.lookAt(ofVec3f(0,0,0));
    cam.setDistance(360);

    light1.setSpecularColor(ofColor(255));
    light1.setDiffuseColor(ofColor(250));
    light1.setAmbientColor(ofColor(100));
    light1.setPointLight();

    ofDisableArbTex();
    ofTexture t;
    //sea sound https://www.youtube.com/watch?v=oKKDfynx4ZY
    ofLoadImage(t,"wat1.jpg"); texs.push_back(t);
    ofLoadImage(t,"wat2.jpg"); texs.push_back(t);
    ofLoadImage(t,"wat3.jpg"); texs.push_back(t);
    ofLoadImage(t,"wat4.jpg"); texs.push_back(t);
    ofLoadImage(t,"wat5.jpg"); texs.push_back(t);
    for (int i=0;i<texs.size();i++)
        texs[i].setTextureWrap(GL_REPEAT, GL_REPEAT);
    wav.activetex=&texs[ofToInt(currenttex)];

    mat.setSpecularColor(ofColor(255, 255, 255, 255));
}

//--------------------------------------------------------------
void ofApp::update(){
    wav.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    ofEnableLighting();
    ofBackground(19,31,51);

    cam.begin();
    light1.enable();

    mat.begin();
    wav.draw();
    mat.end();

    light1.disable();
    light2.disable();
    cam.end();

    if (showgui){
        ofDisableDepthTest();
        light1.enable();
        gui.draw();
        light1.disable();
    }
}

void ofApp::syncGuiValsInt(int &v){syncGuiVals();}
void ofApp::syncGuiValsFloat(float &v){syncGuiVals();}
void ofApp::syncGuiValsBool(bool &v){syncGuiVals();}
void ofApp::syncGuiVals(){
    wav.amp=amp;
    wav.speed=speed;
    wav.freq=freq;
    wav.yang=yang;
    wav.drawnorms=drawnorms;
    if (wav.wid!=wid || wav.hei!=hei || wav.resw!=resw || wav.resh!=resh || wav.texr!=texr){
        wav.wid=wid;
        wav.hei=hei;
        wav.resw=resw;
        wav.resh=resh;
        wav.texr=texr;
        wav.init();
    }
    light1.setAttenuation(attc,attl,attq);
    mat.setShininess(shi);
    light1.setPosition(ofVec3f(200,200,lightz));
}

void ofApp::switchTexPressed(){
    int curri = ofToInt(currenttex);

    curri++;
    if (curri>=texs.size())
        curri=0;
    wav.activetex=&texs[curri];

    currenttex = ofToString(curri);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ')
        showgui=!showgui;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
