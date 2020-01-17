/*
** EPITECH PROJECT, 2019
** 202unsold
** File description:
** main.cpp
*/

#include <iterator>
#include <cstring>
#include "ExpVar.hpp"

double jointLaw(int a, int b, int x, int y)
{
    return (a - x) * (b - y) / ((5. * a - 150.) * (5. * b - 150.));
}

void display_dash(void)
{
    std::cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––"
              << std::endl;
}

int main(int ac, char **av)
{
    if (ac == 1)
        return 84;
    if (strcmp(av[1], "-h") == 0) {
        std::cout << "USAGE" << std::endl;
        std::cout << "\t./202unsold a b" << std::endl << std::endl;
        std::cout << "DESCRIPTION" << std::endl;
        std::cout
        << "\ta\tconstant computed from the past results" << std::endl;
        std::cout
        << "\tb\tconstant computed from the past results" << std::endl;
        return 0;
    }
    if (ac != 3)
        return 84;

    JacketTrouser jT;
    Suit suit;
    ExpVar eV;
    double input[2]{std::atof(av[1]), std::atof(av[2])};

    if (input[0] < 50 or input[1] < 50)
        return 84;
    display_dash();
    jT.compute(jointLaw, input[0], input[1]);
    std::cout << jT;
    display_dash();
    suit = jT;
    suit.compute(jointLaw);
    std::cout << suit;
    display_dash();
    eV = suit;
    eV.compute(jointLaw);
    std::cout << eV;
    display_dash();
    return 0;
}
