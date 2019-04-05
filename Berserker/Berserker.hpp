#ifndef BERSERKER_HPP
#define BERSERKER_HPP

#include<iostream>
#include"../Unit.hpp"

class Berserker : public Unit {
    public:
    Berserker(const std::string&, Location* );
    virtual ~Berserker();
};



#endif // BERSERKER_HPP
