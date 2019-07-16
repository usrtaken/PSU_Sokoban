/*
** EPITECH PROJECT, 2018
** my_sokoban.c
** File description:
** Faire un sokoban
*/

#include "sokoban.h"

int main (int ac, char **av)
{
    char *test = errors(ac, av);
    char **board;
    char **boardor;
    int lines;

    if (test == NULL)
        return (84);
    if (test[0] == 'h')
        return (0);
    board = convert(test);
    boardor = convert(test);
    lines = lignes(test);
    soko(board, lines, boardor);
    return (0);
}