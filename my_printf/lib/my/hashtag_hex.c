/*
** EPITECH PROJECT, 2023
** hashtag hex
** File description:
** things
*/

#include "my.h"

int hashtag_hex(va_list args, int i)
{
    my_putstr("0x");
    print_hex(args);
    return i + 2;
}
