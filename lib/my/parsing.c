/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** parses input
*/

#include "../../include/my.h"

int not_cool(char **str, int *nbr)
{
    int i = 0;
    int j = 0;

    while (str[j] && str[j][0] == '#')
        j++;
    if (!str[j])
        return (1);
    while (str[j][i]) {
        if (str[j][i] && (str[j][i] < '0' || str[j][i] > '9'))
            return (1);
        i++;
    }
    *nbr = my_atoi(str[j]);
    return (0);
}

room_t *add_room(room_t *rooms, char *str, int start, int end)
{
    room_t *elem = malloc(sizeof(room_t));
    char **buf = my_str_to_wordtab(str, ' ');
    room_t *try;

    elem->next = rooms;
    elem->name = my_strdup(buf[0]);
    elem->length = INT_MAX;
    elem->x = my_atoi(buf[1]);
    elem->y = my_atoi(buf[2]);
    elem->start = start;
    elem->end = end;
    elem->connections = NULL;
    try = elem;
    return (elem);
}

room_t *add_connexion(room_t *list, char *str)
{
    char **buf = my_str_to_wordtab(str, '-');
    room_t *first_room;
    room_t *second_room;
    int d;

    first_room = find_room(list, buf[0]);
    second_room = find_room(list, buf[1]);
    if (!first_room || !second_room)
        return (list);
    d = find_distance(first_room->x, first_room->y, second_room->x,
second_room->y);
    first_room->connections = add_node(first_room->connections, buf[1], d);
    second_room->connections = add_node(second_room->connections, buf[0], d);
    free(buf[0]);
    free(buf[1]);
    free(buf);
    return (list);
}

int get_connections(room_t **rooms, char *str)
{
    char *buf = clean_str(str);
    int connection = 0;

    if (!buf)
        return (0);
    for (int j = 0; buf[j]; j++)
        if (buf[j] == '-')
            connection++;
    if (connection == 1) {
        *rooms = add_connexion(*rooms, buf);
    }
    free(buf);
    return (0);
}

int gather_rooms(room_t **rooms, char **str, int *i)
{
    if (my_strncmp(str[*i], "##end", 5) == 0) {
        *i = *i + 1;
        *rooms = add_room(*rooms, str[*i], 0, 1);
        return (0);
    }
    else if (my_strncmp(str[*i], "##start", 7) == 0) {
        *i = *i + 1;
        *rooms = add_room(*rooms, str[*i], 1, 0);
        return (0);
    }
    if (check_for_comment(str[*i]) == 1)
        return (0);
    if (connection_time(str[*i]) == 0)
        return (1);
    else if (check_line(clean_str(str[*i])) == 1) {
        *rooms = NULL;
        return (1);
    }
    *rooms = add_room(*rooms, str[*i], 0, 0);
    return (0);
}

