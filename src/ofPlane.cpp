
#include "ofPlane.h"
#include "ofMain.h"

CPlane::CPlane(){
    x = int(ofRandom(0 + (0.15*ofGetScreenWidth()), ofGetScreenWidth()-(0.15*ofGetScreenWidth())));
    y = int(ofRandom(0 + (0.1*ofGetScreenHeight()), ofGetScreenHeight()- (0.1*ofGetScreenHeight())));
    //printf("Widht: %i\n", ofGetScreenWidth());
    //printf("Height: %i\n", ofGetScreenHeight());
    //printf("PLANE: x:%f, y:%f\n", x, y);
    color = 0xfafa00;

    //ofAddListener(ofEvents.mousePressed, this, &CPlane::clicked);
}

CPlane::CPlane(CPlane *plane){
    x = plane->x;
    y = plane->y;
    color = plane->color;
}


void CPlane::update(){
    x = ofRandom(0, ofGetScreenWidth()-31);
    y = ofRandom(0, ofGetScreenHeight()-31);
}

void CPlane::draw(){
    ofSetColor(255, 222, 0, 80);
    ofRect(x, y, 12, 12);
}

void CPlane::drawLine(CPlane *lastPlane){
    //printf("PointLine: x1:%i, y1:%i, x2:%i, y2:%i\n", x+15, y+15, lastPlane->x+15, lastPlane->y+15);
    ofSetColor(0x5c5c5c);
    ofLine(x+6, y+6, lastPlane->x+6, lastPlane->y+6);
}

void CPlane::setColor(int value){
    color = value;
}

void CPlane::setPos(int posX, int posY){
    x = posX;
    y = posY;
}

//void CPlane::clicked(ofMouseEventArgs & args){
    //printf("CLICKED!! x:%i, y:%i\n", args.x, args.y);

    //ofRemoveListener(ofEvents.mousePressed, this, &CPlane::clicked);
    //parent.plane = new CPlane();

//}

/*void CPlane::setParent(testApp value){
    parent = value;
}*/

/*void CPlane::mousePressed(){
	x = ofRandom(0, ofGetScreenWidth()-1);
    y = ofRandom(0, ofGetScreenHeight()-1);
    draw();

}*/

/*void CPlane::addMouseListenerPressed(){
	ofAddListener(ofEvent.)

}*/
