/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** Renvoie le nombre de lettre dans un string
*/

#include <stdio.h>

int my_putchar(char c);

int my_strlen(char const *str)
{
    int lettre = 0;

    while (str[lettre] != '\0')
    {
	lettre++;
    }
    return (lettre);
}
