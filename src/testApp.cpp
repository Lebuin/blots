#include "testApp.h"
#include "types.h"
#include <algorithm>
#include <stdlib.h>
#include <math.h>

ofColor default_color = ofColor(0, 0, 0);

void testApp::add_neighbours(int x, int y) {
    if(x > 0 && canvas.get(x-1, y) == default_color) {
        todo.push(x-1, y);
    }
    if(y > 0 && canvas.get(x, y-1) == default_color) {
        todo.push(x, y-1);
    }
    if(x < SCR_WIDTH-1 && canvas.get(x+1, y) == default_color) {
        todo.push(x+1, y);
    }
    if(y < SCR_HEIGHT-1 && canvas.get(x, y+1) == default_color) {
        todo.push(x, y+1);
    }
}

void testApp::add_neighbours(Coor c) {
    add_neighbours(c.x, c.y);
}

ofColor testApp::calculate_color(int x, int y) {
    int n = 0;
    int total[3] = {0, 0, 0};

    if(x > 0) {
        n += this->add_color(total, canvas.get(x-1, y));
    }
    if(y > 0) {
        n += this->add_color(total, canvas.get(x, y-1));
    }
    if(x < SCR_WIDTH-1) {
        n += this->add_color(total, canvas.get(x+1, y));
    }
    if(y < SCR_WIDTH-1) {
        n += this->add_color(total, canvas.get(x, y+1));
    }

    //total[0] = total[0] / n;
    //total[1] = total[1] / n;
    //total[2] = total[2] / n;

    //total[0] += rand() % (RAND-1 + min(total[0], RAND)) - min(total[0]-1, RAND-1);
    //total[1] += rand() % (RAND-1 + min(total[1], RAND)) - min(total[1]-1, RAND-1);
    //total[2] += rand() % (RAND-1 + min(total[2], RAND)) - min(total[2]-1, RAND-1);
    //total[2] += rand() % 5 - 2;

    //total[0] = round(1.*total[0]/n + 0.1 * (rand() % (2*randomize[0]) - randomize[0]));
    //total[1] += (rand() % rand_mod[1] + rand_add[1]) / 1000;
    //total[2] += (rand() % rand_mod[2] + rand_add[2]) / 1000;
    //total[0] = round(this->rand_nozero(0) + total[0] / (float) n + drift[0]);

    int add;
    for(int i = 0; i < 3; i++) {
        do {
            add = rand() % (2*randomize[i]+1) - randomize[i] + drift[i];
        } while(add % (multiplier/2) == 0);
        total[i] = round(total[i] / (float) n + add / (float) multiplier);
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

float testApp::rand_nozero(int i) {
    int result;
    do {
        result = rand() % (2*randomize[i]+1) - randomize[i];
    } while(result % (multiplier/2) == 0);
    return result / (float) multiplier;
}

//--------------------------------------------------------------
void testApp::setup() {
    // Seed the animation.
    canvas.add(SCR_WIDTH/2, SCR_HEIGHT/2, seed_color);
    this->add_neighbours(SCR_WIDTH/2, SCR_HEIGHT/2);

    for(int i = 0; i < 3; i++) {
        randomize[i] = randomize_fl[i] * multiplier;
        drift[i] = drift_fl[i] * multiplier;
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
