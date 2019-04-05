#ifndef VAMPIREABILITY_HPP
#define VAMPIREABILITY_HPP

#include "../Ability.hpp"
class Unit;

class VampireAbility : public Ability {
	public:
		VampireAbility();
		~VampireAbility();

		virtual void byte(Unit*, Unit*);

};

#endif // VAMPIREABILITY_HPP