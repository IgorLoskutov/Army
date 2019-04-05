#ifndef MAGICAMENABILITY_HPP
#define MAGICAMENABILITY_HPP

class Unit;
class SpellCaster;


class MagicAmenability {
	public:
		MagicAmenability();
		~MagicAmenability();

		virtual void takeMagic(Unit*, SpellCaster*);

};

#endif  //  MAGICAMENABILITY_HPP