/*
** EPITECH PROJECT, 2019
** 202unsold
** File description:
** Suit.hpp
*/

#pragma once

#include "JacketTrouser.hpp"
#include <list>

class Suit : public JacketTrouser
{
public:
    explicit Suit();
    ~Suit() = default;
    void compute(JointLawPtr jointLaw, int a = 0, int b = 0) override;
    void display(void) override;
    inline std::list<double> getSuitProb(void) const { return _suitProb; }
    Suit &operator=(const JacketTrouser &jT);
protected:
    std::list<double> _suitProb;
};
