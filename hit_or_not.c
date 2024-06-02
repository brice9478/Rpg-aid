/*
** EPITECH PROJECT, 2024
** hit or not
** File description:
** Determine the multiplier from the result of the dice
*/

#include "include/my.h"

float hit_or_not(player_t **ptr_s, int saved_id)
{
    int adjust = ((ptr_s[saved_id]->precision - 100) / 5);
    if (ptr_s[saved_id]->dice >= 20 - adjust) {
        printf("Critical damages ! A fatal injury in a precise point !\n");
        return 2.0;
    }
    if (ptr_s[saved_id]->dice < 20 - adjust && ptr_s[saved_id]->dice >= 15 - adjust) {
        printf("Weakness hit. Damage increased.\n");
        return 1.5;
    }
    if (ptr_s[saved_id]->dice < 15 - adjust && ptr_s[saved_id]->dice >= 5 - adjust) {
        printf("Hit. Nothing else to say.\n");
        return 1.0;
    }
    if (ptr_s[saved_id]->dice < 5 - adjust && ptr_s[saved_id]->dice >= 1 - adjust) {
        printf("Not hit properly. The ennemy was able to dodge a part of the attack.\n");
        return 0.5;
    }
    if (ptr_s[saved_id]->dice < 1 - adjust)
        printf("You moron. How did you miss a target that big ??\n");
    return 0.0;
}
