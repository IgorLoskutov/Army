#ifndef VAMPIREATTACK_HPP
#define VAMPIREATTACK_HPP

#include "../BaseAttack.hpp"

class Unit;

class VampireAttack : public BaseAttack {
public:
	VampireAttack();
	virtual ~VampireAttack();

	virtual void attack(Unit* , Unit* );
};


#endif // VAMPIREATTACK_HPP