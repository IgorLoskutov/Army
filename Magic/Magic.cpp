#include "Magic.hpp"
#include<iostream>
#include "../Unit.hpp"
#include "SpellCaster.hpp"
#include "SpellBook.hpp"
#include<map>

extern std::map<int, Spell> spellbook;

Magic::Magic(Spell* spell) : spellname(&spell->spellname), hpAffect(spell->hpAffect), cost(spell->cost){}
Magic::Magic(std::string& name, int hpAffect, int cost) : spellname(&name), hpAffect(hpAffect), cost(cost){}

Magic::~Magic(){}


std::string* Magic::getName(){
	return this->spellname;
}
int Magic::getCost(){
	return this->cost;
}
int Magic::getHpAffect() {
	return this->hpAffect;
}

