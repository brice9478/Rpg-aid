/*
** EPITECH PROJECT, 2023
** my_itoa
** File description:
** int to str
*/

void itoa_loop(int i, char *str)
{
    char temp;

    for (int j = 0; j < i / 2; j++) {
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}

void my_itoa(int num, char *str)
{
    int i = 0;
    int isNegative = 0;

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }
    do {
        str[i] = '0' + (num % 10);
        i++;
        num /= 10;
    } while (num > 0);
    if (isNegative) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    itoa_loop(i, str);
}
