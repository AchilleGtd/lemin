/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** solver
*/

#include "../../include/my.h"

path_t **set_paths(room_t *rooms)
{
    room_t *current = rooms;
    path_t **paths = alloc_size(rooms);
    int i = 0;
    int x;

    while (current) {
        x = current->start == 1 ? 1 : 0;
        paths[i] = add_path(paths[i], current->name, x);
        current = current->next;
        i++;
    }
    paths[i] = NULL;
    return (paths);
}

char *find_first(room_t *rooms)
{
    char *elem;
    room_t *current = rooms;

    while (current && current->start == 0)
        current = current->next;
    if (!current)
        return (NULL);
    elem = my_strdup(current->name);
    return (elem);
}

int done(path_t **path)
{
    int i = 0;

    while (path[i]) {
        if (path[i]->done == 1 || path[i]->distance < 0)
            return (1);
        i++;
    }
    return (0);
}

char *find_end(room_t *rooms)
{
    room_t *current = rooms;

    while (current) {
        if (current->end == 1)
            return (my_strdup(current->name));
        current = current->next;
    }
    return (NULL);
}

int solver(room_t *rooms, int how_many)
{
    path_t **paths = set_paths(rooms);
    char *name_current;
    char *end = find_end(rooms);

    name_current = find_first(rooms);
    while (done(paths) == 1) {
        paths = modify(name_current, paths, rooms);
        paths = done_this(name_current, paths);
        name_current = find_min(paths);
    }
    name_current = find_first(rooms);
    if (good_path(name_current, end, paths) == 1)
        return (84);
    move_ants(paths, end, name_current, how_many);
    return (0);
}
