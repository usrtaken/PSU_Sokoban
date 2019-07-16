##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC =	my_sokoban.c \
		my_strlen.c \
		rangement.c \
		rangement1.c \
		my_putstr.c \
		my_putchar.c \
		rangement2.c \
		rangement3.c \
		rangement4.c \

CC = 	gcc 

LIB = -lncurses

CFLAGS =  -W -Wall -Wextra -Werror

RM = rm -f

OBJ =	$(SRC:.c=.o)

NAME =	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB) -lncurses

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME) $(OBJ)

re:	fclean all