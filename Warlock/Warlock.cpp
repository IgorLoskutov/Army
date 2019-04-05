#include "Warlock.hpp"
#include "../Location.hpp"



#ifndef SIZE
#define SIZE 8
#endif

extern Location* battlefield[SIZE][SIZE];
extern std::string battlefieldMessege;



Warlock::Warlock(const std::string& name, Location* location) : SpellCaster(name, location) {
	this->spawn;
	*this->state.role = "warlock";
    *this->state.status = "alive";
}

Warlock::~Warlock(){}




void Warlock::readSpell() {
    if( *this->state.role != "warlock" ){
        delete (this->magic);
        this->magic = NULL;
        return;
    }

    int choice;
    std::vector<int> pickSpell;

    pickSpell = SpellCaster::openBook();
    std::cout<< battlefieldMessege;
    
    if (!pickSpell.size()) {
        std::cout<< "........\n but you can`t.\n ..poor bastard"<< std::endl;
        return;
    }
    
    choice = SpellCaster::chooseSpell(pickSpell);
    
    
    if (this->magic != NULL) {
        delete (this->magic);
        this->magic = NULL;
    }


    if ( spellbook[choice].spellname == "summon Deamon"){
        int this_i = this->getLocation()->getX();
        int this_j = this->getLocation()->getY();
        Location* putDeamon = this->getLocation();

        for (int i = this_i - 1; i <= this_i+1;i++) {
            if (i < 0 || i >= SIZE) {
                continue;
            }
            for ( int j = this_j - 1; j <= this_j+1; j++ ) {
                if (j < 0 || j >= SIZE) {
                    continue;
                }

                if ( battlefield[i][j]->isVacant() ) {
                    putDeamon = battlefield[i][j];
                    break;
                }
            }
        } 

        if ( putDeamon != this->getLocation()) {
            if(this->getMana() >= spellbook[choice].cost ) {
                this->setMana(this->getMana() - spellbook[choice].cost);

                int deamonNo = this->spawn.size() + 1;
                this->spawn.insert(new Deamon(this, (this->getName() + "_Deamon" + std::to_string(deamonNo)), putDeamon));
                std::cout<< this->getName() + "_Deamon" + std::to_string(deamonNo) + " created at location(" + std::to_string(putDeamon->getX()) + ", " + std::to_string(putDeamon->getY()) + ")";
            } else {
                battlefieldMessege = "no enough mana to summon a Deamon";
            }
        }else {
                battlefieldMessege = "no place for the Deamon";
        }
        return;
    }

    if (spellbook[choice].role == *this->state.role || spellbook[choice].role == "wizard" ) {
        this->magic = new Magic(&spellbook[choice]);
        return;
    }
    if (spellbook[choice].role == "healer" ) {
        this->magic = new Magic(spellbook[choice].spellname, spellbook[choice].hpAffect / 2, spellbook[choice].cost );
        return;
    }
}
