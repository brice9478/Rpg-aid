/*
** EPITECH PROJECT, 2023
** print_number
** File description:
** things
*/

#include <stdarg.h>
#include "my.h"

void print_number(va_list args)
{
    int arg = va_arg(args, int);

    my_putnbr(arg);
}
