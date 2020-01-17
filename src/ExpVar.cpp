/*
** EPITECH PROJECT, 2019
** 202unsold
** File description:
** ExpVar.cpp
*/

#include <cmath>
#include "ExpVar.hpp"

ExpVar::ExpVar() : _expVar{std::make_pair(0.0, 0.0),
                   std::make_pair(0.0, 0.0), std::make_pair(0.0, 0.0)}
{}

void ExpVar::expectation(std::pair<double, double> expVar[])
{
    _jtPrice = std::make_tuple(10, 10);
    for (auto i : _jtProb[5]) {
        expVar[0].first+=i * std::get<0>(_jtPrice);
        expVar[0].second+=i * std::pow(std::get<0>(_jtPrice), 2);
        std::get<0>(_jtPrice)+=10;
    }
    for (int y = 0; y < 5; ++y) {
        expVar[1].first+=_jtProb[y][5] * std::get<1>(_jtPrice);
        expVar[1].second+=_jtProb[y][5] * std::pow(std::get<1>(_jtPrice), 2);
        std::get<1>(_jtPrice)+=10;
    }
    std::get<0>(_jtPrice) = 20;
    for (auto i : _suitProb) {
        expVar[2].first+=i * std::get<0>(_jtPrice);
        expVar[2].second+=i * std::pow(std::get<0>(_jtPrice), 2);
        std::get<0>(_jtPrice)+=10;
    }
}

void ExpVar::variance(std::pair<double, double> expVar[])
{
    expVar[0].second = expVar[0].second - std::pow(expVar[0].first, 2);
    expVar[1].second = expVar[1].second - std::pow(expVar[1].first, 2);
    expVar[2].second = expVar[2].second - std::pow(expVar[2].first, 2);
}

void ExpVar::compute(JointLawPtr jointLaw, int a, int b)
{
    static_cast<void>(jointLaw);
    static_cast<void>(a);
    static_cast<void>(b);
    this->expectation(_expVar);
    this->variance(_expVar);
}

void ExpVar::display(void)
{
    std::cout << std::fixed << std::setprecision(1)
              << "expected value of X:\t" << _expVar[0].first << std::endl
              << "variance of X:\t\t" << _expVar[0].second << std::endl
              << "expected value of Y:\t" << _expVar[1].first << std::endl
              << "variance of Y:\t\t" << _expVar[1].second << std::endl
              << "expected value of Z:\t" << _expVar[2].first << std::endl
              << "variance of Z:\t\t" << _expVar[2].second << std::endl;
}

ExpVar &ExpVar::operator=(const Suit &suit)
{
    if (this != &suit) {
        _jtProb = suit.getJtProb();
        _jtPrice = suit.getJtPrice();
        _suitProb = suit.getSuitProb();
    }
    return *this;
}
