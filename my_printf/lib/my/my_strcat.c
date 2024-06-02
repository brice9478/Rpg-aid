/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** appends string to another
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int lengthsrc = my_strlen(src);
    int lengthdest = my_strlen(dest);
    int i = 0;

    for (i; src[i] != '\0'; i++) {
        dest[lengthdest + i] = src[i];
    }
    dest[lengthdest + i] = '\0';
    return dest;
}
