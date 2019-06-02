/*
** EPITECH PROJECT, 2018
** tail
** File description:
** read files
*/

#include "../../include/my.h"

char *cat_this(char *str, char *sec)
{
    char *tmp = malloc(sizeof(char) * (1 + my_strlen(str) + my_strlen(sec)));
    int i = 0;
    int j = 0;

    while (str[i]) {
        tmp[i] = str[i];
        i++;
    }
    while (sec[j]) {
        tmp[i] = sec[j];
        i++;
        j++;
    }
    free(str);
    tmp[i] = '\0';
    return (tmp);
}

char *read_input(void)
{
    char buf[101];
    char *tmp;
    int been_read = 0;

    been_read = read(0, buf, 100);
    if (been_read < 0)
        return (NULL);
    buf[been_read] = '\0';
    tmp = my_strdup(buf);
    while (been_read > 0) {
        been_read = read(0, buf, 100);
        buf[been_read] = '\0';
        tmp = cat_this(tmp, buf);
    }
    return (tmp);
}
