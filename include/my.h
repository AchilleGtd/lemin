/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** dig through anthill
*/

#ifndef MY_H_
#define MY_H_
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct names_s {
    char *name;
    int size;
    struct names_s *next;
} names_t;

typedef struct connections_s {
    char *connected_to;
    int distance;
    struct connections_s *next;
} connections_t;

typedef struct pos_s {
    int x;
    int y;
} pos_t;

typedef struct room_s {
    struct room_s *next;
    connections_t *connections;
    char *name;
    int length;
    int x;
    int y;
    int start;
    int end;
} room_t;

typedef struct djikstra_s {
    int number;
    int distance;
    int visited;
    struct djikstra_s *next;
} djikstra_t;

typedef struct path_s {
    char *name;
    int done;
    int distance;
    struct path_s *head;
    struct path_s *next;
} path_t;

typedef struct infos_s {
    int nbr_ants;
    room_t *rooms;
    connections_t *connections;
} infos_t;

path_t *copy_path(path_t *, path_t *, int);
int done(path_t **);
int look_for_stend(room_t *);
connections_t *check_for_double(connections_t *, char *);
int my_strcmp(char *, char *);
void my_putnbr(int);
char *my_strdup(char *str);
int my_atoi(const char *);
char *read_input();
path_t **alloc_size(room_t *);
char **my_str_to_wordtab(char *, char);
int solver(room_t *rooms, int);
int my_strlen(char *);
char *my_revstr(char *str);
int check_buffer(char str[]);
void readme(int, int *, char str[]);
int find_out_number(room_t *rooms);
path_t **set_path(room_t *rooms);
int not_cool_neither(char **);
path_t *add_path(path_t *, char *, int);
char *get_next_line(int fd);
void my_putchar(char c);
room_t *find_room(room_t *list, char *);
int gather_rooms(room_t **, char **, int *);
int get_connections(room_t **, char *);
void my_putstr(char *str);
char *clean_str(char *str);
room_t *add_room(room_t *rooms, char *, int, int);
int not_good_input(char *);
int not_cool(char **, int *);
int check_line(char *);
int connection_time(char *);
int my_strlen(char *str);
int my_strncmp(char *str, char *, int);
int error(int);
connections_t *find_connections(room_t *room, char *);
pos_t find_startend(room_t *rooms, int);
char *read_file(char *);
int find_current(path_t **, char *);
int check_for_comment(char *str);
connections_t *add_node(connections_t *, char *, int d);
int find_distance(int, int, int, int);
path_t **done_this(char *name, path_t **paths);
char *find_min(path_t **);
path_t **modify(char *, path_t **, room_t *);
path_t *modify_distance(path_t *, path_t *, int);
room_t *find_name_(room_t *, char *);
int find_name(path_t **path, char *);
void move_ants(path_t **, char *, char *, int);
int good_path(char *, char *, path_t **);
int my_exit(char *s, char **);
int is_num(char *);
int good_path(char *, char *, path_t **);
int how_many_steps(path_t *);
char **group_up(path_t **, int, int);
names_t *add_ant(names_t *, int, char *);
#endif
