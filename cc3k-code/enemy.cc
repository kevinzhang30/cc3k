#include "enemy.h"
#include "game.h"


Enemy::Enemy(int col, int row, int acc, int agl, int hp, float atk, float def, Game * game, int gold) :
    Character{col, row, acc, agl, hp, gold, atk, def, game} {} // constructor

Enemy::~Enemy() {} // destructor

void Enemy::move(Direction d) {
    if (d == Direction::random) {
        while (true) {
            Direction dir = static_cast<Direction>(rand() % 8);
            pair <int, int> rPos = relativePosition(dir);
            int newCol = rPos.first + col;
            int newRow = rPos.second + row;
            if (game->getCharAt(newCol, newRow) == '.') {
                game->setCharAt(col, row, '.');
                row = newRow;
                col = newCol;
                game->setCharAt(col, row, this->getChar());
                break;
            }
        }
    }
}
void Enemy::respond(Player *p) {
    int pRow = p->getRow();
    int pCol = p->getCol();
    if (abs(pRow - row) <= 1 && abs(pCol - col) <= 1) {
        int initPlayerHp = p->getHp();
        this->attack(p);
        int remPlayerHp = p->getHp();
        if (initPlayerHp == remPlayerHp) {
            game->addToAction("The " + this->getRace() + " missed its attack.");
        } else {
            game->addToAction("The " + this->getRace() + " dealt " + std::to_string(initPlayerHp - remPlayerHp) + " dmg." );
        }
    } else {
        if (!game->isFrozen()) {
            this->move();
        }
    }
}
