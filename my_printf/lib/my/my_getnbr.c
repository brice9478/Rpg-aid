/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** things
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int res = 0;
    int sign = 1;
    int digit;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-'){
            sign = sign * -1;
        }
        i++;
    }
    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9'){
            digit = str[i] - '0';
            res = res * 10 + digit;
        } else {
            break;
        }
    }
    return res * sign;
}
