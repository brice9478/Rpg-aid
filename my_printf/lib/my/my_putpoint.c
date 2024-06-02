/*
** EPITECH PROJECT, 2023
** my_putpoint
** File description:
** things
*/

#include "my.h"

void my_putpoint(const void *ptr)
{
    unsigned long address = (unsigned long)ptr;
    char hexadecimal[9];
    int index = 0;
    int remainder = 0;

    my_putstr("0x7ff");
    if (address == 0)
        my_putchar('0');
    for (index; address > 0 && index < 8; index++) {
        remainder = address % 16;
        if (remainder < 10) {
            hexadecimal[index] = remainder + '0';
        } else {
            hexadecimal[index] = remainder + 'a' - 10;
        }
        address /= 16;
    }
    while (index > 0)
        my_putchar(hexadecimal[--index]);
}
