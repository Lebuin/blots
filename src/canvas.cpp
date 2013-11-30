#include "canvas.h"

Canvas::Canvas(int width, int height) {
    img.allocate(width, height, OF_IMAGE_COLOR);
    img.setColor(default_color);
}

void Canvas::add(int x, int y, ofColor color) {
    img.setColor(x, y, color);
}

void Canvas::add(Coor coor, ofColor color) {
    this->add(coor.x, coor.y, color);
}

ofColor Canvas::get(int x, int y) {
    return img.getColor(x, y);
}

ofColor Canvas::get(Coor coor) {
    return this->get(coor.x, coor.y);
}

void Canvas::draw() {
    img.update();
    img.draw(0, 0);
}
