#include "SpellCaster.hpp"
#include "../Unit.hpp"
#include "../BaseAttack.hpp"
#include "Magic.hpp"
#include "../Location.hpp"



SpellCaster::SpellCaster(const std::string& name, Location* location) : Unit(name, location, 70, 20, new BaseAttack()){
	this->mana = 150;
    location->putUnit(this);
	*this->state.role = "undefined";
	*this->state.status = "undefined";
	*this->state.nature = "magic";
	
}

SpellCaster::SpellCaster(const std::string& name, Location* location, BaseAttack* unit_attack) : Unit(name, location, 70, 20, unit_attack){
    this->mana = 150;
    location->putUnit(this);
    *this->state.role = "undefined";
    *this->state.status = "undefined";
    *this->state.nature = "magic";
}

SpellCaster::~SpellCaster(){}

int SpellCaster::getMana(){
	return this->mana;
}
void SpellCaster::setMana(int mana) {
	this->mana = mana;
}

Magic* SpellCaster::getMagic() {
    return this->magic;
}


std::vector <int> SpellCaster::openBook(){
    std::cout << "You are to choose your spell, "<< *this->state.role <<": \n";

    std::vector<int> options;
    for ( int i = 0; i < spellbook.size(); i++ ) {
        if ( this->getMana() >= spellbook[i].cost ) {
            if ( spellbook[i].role == *this->state.role || spellbook[i].role == "healer" || spellbook[i].role == "wizard") {
                std::cout << i << " " << spellbook[i].spellname << std::endl;
                options.push_back(i);
            }
        }
    }
    return options;
}


int SpellCaster::chooseSpell(std::vector <int> options) {
    int choice;
    bool validation = 0;
    while ( !validation ) {
        std::cin>>choice;
        if (!std::cin){
            std::cin.clear();
            std::cin.get();
        }
        std::cin.get();
        for ( int i = 0; i < options.size(); i++ ) {
            if ( (int)choice == options[i] ){
                validation = 1;
                break;
            }
        }
    }
    return choice;
}

void SpellCaster::hexMagic(Unit* unit){
    if ( this->getMagic() != NULL && unit->getHp() > 0 && this->getMana() >= this->magic->getCost() && *this->state.nature == "magic") {
        std::cout<<this->getName()<< " hex spell "<< *this->getMagic()->getName() << " on "<< unit->getName()<< std::endl;
        this->mana -= this->magic->getCost();
        unit->takeMagic(this);
    }
}
    

std::ostream& operator<<(std::ostream& out, SpellCaster& unit) {
    out << unit.getName();
    out << " [hp: " << unit.getHp();
    out << ", dmg: " << unit.getDamage();
    if ( *unit.state.nature == "magic" ) {
        out << ", mana: " << unit.getMana();
    }
    out << "]";
    out << unit.state;
    out << std::endl;
    return out;
}

