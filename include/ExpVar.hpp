/*
** EPITECH PROJECT, 2019
** 202unsold
** File description:
** ExpVar.hpp
*/

#pragma once

#include "Suit.hpp"

class ExpVar : public Suit
{
public:
    explicit ExpVar();
    ~ExpVar() = default;
    void compute(JointLawPtr jointLaw, int a = 0, int b = 0) final;
    void display(void) final;
    ExpVar &operator=(const Suit &jT);
private:
    std::pair<double, double> _expVar[3];
    
    void expectation(std::pair<double, double> expVar[]);
    void variance(std::pair<double, double> expVar[]);
};
