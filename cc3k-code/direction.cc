#include "direction.h"

pair <int, int> relativePosition(Direction d) {
    switch (d)
    {
        case Direction::no:
            return pair<int, int>{0, -1};
            break;
        case Direction::so:
            return pair<int, int>{0, 1};
            break;
        case Direction::ea:
            return pair<int, int>{1, 0};
            break;
        case Direction::we:
            return pair<int, int>{-1, 0};
            break;
        case Direction::ne:
            return pair<int, int>{1, -1};
            break;
        case Direction::nw:
            return pair<int, int>{-1, -1};
            break;
        case Direction::se:
            return pair<int, int>{1, 1};
            break;
        case Direction::sw:
            return pair<int, int>{-1, 1};
            break;        
        case Direction::random:
            return relativePosition(static_cast<Direction>(rand() % 8));
            break;        
    } 
    return pair<int, int>{0, 0};
}

Direction stringToDir(string s) {
    if (s == "no") {
        return Direction::no;
    } else if (s == "so") {
        return Direction::so;
    } else if (s == "ea") {
        return Direction::ea;
    } else if (s == "we") {
        return Direction::we;
    } else if (s == "ne") {
        return Direction::ne;
    } else if (s == "nw") {
        return Direction::nw;
    } else if (s == "se") {
        return Direction::se;
    } else {
        return Direction::sw;
    }
}

string dirToString(Direction d) {
    switch (d)
    {
        case Direction::no:
            return "North";
            break;
        case Direction::so:
            return "South";
            break;
        case Direction::ea:
            return "East";
            break;
        case Direction::we:
            return "West";
            break;
        case Direction::ne:
            return "North-East";
            break;
        case Direction::nw:
            return "North-West";
            break;
        case Direction::se:
            return "South-East";
            break;
        case Direction::sw:
            return "South-West";
            break;        
        case Direction::random:
            return "Random";
            break;        
    }
    return ""; 
}
