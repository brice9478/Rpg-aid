/*
** EPITECH PROJECT, 2023
** description
** File description:
** The writer who wrote this master piece
*/

#include "include/my.h"

int display_description(void)
{
    struct stat sfile;
    int fd;
    char *buffer;

    stat("description.txt", &sfile);
    fd = open("description.txt", O_RDONLY);
    buffer = malloc(sizeof(char) * (sfile.st_size + 1));
    read(fd, buffer, sfile.st_size);
    write(1, buffer, sfile.st_size);
    close(fd);
    free(buffer);
    return 0;
}