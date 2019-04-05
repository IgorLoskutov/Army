#include "MagicAmenability.hpp"
#include "Unit.hpp"
#include "Magic/SpellCaster.hpp"
#include "Magic/Magic.hpp"

MagicAmenability::MagicAmenability(){}
MagicAmenability::~MagicAmenability(){}

void MagicAmenability::takeMagic(Unit* unit, SpellCaster* sorcerer) {
	int lastHp = unit->getHp();
	
	unit->setHp(unit->getHp() + sorcerer->getMagic()->getHpAffect());
	if ( unit->getHp() <= 0 ) {
		unit->setHp(0);
		*unit->state.status = "dead";
		unit->reportDeath(lastHp);
		std::cout<< unit->getName() << " is dead"<< std::endl;
	}

	if ( unit->getHp() > unit->getMaxHp() ) {
		unit->setHp(unit->getMaxHp());
	}
}
