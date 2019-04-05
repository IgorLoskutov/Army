#include <iostream>
#include "Soldier.hpp"
//#include "../Enums.hpp"

Soldier::Soldier(const std::string& name, Location* location) : Unit(name, location, 100, 15, new BaseAttack()) {
	*state.nature = "creature";
	*state.status = "alive";
	*state.role = "soldier";
}

Soldier::~Soldier(){}

//void Soldier::SpecialAbility(Unit* unit){}