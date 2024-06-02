/*
** EPITECH PROJECT, 2023
** print_E
** File description:
** flag e of my_printf; scientific notation
*/

#include <stdarg.h>
#include "my.h"

int print_e_comma(va_list args, const char *format, int i)
{
    double nb = negative(va_arg(args, double));
    int power = 0;
    int j = 0;

    if (nb > 0 && nb < 1) {
        for (power; nb < 1; power++) {
            nb = nb * 10.0;
        }
        j = special_putfloat(nb, format, i);
        my_putstr("e-");
    }
    if (nb >= 1) {
        for (power; nb >= 10.0; power++) {
            nb = nb / 10.0;
        }
        j = special_putfloat(nb, format, i);
        my_putstr("e+");
    }
    end(power);
    return j + 1;
}
