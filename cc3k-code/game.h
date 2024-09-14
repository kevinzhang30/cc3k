#ifndef GAME_H
#define GAME_H
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <iostream>
#include <sstream>
//#include "character.h"
//#include "player.h"
//#include "enemy.h"
//#include "item.h"
//#include "gold.h"
//#include "potion.h"
#include "player_races/shade.h"
#include "player_races/drow.h"
#include "player_races/vampire.h"
#include "player_races/troll.h"
#include "player_races/goblin.h"
#include "enemy_races/human.h"
#include "enemy_races/dwarf.h"
#include "enemy_races/halfling.h"
#include "enemy_races/orc.h"
#include "enemy_races/elf.h"
#include "enemy_races/merchant.h"
#include "enemy_races/dragon.h"
#include "gold_types/dragonhoard.h"
#include "gold_types/merchanthoard.h"
#include "gold_types/humanpile.h"
#include "gold_types/normalpile.h"
#include "gold_types/smallpile.h"
#include "potion_types/boostatk.h"
#include "potion_types/boostdef.h"
#include "potion_types/poisonhealth.h"
#include "potion_types/restorehealth.h"
#include "potion_types/woundatk.h"
#include "potion_types/wounddef.h"

class Character;
class Player;
class Enemy;
class Potion;
class Gold;

class Game {
    const int WIDTH = 79;
    const int HEIGHT = 25;
    std::shared_ptr<Player> player = nullptr;
    std::pair<int, int> playerPos = make_pair(-1, -1);
    std::pair<int, int> stair;
    std::vector<std::shared_ptr<Potion>> potionList;
    std::vector<std::shared_ptr<Gold>> goldList;
    std::vector<std::shared_ptr<Enemy>> enemyList;
    std::vector<std::string> emptyFloor;
    std::vector<std::string> activeFloor;
    std::vector<std::string> chamberFloor;
    std::vector<std::vector<std::pair<int,int>>> chamberList;
    int level = 1;
    bool win, over; 
    bool frozen;
    std::string action;
    bool playerOnGuarded;
    int guardedCol, guardedRow;
  public:
    bool inputMap = false;
    std::string mapName;
    Game();
    void readChamberFloor(string fileName);
    void readEmptyFloor(string fileName);
    void initActiveFloor();
    void initChambers();
    void readItem(string fileName);
    std::pair<int, int> randomPosition();
    char charAtChamber(int col, int row) const;
    char charAtEmpty(int col, int row) const;
    char getCharAt(int col, int row) const;
    void setCharAt(int col, int row, char c);
    void initPlayer(char const &type, bool newGame);
    void initStairs();
    void initPotions();
    void initTreasure();
    void initEnemies();
    void orderEnemies();
    void playerMove(Direction d);
    void playerAttack(Direction d);
    void playerConsume(Direction d);
    void enemiesRespond();
    void addTreasure(std::shared_ptr<Gold> pile, int col, int row);
    void freeze();
    bool isFrozen() const;
    void printFloor() const;
    void newLevel();
    void gameOver();
    void addAction(string s);
    void addToAction(string s);
    void removeAction();
    string generateMessage() const;
    void reset();
    void init();
    bool isOver() const;
    void resetMerchantsToNonHostile();
    //bool isQuit() const;
};



#endif
