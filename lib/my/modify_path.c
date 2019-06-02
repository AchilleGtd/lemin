/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** modify path
*/

#include "../../include/my.h"

path_t *copy_to_the_end(path_t *to, path_t *current, int distance)
{
    path_t *elem = malloc(sizeof(path_t));
    path_t *rcurrent = to;

    elem->next = NULL;
    elem->name = my_strdup(current->name);
    elem->distance = distance;
    while (rcurrent->next)
        rcurrent = rcurrent->next;
    rcurrent->next = elem;
    return (to);
}

path_t *modify_distance(path_t *from, path_t *to, int distance)
{
    path_t *current;
    path_t *previous;

    while (to->next) {
        previous = to;
        to = to->next;
        free(previous->name);
        free(previous);
    }
    current = from;
    to->distance = distance;
    while (current) {
        to = copy_to_the_end(to, current, distance);
        current = current->next;
    }
    return (to);
}

path_t **modify(char *name, path_t **path, room_t *rooms)
{
    int j = find_name(path, name);
    int i = 0;
    int distance = path[j]->distance;
    room_t *current = find_name_(rooms, name);
    connections_t *current_co = current->connections;

    if (!current_co)
        return (path);
    while (current_co) {
        distance = distance + current_co->distance;
        i = find_name(path, current_co->connected_to);
        if (distance < path[i]->distance)
            path[i] = modify_distance(path[j], path[i], distance);
        current_co = current_co->next;
        distance = path[j]->distance;
    }
    return (path);
}
