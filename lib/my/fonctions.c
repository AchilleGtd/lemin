/*
** EPITECH PROJECT, 2019
** navy
** File description:
** not navy, lemin
*/

#include "../../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

int my_strncmp(char *str, char *sec, int n)
{
    int i = 0;

    while (str[i] || i != n || sec[i]) {
        if (str[i] != sec[i])
            return (1);
        i++;
    }
    return (0);
}

int find_length(int fx, int fy, int sx, int sy)
{
    int x = fx - sx;
    int y = fy - sy;

    x = (x < 0) ? -x : x;
    y = (y < 0) ? -y : y;
    return (x + y);
}

int my_strcmp(char *str, char *src)
{
    int i = 0;

    while (str[i] && src[i] && str[i] == src[i])
        i = i + 1;
    if (!str[i] && !src[i])
        return (0);
    return (1);
}
