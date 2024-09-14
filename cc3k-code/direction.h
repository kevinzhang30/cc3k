#ifndef DIRECTION_H
#define DIRECTION_H

#include <utility>
#include <string>
#include <stdlib.h> // srand/rand
using namespace std;

enum class Direction {
    no,
    so,
    ea,
    we,
    ne,
    nw,
    se,
    sw,
    random
};

pair <int, int> relativePosition(Direction d);

Direction stringToDir(string s);

string dirToString(Direction d);

#endif
