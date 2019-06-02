/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** utility fctions
*/

#include "../../include/my.h"

int  find_distance(int fx, int fy, int sx, int sy)
{
    int new_x, new_y;

    new_x = fx - sx;
    new_x = new_x < 0 ? -new_x : new_x;
    new_y = fy - sy;
    new_y = new_y < 0 ? - new_y : new_y;
    return (new_y + new_x);
}

room_t *find_room(room_t *list, char *str)
{
    room_t *current;

    if (!list)
        return (NULL);
    current = list;
    while (current && my_strncmp(current->name, str, my_strlen(str)) != 0)
        current = current->next;
    return (current);
}

connections_t *add_node(connections_t *list, char *str, int d)
{
    connections_t *elem = malloc(sizeof(connections_t));

    elem->connected_to = my_strdup(str);
    elem->next = list;
    elem->distance = d;
    return (elem);
}
