#include "Werewolf.hpp"
#include "../BaseAttack.hpp"
#include "WerewolfAbility.hpp"
#include "WerewolfMagicAmenability.hpp"

extern std::string battlefieldMessege;

Werewolf::Werewolf(const std::string& name, Location* location) : Unit(name, location, 100, 20, new BaseAttack()){
    this->ability = new WerewolfAbility();
    this->unit_takeMagic = new WerewolfMagicAmenability();
    *this->state.status = "alive";
    *this->state.nature = "creature";
    *this->state.role = "warrior";
}


Werewolf::~Werewolf(){}

void Werewolf::transform(){
	this->ability->transform(this);
}

void Werewolf::byte(Unit* unit) {
	if (*this->state.role == "wolf" ){
		this->ability->byte(this, unit);
	} else {
		battlefieldMessege = "only wolves and vampires can byte!";
	}
}

