#ifndef WIZARD_HPP
#define WIZARD_HPP

#include "../Magic/SpellCaster.hpp"
#include<map>
#include<vector>
extern std::map<int, Spell> spellbook;

class Wizard : public SpellCaster {
    public:
    Wizard(const std::string&, Location*);
    virtual ~Wizard();

    void readSpell();
  /*  void Unit::Wizard::SpecialAbility(Unit*);
    void transform(Unit* unit);*/

};

#endif// WIZARD_HPP