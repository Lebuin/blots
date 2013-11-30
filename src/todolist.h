#pragma once

#include "ofMain.h"
#include "types.h"
#include <queue>

using namespace std;

typedef struct TodoItem {
    int priority;
    Coor coor;
} Item;

class CompareTodoItem {
public:
    bool operator() (Item& i1, Item& i2) {
        return (i1.priority < i2.priority);
    }
};

class TodoList {

public:

    void push(Coor);
    void push(int, int);
    Coor pop();
    bool empty();

private:

    priority_queue<TodoItem, vector<TodoItem>, CompareTodoItem> coors;
};
