#pragma once

#include "ofMain.h"
#include "types.h"
#include "todolist.h"
#include "canvas.h"

using namespace std;

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        void add_neighbours(int, int);
        void add_neighbours(Coor);
        ofColor calculate_color(int, int);
        ofColor calculate_color(Coor);
        int add_color(int*, ofColor);
        float rand_nozero(int);


        // Variables for the randomization.
        float randomize_prob[3] = {0.05, 0.05, 0.05};
        float randomize_bias[3] = {0.0, 0.0, 0.0};
        float randomize[3][2];
        std::default_random_engine generator;
        std::uniform_real_distribution<double> rand01;

        // The number of pixels that have to be drawn each cycle.
        int num_pixels = 100;
        // The priority queue that implements the todo list.
        TodoList todo = TodoList();
        // The canvas on which the pixels will be drawn.
        Canvas canvas = Canvas(SCR_WIDTH, SCR_HEIGHT);

        //ofColor seed_color = ofColor(137, 13, 7);
        ofColor seed_color = ofColor(130, 20, 20);
        Coor neighbours[4] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };

};
