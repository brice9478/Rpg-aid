/*
** EPITECH PROJECT, 2024
** effect manager
** File description:
** Will take into account the effect, its duration and its targets
*/

#include "include/my.h"

void display_effect_h(player_t **ptr_s)
{
    struct stat sfile;
    int fd;
    char *buffer;

    printf("=================================================================================\
    \n\nHere is a list of all the players:\n\n");
    for (int i = 0; ptr_s[i]; i++)
        printf("P%d %s\n", ptr_s[i]->id, ptr_s[i]->name);
    printf("\n");
    stat("help_effect.txt", &sfile);
    fd = open("help_effect.txt", O_RDONLY);
    buffer = malloc(sizeof(char) * (sfile.st_size + 1));
    read(fd, buffer, sfile.st_size);
    write(1, buffer, sfile.st_size);
    close(fd);
    free(buffer);
}

char *read_list_stat(void)
{
    struct stat sfile;
    int fd;
    char *buffer;

    stat("list_stat.txt", &sfile);
    fd = open("list_stat.txt", O_RDONLY);
    buffer = malloc(sizeof(char) * (sfile.st_size + 1));
    read(fd, buffer, sfile.st_size);
    close(fd);
    buffer[sfile.st_size] = '\0';
    return buffer;
}

effect_t *effect_manager(effect_t **effect, player_t **ptr_s)
{
    effect_t *new_node;
    int choice = 0;
    char **array;
    char **short_stat;
    int count;

    printf("Any effects ? (yes: 0; no: 1; help: 2): ");
    choice = atoi(get_a_line());
    while (choice == 0 || choice == 2) {
        if (choice == 2) {
            display_effect_h(ptr_s);
            printf("Any more effects ? (yes: 0; no: 1; help: 2): ");
            choice = atoi(get_a_line());
            continue;
        }
        printf("Please enter the effects: ");
        array = my_str_to_word_array(get_a_line());
        for (int i = 0; i < my_arraylen(array); i++) {
            new_node = malloc(sizeof(effect_t));
            if (array[i][0] == '+')
                new_node->type = BUFF;
            if (array[i][0] == '-')
                new_node->type = DEBUFF;
            new_node->value = atoi(array[i]);
            array[i] = &array[i][1];
            while (array[i][0] >= '0' && array[i][0] <= '9')
                array[i] = &array[i][1];
            if (array[i][0] == '%') {
                new_node->percent = true;
                array[i] = &array[i][1];
            }
            short_stat = my_str_to_word_array(read_list_stat());
            for (count = 0; short_stat[count] != NULL; count++) {
                if (strncmp(short_stat[count], array[i], strlen(short_stat[count])) == 0)
                    break;
            }
            new_node->stat_hit = count;
            for (int x = 0; x < strlen(short_stat[count]) + 1; x++)
                array[i] = &array[i][1];
            new_node->duration = atoi(array[i]);
            while (array[i][0] >= '0' && array[i][0] <= '9')
                array[i] = &array[i][1];
            array[i] = &array[i][1];
            new_node->target = atoi(array[i]);
            new_node->next = *effect;
            *effect = new_node;
        }
        printf("Any more effects ? (yes: 0; no: 1; help: 2): ");
        choice = atoi(get_a_line());
    }
    return *effect;
}
