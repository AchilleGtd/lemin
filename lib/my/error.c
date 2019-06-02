/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** error handling
*/

#include "../../include/my.h"

int not_good_input(char *s)
{
    int i = 0;
    char **buf;
    int nbr_ants = 0;
    int rooms = 0;
    int connections = 0;
    if (!s)
        return (1);
    buf = my_str_to_wordtab(s, '\n');
    for (; buf[i]; i++);
    if (i < 3)
        return (my_exit(s, buf));
    if (is_num(buf[0]))
        return (my_exit(s, buf));
    return (0);
}

int not_cool_neither(char **tab)
{
    int i = 0;
    int end = 0;
    int start = 0;

    while (tab[i]) {
        if (my_strcmp(tab[i], "##end") == 1)
            end = 1;
        else if (my_strcmp(tab[i], "##start") == 1)
            start = 1;
        i++;
    }
    if (end == 0 || start == 0)
        return (1);
    return (0);
}

int error(int error)
{
    char *one = "First line must be a digit representing the number of ants\n";
    char *two = "Error, check the rooms and connections\n";
    char *three = "No start or end\n";

    if (error == 1)
        write(2, one, my_strlen(one));
    if (error == 2)
        write(2, two, my_strlen(two));
    if (error == 3)
        write(2, three, my_strlen(three));
    return (84);
}
