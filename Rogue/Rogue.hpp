#ifndef ROGUE_HPP
#define ROGUE_HPP

#include<iostream>
#include "../Unit.hpp"

class Rogue : public Unit {
public:
	Rogue(const std::string& name, Location* location);
	~Rogue();

};


#endif // ROGUE_HPP