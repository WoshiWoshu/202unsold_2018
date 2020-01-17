/*
** EPITECH PROJECT, 2019
** IClothes.hpp
** File description:
** 202unsold
*/

class IClothes
{
public:
    virtual ~IClothes() = default;
    virtual void compute(JointLawPtr jointLaw, int a, int b) = 0;
    virtual void display(void) = 0;
};
