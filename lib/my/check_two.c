/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** check for correct rooms
*/

#include "../../include/my.h"

pos_t find_startend(room_t *rooms, int n)
{
    room_t *current = rooms;
    pos_t pos;

    pos.x = -1;
    pos.y = -1;
    while (current) {
        if (n ==  0 && current->end == 1) {
            pos.x = current->x;
            pos.y = current->y;
        }
        else if (n == 1 && current->start == 1) {
            pos.x = current->x;
            pos.y = current->y;
        }
        current = current->next;
    }
    return (pos);
}

int look_for_stend(room_t *rooms)
{
    int end = 1;
    int start = 1;
    room_t *cur = rooms;

    while (cur) {
        if (cur->end == 1)
            end = 0;
        if (cur->start == 1)
            end = 0;
        cur = cur->next;
    }
    if (cur == 0 && end == 0)
        return (0);
    return (1);
}

int find_out_number(room_t *rooms)
{
    int i = 0;
    room_t *current = rooms;

    while (current) {
        if (!current->connections)
            current = current->next;
        i++;
        current = current->next;
    }
    return (i);
}
