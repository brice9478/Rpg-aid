/*
** EPITECH PROJECT, 2023
** print_number
** File description:
** things
*/

#include <stdarg.h>
#include "my.h"

void l_print_number(va_list args)
{
    long int arg = va_arg(args, long int);

    l_my_putnbr(arg);
}
