/*
** EPITECH PROJECT, 2023
** print_g_flag
** File description:
** things
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static char *float_for(double decimal, int decimal_pos, char *str, int prec)
{
    int i;
    int digit = 0;

    for (i = 0; i < prec; i++) {
        decimal = decimal * 10;
        digit = (int)decimal;
        str[decimal_pos + i] = '0' + digit;
        decimal = decimal - digit;
    }
    return str;
}

static char *float_to_str(double nb, int precision)
{
    char *str;
    char *int_str = (char *)malloc(12);
    int integer = (int)nb;
    double decimal = nb - integer;
    int len;
    int decimal_pos = 0;

    if (nb < 0)
        decimal = -decimal;
    my_itoa(integer, int_str);
    len = my_strlen(int_str) + 7;
    str = (char *)malloc(len + 1);
    my_strcpy(str, int_str);
    str[my_strlen(int_str)] = '.';
    decimal_pos = my_strlen(int_str) + 1;
    str = float_for(decimal, decimal_pos, str, precision);
    for (len; str[len - 1] == '0'; len--)
        str[len - 1] = '\0';
    return str;
}

char *end_str(int power, char *str, char **float_str)
{
    char power_str[13];
    int power_pos = my_strlen(*float_str) + 1;

    if (power < 10) {
        str[power_pos + 1] = '0';
        str[power_pos + 2] = power + '0';
    } else {
        my_itoa(power, power_str);
        my_strcat(str, power_str);
    }
    return str;
}

static double check_neg(double nb, double absolute_nb)
{
    if (nb < 0) {
        absolute_nb = -nb;
        return absolute_nb;
    } else
        return nb;
}

char *science_2(double nb, double absolute_nb, char **float_str, char **str)
{
    int power = 0;
    int len = 0;

    if (absolute_nb >= 1) {
        for (; absolute_nb >= 10.0; power++) {
            absolute_nb = absolute_nb / 10.0;
        }
        if (nb < 0)
            *float_str = float_to_str(-absolute_nb, 5);
        else
            *float_str = float_to_str(absolute_nb, 5);
        if (*float_str != NULL) {
            (*float_str)[6] = '\0';
            len = my_strlen(*float_str) + 7;
            *str = (char *)malloc(len + 2);
            my_strcpy(*str, *float_str);
            my_strcat(*str, "e-");
        }
        return end_str(power, *str, float_str);
    }
}

char *science_to_str(double nb)
{
    int power = 0;
    char *str = NULL;
    double absolute_nb = check_neg(nb, absolute_nb);
    char *float_str = NULL;
    int len = 0;

    if (absolute_nb > 0 && absolute_nb < 1) {
        for (; absolute_nb < 1; power++)
            absolute_nb = absolute_nb * 10.0;
        if (nb < 0)
            float_str = float_to_str(-absolute_nb, 5);
        else
            float_str = float_to_str(absolute_nb, 5);
        len = my_strlen(float_str) + 6;
        str = (char *)malloc(len + 2);
        my_strcpy(str, float_str);
        my_strcat(str, "e-");
        return end_str(power, str, &float_str);
    }
    science_2(nb, absolute_nb, &float_str, &str);
}

static void remove_zeros(char *str)
{
    int len = my_strlen(str);
    int decimal_pos = -1;

    for (int i = 0; i < len; i++) {
        if (str[i] == '.') {
            decimal_pos = i;
            break;
        }
    }
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == '0' && i != decimal_pos) {
            str[i] = '\0';
        }
        if (i == decimal_pos || str[i] != '0') {
            break;
        }
    }
}

void print_g_flag(va_list args)
{
    int nb;
    double arg = va_arg(args, double);
    char *strfloat = float_to_str(arg, 20);
    char *printstrfloat = float_to_str(arg, 20);
    char *strscience = science_to_str(arg);

    remove_zeros(printstrfloat);
    if (my_strlen(strfloat) > my_strlen(strscience)) {
        my_putstr(strscience);
    } else {
        my_putstr(printstrfloat);
    }
}
