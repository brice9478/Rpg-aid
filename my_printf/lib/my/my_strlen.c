/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** display string length
*/


int my_strlen(char const *str)
{
    int count;

    for (count = 0; str[count] != '\0'; count++);
    return count;
}
