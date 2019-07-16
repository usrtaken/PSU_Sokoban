/*
** EPITECH PROJECT, 2018
** rangement2.c
** File description:
** Ranger mes fonctions.
*/

#include "sokoban.h"

int x_comp(char **str, int lines)
{
    int i = 0;
    int j;
    int x = 0;

    while (i <= lines) {
        j = 0;
        while (str[i][j] != '\0') {
            if (str[i][j] == 'X') 
                x++;
            j++;
        }
        i++;
    }
    return (x);
}

void win(char **str, char **boardor, int lines)
{
    int i = 0;
    int j;
    int x = x_comp(str, lines);
    int xo = 0;

    while (i <= lines) {
        j = 0;
        while (str[i][j] != '\0') {
            if (str[i][j] == 'X' && boardor[i][j] == 'O')
                xo++;
            j++;
        }
        i++;
    }
    if (xo == x) {
        endwin();
        exit (0);
    }
}

void lose(char **str, int lines)
{
    int i = 1;
    int j;
    int x = x_comp(str, lines);
    int xx = 0;

    while (i <= lines) {
        j = 0;
        while (j < my_strlen(str[i])) {
            xx += blocked(str, i, j);
            j++;
        }
        i++;
    }
    if (xx == x) {
        endwin();
        exit (1);
    }
}

int blocked(char **str, int y, int x)
{
    if (str[y][x] == 'X') {
        if (str[y - 1][x] == '#' && str[y][x - 1] == '#')
            return (1);
        if (str[y + 1][x] == '#' && str[y][x -1] == '#')
            return (1);
        if (str[y - 1][x] == '#' && str[y][x + 1] == '#')
            return (1);
        if (str[y + 1][x] == '#' && str[y][x + 1] == '#')
            return (1);
    }
    return (0);
}