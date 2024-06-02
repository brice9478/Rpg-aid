/*
** EPITECH PROJECT, 2024
** effect executioner
** File description:
** Ultra favoritism : will give you a gift, or will torture you
*/

#include "include/my.h"

char *read_list_stat_complete(void)
{
    struct stat sfile;
    int fd;
    char *buffer;

    stat("list_stat_complete.txt", &sfile);
    fd = open("list_stat_complete.txt", O_RDONLY);
    buffer = malloc(sizeof(char) * (sfile.st_size + 1));
    read(fd, buffer, sfile.st_size);
    close(fd);
    buffer[sfile.st_size] = '\0';
    return buffer;
}

void effect_executioner(effect_t *effect, player_t **ptr_s)
{
    effect_t *travel;
    char **array_stats = my_str_to_word_array(read_list_stat_complete());

    for (int p = 0; ptr_s[p] != NULL; p++)
        for (int i = 1; i < 19; i++)
            ptr_s[p]->current_stat[i] = ptr_s[p]->base_stat[i];
    for (travel = effect; travel != NULL; travel = travel->next) {
        printf("P%d %s: %s ", ptr_s[travel->target - 1]->id, ptr_s[travel->target - 1]->name, array_stats[travel->stat_hit]);
        if (travel->type == BUFF)
            printf("+");
        printf("%d", travel->value);
        if (travel->percent == true)
            printf("%%");
        printf(": %d -> ", ptr_s[travel->target - 1]->current_stat[travel->stat_hit]);
        if (travel->percent == true) {
            if (travel->type == BUFF)
                ptr_s[travel->target - 1]->current_stat[travel->stat_hit] = (int)((float)ptr_s[travel->target - 1]->current_stat[travel->stat_hit] + (float)((travel->value * ptr_s[travel->target - 1]->base_stat[travel->stat_hit]) / 100));
            if (travel->type == DEBUFF)
                ptr_s[travel->target - 1]->current_stat[travel->stat_hit] = (int)((float)ptr_s[travel->target - 1]->current_stat[travel->stat_hit] - (float)(((100 + travel->value) * ptr_s[travel->target - 1]->base_stat[travel->stat_hit]) / 100));
        } else
            ptr_s[travel->target - 1]->current_stat[travel->stat_hit] += travel->value;
        printf("%d\n", ptr_s[travel->target - 1]->current_stat[travel->stat_hit]);
    }
}
