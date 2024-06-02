/*
** EPITECH PROJECT, 2023
** print_string
** File description:
** things
*/

#include <stdarg.h>
#include "my.h"

void print_string(va_list args)
{
    char *arg = va_arg(args, char *);

    my_putstr(arg);
}
