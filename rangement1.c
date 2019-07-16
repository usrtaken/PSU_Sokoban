/*
** EPITECH PROJECT, 2018
** rangement1.c
** File description:
** Ranger mes fonctions encore.
*/

#include "sokoban.h"

int lignes(char const *str)
{
    int i = 0, j;

    for (j = 0; str[j] != 0; j++) {
        if (str[j] == '\n')
            i++;
    }
    if (str[j - 1] == '\n')
        i--;
    return (i);
}

char **convert(char const *str)
{
    int lines = lignes(str);
    int i = 0;
    int colo;
    char **idea = malloc(sizeof(char *) * (lines + 1));
    int compteur = 0;
    int rang = 0;

    while (str[compteur] != '\0') {
        colo = compt_li(&str[compteur]);
        idea[rang] = malloc(sizeof(char) * (colo + 1));
        while ((str[compteur] != '\n') && (str[compteur] != '\0'))
            idea[rang][i++] = str[compteur++];
        i = 0;
        compteur++;
        rang++;
    }
    return (idea);
}

void soko(char **str, int lines, char **boardor)
{
    int y = 0;
    int x = 0;
    int stringue;
    int j = 0;

    keypad(stdscr, TRUE);
    while (str[y][x] != 'P') {
        if (str[y][x] == '\0') {
            x = 0;
            y += 1;
        }
        if (str[y][x] != '\0')
            x += 1;
    }
    while (stringue != ' ') {
        initscr();
        j = 0;
        while (j <= lines) {
            mvprintw(j, 0, str[j]);
            printw("\n");
            j++;
        }
        stringue = getch();
        moven(str, &y, &x, stringue);
        board_comp(str, boardor, lines);
        win(str, boardor, lines);
        lose(str, lines);
        clear();
    }
    endwin();
}