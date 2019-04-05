#ifndef PRIESTATTACK_HPP
#define PRIESTATTACK_HPP

#include<iostream>
#include "../BaseAttack.hpp"
#include "../Unit.hpp"

class PriestAttack : public BaseAttack {
public:
	PriestAttack();
	virtual ~PriestAttack();

	virtual void attack(Unit* , Unit* );
};

#endif // PRIESTATTACK_HPP