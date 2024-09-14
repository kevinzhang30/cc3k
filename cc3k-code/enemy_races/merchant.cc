#include "merchant.h"
#include "../game.h"

const int ACC = 2;
const int AGL = 1;
const int HP = 30;
const float ATK = 70;
const float DEF = 5;
const int GOLD = 0;
const char SYMBOL = 'M';
const string RACE = "Merchant";
bool HOSTILITY = false;

std::vector<Merchant*> Merchant::merchants;

Merchant::Merchant(int col, int row, Game * game) : 
    Enemy{col, row, ACC, AGL, HP, ATK, DEF, game, GOLD}, hostile{HOSTILITY} {
        merchants.push_back(this);
    } // constructor

Merchant::~Merchant() {
    auto it = std::find(merchants.begin(), merchants.end(), this);
        if (it != merchants.end()) {
            merchants.erase(it);
        }
} // destructor

char Merchant::getChar() const {
    return SYMBOL;
} // getChar

string Merchant::getRace() const {
    return RACE;
} // getRace

int Merchant::perish() {
    std::shared_ptr<MerchantHoard> merchantHoard = std::make_shared<MerchantHoard>(col, row);
    game->addTreasure(merchantHoard, col, row);
    return 0;
} // perish

bool Merchant::defend(const int &dmg) {
    if (!hostile) {
        HOSTILITY = true;
        for (size_t i = 0; i < merchants.size(); ++i) {
            merchants[i]->hostile = true;
        }
    }
    int dodge = rand() % agl;
    if (dodge == 0) {
        hp = max(hp-dmg, 0);
        return true;
    } 
    return false;
} // defend

void Merchant::respond(Player *p) {
    int pRow = p->getRow();
    int pCol = p->getCol();
    if (abs(pRow - row) <= 1 && abs(pCol - col) <= 1 && hostile) {
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
} // respond
void Merchant::setHostilityToFalse() {
     HOSTILITY = false;
}
