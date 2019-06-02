/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** reads a file line by line
*/

#include "../../include/my.h"

int is_num(char *s)
{
    int i = 0;

    while (s[i]) {
        if ((s[i] < '0' || s[i] > '9') && s[i] != ' ')
            return (1);
        i++;
    }
    return (0);
}

char *my_strdup(char *str)
{
    int i = 0;
    char *buf = NULL;

    while (str[i])
            i++;
    buf = malloc(sizeof(char) * (1 + i));
    i = 0;
    while (str[i]) {
            buf[i] = str[i];
            i++;
    }
    buf[i] = '\0';
    return (buf);
}

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char *buf;

    while (str[i])
            i++;
    buf = malloc(sizeof(char) * (1 + i));
    i = i - 1;
    while (i != -1) {
            buf[j] = str[i];
            j++;
            i--;
    }
    buf[j] = '\0';
    return (buf);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

int my_exit(char *s, char **buf)
{
    free(s);
    for (int i = 0; buf[i]; i++)
        free(buf[i]);
    return (84);
}
