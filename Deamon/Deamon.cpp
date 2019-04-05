#include "Deamon.hpp"
#include "DeamonMagicAmenability.hpp"

Deamon::Deamon(Warlock* master, const std::string& name, Location* location) : Soldier(name, location){
	
	*state.status = "dead";
	*state.role = "deamon";
	this->master = master;  
	this->unit_takeMagic = new DeamonMagicAmenability();
}

Deamon::~Deamon(){}

void Deamon::takeDamage(Unit* enemy){

	int lastHp = this->getHp();
	this->setHp(this->getHp() - enemy->getDamage());
	
	if ( this->getHp() <= 0 ) {

		this->setHp(0);

		*this->state.status = "dead";
		this->reportDeath(lastHp);
		std::cout<< this->getName() << " is dead"<< std::endl;

		//delete(this);
	}
}

void Deamon::takeCounerAttackDamage(Unit* enemy){

	int lastHp = this->getHp();
	this->setHp(this->getHp() - enemy->getDamage()/2);
	if ( this->getHp() <= 0 ) {
		this->setHp(0);

		*this->state.status = "dead";
		this->reportDeath(lastHp);
		std::cout<< this->getName() << " is dead"<< std::endl;
		//delete(this);
	}
}

void Deamon::reportDeath(int lastHp){
	this->master->spawn.erase(this);

}