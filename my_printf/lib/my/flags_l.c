/*
** EPITECH PROJECT, 2023
** flags l
** File description:
** flag l and flag ll
*/

#include "my.h"
#include <stdarg.h>

static void (*plong[6])(va_list) = {
    &l_print_number,
    &l_print_number,
    &l_print_undecimal,
    &l_print_octal,
    &l_print_hex,
    &l_print_hex_caps
};

static void (*plonglong[6])(va_list) = {
    &ll_print_number,
    &ll_print_number,
    &ll_print_undecimal,
    &ll_print_octal,
    &ll_print_hex,
    &ll_print_hex_caps
};

int flags_l(char const *f, int i, va_list args)
{
    char tab[6] = {'i', 'd', 'u', 'o', 'x', 'X'};
    int dex = 0;

    for (dex = 0; dex < 6; dex++) {
        if (f[i + 1] == 'l' && f[i + 2] == tab[dex]) {
            plong[dex](args);
            i = i + 2;
        }
    }
    for (dex = 0; dex < 6; dex++) {
        if (f[i + 1] == 'l' && f[i + 2] == 'l' && f[i + 3] == tab[dex]) {
            plonglong[dex](args);
            i = i + 3;
        }
    }
    return i;
}
