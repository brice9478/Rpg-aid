/*
** EPITECH PROJECT, 2023
** print_hex
** File description:
** things
*/

#include <stdarg.h>
#include "my.h"

void print_hex(va_list args)
{
    unsigned int arg = va_arg(args, unsigned int);

    my_puthex(arg);
}
