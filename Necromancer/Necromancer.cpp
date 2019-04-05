#include "Necromancer.hpp"


Necromancer::Necromancer(const std::string& name, Location* location) : SpellCaster(name, location) {
	*this->state.role = "necromancer";
    *this->state.status = "dead";
}

Necromancer::~Necromancer() {}

void Necromancer::readSpell() {
    delete (this->magic);
    this->magic = NULL;

    if( *this->state.role != "necromancer" ){
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

    if (spellbook[choice].role == *this->state.role || spellbook[choice].role == "wizard" ) {
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

void Necromancer::hexMagic(Unit* unit){
    
    if ( this->getMagic() != NULL && unit->getHp() > 0 && this->getMana() >= this->magic->getCost() && *this->state.nature == "magic") {
        this->victimList.insert(unit);
        unit->insertObserver(this);
        this->setMana(this->getMana() - this->magic->getCost());
        unit->takeMagic(this);

        std::cout<<this->getName()<< " hex spell "<< *this->getMagic()->getName() << " on "<<unit->getName()<<std::endl;
    }

}

void Necromancer::reportDeath(int lastHp) {
	int countNecromancers = 0;
	for (Unit* unit : this->getReportList()) {
		if (*unit->state.role == "necromancer") {
			countNecromancers += 1;
		}
	}
	for (Unit* unit : this->getReportList()) {
		unit->setHp(unit->getHp()+lastHp/countNecromancers);
	} 
	for (Unit* unit : this->victimList) {
		unit->deleteObserver(this);
	}
}

