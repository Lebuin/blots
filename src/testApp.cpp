#include "testApp.h"
#include "types.h"
#include <algorithm>
#include <stdlib.h>
#include <math.h>
//#include <random>

ofColor default_color = ofColor(0, 0, 0);

void testApp::add_neighbours(int x, int y) {
    int newx, newy;
    for(int i=0; i < NEIGHBOURS; i++) {
        newx = x + neighbours[i].x;
        newy = y + neighbours[i].y;
        if(in_screen(newx, newy) && canvas.get(newx, newy) == default_color) {
            todo.push(newx, newy);
        }
    }
}
void testApp::add_neighbours(Coor c) {
    add_neighbours(c.x, c.y);
}

bool testApp::in_screen(int x, int y) {
    return x >= 0 && x < SCR_WIDTH && y >= 0 && y < SCR_HEIGHT;
}
bool testApp::in_screen(Coor c) {
    return in_screen(c.x, c.y);
}

ofColor testApp::calculate_color(int x, int y) {
    int n = 0;
    int total[3] = {0, 0, 0};

    int newx, newy;
    for(int i=0; i < NEIGHBOURS; i++) {
        newx = x + neighbours[i].x;
        newy = y + neighbours[i].y;
        if(in_screen(newx, newy)) {
            n += this->add_color(total, canvas.get(newx, newy));
        }
    }

    float r;
    for(int i=0; i < 3; i++) {
        if(rand() % 2 == 0) {
            total[i] = floor(total[i] / (float) n);
        } else {
            total[i] = ceil(total[i] / (float) n);
        }

        r = rand01(generator);
        if(r < randomize[i][0]) {
            if(total[i] == bound_colors[0][i]) {
                total[i] += bound_colors[1][i] - bound_colors[0][i];
            } else {
                total[i]--;
            }
        } else if(r < randomize[i][1]) {
            if(total[i] == bound_colors[1][i]) {
                total[i] -= bound_colors[1][i] - bound_colors[0][i];
            } else {
                total[i]++;
            }
        }
    }

    return ofColor(total[0], total[1], total[2]);
}

ofColor testApp::calculate_color(Coor c) {
    return this->calculate_color(c.x, c.y);
}

int testApp::add_color(int* total, ofColor color) {
    if(color == default_color) {
        return 0;
    } else {
        total[0] += color.r;
        total[1] += color.g;
        total[2] += color.b;
        return 1;
    }
}

//--------------------------------------------------------------
void testApp::setup() {
    // Seed the animation.
    canvas.add(start_point, seed_color);
    this->add_neighbours(start_point);

    rand01 = std::uniform_real_distribution<double>(0.0,1.0);

    for(int i = 0; i < 3; i++) {
        /*randomize[i] = randomize_fl[i] * multiplier;
        drift[i] = drift_fl[i] * multiplier;*/

        // randomize[i][0] is the probability to go one color value down.
        // randomize[i][1] - randomize[i][0] is the probability to go one color value up.
        randomize[i][0] = (randomize_prob[i]/2 - randomize_bias[i]);
        randomize[i][1] = randomize_prob[i];
    }
}

//--------------------------------------------------------------
void testApp::update() {
    int added = 0;

    while(added < num_pixels) {
        if(todo.empty()) {
            return;
        }

        Coor coor = todo.pop();
        if(canvas.get(coor) == default_color) {
            this->add_neighbours(coor);

            ofColor color = this->calculate_color(coor);
            canvas.add(coor, color);
            added++;
        }
    }
}

//--------------------------------------------------------------
void testApp::draw() {
    canvas.draw();
    ofDrawBitmapString(ofToString(ofGetFrameRate())+" fps", 15, 10);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
