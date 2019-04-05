#ifndef MAGICATTACK_HPP
#define MAGICATTACK_HPP

#include<iostream>
#include "../Unit.hpp"
#include "SpellCaster.hpp"
#include "SpellBook.hpp"

//class SpellCaster;

class Magic {
private:
	std::string* spellname;
	int hpAffect;
	int cost;
		
public:
	
	Magic(Spell* spell);
	Magic(std::string& name, int hpAffect, int cost);
	virtual ~Magic();

	std::string* getName();
	int getCost();
	int getHpAffect();
	
};

#endif // MAGICATTACK_HPP