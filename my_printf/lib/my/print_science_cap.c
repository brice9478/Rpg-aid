/*
** EPITECH PROJECT, 2023
** print_E
** File description:
** flag e of my_printf; scientific notation
*/

#include <stdarg.h>
#include "my.h"

void print_science_cap(va_list args)
{
    double nb = negative(va_arg(args, double));
    int power = 0;

    if (nb > 0 && nb < 1) {
        for (power; nb < 1; power++) {
            nb = nb * 10.0;
        }
        my_putfloat(nb, 6);
        my_putstr("E-");
    }
    if (nb >= 1) {
        for (power; nb >= 10.0; power++)
            nb = nb / 10.0;
        my_putfloat(nb, 6);
        my_putstr("E+");
    }
    end(power);
}
