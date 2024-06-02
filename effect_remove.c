/*
** EPITECH PROJECT, 2024
** effect_remove
** File description:
** remove all effects at the end of their duration
*/

#include "include/my.h"

void effect_remove(effect_t *effect)
{
    effect_t *travel = effect;
    effect_t *prev = NULL;
    effect_t *temp;

    while (travel != NULL) {
        if (travel->duration <= 0) {
            if (prev != NULL) {
                prev->next = travel->next;
            } else
                effect = travel->next;
            temp = travel;
            travel = travel->next;
            free(temp);
        } else {
            prev = travel;
            travel = travel->next;
        }
    }
}
