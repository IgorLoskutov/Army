#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <set>
#include <map>
#include "../Magic/SpellCaster.hpp"
#include "../Deamon/Deamon.hpp"
#include "../Magic/Magic.hpp"
extern std::map<int, Spell> spellbook;

class Deamon;
class Warlock : public SpellCaster {
private:
	
public:
	std::set<Deamon*> spawn;
	Warlock(const std::string&, Location*);
	~Warlock();

	void readSpell();
	//void hexMagic(Unit*);

};

#endif //WARLOCK_HPP