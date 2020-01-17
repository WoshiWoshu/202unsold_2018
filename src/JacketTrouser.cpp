/*
** EPITECH PROJECT, 2019
** 202unsold
** File description:
** JacketTrouser.cpp
*/

#include <algorithm>
#include "JacketTrouser.hpp"

JacketTrouser::JacketTrouser() : _jtProb(0), _jtPrice(10, 10)
{}

void JacketTrouser::compute(JointLawPtr jointLaw, int a, int b)
{
    for (int y = 0; y < 5; ++y) {
        std::get<0>(_jtPrice) = 10;
        _jtProb.push_back(std::vector<double>());
        for (int x = 0; x < 5; x++) {
            _jtProb[y].push_back(jointLaw(a, b,
            std::get<0>(_jtPrice), std::get<1>(_jtPrice)));
            std::get<0>(_jtPrice)+=10;
        }
        _jtProb[y].push_back(marginalLaw<double,
        std::vector<double>>(_jtProb[y]));
        std::get<1>(_jtPrice)+=10;
    }
    _jtProb.push_back(std::vector<double>(5, 0));
    _jtProb = marginalLaw<VectorTwoDims, VectorTwoDims>(_jtProb);
}

void JacketTrouser::display(void)
{
    _jtPrice = std::make_tuple(10, 10);
    for (int x = 0; x < 5; ++x) {
        std::cout << "\tX=" << std::get<0>(_jtPrice);
        std::get<0>(_jtPrice)+=10;
    }
    std::cout << "\tY law" << std::endl;
    for (int y = 0; y < 5; ++y) {
        std::cout << "Y=" << std::get<1>(_jtPrice);
        for_each(_jtProb[y].begin(), _jtProb[y].end(), DispFonct());
        std::cout << std::endl;
        std::get<1>(_jtPrice)+=10;
    }
    std::cout << "X law";
    for_each(_jtProb[5].begin(), _jtProb[5].end(), DispFonct());
    std::cout << '\t' << "1" << std::endl;
}

void operator<<(std::ostream &flux, IClothes &clothes)
{
    static_cast<void>(flux);
    clothes.display();
}
