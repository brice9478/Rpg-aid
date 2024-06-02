/*
** EPITECH PROJECT, 2024
** determine time
** File description:
** How long will it take to launch your next attack ?
*/

#include "include/my.h"

int check_digit(char *line, int nread)
{
    for (int check = 0; check < nread; check++) {
        if (line[check] == '\n')
            continue;
        if (line[check] < '0' || line[check] > '9') {
            printf("Error. Please retry.\n");
            free(line);
            return 84;
        }
    }
    return 0;
}

int update_stat(int *update)
{
    char *line = NULL;
    size_t len;
    ssize_t nread;

    while (1) {
        nread = getline(&line, &len, stdin);
        if (nread == -1 || line[0] == '\n') {
            printf("Error. Please retry.\n");
            free(line);
            return 84;
        }
        if (check_digit(line, nread) == 84)
            return 84;
        if (line[nread - 1] == '\n') {
            line[nread - 1] = '\0';
            (*update) = atoi(line);
            free(line);
            return 0;
        }
    }
}

void determine_time(player_t **ptr_s, int i)
{
    bool wrong;

    wrong = false;
    printf("P%d %s : delay capacity : ", ptr_s[i]->id, ptr_s[i]->name);
    while (update_stat(&ptr_s[i]->delay) == 84);
    printf("Skill : physical (0) or magical (1) or mental (2) ? ");
    while (update_stat(&ptr_s[i]->type) == 84);
    switch (ptr_s[i]->type) {
    case 0:
        ptr_s[i]->time = (float)ptr_s[i]->delay / (float)ptr_s[i]->current_stat[PHYSICAL_SPEED];
        break;
    case 1:
        ptr_s[i]->time = (float)ptr_s[i]->delay / (float)ptr_s[i]->current_stat[PERCEPTION_SPEED];
        break;
    case 2:
        ptr_s[i]->time = (float)ptr_s[i]->delay / (float)ptr_s[i]->current_stat[THINKING_SPEED];
        break;
    default:
        wrong = true;
        break;
    }
    if (wrong == true) {
        wrong = false;
        printf("Something's not right... retry\n");
        determine_time(ptr_s, i);
    }
//        printf("%f %d %d \n", ptr_s[i]->time, ptr_s[i]->delay, ptr_s[i]->physical_speed);
    printf("P%d %s has to wait %f turn !\n\n", ptr_s[i]->id, ptr_s[i]->name, ptr_s[i]->time);
}
