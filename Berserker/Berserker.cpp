#include "Berserker.hpp"
#include "../BaseAttack.hpp"
#include "BerserkerMagicAmenability.hpp"

Berserker::Berserker(const std::string& name, Location* location): Unit(name, location, 120, 40, new BaseAttack()) {
	this->ability = NULL;
    this->unit_takeMagic = new BerserkerMagicAmenability();
    *this->state.role = "berserker";
    *this->state.status = "alive";
    *this->state.nature = "creature";
}

Berserker::~Berserker() {}



