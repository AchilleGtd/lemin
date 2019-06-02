/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** char in int
*/

#include "../../include/my.h"

int my_atoi(const char *str)
{
    int nb = 0;
    int signe = 1;
    int i = 0;

    if (str[0] == '-') {
        signe = -1;
        i = i + 1;
    }
    while (str[i] != '\0' && str[i] != '\n') {
        nb = nb * 10 + (str[i] - 48);
        i = i + 1;
    }
    return (nb * signe);
}
