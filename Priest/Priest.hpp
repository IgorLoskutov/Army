#ifndef PRIEST_HPP
#define PRIEST_HPP

#include "../Magic/SpellCaster.hpp"
#include<map>
#include<vector>
extern std::map<int, Spell> spellbook;

class Priest : public SpellCaster {
    public:
    Priest(const std::string&, Location* location);
    ~Priest();

    void readSpell();
    void counterAttack(Unit* enemy);
    void hexMagic(Unit*);

  /*  void Unit::Priest::SpecialAbility(Unit*);
    void transform(Unit* unit);*/

};

#endif// PRIEST_HPP