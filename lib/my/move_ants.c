/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** move the anthill
*/

#include "../../include/my.h"

names_t *free_ant(names_t *ants)
{
    names_t *current = ants;

    ants = ants->next;
    free(current);
    return (ants);
}

int get_this_slot(char *name, char **slots)
{
    int i = 0;

    while (slots[i]) {
        if (my_strcmp(slots[i], name) == 0)
            return (i);
        i++;
    }
    return (-1);
}

names_t *move_those_ants(names_t *ants, char **slots)
{
    names_t *current = ants;
    int i;

    while (current) {
        i = get_this_slot(current->name, slots);
        free(current->name);
        current->name = my_strdup(slots[i + 1]);
        current = current->next;
    }
    return (ants);
}

void print(names_t *ants, int i)
{
    names_t *current = ants;

    while (current) {
        my_putstr("P");
        my_putnbr(current->size);
        my_putstr("-");
        my_putstr(current->name);
        if (current->next)
            write(1, " ", 1);
        current = current->next;
    }
    write(1, "\n", 1);
}

void move_ants(path_t **paths, char *end, char *start,  int how_many)
{
    int i = find_name(paths, end);
    static int x;
    names_t *ants = NULL;
    int nbr_slots = how_many_steps(paths[i]);
    char **slots = group_up(paths, i, nbr_slots);
    my_putstr("#moves\n");
    for (int j = 0; j != (how_many + (nbr_slots - 2)); j++) {
        x++;
        if (j < how_many)
            ants = add_ant(ants, j + 1, slots[0]);
        if (!ants)
            break;
        if (my_strcmp(ants->name, end) == 0)
            ants = free_ant(ants);
        if (ants) {
            ants = move_those_ants(ants, slots);
            print(ants, x);
        }
    }
    write(1, "\n", 1);
}

