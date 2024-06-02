/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** display one by one characters of a string
*/

#include "my.h"

void my_putstr(char const *str)
{
    int count = 0;

    while (str[count] != '\0'){
        my_putchar(str[count]);
        count++;
    }
}
