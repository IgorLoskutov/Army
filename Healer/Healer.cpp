#include "Healer.hpp"
#include "../Magic/SpellCaster.hpp"
#include "../Magic/Magic.hpp"


Healer::Healer(const std::string& name, Location* location): SpellCaster(name, location) {
    this->setMana(150);
    *this->state.role = "healer";
    *this->state.status = "alive";
    *this->state.nature = "magic";
}

Healer::~Healer() {}

void Healer::readSpell() {
    if( *this->state.role != "healer" ){
        delete (this->magic);
        this->magic = NULL;
        return;
    }

    int choice;
    std::vector<int> pickSpell;

    pickSpell = SpellCaster::openBook();
    
    if (!pickSpell.size()) {
        std::cout<< "........\n but you can`t.\n ..poor bastard"<< std::endl;
        return;
    }

    choice = SpellCaster::chooseSpell(pickSpell);
    delete (this->magic);
    this->magic = NULL;

    if ( spellbook[choice].role == *this->state.role ) {
        this->magic = new Magic(&spellbook[choice]);
        std::cout <<  spellbook[choice].spellname<<" is chosen, " << *this->state.role  << " \n";
        return;
    }
    if (spellbook[choice].role == "wizard" ) {
        this->magic = new Magic(spellbook[choice].spellname, spellbook[choice].hpAffect / 2, spellbook[choice].cost );
        std::cout <<  spellbook[choice].spellname<<" is chosen, " << *this->state.role  << " \n";
        return;
    }
}