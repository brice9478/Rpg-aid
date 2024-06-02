/*
** EPITECH PROJECT, 2024
** first turn
** File description:
** Who are the players ? Let's find out
*/

#include "include/my.h"

char *my_strcpy_line(char *dest, char const *src, int start)
{
    int i = start;

    for (i; src[i] != '\n' && src[i] != '\0'; i++);
    dest = malloc(sizeof(char) * (i + 1));
    for (i = start; src[i] != '\n' && src[i] != '\0'; i++)
        dest[i - start] = src[i];
    dest[i - start] = '\0';
    return (dest);
}

char *my_strcpy_to_max(char *dest, char const *src, int max)
{
    int i;

    for (i = 0; src[i] != '\0' && i < max; i++) {
        dest[i] = src[i];
        printf("src %c\n", src[i]);
        printf("dest %c\n", dest[i]);
        }
    dest[i] = '\0';
    return (dest);
}

player_t **init_player(char **av)
{
    struct stat sfile;
    int fd;
    char *buffer;
    int count = 0;
    int line = 0;
    player_t **ptr_s;
    char *str;
    int begin_line = 0;
    char **array;
    int prev = -1;
    bool one_player = false;

    stat(av[1], &sfile);
    fd = open(av[1], O_RDONLY);
    if (fd == -1) {
        perror("Non existing file.\n");
        return NULL;
    }
    buffer = malloc(sizeof(char) * (sfile.st_size + 1));
    read(fd, buffer, sfile.st_size);
    buffer[sfile.st_size] = '\0';
    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] == '\n') {
            line++;
            one_player = true;
        }
        if (line % 20 == 1 && one_player == true) {
            count++;
            one_player = false;
        }
    }
    if (line % 20 != 19) {
        perror("Wrong number of lines.\nPlease either remove the last empty line or check if everything is correct.\n");
        return NULL;
    }
    array = malloc(sizeof(char *) * (line + 1));
    line = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            array[line] = malloc(sizeof(char) * (i - prev));
            array[line] = strncpy(array[line], &buffer[prev + 1], i - prev - 1);
            array[line][i - prev - 1] = '\0';
            line++;
            prev = i;
        }
    }
    array[line] = NULL;
    ptr_s = malloc(sizeof(player_t *) * (count + 1));
    for (int i = 0; i < count; i++) {
        ptr_s[i] = malloc(sizeof(player_t));
        ptr_s[i]->base_stat = malloc(sizeof(int) * 19);
        ptr_s[i]->current_stat = malloc(sizeof(int) * 19);
        ptr_s[i]->id = i + 1;
    }
    count = 0;
    for (int i = 0; array[i] != NULL; i++) {
        count = i / 20;
        if (i % 20 == 0) {
            ptr_s[count]->name = malloc(sizeof(char) * (strlen(array[i]) + 1));
            ptr_s[count]->name = strcpy(ptr_s[count]->name, array[i]);
        } else {
            ptr_s[count]->base_stat[(i % 20) - 1] = atoi(array[i]);
            ptr_s[count]->current_stat[(i % 20) - 1] = atoi(array[i]);
        }
    }
    ptr_s[count + 1] = NULL;
    for (int i = 0; ptr_s[i] != NULL; i++) {
        ptr_s[i]->targets = NULL;
        ptr_s[i]->dead = false;
    }
    close(fd);
    free(buffer);
    return ptr_s;
}
