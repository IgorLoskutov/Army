#ifndef BERSERKERMAGICAMENABILITY_HPP
#define BERSERKERMAGICAMENABILITY_HPP

#include "../MagicAmenability.hpp"
class Unit;
class SpellCaster;

class BerserkerMagicAmenability : public MagicAmenability{
   public:
    BerserkerMagicAmenability();
    ~BerserkerMagicAmenability();

    void takeMagic(Unit*, SpellCaster*);

};

#endif //BERSERKERMAGICAMENABILITY_HPP