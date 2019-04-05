#ifndef DEAMONMAGICAMENABILITY_HPP
#define DEAMONMAGICAMENABILITY_HPP
#include "../MagicAmenability.hpp"
class Unit;
class SpellCaster;


class DeamonMagicAmenability : public MagicAmenability {
public:
	DeamonMagicAmenability();
	~DeamonMagicAmenability();

	void takeMagic(Unit*, SpellCaster*);
	
};

#endif //DEAMONMAGICAMENABILITY_HPP