#include<iostream>
#include "Unit.hpp"
#include "State.hpp"
#include "Magic/SpellBook.hpp" 
#include "Magic/SpellCaster.hpp"
#include "Magic/Magic.hpp"
#include "MagicAmenability.hpp"
#include "Ability.hpp"
#include "Location.hpp"
//#include "Enums.hpp"

#ifndef SIZE
#define SIZE 8
#endif // SIZE

extern std::string battlefieldMessege;
std::set<Unit*> Unit::unitList;

Unit::Unit(const std::string& name, Location* location, int maxHp, int damage, BaseAttack* unit_attack) : name(new std::string(name)),
				location(location), 
				maxHp(maxHp), damage(damage), 
				unit_attack (unit_attack) {
	this->hp = maxHp;
	this->ability = NULL;
	this->movement = 1;
	location->putUnit(this);
	this->unit_takeMagic = new MagicAmenability();
	Unit::unitList.insert(this); 
}
 Unit::~Unit() {
	delete(this->name);
	delete(this->unit_attack);
	delete(this->unit_takeMagic);
	delete(this->ability);
	this->getLocation()->moveUnit();
	Unit::unitList.erase(this);
}

const std::string& Unit::getName() const{
	return *this->name;
}
int Unit::getHp(){
	return this->hp;
}

int Unit::getMaxHp(){
	return this->maxHp;
}

int Unit::getDamage(){
	return this->damage;
}

int Unit::getMove() {
	return this->movement;
}

Location* Unit::getLocation() {
	return this->location;
}


void Unit::setHp(int newHp) {
    this->hp = newHp;
    if (this->hp >= maxHp ){
    	this->hp = maxHp;
    }
}

void Unit::setMaxHp(int newMaxHp) {
    this->maxHp = newMaxHp;
}

void Unit::setDamage(int newDamage) {
    this->damage = newDamage;
}

void Unit::setMovement(int movement) {
	this->movement = movement;
}

void Unit::setAttack(BaseAttack* attack) {
	delete(this->unit_attack);
	this->unit_attack = attack;
}

void Unit::setMagicAmenability(MagicAmenability* takeMagic)  {
	delete(this->unit_takeMagic);
	this->unit_takeMagic = takeMagic;
}

void Unit::attack(Unit* enemy) {
	if ( this->getHp() > 0 ){
		this->unit_attack->attack(this, enemy);
	}
}

void Unit::counterAttack(Unit* enemy) {
	if ( this->hp > 0 ) {
		enemy->takeCounterAttackDamage(this);
	}
}

void Unit::takeDamage(Unit* enemy) {

	int lastHp = this->getHp();
	this->setHp(this->getHp() - enemy->getDamage());
	
	if ( this->getHp() <= 0 ) {

		this->setHp(0);

		*this->state.status = "dead";
		this->reportDeath(lastHp);

		std::cout<< this->getName() << " is dead"<< std::endl;
	}
}
void Unit::takeCounterAttackDamage(Unit* enemy) {
	int lastHp = this->getHp();
	this->hp -= enemy->getDamage()/2;
	if ( this->hp <= 0 ) {
		this->hp = 0;

		*this->state.status = "dead";
		this->reportDeath(lastHp);
		std::cout<< this->getName() << " is dead"<< std::endl;
	}
}
void Unit::takeMagic(SpellCaster* sorcerer){
	this->unit_takeMagic->takeMagic(this, sorcerer);

}

std::set <Unit*> Unit::getReportList(){
	return this->reportList;
}

void Unit::insertObserver(Unit* unit) {
	this->reportList.insert(unit);
}

void Unit::deleteObserver(Unit* unit){
	this->reportList.erase(this->reportList.find(unit));
}

void Unit::reportDeath(int lastHp) {
	int countNecromancers = 0;

	for (Unit* unit : this->reportList) {
		std::cout<< *unit << std::endl;

		if (*unit->state.role == "necromancer") {
			countNecromancers += 1;
		}
	}
	if (countNecromancers){
		for (Unit* unit : this->reportList) {
			if (*unit->state.role == "necromancer"){
				unit->setHp(unit->getHp()+lastHp/countNecromancers);
			}
		}
	} 
	for (Unit* unit : this->reportList) {
			this->deleteObserver(unit);
		}
}

void Unit::changeLocation(Location* target) {
	if ( this->getHp() > 0 ){
		if( this->getLocation()->distance(target) <= this->movement && target->getX() < SIZE && target->getY() < SIZE&& target->getX() >=0 && target->getY() >= 0  ){
			if ( target->isVacant() ) {
				this->location->moveUnit();
				target->putUnit(this);
				this->location = target;
				battlefieldMessege =  this->getName() + " moved to location (" + std::to_string(this->getLocation()->getX()) + "," + std::to_string(this->getLocation()->getY()) + ")";
			} else {
				battlefieldMessege =  " location is occupied by " + target->getUnit()->getName();
			}
		} else {
				battlefieldMessege =  this->getName() + " can't move this far";
		}
	} else {
				battlefieldMessege =  this->getName() + " is dead, it can't move";
	}	
}

std::ostream& operator<<(std::ostream& out, Unit& unit) {
    out << unit.getName();
    out << " [hp: " << unit.getHp();
    out << ", dmg: " << unit.getDamage();
    out << "]";
    out << unit.state;
    out << std::endl;
    return out;
}