/*
** EPITECH PROJECT, 2023
** print_float
** File description:
** things
*/

#include <stdarg.h>
#include "my.h"

void print_float(va_list args)
{
    double arg = va_arg(args, double);

    my_putfloat(arg, 6);
}
