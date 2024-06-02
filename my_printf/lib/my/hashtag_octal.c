/*
** EPITECH PROJECT, 2023
** hashtag hex
** File description:
** things
*/

#include "my.h"

int hashtag_octal(va_list args, int i)
{
    my_putstr("0");
    print_octal(args);
    return i + 2;
}
