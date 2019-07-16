/*
** EPITECH PROJECT, 2018
** sokoban.h
** File description:
** Faire un sokoban 
*/

#include <unistd.h>
#include <fcntl.h>
#include <ncurses.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int my_strlen(char const *str);
int my_putstr(char const *str);
int my_putchar(char c);
char *read_map(char **av);
char *find_error(char *error);
char *errors(int ac, char **av);
int gerance(char **av);
char **convert(char const *str);
int compt_li(char const *str);
int lignes(char const *str);
void soko(char **str, int lines, char **boardor);
int moven(char **str, int *y, int *x, int P);
void movenup(char **str, int *y, int *x);
void movendown(char **str, int *y, int *x);
void movenright(char **str, int *y, int *x);
void movenleft(char **str, int *y, int *x);
void board_comp(char **str, char **boardor, int lines);
int x_comp(char **str, int lines);
void win(char **str, char **boardor, int lines);
int blocked(char **str, int y, int x);
void lose(char **str, int lines);