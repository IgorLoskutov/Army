#ifndef BASEATTACK_HPP
#define BASEATTACK_HPP

#include <iostream>
#include "Unit.hpp"


class Unit;



class BaseAttack {
    public:
        BaseAttack();
        virtual ~BaseAttack();
        
        virtual void attack(Unit* attacker, Unit* enemy);
        
};

#endif // BASEATTACK_HPP