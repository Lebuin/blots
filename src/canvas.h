#pragma once

#include "ofMain.h"
#include "types.h"
#include "todolist.h"

class Canvas {

public:

    Canvas(int, int);

    void add(int, int, ofColor);
    void add(Coor, ofColor);
    ofColor get(int, int);
    ofColor get(Coor);
    void draw();

private:

    ofImage img;

};
