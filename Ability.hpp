#ifndef ABILITY_HPP
#define ABILITY_HPP

class Unit;

class Ability {

public:
	Ability();
	virtual ~Ability();

	virtual void transform(Unit*);
	virtual void byte(Unit*, Unit*);
	
};


#endif // ABILITY_HPP 