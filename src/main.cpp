#include "ofMain.h"
#include "testApp.h"
#include "types.h"

//========================================================================
int main(){

	ofSetupOpenGL(SCR_WIDTH, SCR_HEIGHT, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new testApp());

}
