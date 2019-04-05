#include "WerewolfMagicAmenability.hpp"
#include "../Unit.hpp"
#include "../Magic/SpellCaster.hpp"
#include "../Magic/Magic.hpp"

WerewolfMagicAmenability::WerewolfMagicAmenability(){}
WerewolfMagicAmenability::~WerewolfMagicAmenability(){}

void WerewolfMagicAmenability::takeMagic(Unit* unit, SpellCaster* sorcerer) {
	float extraMagicDamage = 1.5;
	if (*unit->state.role == "wolf" && sorcerer->getMagic()->getHpAffect() < 0 ) {
		unit->setHp(unit->getHp() + sorcerer->getMagic()->getHpAffect()*extraMagicDamage);
	} else {
		unit->setHp(unit->getHp() + sorcerer->getMagic()->getHpAffect());
	}
	
	if ( unit->getHp() <= 0 ) {
		unit->setHp(0);
		*unit->state.status = "dead";
		std::cout<< "dead";
	}

	if ( unit->getHp() > unit->getMaxHp() ) {
		unit->setHp(unit->getMaxHp());
	}
}
