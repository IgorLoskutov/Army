#include "Wizard.hpp"
#include "../Magic/SpellCaster.hpp"
#include "../Magic/Magic.hpp"
#include <iostream>


Wizard::Wizard(const std::string& name, Location* location): SpellCaster(name, location) {
    this->setMana(150);
    *this->state.role = "wizard";
    *this->state.status = "alive";
    *this->state.nature = "magic";
}

Wizard::~Wizard() {}

void Wizard::readSpell() {
    delete (this->magic);
    this->magic = NULL;

    if( *this->state.role != "wizard" ){
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

    if (spellbook[choice].role == *this->state.role ) {
        this->magic = new Magic(&spellbook[choice]);
        std::cout <<  spellbook[choice].spellname<<" is chosen, " << *this->state.role  << " \n";
        return;
    }
    if (spellbook[choice].role == "healer" ) {
        this->magic = new Magic(spellbook[choice].spellname, spellbook[choice].hpAffect / 2, spellbook[choice].cost );
        std::cout <<  spellbook[choice].spellname<<" is chosen, " << *this->state.role  << " \n";
        return;
    }
}