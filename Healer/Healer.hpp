#ifndef HEALER_HPP
#define HEALER_HPP

#include "../Magic/SpellCaster.hpp"
#include <map>
#include <vector>
extern std::map<int, Spell> spellbook;

class Healer : public SpellCaster {
    public:
    Healer(const std::string&, Location* location);
    ~Healer();

    void readSpell();
};

#endif// HEALER_HPP