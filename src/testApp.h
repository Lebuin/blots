#pragma once

#include "ofMain.h"
#include "types.h"
#include "todolist.h"
#include "canvas.h"

#define NEIGHBOURS 4

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
        bool in_screen(int, int);
        bool in_screen(Coor);


        // Variables for the randomization.
        float randomize_prob[3] = {0.05, 0.05, 0.05};
        float randomize_bias[3] = {-0.01, 0.005, 0.005};
        float randomize[3][2];
        std::default_random_engine generator;
        std::uniform_real_distribution<double> rand01;

        int bound_colors[2][3] = {
            {100, 0, 0},
            {250, 100, 100}
        };

        // The number of pixels that have to be drawn each cycle.
        int num_pixels = 500;
        // The priority queue that implements the todo list.
        TodoList todo = TodoList();
        // The canvas on which the pixels will be drawn.
        Canvas canvas = Canvas(SCR_WIDTH, SCR_HEIGHT);

        //ofColor seed_color = ofColor(137, 13, 7);
        Coor start_point = {0, 0};
        ofColor seed_color = ofColor(150, 50, 50);
        Coor neighbours[NEIGHBOURS] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };

};
