/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** splits a string into words
*/

#include <stdlib.h>
#include <stddef.h>
#include "include/my.h"

int alphanumeric(char a)
{
    if (a == ' ' || a == '\0' || a == '\t')
        return 1;
    return 0;
}

int nb_of_words(char const *str, int c)
{
    int i = 0;
    int nb = 0;
    int one = 0;

    if (alphanumeric(str[c - 1]) == 0) {
        nb = 1;
    }
    while (i < c){
        if (alphanumeric(str[i]) == 1) {
            nb++;
        }
        while (str[i + one] != '\0' && alphanumeric(str[i + one]) == 1) {
            one++;
        }
        i = i + one;
        one = 0;
        i++;
    }
    return nb;
}

int pseudo_strlen(char const *str)
{
    int i = 0;

    while (alphanumeric(str[i]) == 0) {
        i++;
    }
    return i;
}

char **my_str_to_word_array(char const *str)
{
    int total = strlen(str);
    int a = 0;
    int b = 0;
    int nb = nb_of_words(str, total);
    char **word = malloc(sizeof(char *) * (nb_of_words(str, total) + 1));

    for (a = 0; a < nb; a++) {
        word[a] = malloc(sizeof(char) * (pseudo_strlen(str) + 1));
        for (b = 0; b < pseudo_strlen(str); b++) {
            word[a][b] = str[b];
        }
        word[a][b] = '\0';
        for (b; str[b] != '\0' && alphanumeric(str[b]) == 1; b++) {
        }
        str = &str[b];
    }
    word[a] = NULL;
    return word;
}
