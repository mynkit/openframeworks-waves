#include "wave.h"

wave::wave()
{
}

void wave::init()
{
    prim = ofPlanePrimitive((float)wid, (float)hei, resw, resh);

    mesh = prim.getMeshPtr();    
    meshpverts = mesh->getVerticesPointer();

    ofDisableArbTex();
    prim.mapTexCoords(0,texr,texr,0);
}

void wave::update()
{
    float animparam = ofGetElapsedTimef()*speed*PI/50;
    ofVec3f v;
    for (int x = 0;x<resw;x++){
        for (int y = 0;y<resh;y++){
            int meshi = x+y*resw;            
            //The "wave" equation
            float ang = animparam + (x/(float)resw) * yang + (y*hei/(float)resh) * freq;
            v.x=meshpverts[meshi].x;
            v.y=meshpverts[meshi].y;
            v.z = sin(ang)*amp;
            mesh->setVertex(meshi,v);
        }
    }

    int meshi = 0;
    for (int y = 0;y<resh-1;y++,meshi++){
        for (int x = 0;x<resw-1;x++,meshi++)
            setNormalsFromIs(meshi,+1,0,resw,0);
        setNormalsFromIs(meshi,0,-1,resw,0);
    }
    for (int x = 0;x<resw-1;x++,meshi++)
        setNormalsFromIs(meshi,+1,0,0,-resw);
    setNormalsFromIs(meshi,0,-1,0,-resw);
}

void wave::draw()
{
    activetex->bind();
    prim.draw();
    activetex->unbind();

    if (drawnorms){
        ofSetColor(ofColor::blue);
        ofSetLineWidth(2);
        prim.drawNormals(5);
    }
}

void wave::setNormalsFromIs(int meshi,int mv1,int mv2,int mu1, int mu2){
    mesh->setNormal(meshi,glm::cross(
        meshpverts[meshi+mv1] - meshpverts[meshi+mv2],
        meshpverts[meshi+mu1] - meshpverts[meshi+mu2]
    ));
}
