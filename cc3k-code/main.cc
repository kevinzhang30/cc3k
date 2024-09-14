#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> // getpid
#include "game.h"
#include "direction.h"
using namespace std;

int main(int argc, char* argv[]) {
    int seed = getpid();
    std::srand(seed);
    Game g;
    g.readChamberFloor("floorwithchambernum.txt");
    g.readEmptyFloor("emptyfloor.txt");
    g.initChambers();
    string map;
    if (argc > 1) {
        map = argv[1];
        g.readItem(map);
        g.inputMap = true;
        g.mapName = map;
    } 
    g.init();
    g.printFloor();
    string cmd;
    while (cin >> cmd) {
        if (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we" ||
            cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "sw") {
                Direction dir = stringToDir(cmd);
                g.playerMove(dir);
        } else if (cmd == "u") {
            cin >> cmd;
            Direction dir = stringToDir(cmd);
            g.playerConsume(dir);
        } else if (cmd == "a") {
            cin >> cmd;
            Direction dir = stringToDir(cmd);
            g.playerAttack(dir);
        } else if (cmd == "f") {
            g.freeze();
            if (g.isFrozen()) {
                g.addAction("Enemies are now frozen.");
            } else {
                g.addAction("Enemies are unfrozen.");
            }
        } else if (cmd == "r") {
            g.reset();
            g.resetMerchantsToNonHostile();
            if (argc > 1) {

                g.readItem(map);

            } 
            g.init();
        } else if (cmd == "q") {
            cout << "You quit. L." << endl;
            break;
        }
        if (g.isOver()) {
            std::cout << " -----     ---    -    -   -----   -----   -      -  ------  ---- " << std::endl;
            std::cout << "|         /   \\   |\\  /|  |       |     |   \\    /  |       |    |" << std::endl;
            std::cout << "|   ---  |-----|  | \\/ |  |----   |     |    \\  /   |----   |  --" << std::endl;
            std::cout << "|     |  |     |  |    |  |       |     |     \\/    |       |   \\  " << std::endl;
            std::cout << " -----                     -----   -----             -----  |    \\" << std::endl;
            std::cout << "------------------------------------------------------------------" <<std::endl;
            g.reset();
            std::cout << "Enter q to quit, any other key to play again." << std::endl;
            char c;
            cin >> c;
            if (c != 'q') {
                g.reset();
                g.resetMerchantsToNonHostile();
                if (argc > 1) {
                    g.readItem(map);
                }
                    g.init();
            } else {
                break;
            }
        }
        g.printFloor();
        g.removeAction();
    }
    return 0;
}
