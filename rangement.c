/*
** EPITECH PROJECT, 2018
** rangement.c
** File description:
** Ranger mes fonctions.
*/

#include "sokoban.h"

char *read_map(char **av)
{
    int length = 0;
    int offset = 0;
    char *test;
    int sesame;
    int octet;
    struct stat total;

    sesame = open(av[1], O_RDONLY);
    if (sesame == -1)
        return (NULL);
    stat(av[1], &total);
    octet = total.st_size;
    test = malloc(sizeof(char) * (octet + 1));
    while ((length = read(sesame, test + offset, octet - offset)) > 0)
        offset += length;
    test[offset] = '\0';
    return (test);
}

char *errors(int ac, char **av)
{
    char *test;
    int f = 0, X = 0, O = 0, test1;

    if (ac != 2)
        return (find_error("Please send a correct request\n"));
    test1 = gerance(av);
    if (test1 == 1)
        return ("h");
    test = read_map(av);
    if (test == NULL)
        return (find_error("Please send a correct request\n"));
    for (int i = 0; i < my_strlen(test); i++) {
        if (test[i] != '#' && test[i] != 'X' && test[i] != 'O' \
            && test[i] != 'P' && test[i] != ' ' && test[i] != '\n')
            return (find_error("Please send a valid map\n"));
    }
    for (int j = 0; j < my_strlen(test); j++) {
        if (test[j] == 'P')
            f++;
        if (test[j] == 'X')
            X++;
        if (test[j] == '0')
            O++;
    }
    if (f != 1) 
        return (find_error("Not more or less than one player, cheater\n"));
    if (X != O && X == 0)
        return (find_error("Need the same amount of boxes and spaces,duh\n"));
    return (test);
}

int gerance(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        my_putstr("USAGE\n");
        my_putstr("    ./my_sokoban map\n");
        my_putstr("DESCRIPTION");
        my_putstr("    map file representing the warehouse map, ");
        my_putstr("containing '#' for walls, \n");
        my_putstr("                 'P' for the player, ");
        my_putstr("'X' for the boxes and 'O' for the storage locations\n");
        return (1);
    }
    return (0);
}