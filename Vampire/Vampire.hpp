#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "../Unit.hpp"

class Vampire : public Unit {
	public:
	Vampire(const std::string& name, Location*);
	virtual ~Vampire();

	void byte(Unit*);
};

#endif //VAMPIRE_HPP