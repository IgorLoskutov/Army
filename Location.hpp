#ifndef LOCATION_HPP
#define LOCATION_HPP
#include <set>
#include <iostream>


class Unit;

class Location {
	private:
		int coordX;
		int coordY;
		Unit* unit;
		static std::set<Location*> battlefield;

	public:
		Location(int, int);
		~Location();

		bool isVacant();
		int getX();
		int getY();
		Unit* getUnit();
		static std::set<Location*> getBattlefield();

		void putUnit(Unit*);
		void moveUnit();

		int distance(Location*);
};

std::ostream& operator<<(std::ostream& out, Location& location);
//const bool operator == (const Location*, const Location*);


#endif //LOCATION_HPP