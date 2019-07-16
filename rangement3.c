/*
** EPITECH PROJECT, 2018
** rangement3.c
** File description:
** Ce rangement sert à garder les petites fonctions.
*/

#include "sokoban.h"

char *find_error(char *error)
{
    write(2, error, my_strlen(error));
    return (NULL);
}

int compt_li(char const *str)
{
    int charac = 0;

    while (str[charac] != '\n' && str[charac] != '\0')
        charac++;
    return (charac);
}

void board_comp(char **str, char **boardor, int lines)
{
    int com = 0;
    int comp;

    while (com <= lines) {
        comp = 0;
        while (str[com][comp] != '\0') {
            if (boardor[com][comp] == 'O' && str[com][comp] == ' ') 
                str[com][comp] = 'O';
            comp++;
        }
        com++;
    }
}

int moven(char **str, int *y, int *x, int P)
{
    keypad(stdscr, TRUE);
    if (P == KEY_UP || P == 65)
        movenup(str, y, x);
    if (P == KEY_DOWN || P == 66)
        movendown(str, y, x);
    if (P == KEY_RIGHT || P == 67)
        movenright(str, y, x);
    else if (P == KEY_LEFT || P == 68)
        movenleft(str, y, x);
    return (0);
}