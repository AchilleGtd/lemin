/*
** EPITECH PROJECT, 2018
** commande
** File description:
** commande
*/

#include "../../include/my.h"

char **nb_malloc_array(char **str, char *s, char letter)
{
    int x = 0;
    int size2 = 0;

    while (s[x] != '\0') {
        if (s[x] == letter)
            size2 = size2 + 1;
        x = x + 1;
    }
    str = malloc(sizeof(char *) * (size2 + 2));
    str[size2 + 1] = NULL;
    return (str);
}

char **copie2(int *box, char **str, char *s)
{
    int e = 0;
    int save2 = box[3];

    str[box[2]] = malloc(sizeof(char) * ((box[1] - box[3]) + 1));
    while (e < box[1] - save2) {
        str[box[2]][e] = s[box[3]];
        e = e + 1;
        box[3] = box[3] + 1;
    }
    str[box[2]][e] = '\0';
    box[2] = box[2] + 1;
    box[3] = box[3] + 1;
    return (str);
}

char **my_str_to_wordtab(char *s, char letter)
{
    int *box = malloc(sizeof(int) * 4);
    char **str = nb_malloc_array(str, s, letter);

    box[1] = 0;
    box[2] = 0;
    box[3] = 0;
    while (s[box[1]] != '\0') {
        box[1] = box[1] + 1;
        if (s[box[1]] == letter || s[box[1]] == '\0')
            str = copie2(box, str, s);
    }
    free(box);
    return (str);
}
