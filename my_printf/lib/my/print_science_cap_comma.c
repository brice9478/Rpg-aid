/*
** EPITECH PROJECT, 2023
** print_E
** File description:
** flag e of my_printf; scientific notation
*/

#include <stdarg.h>
#include "my.h"
#include <stdlib.h>

double special_putfloat(double nb, const char *format, int i)
{
    int nb_of_char = 0;
    int j = 0;
    char *str;

    for (j = i + 2; format[j] >= 48 && format[j] <= 57; j++) {
        nb_of_char++;
    }
    str = malloc(sizeof(char) * (nb_of_char + 1));
    nb_of_char = 0;
    for (j = i + 2; format[j] >= 48 && format[j] <= 57; j++) {
        str[nb_of_char] = format[j];
        nb_of_char++;
    }
    my_putfloat(nb, my_getnbr(str));
    return j;
}

int print_science_cap_comma(va_list args, const char *format, int i)
{
    double nb = negative(va_arg(args, double));
    int power = 0;
    int j = 0;

    if (nb > 0 && nb < 1) {
        for (power; nb < 1; power++)
            nb = nb * 10.0;
        j = special_putfloat(nb, format, i);
        my_putstr("E-");
    }
    if (nb >= 1) {
        for (power; nb >= 10.0; power++)
            nb = nb / 10.0;
        j = special_putfloat(nb, format, i);
        my_putstr("E+");
    }
    end(power);
    return j + 1;
}
