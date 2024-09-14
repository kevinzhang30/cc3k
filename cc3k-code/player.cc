#include "player.h"
#include "game.h"

char const pChar = '@';

Player::Player(int col, int row, int acc, int agl, int hp, float atk, float def, Game * game, int gold, int maxHp, float potMult) :
    Character{col, row, acc, agl, hp, gold, atk, def, game}, maxHp{maxHp}, consumed{make_unique<NoPotion>(atk, def)}, potMult{potMult} {} // constructor

Player::~Player() {} // destructor

float Player::getMult() const {
    return potMult;
}

void Player::consume(Item * i) {
    i->consumed(this);
} // consume

void Player::resetEffects() {
    consumed = make_unique<NoPotion>(atk, def);
} // resetEffects

void Player::move(Direction d) {
    pair<int, int> relative = relativePosition(d);
    switch(game->getCharAt(relative.first + col, relative.second + row)) {
        case '.':
        case '+':
        case '#':
        case 'G':
        case '\\':
            col += relative.first;
            row += relative.second;
            break;
        default:
            game->addAction("Invalid Move.");
            break;
    }
} // move

char Player::getChar() const {
    return pChar;
} // getChar

void Player::attack(Character *c) {
    int hit = rand() % acc;
    int damage = 0;
    if (hit == 0) {
        damage = ceil((100.0 / (100 + c->getDef()))*(consumed->getAtk()));
    }
    c->defend(damage);
} // attack

float Player::getAtk() const {
    return consumed->getAtk();
} // getDef

float Player::getDef() const {
    return consumed->getDef();
} // getDef

void Player::alterHp(int const &amount) {
    hp = min(maxHp, max(0, hp+amount));
}

void Player::gain(int const &amount) {
    gold+=amount;
}
