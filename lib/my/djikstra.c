/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** djikstra
*/

#include "../../include/my.h"

int find_name(path_t **path, char *name)
{
    int i = 0;

    while (path[i]->name && my_strcmp(path[i]->name, name) != 0)
        i++;
    return (i);
}

room_t *find_name_(room_t *room, char *name)
{
    room_t *current = room;

    while (current && my_strcmp(current->name, name) != 0)
        current = current->next;
    return (current);
}

char *find_min(path_t **paths)
{
    int i = 0;
    int j = 0;
    char *buf = NULL;
    int min = INT_MAX;

    while (paths[i]) {
        if (paths[i]->distance < min &&
            paths[i]->distance != 0 && paths[i]->done == 1) {
            min = paths[i]->distance;
            j = i;
        }
        i++;
    }
    buf = my_strdup(paths[j]->name);
    return (buf);
}

path_t **done_this(char *name, path_t **paths)
{
    int i = find_name(paths, name);

    paths[i]->done = 0;
    return (paths);
}
