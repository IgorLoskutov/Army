#ifndef UNIT_HPP
#define UNIT_HPP

#include<iostream>

#include "State.hpp"
#include "BaseAttack.hpp"
#include "Enums.hpp"
#include "Ability.hpp"
#include "MagicAmenability.hpp"
#include <set>

class SpellCaster;
class BaseAttack;
class Magic;
class Location;

class Unit {
private:
	std::string* name;
	int hp;
	int maxHp;
	int damage;
	int movement;
	Location* location;
	std::set <Unit*> reportList;
	
protected:
	BaseAttack* unit_attack;
	
	

public:
	static std::set<Unit*> unitList;
	Ability* ability;
	MagicAmenability* unit_takeMagic;
	State state;
	Unit(const std::string& name, Location* location, int maxHp,  int damage, BaseAttack* unit_attack);
	virtual ~Unit();

	const std::string& getName() const;
	virtual int getHp();
	virtual int getMaxHp();
    virtual int getDamage();
    virtual int getMove();
    virtual Location* getLocation();

    virtual void setHp(int);
    virtual void setMaxHp(int);
    virtual void setDamage(int);
    virtual void setMovement(int);
    virtual void setAttack(BaseAttack*);
    virtual void setMagicAmenability(MagicAmenability*);

    virtual void attack(Unit* enemy);
    virtual void counterAttack(Unit* enemy);

    virtual void takeDamage(Unit* enemy);
	virtual void takeCounterAttackDamage(Unit* enemy);
	virtual void takeMagic(SpellCaster*);
	
	virtual std::set <Unit*> getReportList();
	virtual void insertObserver(Unit*);
	virtual void deleteObserver(Unit*);
	virtual void reportDeath(int);
	virtual void changeLocation(Location*);

};

std::ostream& operator<<(std::ostream& out, Unit& unit);
#endif // UNIT_HPP