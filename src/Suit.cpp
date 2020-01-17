/*
** EPITECH PROJECT, 2019
** 202unsold
** File description:
** Suit.cpp
*/

#include <algorithm>
#include <iterator>
#include "Suit.hpp"

Suit::Suit() : JacketTrouser(), _suitProb{}
{}

void Suit::compute(JointLawPtr jointLaw, int a, int b)
{
    static_cast<void>(jointLaw);
    static_cast<void>(a);
    static_cast<void>(b);
    _suitProb.push_back(_jtProb[0][0]);
    _suitProb.push_back(_jtProb[1][0] + _jtProb[0][1]);
    _suitProb.push_back(_jtProb[2][0] + _jtProb[0][2] + _jtProb[1][1]);
    _suitProb.push_back(_jtProb[1][2] + _jtProb[2][1] + _jtProb[3][0]
    + _jtProb[0][3]);
    _suitProb.push_back(_jtProb[2][2] + _jtProb[0][4] + _jtProb[4][0]
    + _jtProb[3][1] + _jtProb[1][3]);
    _suitProb.push_back(_jtProb[2][3] + _jtProb[3][2] + _jtProb[4][1]
    + _jtProb[1][4]);
    _suitProb.push_back(_jtProb[3][3] + _jtProb[2][4] + _jtProb[4][2]);
    _suitProb.push_back(_jtProb[4][3] + _jtProb[3][4]);
    _suitProb.push_back(_jtProb[4][4]);
}

Suit &Suit::operator=(const JacketTrouser &jT)
{
    if (this != &jT) {
            _jtProb = jT.getJtProb();
            _jtPrice = jT.getJtPrice();
        }
    return *this;
}

void Suit::display(void)
{
    std::ostream_iterator<std::string> itCout(std::cout, "\t");

    *itCout = "z";
    for (int i = 20; i < 110; i+=10)
        *itCout = std::to_string(i);
    std::cout << "total" << std::endl;
    *itCout = "p(Z=z)";
    std::copy(_suitProb.begin(), _suitProb.end(),
              std::ostream_iterator<double>(std::cout, "\t"));
    std::cout << "1" << std::endl;
}
