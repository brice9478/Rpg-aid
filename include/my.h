/*
** EPITECH PROJECT, 2024
** my h
** File description:
** The mastermind behind this ambitious project
*/

#ifndef MY_H_
    #define MY_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "stdbool.h"

typedef enum type_skill {
    PHYSICAL = 0,
    MAGICAL,
    STATUS,
} type_skill;

typedef enum type_effect {
    BUFF = 0,
    DEBUFF,
} type_effect;

typedef enum type_stat {
    PV = 0,
    ATTACK,
    DEFENSE,
    STAMINA,
    PHYSICAL_SPEED,
    MAGICAL_POWER,
    MANA,
    PERCEPTION_SPEED,
    INTELLIGENCE,
    MENTAL,
    THINKING_SPEED,
    WATER,
    FIRE,
    EARTH,
    WIND,
    ELECTRICITY,
    PLANT,
    LIGHT,
    DARKNESS,
} type_stat;

typedef struct effect_s {
    int type;
    int target;
    int stat_hit;
    int duration;
    int value;
    bool percent;
    struct effect_s *next;
} effect_t;

typedef struct player_s {
    int id;
    char *name;
    int delay;
    float time;
    int type;
    int *base_stat;
    int *current_stat;
    int basic_dmg;
    int *targets;
    int dice;
    int precision;
    bool dead;
} player_t;

int main(int ac, char **av);
int display_description(void);
int my_strcmp(char const *s1, char const *s2);
player_t **init_player(char **av);
int my_getnbr(char const *str);
char **my_str_to_word_array(char const *str);
int my_compute_power_rec(int nb, int p);
void game_loop(player_t **ptr_s);
void determine_time(player_t **ptr_s, int i);
int update_stat(int *update);
float hit_or_not(player_t **ptr_s, int saved_id);
effect_t *effect_manager(effect_t **effect, player_t **ptr_s);
void effect_executioner(effect_t *effect, player_t **ptr_s);
char *read_list_stat(void);
void effect_remove(effect_t *effect);
char *get_a_line(void);
int my_arraylen(char **array);
void end_of_turn(effect_t *effect, player_t **ptr_s, int saved_id);
char *read_list_stat_complete(void);
#endif