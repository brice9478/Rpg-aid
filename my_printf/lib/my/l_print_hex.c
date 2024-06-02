/*
** EPITECH PROJECT, 2023
** print_hex
** File description:
** things
*/

#include <stdarg.h>
#include "my.h"

void l_print_hex(va_list args)
{
    unsigned long int arg = va_arg(args, unsigned long int);

    l_my_puthex(arg);
}
