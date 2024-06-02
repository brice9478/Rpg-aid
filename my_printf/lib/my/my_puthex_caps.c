/*
** EPITECH PROJECT, 2023
** my_puthex
** File description:
** displays hex
*/

#include "my.h"

void my_puthex_caps(unsigned int decimal)
{
    char hexadecimal[100];
    int index = 0;
    int remainder = 0;

    if (decimal == 0)
        my_putchar('0');
    while (decimal > 0) {
        remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[index] = remainder + '0';
            index++;
        } else {
            hexadecimal[index] = remainder + 'A' - 10;
            index++;
        }
        decimal /= 16;
    }
    for (int i = index - 1; i >= 0; i--)
        my_putchar(hexadecimal[i]);
}
