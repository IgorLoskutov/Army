#ifndef SOLDIER_HPP
#define SOLDIER_HPP

#include <iostream>
#include "../Unit.hpp"

class Soldier : public Unit {
public:
	Soldier(const std::string&, Location*);
	virtual ~Soldier();

	//virtual void SpecialAbility(Unit*);

};


#endif  // SOLDIER_HPP