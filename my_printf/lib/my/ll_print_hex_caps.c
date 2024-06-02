/*
** EPITECH PROJECT, 2023
** print_hex
** File description:
** things
*/

#include <stdarg.h>
#include "my.h"

void ll_print_hex_caps(va_list args)
{
    unsigned long long int arg = va_arg(args, unsigned long long int);

    ll_my_puthex_caps(arg);
}
