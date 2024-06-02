/*
** EPITECH PROJECT, 2024
** main
** File description:
** The beginning and the end at the same time
*/

#include "include/my.h"

int main(int ac, char **av)
{
    player_t **ptr_s;
    char *statistics[20] = {"PV\t\t", "ATTACK\t\t", "DEFENSE\t\t", "STAMINA\t\t", "PHYSICAL SPEED\t",
    "MAGICAL POWER\t", "MANA\t\t", "PERCEPTION SPEED", "INTELLIGENCE\t", "MENTAL\t\t",
    "THINKING SPEED\t", "WATER\t\t", "FIRE\t\t", "EARTH\t\t", "WIND\t\t", "ELECTRICITY\t",
    "PLANT\t\t", "LIGHT\t\t", "DARKNESS\t", NULL};

    if (ac != 2) {
        printf("Wrong number of arguments. Please rerun with -h.\n");
        return 84;
    }
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        display_description();
        return 0;
    }
    ptr_s = init_player(av);
    for (int i = 0; ptr_s[i] != NULL; i++) {
        printf("= = = = = = = = %s = = = = = = = =\n", ptr_s[i]->name);
        for (int x = 0; x < 19; x++)
            printf("%s %d\n", statistics[x], ptr_s[i]->base_stat[x]);
    }
    for (int i = 0; ptr_s[i] != NULL; i++)
        determine_time(ptr_s, i);
    game_loop(ptr_s);
}
