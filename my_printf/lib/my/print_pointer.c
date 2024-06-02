/*
** EPITECH PROJECT, 2023
** print_pointer
** File description:
** things
*/

#include <stdarg.h>
#include "my.h"
#include <stddef.h>

void print_pointer(va_list args)
{
    const void *arg = (const void *)(size_t)va_arg(args, int);

    my_putpoint(arg);
}
