#include "Unit.hpp"
#include "Location.hpp"
#include "BaseAttack.hpp"
//#include "Enums.hpp"
extern std::string battlefieldMessege;

BaseAttack::BaseAttack(){}
BaseAttack::~BaseAttack(){}

void BaseAttack::attack(Unit* attacker, Unit* enemy) {
	if ( attacker->getLocation()->distance(enemy->getLocation()) < RANGE::unit ) {
		if ( enemy->getHp() > 0 ) {
			battlefieldMessege = attacker->getName() + " attacks " + enemy->getName();
			enemy->takeDamage(attacker);
			
			enemy->counterAttack(attacker);
		}
	} else { 
		battlefieldMessege = enemy->getName() + " is out of " + attacker->getName() + "'s range of attack ";
	 }
} 

