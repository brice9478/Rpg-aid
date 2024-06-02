/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** compare the first character of a string
*/

#include "include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int a = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') {
        i++;
    }
    a = s1[i] - s2[i];
    if (a == 0) {
        return 0;
    } else {
        return (s1[i] - s2[i]);
    }
}
