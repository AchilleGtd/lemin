/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** move ants
*/

#include "../../include/my.h"

int good_path(char *first, char *end, path_t **paths)
{
    path_t *current;
    int i = find_name(paths, end);

    current = paths[i];
    if (current->next)
        while (current->next)
            current = current->next;
    if (my_strcmp(first, current->name) != 0)
        return (1);
    return (0);
}

int how_many_steps(path_t *path)
{
    path_t *current = path;
    int i = 0;

    while (current) {
        i++;
        current = current->next;
    }
    return (i);
}

char **group_up(path_t **paths, int i, int nbr)
{
    char **buf = malloc(sizeof(char *) * (1 + nbr));
    path_t *prev;
    path_t *current = paths[i];
    buf[nbr] = NULL;
    nbr--;
    while (nbr != -1) {
        buf[nbr] = my_strdup(current->name);
        nbr--;
        current = current->next;
    } for (int j = 0; paths[j]; j++) {
        current = paths[j];
        prev = current;
        while (current) {
            prev = current;
            free(current->name);
            current = current->next;
            free(prev);
        }
    }
    return (buf);
}

names_t *add_ant(names_t *ants, int number, char *name)
{
    names_t *current = ants;
    names_t *elem = malloc(sizeof(names_t));

    elem->size = number;
    elem->name = my_strdup(name);
    elem->next = NULL;
    if (ants && ants->next) {
        while (current->next)
            current = current->next;
    }
    else if (!ants)
        return (elem);
    current->next = elem;
    return (ants);
}
