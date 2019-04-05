#include "RogueAttack.hpp"


RogueAttack::RogueAttack(){}
RogueAttack::~RogueAttack(){}

void RogueAttack::attack(Unit* attacker, Unit* enemy) {
	if ( enemy->getHp() > 0 ) {
		enemy->takeDamage(attacker);
		std::cout<<"RogueAttack..\n"<<std::endl;
	}
}