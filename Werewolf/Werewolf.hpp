#ifndef WEREWOLF_HPP
#define WEREWOLF_HPP

#include <iostream>
#include "../Unit.hpp"


class Werewolf : public Unit{
   public:
    Werewolf(const std::string& name, Location*);
    ~Werewolf();

    void transform();
    void byte(Unit*);

};

#endif // !WEREWOLF_HPP
