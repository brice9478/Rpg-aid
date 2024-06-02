/*
** EPITECH PROJECT, 2023
** my_compute_power_rec.c
** File description:
** recursive power
*/

#include "include/my.h"

int my_compute_power_rec(int nb, int p)
{
    int a;

    if (p > 0) {
        a = my_compute_power_rec(nb, p - 1);
        nb = nb * a;
        return (nb);
    } else if (p == 0) {
        return (1);
    } else {
        return (0);
    }
}
