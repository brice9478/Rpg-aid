/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** reverses a string
*/

char *my_revstr(char *str)
{
    int count = 0;
    char t;
    int i;

    while (str[count] != '\0'){
        ++count;
    }
    for (i = 0; i < count / 2; ++i){
        t = str[i];
        str[i] = str[count - i - 1];
        str[count - i - 1] = t;
    }
    return str;
}
