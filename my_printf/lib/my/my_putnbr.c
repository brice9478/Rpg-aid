/*
** EPITECH PROJECT, 2023
** my_putnbr
** File description:
** things
*/

#include "my.h"

void my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb < 10) {
        my_putchar(nb + '0');
    } else {
        my_putnbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
}
