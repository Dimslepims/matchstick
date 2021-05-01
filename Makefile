##
## EPITECH PROJECT, 2019
## makz
## File description:
## makz
##

SRC =	src/print_game_board.c	\
		src/my_putstr.c	\
		src/my_getnbr.c	\
		src/my_put_nbr.c	\
		src/print_map.c	\
		src/gameloop.c	\
		src/player.c	\
		src/check.c

NAME =	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -g -o $(NAME) $(SRC) -O2

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re : fclean all
