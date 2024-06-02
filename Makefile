##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## The ruler of this forgotten land
##

CFLAGS	=	-g

SRC	=	main.c	\
		display_description.c	\
		my_strcmp.c	\
		my_getnbr.c	\
		my_str_to_word_array.c	\
		my_compute_power_rec.c	\
		init_player.c	\
		game_loop.c	\
		determine_time.c	\
		hit_or_not.c	\
		effect_manager.c	\
		effect_executioner.c	\
		effect_remove.c	\
		end_of_turn.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	rpg_aid

$(NAME):	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(OBJ)
		rm -f $(NAME)

re:	fclean all

.PHONY:	clean fclean all re