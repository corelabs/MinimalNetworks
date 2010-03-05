#ifndef _TEST_APP
#define _TEST_APP



#include "ofMain.h"
#include "ofPlane.h"
#include "ofxALSoundPlayer.h"
#include "pause.h"

#define TAM_PLANE 12

class testApp : public ofBaseApp{

	private:
        int counter;
        int resetX;
        int resetY;
        int resetW;
        int resetH;
        int MAX_PLANES;
		int thetime;
		int newtime;
	
		double intthetime;
	
		bool gameover;

	public:

		void setup();
		void update();
		void draw();
	
		void checkHit(int x, int y);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

		//float 			counter;
		float j;
		
		ofTrueTypeFont  tempesta;
	
		char            eventString[255];
		char            timeString[255];
		char            counterString[255];
		char            resetString[255];

        CPlane          **planes;
        CPlane          *plane;
        CPlane          *lastPlane;
        ofRectangle     **rectangles;
		
		Pause			*pause;
	

		ofxALSoundPlayer connection;
	

};

#endif

