/*
** EPITECH PROJECT, 2023
** print_number
** File description:
** things
*/

#include <stdarg.h>
#include "my.h"

void ll_print_number(va_list args)
{
    long long int arg = va_arg(args, long long int);

    ll_my_putnbr(arg);
}
