#ifndef NECROMANCER_HPP
#define NECROMANCER_HPP

#include <set>
#include <map>
#include<vector>

#include "../Magic/SpellCaster.hpp"
#include "../Magic/Magic.hpp"
extern std::map<int, Spell> spellbook;

class Necromancer : public SpellCaster {
private:
	std::set<Unit*> victimList;
public:
	Necromancer(const std::string&, Location* location);
	~Necromancer();

	void reportDeath(int);
	void readSpell();
	void hexMagic(Unit*);
};

#endif// NECROMANCER_HPP