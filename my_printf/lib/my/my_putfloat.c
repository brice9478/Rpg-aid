/*
** EPITECH PROJECT, 2023
** my_putfloat
** File description:
** things
*/

#include "my.h"

void rounding(double decimal, int precision)
{
    double multiplier = 1.0;
    int nextdigit;

    for (int i = 0; i < precision; i++) {
        multiplier = multiplier * 10.0;
    }
    decimal = decimal * multiplier;
    nextdigit = (int)decimal;
    decimal = decimal - nextdigit;
    if (decimal >= 0.5) {
        nextdigit++;
    }
    my_putnbr(nextdigit);
}

void my_putfloat(double nb, int precision)
{
    int integer = (int)nb;
    double decimal = nb - integer;
    int i = 0;
    int digit = 0;

    my_putnbr(integer);
    my_putchar('.');
    rounding(decimal, precision);
}
