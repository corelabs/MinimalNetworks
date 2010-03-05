/*
 *  pause.cpp
 *  iPhone MinimalNet
 *
 *  Created by Rez on 2/14/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "pause.h"
#include "ofMain.h"


Pause::Pause()
{
	//--------Load Fonts
	pausetext.loadFont(ofToDataPath("pf_tempesta_seven.ttf"),6, false, true);

}


void Pause::update()
{

}

void Pause::draw()
{

	//ofSleepMillis(5000);
	
	//ofSetColor(255, 222, 0);
	//ofRect(0,0,320,480);
	
	ofSetColor(0xFF0000);
	pausetext.drawString("GAME PAUSED", 100,100);
	
	
}