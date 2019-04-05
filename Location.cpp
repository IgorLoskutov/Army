#include "Location.hpp"
#include "Unit.hpp"
#include <cmath>
std::set<Location*> Location::battlefield;

Location::Location(int x, int y) : coordX(x), coordY(y) {
	this->unit = NULL;
	battlefield.insert(this);
}

Location::~Location(){}

bool Location::isVacant(){
	if (this->unit == NULL) {
		return true;
	}
	return false;
}

int Location::getX() {
	return coordX;
}

int Location::getY() {
	return coordY;
}

Unit* Location::getUnit() {
	return this->unit;
}

std::set<Location*> Location::getBattlefield() {
	return battlefield;
}

void Location::putUnit(Unit* unit) {
	if (this->isVacant()){
		this->unit = unit;
	}

}

void Location::moveUnit() {
	this->unit = NULL;
}

int Location::distance(Location* target) {
	return hypot(this->getX() - target->getX() , this->getY() - target->getY() );
}


std::ostream& operator<<(std::ostream& out, Location& location) {
	out << location.getUnit()->getName();
}
/*const bool operator == (const Location* point1, const Location* point2){
	if ( point1->getX() == point2->getX() && point1->getY() == point2->getY() ) {
		return true;
	}
	return false;
}


*/
