/*
** EPITECH PROJECT, 2023
** my_compute_power_it
** File description:
** calculate power
*/

int my_compute_power_it(int nb, int p)
{
    int count;
    int pwr;

    pwr = 1;
    if (p == 0){
        return 1;
    }
    if (p < 0){
        return 0;
    }
    for (; p >= 1; p--){
        pwr = pwr * nb;
    }
    return pwr;
}
