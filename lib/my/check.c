/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** check input
*/

#include "../../include/my.h"

char *clean_str(char *str)
{
    int i = 0;
    char *buf;

    while (str[i] && str[i] != '#')
        i++;
    if (i < 1)
        return (NULL);
    buf = malloc(sizeof(char) * (1 + i));
    for (int j = 0; j != i; j++)
        buf[j] = str[j];
    buf[i] = '\0';
    return (buf);
}

int connection_time(char *str)
{
    for (int i = 0; str[i] && str[i] != '#'; i++)
        if (str[i] == '-')
            return (0);
    return (1);
}

int check_line(char *str)
{
    int spaces = 0;

    if (!str)
        return (1);
    for (int i = 0; str[i] && str[i] != '#'; i++) {
        if (str[i] == ' ')
            spaces++;
        else if (spaces > 0 && (str[i] < '0' || str[i] > '9'))
            return (1);
    }
    if (spaces < 2 && spaces != 0)
        return (1);
    return (0);
}

int check_for_comment(char *str)
{
    int i = 0;

    if (!str)
        return (0);
    if (str[i] == '#' && (str[i + 1] && str[i + 1] != '#'))
            return (1);
    return (0);
}
