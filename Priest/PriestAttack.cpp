#include "PriestAttack.hpp"


PriestAttack::PriestAttack(){}
PriestAttack::~PriestAttack(){}

void PriestAttack::attack(Unit* attacker, Unit* enemy) {
	if ( enemy->getHp() > 0 ) {
		enemy->takeDamage(attacker);
		enemy->counterAttack(attacker);
		if ( enemy->getHp() > 0 && *enemy->state.status == "dead" ) {
			enemy->takeDamage(attacker);
		}
	
	std::cout<<"PriestAttack.\n"<<std::endl;
	}
}