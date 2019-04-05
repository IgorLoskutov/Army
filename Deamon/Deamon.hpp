#ifndef DEAMON_HPP
#define DEAMON_HPP
#include "../Soldier/Soldier.hpp"
#include "../Warlock/Warlock.hpp"

class Warlock;

class Deamon : public Soldier {
private:
	Warlock* master;
public:
	Deamon(Warlock*, const std::string&, Location* );
	~Deamon();
	void setMaster(Warlock*);
	void takeDamage(Unit* enemy);
	void takeCounerAttackDamage(Unit*);
	void reportDeath(int);
};

#endif //DEAMON_HPP