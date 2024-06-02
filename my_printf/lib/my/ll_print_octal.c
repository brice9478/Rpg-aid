/*
** EPITECH PROJECT, 2023
** print_octal
** File description:
** flag o of my_printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void ll_print_octal(va_list args)
{
    unsigned long long int number = va_arg(args, unsigned long long int);
    char *str;
    unsigned long long int for_malloc = number;
    int count = 0;

    for (int i = 0; for_malloc > 0; i++) {
        for_malloc = for_malloc / 8;
        count++;
    }
    str = malloc(sizeof(char) * (count + 1));
    for (count = 0; number > 0; count++) {
        str[count] = number % 8;
        number = number / 8;
    }
    for (count--; count >= 0; count--) {
        my_putchar(str[count] + 48);
    }
}
