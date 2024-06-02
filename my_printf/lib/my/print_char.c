/*
** EPITECH PROJECT, 2023
** print_char
** File description:
** things
*/

#include <stdarg.h>
#include "my.h"

void print_char(va_list args)
{
    char arg = va_arg(args, int);

    my_putchar(arg);
}
