/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** add
*/

#include "../../include/my.h"

path_t **alloc_size(room_t *rooms)
{
    path_t **paths;
    room_t *current = rooms;
    int i = 0;

    while (current) {
        i++;
        current = current->next;
    }
    paths = malloc(sizeof(path_t *) * (1 + i));
    return (paths);
}

names_t *add_name(names_t *list, char *name)
{
    names_t *elem = malloc(sizeof(names_t));

    elem->name = my_strdup(name);
    elem->next = list;
    return (elem);
}

names_t *add_start(room_t *rooms)
{
    names_t *list = NULL;
    connections_t *current_co;
    room_t *current = rooms;

    while (current && current->start == 0)
        current = current->next;
    if (!current)
        return (NULL);
    current_co = current->connections;
    while (current_co) {
        list = add_name(list, current_co->connected_to);
        current_co = current_co->next;
    }
    return (list);
}

path_t *add_path(path_t *list, char *name, int x)
{
    path_t *elem = malloc(sizeof(path_t));

    elem->done = 1;
    elem->name = my_strdup(name);
    elem->distance = (x == 0) ? INT_MAX : 0;
    elem->head = elem;
    elem->next = NULL;
    return (elem);
}

