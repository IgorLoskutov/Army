#ifndef WEREWOLFMAGICAMENABILITY_HPP
#define WEREWOLFMAGICAMENABILITY_HPP

#include "../MagicAmenability.hpp"
class Unit;
class SpellCaster;

class WerewolfMagicAmenability : public MagicAmenability{
   public:
    WerewolfMagicAmenability();
    ~WerewolfMagicAmenability();

    void takeMagic(Unit*, SpellCaster*);

};

#endif //WEREWOLFMAGICAMENABILITY_HPP