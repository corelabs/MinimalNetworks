
#ifndef _OFPLANE_H
#define _OFPLANE_H

#include "ofMain.h"
//#include "ofxVectorGraphics.h"

class CPlane {

    public:
        int x;
        int y;
        int color;
        char eventString[255];
        //ofxVectorGraphics output;

        CPlane();
        CPlane(CPlane *plane);
        void draw();
        void update();
        void drawLine(CPlane *lastPlane);
        void mousePressed(int x, int y, int button);
        void setColor(int value);
       // void clicked(ofMouseEventArgs & _args);
        void setPos(int posX, int posY);




};

#endif
