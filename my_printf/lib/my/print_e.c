/*
** EPITECH PROJECT, 2023
** print_E
** File description:
** flag e of my_printf; scientific notation
*/

#include <stdarg.h>
#include "my.h"

double negative(double nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    return nb;
}

void end(int power)
{
    if (power < 10) {
        my_putchar('0');
        my_putnbr(power);
    } else {
        my_putnbr(power);
    }
}

void print_e(va_list args)
{
    double nb = negative(va_arg(args, double));
    int power = 0;

    if (nb > 0 && nb < 1) {
        for (power; nb < 1; power++) {
            nb = nb * 10.0;
        }
        my_putfloat(nb, 6);
        my_putstr("e-");
    }
    if (nb >= 1) {
        for (power; nb >= 10.0; power++)
            nb = nb / 10.0;
        my_putfloat(nb, 6);
        my_putstr("e+");
    }
    end(power);
}
