#ifndef WAVE_H
#define WAVE_H
#include "ofMain.h"

class wave
{
public:
    int wid,hei,resw,resh;
    float amp,speed,freq,yang,texr;

    ofPlanePrimitive prim;
    ofMesh *mesh;
    glm::vec3 *meshpverts;
    bool drawnorms;
    ofTexture *activetex;

    wave();
    void init();
    void update();
    void draw();

    void setNormalsFromIs(int meshi,int mv1,int mv2,int mu1, int mu2);
};

#endif // WAVE_H
