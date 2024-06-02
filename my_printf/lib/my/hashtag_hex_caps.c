/*
** EPITECH PROJECT, 2023
** hashtag hex
** File description:
** things
*/

#include "my.h"

int hashtag_hex_caps(va_list args, int i)
{
    my_putstr("0X");
    print_hex_caps(args);
    return i + 2;
}
