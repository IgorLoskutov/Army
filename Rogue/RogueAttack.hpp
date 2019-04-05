#ifndef ROGUEATTACK_HPP
#define ROGUEATTACK_HPP

#include<iostream>
#include "../BaseAttack.hpp"
#include "../Unit.hpp"

class RogueAttack : public BaseAttack {
public:
	RogueAttack();
	virtual ~RogueAttack();

	virtual void attack(Unit* , Unit* );
};

#endif // ROGUEATTACK_HPP