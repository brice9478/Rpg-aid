/*
** EPITECH PROJECT, 2024
** game loop
** File description:
** roll rolling rollers
*/

#include "include/my.h"

char *get_a_line(void)
{
    char *line = NULL;
    size_t len;
    ssize_t nread;

    while (1) {
        nread = getline(&line, &len, stdin);
        if (nread == -1 || line[0] == '\n') {
            printf("Error. Please retry.\n");
            free(line);
            continue;
        }
        if (line[nread - 1] == '\n') {
            line[nread - 1] = '\0';
            return line;
        }
    }
}

int my_arraylen(char **array)
{
    int count = 0;

    for (count; array[count]; count++);
    return count;
}

void physical_dmg(player_t **ptr_s, int saved_id)
{
    char **array;
    int dmg = 0;
    int def;
    int stat_dmg = ATTACK;

    printf("Basic damage of the skill (0 means that no damage will be taken into account): ");
    while (update_stat(&ptr_s[saved_id]->basic_dmg) == 84);
  //  printf("/!\\ If an effect has a probability of activation, please determine if it activates or not before selecting the targets.\n");
    printf("Here is a list of all the players:\n");
    for (int i = 0; ptr_s[i]; i++)
        printf("P%d %s\n", ptr_s[i]->id, ptr_s[i]->name);
    printf("Select the target(s) (ex: \"1 2\" for player 1 and 2): ");
    array = my_str_to_word_array(get_a_line());
    if (ptr_s[saved_id]->targets != NULL)
        free(ptr_s[saved_id]->targets);
    ptr_s[saved_id]->targets = malloc(sizeof(int) * my_arraylen(array));
    for (int i = 0; array[i]; i++)
        ptr_s[saved_id]->targets[i] = atoi(array[i]);
    printf("Skill precision : ");
    while (update_stat(&ptr_s[saved_id]->precision) == 84);
    for (int i = 0; array[i]; i++) {
        def = ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[DEFENSE];
        printf("Any particularities ? (yes: 0; no: 1): ");
        if (atoi(get_a_line()) == 0) {
            printf("Ignore defense ? (yes: 0; no: 1): ");
            if (atoi(get_a_line()) == 0)
                def = 100;
            printf("Consider Intelligence as Attack ? (yes: 0; no: 1): ");
            if (atoi(get_a_line()) == 0)
                stat_dmg = INTELLIGENCE;
        }
        printf("Basic dmg: %d Attack: %d against Ennemy's defense: %d\n", ptr_s[saved_id]->basic_dmg, ptr_s[saved_id]->current_stat[stat_dmg], def);
        dmg = (int)((float)ptr_s[saved_id]->basic_dmg * (float)ptr_s[saved_id]->current_stat[stat_dmg] / (float)def);
        printf("Result of the dice (/20): ");
        while (update_stat(&ptr_s[saved_id]->dice) == 84);
        dmg = (int)((float)dmg * hit_or_not(ptr_s, saved_id));
        printf("Damage inflicted to P%d %s: %d. Pv : %d -> ", ptr_s[ptr_s[saved_id]->targets[i] - 1]->id, ptr_s[ptr_s[saved_id]->targets[i] - 1]->name, dmg, ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[PV]);
        ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[PV] -= dmg;
        if (ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[PV] <= 0) {
            ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[PV] = 0;
            ptr_s[ptr_s[saved_id]->targets[i] - 1]->dead = true;
            printf("%d\n", ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[PV]);
            printf("P%d %s's pv hit rock bottom.\n", ptr_s[ptr_s[saved_id]->targets[i] - 1]->id, ptr_s[ptr_s[saved_id]->targets[i] - 1]->name);
            continue;
        }
        printf("%d\n", ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[PV]);
    }
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

void magical_dmg(player_t **ptr_s, int saved_id)
{
    char **array;
    char **affinities;
    int dmg = 0;
    int tmp = 0;
    char *elements[9] = {"WATER", "FIRE", "EARTH", "WIND", "ELECTRICITY", "PLANT", "LIGHT", "DARKNESS", NULL};

    printf("Here is a list of the elements:\n");
    for (int i = 0; elements[i]; i++)
        printf("%d %s\n", i, elements[i]);
    printf("Select the element(s) (ex: \"0 5\" for WATER and  PLANT): ");
    affinities = my_str_to_word_array(get_a_line());
    printf("Basic damage of the skill (0 means that no damage will be taken into account): ");
   // while (update_stat(&ptr_s[saved_id]->basic_dmg) == 84);
 //   printf("/!\\ If an effect has a probability of activation, please determine if it activates or not before selecting the targets.\n");
    printf("Here is a list of all the players:\n");
    for (int i = 0; ptr_s[i]; i++)
        printf("P%d %s\n", ptr_s[i]->id, ptr_s[i]->name);
    printf("Select the target(s) (ex: \"1 2\" for player 1 and 2): ");
    array = my_str_to_word_array(get_a_line());
    if (ptr_s[saved_id]->targets != NULL)
        free(ptr_s[saved_id]->targets);
    ptr_s[saved_id]->targets = malloc(sizeof(int) * my_arraylen(array));
    for (int i = 0; array[i]; i++)
        ptr_s[saved_id]->targets[i] = atoi(array[i]);
    printf("Skill precision : ");
    while (update_stat(&ptr_s[saved_id]->precision) == 84);
    for (int i = 0; array[i]; i++) {
        for (int x = 0; affinities[x]; x++) {
            tmp = (int)((float)ptr_s[saved_id]->current_stat[atoi(affinities[x]) + 11] * (float)ptr_s[saved_id]->current_stat[MAGICAL_POWER] / 100.0 - ((float)ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[atoi(affinities[x]) + 11] * (float)ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[MAGICAL_POWER] / 100.0));
            if (tmp < 0)
                tmp = 0;
            dmg += tmp;
        }
        printf("Result of the dice (/20): ");
        while (update_stat(&ptr_s[saved_id]->dice) == 84);
        dmg = (int)((float)dmg * hit_or_not(ptr_s, saved_id));
        printf("Damage inflicted to P%d %s: %d. Pv : %d -> ", ptr_s[ptr_s[saved_id]->targets[i] - 1]->id, ptr_s[ptr_s[saved_id]->targets[i] - 1]->name, dmg, ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[PV]);
        ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[PV] -= dmg;
        if (ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[PV] <= 0) {
            ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[PV] = 0;
            ptr_s[ptr_s[saved_id]->targets[i] - 1]->dead = true;
            printf("%d\n", ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[PV]);
            printf("P%d %s's pv hit rock bottom.\n", ptr_s[ptr_s[saved_id]->targets[i] - 1]->id, ptr_s[ptr_s[saved_id]->targets[i] - 1]->name);
            continue;
        }
        printf("%d\n", ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[PV]);
    }
}

void mental_dmg(player_t **ptr_s, int saved_id)
{
    char **array;
    int dmg = 0;

    printf("Basic damage of the skill (0 means that no damage will be taken into account): ");
    while (update_stat(&ptr_s[saved_id]->basic_dmg) == 84);
  //  printf("/!\\ If an effect has a probability of activation, please determine if it activates or not before selecting the targets.\n");
    printf("Here is a list of all the players:\n");
    for (int i = 0; ptr_s[i]; i++)
        printf("P%d %s\n", ptr_s[i]->id, ptr_s[i]->name);
    printf("Select the target(s) (ex: \"1 2\" for player 1 and 2): ");
    array = my_str_to_word_array(get_a_line());
    if (ptr_s[saved_id]->targets != NULL)
        free(ptr_s[saved_id]->targets);
    ptr_s[saved_id]->targets = malloc(sizeof(int) * my_arraylen(array));
    for (int i = 0; array[i]; i++)
        ptr_s[saved_id]->targets[i] = atoi(array[i]);
    printf("Skill precision : ");
    while (update_stat(&ptr_s[saved_id]->precision) == 84);
    for (int i = 0; array[i]; i++) {
        printf("Basic dmg: %d Intelligence: %d\n", ptr_s[saved_id]->basic_dmg, ptr_s[saved_id]->current_stat[INTELLIGENCE]);
        dmg = (int)((float)ptr_s[saved_id]->basic_dmg * (float)ptr_s[saved_id]->current_stat[ATTACK] / 100);
        printf("Result of the dice (/20): ");
        while (update_stat(&ptr_s[saved_id]->dice) == 84);
        dmg = (int)((float)dmg * hit_or_not(ptr_s, saved_id));
        printf("Damage inflicted to P%d %s: %d. Pv : %d -> ", ptr_s[ptr_s[saved_id]->targets[i] - 1]->id, ptr_s[ptr_s[saved_id]->targets[i] - 1]->name, dmg, ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[PV]);
        ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[PV] -= dmg;
        if (ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[PV] <= 0) {
            ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[PV] = 0;
            ptr_s[ptr_s[saved_id]->targets[i] - 1]->dead = true;
            printf("%d\n", ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[PV]);
            printf("P%d %s's pv hit rock bottom.\n", ptr_s[ptr_s[saved_id]->targets[i] - 1]->id, ptr_s[ptr_s[saved_id]->targets[i] - 1]->name);
            continue;
        }
        printf("%d\n", ptr_s[ptr_s[saved_id]->targets[i] - 1]->current_stat[PV]);
    }
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

static void (*ptr_function[3])(player_t **, int) = {
    &physical_dmg,
    &magical_dmg,
    &mental_dmg,
};

void game_loop(player_t **ptr_s)
{
    int saved_id = 0;
    float saved_time;
    effect_t *effect = NULL;

    while (1) {
        saved_id = 0;
        for (int i = 0; ptr_s[i] != NULL; i++)
            if (ptr_s[i]->time < ptr_s[saved_id]->time)
                saved_id = i;
        saved_time = ptr_s[saved_id]->time;
        for (int i = 0; ptr_s[i] != NULL; i++) {
            printf("P%d %s: time : %f -> ", ptr_s[i]->id, ptr_s[i]->name, ptr_s[i]->time);
            ptr_s[i]->time = ptr_s[i]->time - saved_time;
            printf("%f\n", ptr_s[i]->time);
        }
        printf("\nAttacking player : P%d %s\n\n", ptr_s[saved_id]->id, ptr_s[saved_id]->name);
        ptr_function[ptr_s[saved_id]->type](ptr_s, saved_id);
        effect = effect_manager(&effect, ptr_s);
        effect_executioner(effect, ptr_s);
        end_of_turn(effect, ptr_s, saved_id);
        effect_remove(effect);
        determine_time(ptr_s, saved_id);
    }
}
