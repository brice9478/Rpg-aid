/*
** EPITECH PROJECT, 2023
** number_flag
** File description:
** things
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include "my.h"

int determine_nb(int j, int i, char const *format)
{
    int nb = 0;

    for (j = i + 1; format[j] >= 48 && format[j] <= 57; j++)
        nb++;
    return nb;
}

static void check_char_str(char *str, char *numberstr, char *argstr)
{
    int k = 0;

    if (str[0] == '0') {
        for (k = 0; k < my_getnbr(numberstr) - my_strlen(argstr); k++) {
            my_putchar('0');
        }
    } else {
        for (k = 0; k < my_getnbr(str) - my_strlen(argstr); k++) {
            my_putchar(' ');
        }
    }
}

int number_flag(va_list args, char const *format, int i)
{
    int nb = 0;
    int j = 0;
    char *str;
    char *numberstr;
    char argstr[20];
    int arg = va_arg(args, int);

    nb = determine_nb(j, i, format);
    str = malloc(sizeof(char) * (nb + 1));
    nb = 0;
    for (j = i + 1; format[j] >= '0' && format[j] <= '9'; j++) {
        str[nb] = format[j];
        nb++;
    }
    numberstr = malloc(sizeof(char) * (nb));
    my_strcpy(numberstr, str + 1);
    my_itoa(arg, argstr);
    check_char_str(str, numberstr, argstr);
    my_putnbr(arg);
    return j;
}
