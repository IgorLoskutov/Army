#include "../BaseAttack.hpp"
#include "../Unit.hpp"
#include "VampireAttack.hpp"

VampireAttack::VampireAttack(){}
VampireAttack::~VampireAttack(){}

	
void VampireAttack::attack(Unit* attacker , Unit* enemy ) {
	std::cout<<"VampireAttack"<<std::endl;
	if ( enemy->getHp() > 0 ) {
		int lifePower = attacker->getDamage();
		if (attacker->getDamage() > enemy->getHp() ) {
			lifePower = enemy->getHp();
		}
		enemy->takeDamage(attacker);
		attacker->setHp(attacker->getHp()+int(lifePower/4));

		enemy->counterAttack(attacker);
				
	}
}