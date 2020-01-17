/*
** EPITECH PROJECT, 2019
** 202unsold
** File description:
** Basis.hpp
*/

#pragma once

#include <iomanip>
#include <iostream>
#include <vector>

using JointLawPtr = double (&)(int a, int b, int x, int y);

typedef std::vector<std::vector<double>> VectorTwoDims;

class Sum
{
public:
    Sum(double result) : _result(result){}
    double getSum(void){ return _result; }
    void operator()(double elem)
    {
        _result+=elem;
    }
private:
    double _result;
};

class DispFonct
{
public:
    void operator()(double elem)
    {
      std::cout << std::fixed
                << std::setprecision(3) << '\t' << elem;
    }
};

template<typename T, typename S>
T marginalLaw(S price);
