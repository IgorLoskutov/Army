#ifndef WEREWOLFABILITY_HPP
#define WEREWOLFABILITY_HPP

#include "../Ability.hpp"
class Unit;

class WerewolfAbility : public Ability {
	public:
		WerewolfAbility();
		~WerewolfAbility();

		virtual void transform(Unit*);
		virtual void byte(Unit*, Unit*);

};

#endif // WEREWOLFABILITY_HPP