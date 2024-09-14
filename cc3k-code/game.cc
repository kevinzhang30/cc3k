#include <fstream>
#include <iostream>
#include "game.h"
#include "player.h"
#include "enemy.h"
#include "potion.h"
#include "gold.h"


Game::Game() : level{1}, win{false}, over{false}, frozen{false}, playerOnGuarded{false} {} // constructor

void Game::readChamberFloor(string fileName) {
    ifstream ifs{fileName};
    if (ifs.is_open()) {
        string line;
        for (int i = 0; i < HEIGHT && getline(ifs, line); i++){
            chamberFloor.push_back(line);
        }
    }
} // readChamberFloor

void Game::readEmptyFloor(string fileName) {
    ifstream ifs{fileName};
    if (ifs.is_open()) {
        string line;
        for (int i = 0; i < HEIGHT && getline(ifs, line); i++){
            emptyFloor.push_back(line);
        }
    }
} // readEmptyFloor

void Game::initActiveFloor() {
    activeFloor = emptyFloor;
} // initActiveFloor

void Game::initChambers(){
    char c;
    std::pair<int, int> rowColPair;
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            c = chamberFloor[i][j];
            rowColPair.first = j;
            rowColPair.second = i;
            if ((c > '0') && (c <= '9')) {
                size_t chamberNum = c - '0'; 
                if (chamberList.size() < chamberNum ){
                    std::vector<std::pair<int,int>> tempVec;
                    tempVec.push_back(rowColPair);
                    chamberList.push_back(tempVec);
                } else {
                    chamberList[chamberNum - 1].push_back(rowColPair);
                }
            }
        }
    }
} // initChambers

void Game::readItem(string fileName) {
    ifstream ifs{fileName};
    if (ifs.is_open()) {
        string line;
        for (int i = 0; i < HEIGHT && getline(ifs, line); i++) {
            for (int j = 0; j < WIDTH; j++) {
                switch (line[j]) {
                    case ' ':
                    case '-':
                    case '|':
                    case '+':
                    case '#':
                    case '.':
                        break;
                    case 'H': {
                        auto humanPtr = std::make_shared<Human>(j, i, this);
                        enemyList.push_back(humanPtr);
                        break;
                    }
                    case 'W': {
                        auto dwarfPtr = std::make_shared<Dwarf>(j, i, this);
                        enemyList.push_back(dwarfPtr);
                        break;
                    }
                    case 'E': {
                        auto elfPtr = std::make_shared<Elf>(j, i, this);
                        enemyList.push_back(elfPtr);
                        break;
                    }
                    case 'O': {
                        auto orcPtr = std::make_shared<Orc>(j, i, this);
                        enemyList.push_back(orcPtr);
                        break;
                    }
                    case 'L': {
                        auto halflingPtr = std::make_shared<Halfling>(j, i, this);
                        enemyList.push_back(halflingPtr);
                        break;
                    }
                    case 'M': {
                        auto merchantPtr = std::make_shared<Merchant>(j, i, this);
                        enemyList.push_back(merchantPtr);
                        break;
                    }
                    case 'D': {
                        break;
                    }
                    case '0': {
                        auto rhPtr = std::make_shared<RH>(j, i);
                        potionList.push_back(rhPtr);
                        line[j] = 'P';
                        break;
                    }
                    case '1': {
                        auto baPtr = std::make_shared<BA>(j, i);
                        potionList.push_back(baPtr);
                        line[j] = 'P';
                        break;
                    }
                    case '2': {
                        auto bdPtr = std::make_shared<BD>(j, i);
                        potionList.push_back(bdPtr);
                        line[j] = 'P';
                        break;
                    }
                    case '3': {
                        auto phPtr = std::make_shared<PH>(j, i);
                        potionList.push_back(phPtr);
                        line[j] = 'P';
                        break;
                    }
                    case '4': {
                        auto waPtr = std::make_shared<WA>(j, i);
                        potionList.push_back(waPtr);
                        line[j] = 'P';
                        break;
                    }
                    case '5': {
                        auto wdPtr = std::make_shared<WD>(j, i);
                        potionList.push_back(wdPtr);
                        line[j] = 'P';
                        break;
                    }
                    case '6': {
                        auto normalPilePtr = std::make_shared<NormalPile>(j, i);
                        goldList.push_back(normalPilePtr);
                        line[j] = 'G';
                        break;
                    }
                    case '7': {
                        auto smallPilePtr = std::make_shared<SmallPile>(j, i);
                        goldList.push_back(smallPilePtr);
                        line[j] = 'G';
                        break;
                    }
                    case '8': {
                        auto merchantHoardPtr = std::make_shared<MerchantHoard>(j, i);
                        goldList.push_back(merchantHoardPtr);
                        line[j] = 'G';
                        break;
                    }
                    case '9': {
                        auto dragonHoardPtr = std::make_shared<DragonHoard>(j, i);
                        goldList.push_back(dragonHoardPtr);
                        line[j] = 'G';
                        break;
                    }
                    case '\\': {
                        stair.first = j;
                        stair.second = i;
                        break;
                    }
                    case '@': {
                        playerPos = make_pair(j ,i);
                        break;
                    }
                }

            }
            activeFloor.push_back(line);
        }
        // go through potion list for dragon hoard then find dragon
        for (size_t i = 0; i < goldList.size(); ++i) {     
            if (goldList[i]->getType() == "Dragon") {
                // look for surrounding for dragon
                int gCol = goldList[i]->getCol();
                int gRow = goldList[i]->getRow();
                for (int j = 0; j < 8; ++j) {
                    pair <int, int> rPos = relativePosition(static_cast<Direction>(j));
                    if (getCharAt(gCol+rPos.first, gRow+rPos.second) == 'D') {
                        auto dragonPtr = std::make_shared<Dragon>(gCol+rPos.first, gRow+rPos.second, this, static_cast<DragonHoard*>(goldList[i].get()));
                        enemyList.push_back(dragonPtr);
                        break;
                    }
                    
                }
            }
        }
    } 
} // readItem

std::pair<int, int> Game::randomPosition() {
    int chamber = rand() % chamberList.size();
    int size = chamberList[chamber].size();
    int tile = rand() % size;
    return chamberList[chamber][tile];
} // randomPosition

char Game::charAtChamber(int col, int row) const {
    std::string rowString = chamberFloor[row];
    return rowString[col];
} // charAtChamber

char Game::charAtEmpty(int col, int row) const {
    return emptyFloor[row][col];
} // charAtEmpty

char Game::getCharAt(int col, int row) const {
    return activeFloor[row][col];
} // getCharAt

void Game::setCharAt(int col, int row, char c) {
    std::string& rowString = activeFloor[row];
    rowString[col] = c; 
} // setCharAt

void Game::initPlayer(char const &type, bool newGame) {
    std::pair<int, int> pos = randomPosition();
    if (newGame) {
        switch (type) {
            case 's':
                player = std::make_shared<Shade>(pos.first, pos.second, this);
                break;
            case 'd':
                player = std::make_shared<Drow>(pos.first, pos.second, this);
                break;
            case 'v':
                player = std::make_shared<Vampire>(pos.first, pos.second, this);
                break; 
            case 't':
                player = std::make_shared<Troll>(pos.first, pos.second, this);
                break;
            case 'g':
                player = std::make_shared<Goblin>(pos.first, pos.second, this);
                break;
            default:
                player = std::make_shared<Shade>(pos.first, pos.second, this);
                break;
        }
        addAction("The Player has spawned.");
    } else {
        player->setCol(pos.first);
        player->setRow(pos.second);
        addAction("The Player has reached level " + std::to_string(level) + ".");
    }
    setCharAt(pos.first, pos.second, player->getChar());
} // initPlayer

void Game::initStairs() {
    char playerChamber = charAtChamber(player->getCol(), player->getRow());
    while (true) {
        std::pair<int, int> pos = randomPosition();
        if (charAtChamber(pos.first, pos.second) != playerChamber) {
            setCharAt(pos.first, pos.second, '\\');
            break;
        }
    }
} // initStair

void Game::initPotions() {
    for (int i = 0; i < 10; ++i) {
        while (true) {
            std::pair<int, int> pos = randomPosition();
            if (getCharAt(pos.first, pos.second) == '.') {
                setCharAt(pos.first, pos.second, 'P');
                std::shared_ptr<Potion> potionPtr;
                switch (rand() % 6) {
                    case 0:
                        potionPtr = std::make_shared<RH>(pos.first, pos.second);
                        break;
                    case 1:
                        potionPtr = std::make_shared<BA>(pos.first, pos.second);
                        break;
                    case 2:
                        potionPtr = std::make_shared<BD>(pos.first, pos.second);
                        break;
                    case 3:
                        potionPtr = std::make_shared<PH>(pos.first, pos.second);
                        break;
                    case 4:
                        potionPtr = std::make_shared<WA>(pos.first, pos.second);
                        break;
                    case 5:
                        potionPtr = std::make_shared<WD>(pos.first, pos.second);
                        break;
                }
                potionList.push_back(potionPtr);
                break;
            }
        }
    }
} // initPotions

void Game::initTreasure() {
    for (int i = 0; i < 10; ++i) {
        while (true) {
            std::pair<int, int> pos = randomPosition();
            if (getCharAt(pos.first, pos.second) == '.') {
                setCharAt(pos.first, pos.second, 'G');
                std::shared_ptr<Gold> goldPtr;
                std::shared_ptr<DragonHoard> dragonHoardPtr;
                switch (rand() % 8) {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        goldPtr = std::make_shared<NormalPile>(pos.first, pos.second);
                        goldList.push_back(goldPtr);
                        break;
                    case 5:
                    case 6:
                        goldPtr = std::make_shared<SmallPile>(pos.first, pos.second);
                        goldList.push_back(goldPtr);
                        break;
                    case 7:
                        dragonHoardPtr = std::make_shared<DragonHoard>(pos.first, pos.second);
                        while (true) {
                            std::pair<int, int> rPos = relativePosition(Direction::random);
                            if (getCharAt(rPos.first + pos.first, rPos.second + pos.second) == '.') {
                                std::shared_ptr<Dragon> dragonPtr = std::make_shared<Dragon>(rPos.first + pos.first, rPos.second + pos.second, this, dragonHoardPtr.get());
                                setCharAt(rPos.first + pos.first, rPos.second + pos.second, dragonPtr.get()->getChar());
                                enemyList.push_back(dragonPtr);
                                break;
                            }
                        }
                        goldList.push_back(dragonHoardPtr);
                        break;
                }
                break;
            }
        }
    }
} // initTreasure()

void Game::initEnemies() {
    for (int i = 0; i < 20; ++i) {
        while (true) {
            std::pair<int, int> pos = randomPosition();
            if (getCharAt(pos.first, pos.second) == '.') {
                std::shared_ptr<Enemy> enemyPtr;
                switch (rand() % 18) {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                        enemyPtr = std::make_shared<Human>(pos.first, pos.second, this);
                        setCharAt(pos.first, pos.second, enemyPtr.get()->getChar());
                        break;
                    case 4:
                    case 5:
                    case 6:
                        enemyPtr = std::make_shared<Dwarf>(pos.first, pos.second, this);
                        setCharAt(pos.first, pos.second, enemyPtr.get()->getChar());            
                        break;
                    case 7:
                    case 8:
                    case 9:
                    case 10:
                    case 11:
                        enemyPtr = std::make_shared<Halfling>(pos.first, pos.second, this);
                        setCharAt(pos.first, pos.second, enemyPtr.get()->getChar());
                        break;
                    case 12:
                    case 13:
                        enemyPtr = std::make_shared<Elf>(pos.first, pos.second, this);
                        setCharAt(pos.first, pos.second, enemyPtr.get()->getChar());
                        break;
                    case 14:
                    case 15:
                        enemyPtr = std::make_shared<Orc>(pos.first, pos.second, this);
                        setCharAt(pos.first, pos.second, enemyPtr.get()->getChar());
                        break;
                    case 16:
                    case 17:
                        enemyPtr = std::make_shared<Merchant>(pos.first, pos.second, this);
                        setCharAt(pos.first, pos.second, enemyPtr.get()->getChar());
                        break;
                }
                if (enemyPtr) {
                    enemyList.push_back(enemyPtr);
                }
                break;
            }
        }
    }
} // initEnemies()

void Game::orderEnemies() {
    std::sort(enemyList.begin(), enemyList.end(), [](std::shared_ptr<Enemy>a, std::shared_ptr<Enemy>b) {
        if (a->getRow() == b->getRow()) {
            return a->getCol() < b->getCol(); 
        }
        return a->getRow() < b->getRow();
    });
} // orderEnemies()

void Game::playerMove(Direction d) {
    int ogCol = player->getCol();
    int ogRow = player->getRow();
    player->move(d);
    string direction = dirToString(d);
    int newCol = player->getCol();
    int newRow = player->getRow();
    switch (getCharAt(newCol, newRow)) {
        case '.':
            setCharAt(newCol, newRow, player->getChar());
            setCharAt(ogCol, ogRow, charAtEmpty(ogCol, ogRow));
            addAction("The Player moves " + direction + ".");
            if (playerOnGuarded) {
                setCharAt(guardedCol, guardedRow, 'G');
            }
            enemiesRespond();
            break;
        case '+':
            setCharAt(newCol, newRow, player->getChar());
            setCharAt(ogCol, ogRow, charAtEmpty(ogCol, ogRow));
            addAction("The Player moves " + direction + " into a door.");
            if (playerOnGuarded) {
                setCharAt(guardedCol, guardedRow, 'G');
            }
            enemiesRespond();
            break;
        case '#':
            setCharAt(newCol, newRow, player->getChar());
            setCharAt(ogCol, ogRow, charAtEmpty(ogCol, ogRow));
            addAction("The Player moves " + direction + " through a passage.");
            if (playerOnGuarded) {
                setCharAt(guardedCol, guardedRow, 'G');
            }
            enemiesRespond();
            break;
        case 'G':
            for (size_t i = 0; i < goldList.size(); ++i) {
                if (goldList[i]->getRow() == newRow && goldList[i]->getCol() == newCol) {
                    if (goldList[i]->isGuarded()) {
                        playerOnGuarded = true;
                        guardedCol = newCol;
                        guardedRow = newRow;
                        setCharAt(newCol, newRow, player->getChar());
                        setCharAt(ogCol, ogRow, charAtEmpty(ogCol, ogRow));
                    } else {
                        player->consume(goldList[i].get());
                        addAction("The Player moves " + direction + " and picks up " + goldList[i].get()->getType() + " treasure (+" + std::to_string(goldList[i].get()->getValue()) + ").");
                        goldList.erase(goldList.begin() + i);
                        setCharAt(newCol, newRow, player->getChar());
                        setCharAt(ogCol, ogRow, charAtEmpty(ogCol, ogRow));
                        if (playerOnGuarded) {
                            setCharAt(guardedCol, guardedRow, 'G');
                        }
                    }
                    break;
                }
            }
            enemiesRespond();
            break;
        case '\\':
            if (level == 5) {
                win = true;
                gameOver();
            } else {
                addAction("The Player reached the next floor. ");
                newLevel();
            }
            if (playerOnGuarded) {
                setCharAt(guardedCol, guardedRow, 'G');
            }
            break;
    }
} // playerMove

void Game::playerAttack(Direction d) {
    bool attackValid = false;
    std::pair<int, int> rPos = relativePosition(d);
    int enemyCol = player->getCol() + rPos.first;
    int enemyRow = player->getRow() + rPos.second;
    for (size_t i = 0; i < enemyList.size(); ++i) {
        if (enemyList[i]->getRow() == enemyRow && enemyList[i]->getCol() == enemyCol) {
            attackValid = true;
            int initEnemyHp = enemyList[i]->getHp();
            player->attack(enemyList[i].get());
            int remEnemyHp = enemyList[i]->getHp();
            std::string enemyRace = enemyList[i]->getRace();
            addAction("The Player attacked the " + enemyRace + " to the " + dirToString(d) + ".");
            if (initEnemyHp == remEnemyHp) {
                addToAction("The " + enemyRace + " dodged the attack.");
            } else {
                addToAction("The " + enemyRace + " lost " + std::to_string(initEnemyHp - remEnemyHp) + "hp.");
            }
            if (enemyList[i]->getHp() == 0) {
                addToAction("The Player slayed the " + enemyList[i]->getRace() + ".");
                int initGold = player->getGold();
                player->slay(enemyList[i].get());
                int newGold = player->getGold();
                enemyList.erase(enemyList.begin() + i);
                if (initGold != newGold) {
                    addToAction("The Player gained " + std::to_string(newGold - initGold) + " gold.");
                }
                if (playerOnGuarded) { // specific case where player kills dragon while standing on its hoard
                    for (size_t i = 0; i < goldList.size(); ++i) {
                        if (goldList[i]->getRow() == guardedRow && goldList[i]->getCol() == guardedCol) {
                            player->consume(goldList[i].get());
                            goldList.erase(goldList.begin() + i);
                            playerOnGuarded = false;
                            setCharAt(guardedCol, guardedRow, player->getChar());
                            if (initGold != newGold) {
                                addToAction("The Player gained " + std::to_string(newGold - initGold) + " gold.");
                            }
                            break;
                        }
                    }
                }
            } else {
                addToAction(enemyRace + " remaining HP: " + std::to_string(remEnemyHp) + ".");
            }
            break;
        }
    }
    if (!attackValid) {
        addAction("The Player's attack was not aimed at any enemy. ");
    }
    enemiesRespond();  
} // playerAttack

void Game::playerConsume(Direction d) {
    // check if potion is valid
    string direction = dirToString(d);
    std::pair<int, int> rPos = relativePosition(d);
    int potionCol = player->getCol() + rPos.first;
    int potionRow = player->getRow() + rPos.second;
    bool potionValid = false;
    for (size_t i = 0; i < potionList.size(); ++i) {
        if (potionList[i]->getRow() == potionRow && potionList[i]->getCol() == potionCol) {
            potionValid = true;
            player->consume(potionList[i].get());
            addAction("The Player uses the " + potionList[i].get()->getType() + " to its " + direction + " " + potionList[i].get()->getEffect() + ".");
            potionList.erase(potionList.begin() + i);
            setCharAt(potionCol, potionRow, charAtEmpty(potionCol, potionRow));
            break;
        }
    }
    if (!potionValid) {
        addAction("There is no potion at that direction. ");
    }
    enemiesRespond();
} // playerConsume

void Game::enemiesRespond()  {
    orderEnemies();
    for (size_t i = 0; i < enemyList.size(); ++i) {
        enemyList[i]->respond(player.get());
        if (player->getHp() == 0) {
        gameOver();
        break;
    }
       
    }
} // enemiesRespond

void Game::addTreasure(std::shared_ptr<Gold> pile, int col, int row) {
    goldList.push_back(pile);
    setCharAt(col, row, 'G');
} // addTreasure

void Game::freeze() {
    frozen = !frozen;
} // freeze

bool Game::isFrozen() const {
    return frozen;
} // frozen

// Define ANSI color codes
const std::string RESET = "\033[0m";
const std::string BLUE = "\033[34m";
const std::string RED = "\033[31m";
const std::string YELLOW = "\033[33m";
const std::string GREEN = "\033[32m";

void Game::printFloor() const {
    for (const auto& line : activeFloor) {
        std::string coloredLine;
        for (const auto& ch : line) {
            switch (ch) {
                case '@':
                case '\\':
                    coloredLine += BLUE + ch + RESET;
                    break;
                case 'H':
                case 'E':
                case 'W':
                case 'O':
                case 'L':
                case 'M':
                case 'D':
                    coloredLine += RED + ch + RESET;
                    break;
                case 'G':
                    coloredLine += YELLOW + ch + RESET;
                    break;
                case 'P':
                    coloredLine += GREEN + ch + RESET;
                    break;
                default:
                    coloredLine += ch;
                    break;
            }
        }
        std::cout << coloredLine << std::endl;
    }
    std::cout << generateMessage() << endl;
} // printFloor

void Game::newLevel() {
    ++level;
    potionList.clear();
    goldList.clear();
    enemyList.clear();
    player->resetEffects();
    if (inputMap) {
        activeFloor.clear();
        readItem(mapName);
        player->setCol(playerPos.first);
        player->setRow(playerPos.second);
        addAction("Continuing game from input file.");
    } else {
        initActiveFloor();
        initPlayer(player->getChar(), false);
        initStairs();
        initPotions();
        initTreasure();
        initEnemies();
    }

} // newLevel()

void Game::gameOver() {
    over = true;
    if (win) {
        std::cout << "Congratulations you beat the game!" << '\n' << "Your score is: ";
        if (player->getRace() == "Shade") {
            std::cout << ceil(player->getGold() * 1.5) << std::endl;
        } else {
            std::cout << player->getGold() << std::endl;
        }
    } else {
        std::cout << "Ha you died. L Bozo." << std::endl;
    }
} // gameOver()

void Game::addAction(string s) {
    action = s;
} // addAction

void Game::addToAction(string s) {
    action += " " + s;
}

void Game::removeAction() {
    action = "";
} // removeAction


string Game::generateMessage() const {
    std::stringstream ss;
    ss << "Race: " << player->getRace() << " Gold: " << player->getGold() 
        << "                                                  " << "Floor " << level << '\n' 
        << "HP: " << player->getHp() << '\n' << "ATK: " << player->getAtk() << '\n' << "DEF: " << player->getDef() << '\n'
        << "Action: " << action;
    return ss.str();
} // generateMessage

void Game::reset() {
    level = 1;
    over = false;
    win = false;
    frozen = false;
    playerOnGuarded = false;
    player = nullptr;
    playerPos = make_pair(-1, -1);
    potionList.clear();
    goldList.clear();
    enemyList.clear();
    activeFloor.clear();
    std::cout << "Game restarting ..." << std::endl;
} // reset

void Game::init() {
        std::cout << "______________________________________________________________________________" << std::endl;
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        std::cout << "                          -----  -----  -----  |    /" << std::endl;
        std::cout << "                         |      |            | |   /" << std::endl;
        std::cout << "                         |      |       -----  |---  " << std::endl;
        std::cout << "                         |      |            | |   \\" << std::endl;
        std::cout << "                          -----  -----  -----  |    \\" << std::endl;
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        std::cout << "To begin game enter: \ns to play as Shade \nd to play as Drow \nv to play as Vampire \ng to play as Goblin \nt to play as Troll" << std::endl;
        char c;
        std::cin >> c;
    //if (playerPos == make_pair(-1, -1)) {
    if (!inputMap) {
        initActiveFloor();
        initPlayer(c, true);
        initStairs();
        initPotions();
        initTreasure();
        initEnemies();
    } else {
        switch (c) {
            case 's':
                player = std::make_shared<Shade>(playerPos.first, playerPos.second, this);
                break;
            case 'd':
                player = std::make_shared<Drow>(playerPos.first, playerPos.second, this);
                break;
            case 'v':
                player = std::make_shared<Vampire>(playerPos.first, playerPos.second, this);
                break; 
            case 't':
                player = std::make_shared<Troll>(playerPos.first, playerPos.second, this);
                break;
            case 'g':
                player = std::make_shared<Goblin>(playerPos.first, playerPos.second, this);
                break;
            default:
                player = std::make_shared<Shade>(playerPos.first, playerPos.second, this);
                break;
        }
        addAction("Starting game from input file.");
        }
} // init

bool Game::isOver() const{
    return over;
}
void Game::resetMerchantsToNonHostile() {
    auto merchantPtr = std::make_shared<Merchant>(-1, -1, nullptr);
    merchantPtr->setHostilityToFalse();
    merchantPtr = nullptr;
}
