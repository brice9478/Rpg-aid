/*
** EPITECH PROJECT, 2023
** my_putnbr
** File description:
** things
*/

#include "my.h"

void ll_my_putnbr(long long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb < 10) {
        my_putchar(nb + '0');
    } else {
        ll_my_putnbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
}
