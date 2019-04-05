#include<iostream>
#include "WerewolfAbility.hpp"
#include "../Unit.hpp"
#include "WerewolfMagicAmenability.hpp"
#include "../Location.hpp"

WerewolfAbility::WerewolfAbility(){}
WerewolfAbility::~WerewolfAbility(){}

void WerewolfAbility::transform(Unit* unit) {
	if ( *unit->state.role == "warrior" ){
		unit->setMaxHp(2*unit->getMaxHp());
		unit->setHp(unit->getHp()*1.2);
		unit->setDamage(unit->getDamage()*2);
		*unit->state.role = "wolf";
		std::cout<< "WerewolfTransform"<<std::endl;
	} else if ( *unit->state.role == "wolf" ) {
		unit->setMaxHp(unit->getMaxHp()/2);
		unit->setHp(unit->getHp()/1.2);
		unit->setDamage(unit->getDamage()/2);
		*unit->state.role = "warrior";
	}

}

void WerewolfAbility::byte(Unit* attacker, Unit* enemy) {
	if (*enemy->state.role != "vampire" ){
		if ( attacker->getLocation()->distance(enemy->getLocation()) < RANGE::unit ) {
			delete(enemy->ability);
			enemy->ability = new WerewolfAbility();
			enemy->setMagicAmenability(new WerewolfMagicAmenability());
			*enemy->state.role = "warrior";
			*enemy->state.nature = "creature";

			enemy->setMaxHp(100);
			enemy->setDamage(20);
		} else { 
			std::cout<< enemy->getName() + " is out of " + attacker->getName() + "'s range of attack "<<std::endl;
	 	}
	}
}