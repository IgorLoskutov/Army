#include "Vampire.hpp"
#include "../Unit.hpp"
#include "VampireAbility.hpp"
#include "VampireAttack.hpp"
//#include "VampireMagicAmenability.hpp"

Vampire::Vampire(const std::string& name, Location* location) : Unit( name, location, 100, 25, new VampireAttack() ){
	this->ability = new VampireAbility();
    //this->unit_takeMagic = new VampireMagicAmenability();
    *this->state.status = "dead";
    *this->state.nature = "creature";
    *this->state.role = "vampire";
}

Vampire::~Vampire(){}

void Vampire::byte(Unit* unit) {
	if (*this->state.role == "vampire" ){
		this->ability->byte(this, unit);
	} else {
		std::cout<< "only wolves and vampires can byte!"<<std::endl;
	}
}


