/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** real get nbr
*/

#include "include/my.h"

int minus(char const *str, int i)
{
    if (str[i] == '-' && str[i + 1] >= 48 && str[i] <= 57) {
        return (1);
    } else {
        return 0;
    }
}

int number(int a, int c)
{
    if (c == 1) {
        a = a * -1;
    }
    return a;
}

int my_getnbr(char const *str)
{
    int a = 0;
    int i = 0;
    int b = 0;
    int c = 0;

    if (*str > 2147483647) {
        return (0);
    }
    for (i = 0; str[i] < 48 || str[i] > 57; i++) {
        c = minus(str, i);
    }
    str = &str[i];
    for (i = 0; str[i] >= 48 && str[i] <= 57; i++) {
        b++;
    }
    for (i = 0; b > 0; i++) {
        b--;
        a = a + (str[i] - 48) * my_compute_power_rec(10, b);
    }
    return number(a, c);
}
