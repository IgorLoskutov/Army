#include "Priest.hpp"
#include "../Magic/SpellCaster.hpp"
#include "../Magic/Magic.hpp"
#include "PriestAttack.hpp"

Priest::Priest(const std::string& name, Location* location): SpellCaster (name, location, new PriestAttack()) {
    this->setMana(150);
    *this->state.role = "priest";
    *this->state.status = "alive";
    *this->state.nature = "magic";
}

Priest::~Priest() {}

void Priest::readSpell() {
    if( *this->state.role != "priest" ){
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

    if ( spellbook[choice].role == *this->state.role || spellbook[choice].role == "healer" ) {
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

void Priest::counterAttack(Unit* enemy) {
    if ( this->getHp() > 0 ) {
        enemy->takeCounterAttackDamage(this);
    } 
    if (*enemy->state.status == "dead" && enemy->getHp()> 0 && this->magic->getHpAffect() > 0 ) {
        enemy->takeCounterAttackDamage(this);
    }

}


void Priest::hexMagic(Unit* unit){
   
    if (this->getMagic() != NULL && unit->getHp() > 0 && this->getMana() >= this->magic->getCost() && *this->state.nature == "magic") {
        this->setMana(this->getMana() - this->magic->getCost());
        unit->takeMagic(this);    
        if (*unit->state.status == "dead" && unit->getHp()> 0 && this->magic->getHpAffect() < 0 ) {
            unit->takeMagic(this);
        }
        std::cout<<this->getName()<< " hex spell "<< *this->getMagic()->getName() << " on "<<unit->getName()<<std::endl;
    }
}
