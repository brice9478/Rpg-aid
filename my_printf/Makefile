##
## EPITECH PROJECT, 2023
## makefile
## File description:
## things
##

.SILENT:

SRC	=	./lib/my/my_putchar.c	\
		./lib/my/my_putnbr.c	\
		./lib/my/my_putstr.c	\
		./lib/my/my_strlen.c	\
		./lib/my/my_putfloat.c	\
		./lib/my/my_puthex.c	\
		./lib/my/my_puthex_caps.c	\
		./lib/my/my_putpoint.c	\
		./lib/my/my_compute_power_it.c	\
		./lib/my/my_getnbr.c	\
		./lib/my/my_revstr.c	\
		./lib/my/my_strcpy.c	\
		./lib/my/my_strcat.c	\
		./lib/my/my_printf.c	\
		./lib/my/print_char.c	\
		./lib/my/print_number.c	\
		./lib/my/print_float.c	\
		./lib/my/print_float_comma.c	\
		./lib/my/print_hex_caps.c	\
		./lib/my/print_hex.c	\
		./lib/my/print_string.c	\
		./lib/my/print_octal.c	\
		./lib/my/print_undecimal.c	\
		./lib/my/print_pointer.c	\
		./lib/my/hashtag_hex.c	\
		./lib/my/hashtag_hex_caps.c	\
		./lib/my/hashtag_float.c	\
		./lib/my/hashtag_octal.c	\
		./lib/my/hashtag_e.c	\
		./lib/my/hashtag_e_cap.c	\
		./lib/my/print_science_cap.c	\
		./lib/my/print_science_cap_comma.c	\
		./lib/my/print_e.c	\
		./lib/my/print_e_comma.c	\
		./lib/my/print_g_flag.c	\
		./lib/my/number_flag.c	\
		./lib/my/my_itoa.c	\
		./lib/my/minus_flag.c	\
		./lib/my/plus_flag.c	\
		./lib/my/l_print_octal.c	\
		./lib/my/l_print_undecimal.c	\
		./lib/my/ll_print_octal.c	\
		./lib/my/ll_print_undecimal.c	\
		./lib/my/l_my_puthex.c	\
		./lib/my/l_my_puthex_caps.c	\
		./lib/my/ll_my_puthex.c	\
		./lib/my/ll_my_puthex_caps.c	\
		./lib/my/l_print_hex_caps.c	\
		./lib/my/l_print_hex.c	\
		./lib/my/ll_print_hex_caps.c	\
		./lib/my/ll_print_hex.c	\
		./lib/my/flags_l.c	\
		./lib/my/l_my_putnbr.c	\
		./lib/my/ll_my_putnbr.c	\
		./lib/my/l_print_number.c	\
		./lib/my/ll_print_number.c	\


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	chmod 777 $(NAME)

clean:
	rm -f $(OBJ) *~

fclean: clean
	rm $(NAME)

re: fclean all

auteur:
	echo $(USER) > auteur
