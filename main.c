/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** main
*/

#include "include/my.h"

void my_putnbr(int nb)
{
    int n;

    if (nb < 0) {
            nb = -nb;
            my_putchar('-');
    }
    if (nb > 9) {
            my_putnbr(nb / 10);
    }
    n = nb % 10 + '0';
    my_putchar(n);
}

void print_tunnels(char **tunnels)
{
    int i = 0;

    while (tunnels[i] && my_strlen(tunnels[i]) != 3)
        i++;
    my_putstr("#tunnels\n");
    while (tunnels[i] && my_strlen(tunnels[i]) == 3) {
        my_putstr(tunnels[i]);
        write(1, "\n", 1);
        i++;
    }
    for (int j = 0; tunnels[j]; j++)
        free(tunnels[j]);
}

void print_infos(room_t *rooms, int number, char **tunnels)
{
    room_t *current = rooms;

    my_putstr("#number_of_ants\n");
    my_putnbr(number);
    my_putstr("\n#rooms\n");
    while (current) {
        if (current->start == 1)
            my_putstr("##start\n");
        if (current->end == 1)
            my_putstr("##end\n");
        my_putstr(current->name);
        write(1, " ", 1);
        my_putnbr(current->x);
        write(1, " ", 1);
        my_putnbr(current->y);
        write(1, "\n", 1);
        current = current->next;
    }
    print_tunnels(tunnels);
}

int lemin(void)
{
    char *s = read_input();
    int how_many = 0;
    room_t *rooms = NULL;
    char **tab;
    if (not_good_input(s))
        return (error(2));
    tab = my_str_to_wordtab(s, '\n');
    if (not_cool(tab, &how_many) == 1)
        return (error(1));
    for (int i = 1; tab[i]; i++) {
        while (tab[i] && gather_rooms(&rooms, tab, &i) != 1)
            i++;
        if (!rooms || not_cool_neither(tab) == 1)
            return (error(2));
        while (tab[i] && get_connections(&rooms, tab[i]) != 1)
            i++;
        print_infos(rooms, how_many, tab);
        return (solver(rooms, how_many));
    }
    return (0);
}

int main(int ac, char **av)
{
    char *s;

    if (ac != 1) {
        return (84);
    }
    return (lemin());
}
