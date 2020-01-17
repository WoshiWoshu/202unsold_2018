/*
** EPITECH PROJECT, 2019
** 202unsold
** File description:
** Basis.cpp
*/

#include <algorithm>
#include <functional>
#include "Basis.hpp"

template<>
double marginalLaw<double, std::vector<double>>(std::vector<double> price)
{
    Sum mySum(0.0);

    mySum = for_each(price.begin(), price.end(), mySum);
    return mySum.getSum();
}

template<>
VectorTwoDims marginalLaw<VectorTwoDims, VectorTwoDims>(VectorTwoDims price)
{
    for (int x = 0; x < 5; ++x)
        for (int y = 0; y < 5; y++)
            price[5][x]+=price[y][x];
    return price;
}
