/*
** EPITECH PROJECT, 2024
** end of turn
** File description:
** Update all duration of all effects
*/

#include "include/my.h"

void end_of_turn(effect_t *effect, player_t **ptr_s, int saved_id)
{
    effect_t *travel;
    char **array = my_str_to_word_array(read_list_stat_complete());
    char *statistics[20] = {"PV\t\t", "ATTACK\t\t", "DEFENSE\t\t", "STAMINA\t\t", "PHYSICAL SPEED\t",
    "MAGICAL POWER\t", "MANA\t\t", "PERCEPTION SPEED", "INTELLIGENCE\t", "MENTAL\t\t",
    "THINKING SPEED\t", "WATER\t\t", "FIRE\t\t", "EARTH\t\t", "WIND\t\t", "ELECTRICITY\t",
    "PLANT\t\t", "LIGHT\t\t", "DARKNESS\t", NULL};

    printf("End of turn:\n");
    for (travel = effect; travel != NULL; travel = travel->next) {
        if (travel->target == saved_id + 1) {
            if (travel->type == BUFF)
                printf("Buff ");
            if (travel->type == DEBUFF)
                printf("Debuff ");
            printf("duration: %d -> ", travel->duration);
            travel->duration -= 1;
            if (travel->duration < 0)
                travel->duration = 0;
            printf("%d\n", travel->duration);
        }
    }
    for (int i = 0; ptr_s[i] != NULL; i++) {
        printf("= = = = = = = = %s = = = = = = = =\n", ptr_s[i]->name);
        for (int x = 0; x < 19; x++)
            printf("%s %d\n", statistics[x], ptr_s[i]->current_stat[x]);
    }
    printf("= = = = = = = = = = = = = = = = = = = = =\n");
}
