#include "testApp.h"
#include "stdio.h"



//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetFrameRate(25);
	ofBackground(50,50,50);


	counter = 0;
	thetime = 150;
	gameover = false;
	
	
	//--------Initialize positions and max number of planes
	resetX = 230;
	resetY = 462;
	resetW = 80;
	resetH = 10;
    MAX_PLANES = 1000;
	
	//--------Setup pause
	pause = new Pause();

	//--------Allocate memory
	planes = new CPlane*[MAX_PLANES];
	for (int i = 0; i < MAX_PLANES; ++i)
        planes[i] = new CPlane();
	//lastPlane = NULL;
	planes[counter]->draw();
	
	//--------Load Fonts
	tempesta.loadFont(ofToDataPath("pf_tempesta_seven.ttf"),6, false, true);
	//--------Useful for multilines   
	//tempesta.setLineHeight(20.0f);
	
	//--------Sounds
	//--------creates the SoundStream
	ofSoundStreamSetup(2,0,this);
	ofSoundStreamStart();
	//--------Load sound
	connection.loadSound(ofToDataPath("connection4.wav"));
    connection.setVolume(0.5f);
	connection.play();
	connection.vibrate();
	


}


//--------------------------------------------------------------
void testApp::update(){
	//counter = counter + 0.033f;
	
	
	newtime = thetime/25;
	printf("Time: %i",newtime);
	thetime = thetime - 1;
	if (newtime < 0) 
	{
		planes = NULL;
		setup();

	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	sprintf (timeString, "Time Remaining %i",newtime);
	sprintf (counterString, "Nodes: %i", counter);
	sprintf (resetString, "Reset System");//ESTA LINEA NO HACE FALTA??
	
	//--------Title
	ofSetColor(0xFFDE00);
	tempesta.drawString("Minimal 2D Networks", 10,10);
	
	//--------How to play
	//ofSetColor(0xFFDE00);
	//tempesta.drawString("The last element creates a new node", 10,470);
	
	//--------Time remaining
	ofSetColor(0xFFDE00);
	tempesta.drawString(timeString, 10,470);
	

	//--------Display number of connections
	ofSetColor(0xFFDE00);
	tempesta.drawString(counterString, (0.8*ofGetScreenWidth()), 10);

	//--------Reset Button
	ofSetColor(255, 222, 0, 30);
    ofRect(resetX, resetY, resetW, resetH);
	ofSetColor(0x111111);
	tempesta.drawString("Pause System", resetX+5, resetY+8);

        for(int i = 0; i<=counter; ++i)
        {
            planes[i]->draw();
            if(i-1 != -1)
                planes[i]->drawLine(planes[i-1]);
        }
}

//-------- Checking if hitted. If maximum number of connections has been reached, resets the app and starts again.
//-------- if there's a hit on a plane, draw a new plane and creates a new line connection. 
//-------- if there's a hit on the RESET button, resets the app and starts again.
void testApp::checkHit(int x, int y){
	if (((x < planes[counter]->x+30) && (x > planes[counter]->x)) && ((y < planes[counter]->y+30) && (y > planes[counter]->y)))
	{
	    if(counter == MAX_PLANES-1)
	    {
			planes = NULL;
            setup();
	    }else{
            counter++;
			planes[counter]->drawLine(planes[counter-1]);
			connection.play();
			connection.vibrate();
			thetime = 150;
		}
	}

	if (((x < resetX+resetW) && (x > resetX)) && ((y < resetY+resetH) && (y > resetY)))
	{
	   //planes = NULL;
	   //setup();
		//pause->draw();
		ofSleepMillis(5000);
	}
}



//--------------------------------------------------------------

void testApp::keyPressed  (int key){
	sprintf(eventString, "keyPressed = (%i)", key);
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	sprintf(eventString, "mouseMoved = (%i,%i)", x, y);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	sprintf(eventString, "mouseDragged = (%i,%i - button %i)", x, y, button);
    //printf("CLICKED!");

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	sprintf(eventString, "mousePressed = (%i,%i - button %i)", x, y, button);
	checkHit(x, y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	sprintf(eventString, "mouseReleased = (%i,%i - button %i)", x, y, button);
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	sprintf(eventString, "resized = (%i,%i)", w, h);
}
