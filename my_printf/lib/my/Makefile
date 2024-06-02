##
## EPITECH PROJECT, 2023
## makefile
## File description:
## things
##

SRC	=	my_putchar.c	\
		my_putnbr.c	\
		my_putstr.c	\
		my_strlen.c	\
		my_putfloat.c	\
		my_puthex.c	\
		my_puthex_caps.c	\
		my_putpoint.c	\
		my_compute_power_it.c	\
		my_getnbr.c	\
		l_my_putnbr.c	\
		l_my_putnbr.c	\
		l_my_puthex.c	\
		l_my_puthex_caps.c	\
		ll_my_puthex.c	\
		ll_my_puthex_caps.c	\


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../
	cp my.h ../../include

clean:
	rm -f $(OBJ) *~

fclean: clean
	rm ../$(NAME)

re: fclean all

auteur:
	echo $(USER) > auteur
