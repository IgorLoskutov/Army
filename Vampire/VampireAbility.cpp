#include "Vampire.hpp"
#include "VampireAbility.hpp"
#include "VampireAttack.hpp"
#include "../Unit.hpp"
#include "../Location.hpp"

VampireAbility::VampireAbility(){}
VampireAbility::~VampireAbility(){}

void VampireAbility::byte(Unit* attacker, Unit* enemy) {
	if (*enemy->state.role != "warrior" && *enemy->state.role != "wolf" ){
		if ( attacker->getLocation()->distance(enemy->getLocation()) < RANGE::unit ) {
			delete(enemy->ability);
			enemy->ability = new VampireAbility();
			enemy->setAttack(new VampireAttack()); 
						
			*enemy->state.role = "vampire";
			*enemy->state.nature = "creature";
			*enemy->state.status = "dead";


			enemy->setMaxHp(100);
			enemy->setDamage(25);
		} else { 
			std::cout<< enemy->getName() + " is out of " + attacker->getName() + "'s range of attack "<<std::endl;
	 	}
	 }
}