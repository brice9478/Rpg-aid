/*
** EPITECH PROJECT, 2023
** minus_flag
** File description:
** things
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include "my.h"

int minus_flag(va_list args, char const *format, int i)
{
    int nb = 0;
    int j = 0;
    char *str;
    char *numberstr;
    char argstr[20];
    int arg = va_arg(args, int);

    str = malloc(sizeof(char) * (determine_nb(j, i, format) + 1));
    nb = 0;
    for (j = i + 2; format[j] >= '0' && format[j] <= '9'; j++) {
        str[nb] = format[j];
        nb++;
    }
    numberstr = malloc(sizeof(char) * (nb + 1));
    my_strcpy(numberstr, str);
    my_itoa(arg, argstr);
    my_putnbr(arg);
    for (int k = 0; k < my_getnbr(numberstr) - my_strlen(argstr); k++)
        my_putchar(' ');
    return j;
}
