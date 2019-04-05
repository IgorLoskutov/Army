#include "Rogue.hpp"
#include "../BaseAttack.hpp"
#include "RogueAttack.hpp"


Rogue::Rogue(const std::string& name, Location* location) : Unit(name, location, 70, 15, new RogueAttack()){
	*this->state.role = "rogue";
	*this->state.status = "alive";
	*this->state.nature = "creature";
}

Rogue::~Rogue(){}
