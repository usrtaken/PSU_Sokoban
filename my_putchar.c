/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** Créer le putchar de la moulinette pour les tests
*/

#include <unistd.h>

void my_putchar (char c)
{
    write (1, &c, 1);
}
