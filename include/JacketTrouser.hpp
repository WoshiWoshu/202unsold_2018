/*
** EPITECH PROJECT, 2019
** 202unsold
** File description:
** JacketTrouser.hpp
*/

#pragma once

#include <tuple>
#include "Basis.hpp"
#include "IClothes.hpp"

class JacketTrouser : public IClothes
{
public:
    explicit JacketTrouser();
    ~JacketTrouser() = default;
    void compute(JointLawPtr jointLaw, int a, int b) override;
    void display(void) override;
    std::vector<std::vector<double>> getJtProb(void) const { return _jtProb; }
    std::tuple<int, int> getJtPrice(void) const { return _jtPrice; }
protected:
    std::vector<std::vector<double>> _jtProb;
    std::tuple<int, int> _jtPrice;
};

void operator<<(std::ostream &flux, IClothes &clothes);
