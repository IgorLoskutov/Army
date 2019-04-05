#ifndef SPELLCASTER_HPP
#define SPELLCASTER_HPP

#include<iostream>
#include <vector>
#include <map>
#include "../Unit.hpp"
#include "SpellBook.hpp"

extern std::map<int, Spell> spellbook;

class Magic;
//class Location;

class SpellCaster : public Unit {
private:
	int mana;
protected:
    Magic* magic;
    std::vector <int> openBook();
    int chooseSpell(std::vector <int>);


public:
	SpellCaster(const std::string& name, Location* );
	SpellCaster(const std::string& name, Location* , BaseAttack*);
	virtual ~SpellCaster();
	virtual int getMana();
	virtual void setMana(int);
	
	virtual Magic* getMagic();
	
	virtual void readSpell() = 0;
	//virtual void hexMagic(SpellCaster*);
	virtual void hexMagic(Unit*);
	
};

std::ostream& operator<<(std::ostream& out, SpellCaster& unit);

#endif // SPELLCASTER_HPP