/*
** EPITECH PROJECT, 2023
** print_float
** File description:
** things
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int print_float_comma(va_list args, const char *format, int i)
{
    int nb = 0;
    int j = 0;
    char *str;
    double arg = va_arg(args, double);

    for (j = i + 2; format[j] >= 48 && format[i] <= 57; j++) {
        nb++;
    }
    str = malloc(sizeof(char) * (nb + 1));
    nb = 0;
    for (j = i + 2; format[j] >= 48 && format[i] <= 57; j++) {
        str[nb] = format[j];
        nb++;
    }
    my_putfloat(arg, my_getnbr(str));
    return j;
}
