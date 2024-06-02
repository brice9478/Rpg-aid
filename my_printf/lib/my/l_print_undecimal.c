/*
** EPITECH PROJECT, 2023
** print undecimal
** File description:
** flag u of printf : unsigned decimal integer
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int long_unverif(unsigned long int nb)
{
    int i = 0;

    for (i = 0; nb != 0; i++) {
        nb = nb / 10;
    }
    return i;
}

int my_long_put_unnbr(unsigned long int nb)
{
    char *str;
    int i = 0;

    if (nb == 0) {
        my_putchar('0');
        return 0;
    }
    str = malloc(sizeof(char) * (long_unverif(nb)));
    for (i = 0; nb > 0; i++) {
        str[i] = nb % 10;
        nb = nb / 10;
    }
    for (i--; i >= 0; i--) {
        my_putchar(str[i] + 48);
    }
    return 0;
}

void l_print_undecimal(va_list args)
{
    unsigned long int number = va_arg(args, unsigned long int);

    my_long_put_unnbr(number);
}
