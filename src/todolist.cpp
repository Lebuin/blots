# include "todolist.h"
# include "types.h"
#include <stdlib.h>

void TodoList::push(Coor coor) {
    int priority = rand() % (this->coors.size()+1);
    TodoItem item = {priority, coor};
    this->coors.push(item);
}

void TodoList::push(int x, int y) {
    this->push({x, y});
}

Coor TodoList::pop() {
    TodoItem item = coors.top();
    coors.pop();
    return item.coor;
}

bool TodoList::empty() {
    return coors.empty();
}
