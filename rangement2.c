/*
** EPITECH PROJECT, 2018
** rangement2.c
** File description:
** Ranger mes fonctions.
*/

#include "sokoban.h"

void movenup(char **str, int *y, int *x)
{
    if ((str[*y - 1][*x] == 'X') && ((str[*y - 2][*x] != '#') &&\
    (str[*y - 2][*x] != 'X'))) {
        str[*y][*x] = ' ';
        str[*y - 1][*x] = 'P';
        str[*y - 2][*x] = 'X';
        *y -= 1;
    } else if (str[*y - 1][*x] == ' ' || str[*y - 1][*x] == 'O')   {
        str[*y][*x] = ' ';
        str[*y - 1][*x] = 'P';
        *y -= 1;
    }
}

void movendown(char **str, int *y, int *x)
{
    if (str[*y + 1][*x] == 'X'&& ((str[*y + 2][*x] != '#') &&\
    (str[*y + 2][*x] != 'X'))) {
        str[*y][*x] = ' ';
        str[*y + 1][*x] = 'P';
        str[*y + 2][*x] = 'X';
        *y += 1;
    }else if (str[*y + 1][*x] == ' ' || str[*y + 1][*x] == 'O') {
        str[*y][*x] = ' ';
        str[*y + 1][*x] = 'P';
        *y += 1;
    }
}

void movenright(char **str, int *y, int *x)
{
    if (str[*y][*x + 1] == 'X' && ((str[*y][*x + 2] != '#') &&\
    (str[*y][*x +2] != 'X'))) {
        str[*y][*x] = ' ';
        str[*y][*x + 1] = 'P';
        str[*y][*x + 2] = 'X';
        *x += 1;
    } else if (str[*y][*x + 1] == ' ' || str[*y][*x + 1] == 'O') {
        str[*y][*x] = ' ';
        str[*y][*x + 1] = 'P';
        *x += 1;
    }
}

void movenleft(char **str, int *y, int *x)
{
    if (str[*y][*x - 1] == 'X' && ((str[*y][*x - 2] != '#') &&\
    (str[*y][*x - 2] != 'X'))) {
        str[*y][*x] = ' ';
        str[*y][*x - 1] = 'P';
        str[*y][*x - 2] = 'X';
        *x -= 1;
    } else if (str[*y][*x - 1] == ' ' || str[*y][*x - 1] == 'O') {
        str[*y][*x] = ' ';
        str[*y][*x - 1] = 'P';
        *x -= 1;
    }
}